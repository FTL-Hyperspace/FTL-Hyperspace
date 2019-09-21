#pragma once

#include <list>
#include <string>

class FilePath
{
public:
	FilePath(const std::string &path);
	~FilePath();

	bool IsEmpty() const;
	bool IsValid() const;
	std::string ToString(bool collapse = true) const;

	bool RemoveLast();
	void Append(const FilePath &f);
	
	bool Collapse();

private:
	struct Node
	{
		Node(const std::string &name) : _name(name)
		{
			const char *n = _name.c_str();
			_type = 0;
			if(n[0] == '.')
			{
				if(!n[1])
					_type = 1;
				else if(n[1] == '.' && !n[2])
					_type = 2;
			}
		}

		std::string _name;
		int _type;
	};
	std::list<Node> _nodes;
};
