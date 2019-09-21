#include "FilePath.h"

FilePath::FilePath(const std::string &path)
{
	const char *p0 = path.c_str();
	const char *p;

	for(;;)
	{
		for(p = p0 ; *p && *p != '\\' && *p !='/' ; ++p);

		if(p > p0)
			_nodes.emplace_back(Node(std::string(p0, p-p0)));

		if(!*p) break;

		p0 = p+1;
	}
}

FilePath::~FilePath()
{

}

bool FilePath::IsEmpty() const
{
	return _nodes.empty();
}

bool FilePath::IsValid() const
{
	int n = 0;
	for(auto it = _nodes.begin() ; it != _nodes.end() ; ++it)
	{
		if(it->_type == 0)
			++n;
		else if(it->_type == 2)
		{
			--n;
			if(n < 0) return false;
		}
	}

	return true;
}

std::string FilePath::ToString(bool collapse) const
{
	if(collapse)
	{
		FilePath tmp = *this;
		if(!tmp.Collapse()) return "";
		return tmp.ToString(false);
	}

	std::string res;
	int n = 0;
	for(auto it = _nodes.begin() ; it != _nodes.end() ; ++it, ++n)
	{
		if(n > 0) res.append("/");
		res.append(it->_name);
	}

	return res;
}

bool FilePath::Collapse()
{
	for(auto it = _nodes.begin() ; it != _nodes.end() ; )
	{
		if(it->_type == 1)
		{
			// . (do nothing)
			it = _nodes.erase(it);
		}
		else if(it->_type == 2)
		{
			// .. (remove last node)
			if(it == _nodes.begin())
				return false;

			--it;
			it = _nodes.erase(it);
			it = _nodes.erase(it);
		}
		else
			++it;
	}

	return true;
}

bool FilePath::RemoveLast()
{
	if(_nodes.empty()) return false;
	_nodes.pop_back();
	return true;
}

void FilePath::Append(const FilePath &f)
{
	_nodes.insert(_nodes.end(), f._nodes.begin(), f._nodes.end());
}
