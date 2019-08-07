/*
 * ResourceManager.h
 *
 *  Created on: 5 août 2019
 *      Author: fabien
 */

#ifndef SRC_RESOURCEMANAGER_H_
#define SRC_RESOURCEMANAGER_H_

#include <unordered_map>
#include <sstream>
#include <fstream>

#include "Utilities.h"

template<typename Derived, typename T>
class ResourceManager
{

public:

	ResourceManager(const std::string& l_pathsFile)
	{
		loadPaths(l_pathsFile);
	}
	virtual ~ResourceManager() { purgeResources(); }

	T* getResource(const std::string& l_id)
	{
		auto resource = find(l_id);
		return (resource ? resource->first : nullptr);
	}
	std::string getPath(const std::string& l_id)
	{
		auto path = m_paths.find(l_id);
		return (path != m_paths.end() ? path->second : "");
	}

	bool requireResource(const std::string& l_id)
	{
		auto res = find(l_id);
		if(res)
		{
			++res->second;
			return true;
		}
		auto path = m_paths.find(l_id);
		if(path == m_paths.end()) { return false; }
		T* resource = load(path->second);
		if(!resource) { return false; }
		m_resources.emplace(l_id, std::make_pair(resource, 1));
		return true;
	}

	bool releaseResource(const std::string& l_id)
	{
		auto res = find(l_id);
		if(!res) { return false; }
		--res->second;
		if(!res->second)
		{
			unload(l_id);
		}
		return true;
	}
	void purgeResources()
	{
		while(m_resources.begin() != m_resources.end())
		{
			delete m_resources.begin()->second.first;
			m_resources.erase(m_resources.begin());
		}
	}

private:

	void loadPaths(const std::string& l_pathsFile)
	{
		std::ifstream paths;
		paths.open(Utils::getWorkingDirectory() + l_pathsFile);
		if(paths.is_open())
		{
			std::string line;
			while(std::getline(paths, line))
			{
				std::stringstream keystream(line);
				std::string path;
				std::string id;
				keystream >> id;
				keystream >> path;
				m_paths.emplace(id, path);
			}
			paths.close();
			return;
		}
		std::cerr << "! Failed to load " << l_pathsFile	<< std::endl;
	}

	std::pair<T*, unsigned int>* find(const std::string& l_id)
	{
		auto itr = m_resources.find(l_id);
		return (itr != m_resources.end() ? &itr->second : nullptr);
	}

	T* load(const std::string& l_path)
	{
		return static_cast<Derived*>(this)->load(l_path);
	}

	bool unload(const std::string& l_id)
	{
		auto itr = m_resources.find(l_id);
		if(itr == m_resources.end()) { return false; }
		delete itr->second.first;
		m_resources.erase(itr);
		return true;
	}

	std::unordered_map<std::string, std::pair<T*, unsigned int>> m_resources;
	std::unordered_map<std::string, std::string> m_paths;

};

#endif /* SRC_RESOURCEMANAGER_H_ */
