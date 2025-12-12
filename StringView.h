#pragma once
#include <boost/functional/hash.hpp>
#include <boost/utility/string_view.hpp>

using StringView = boost::string_view;
using HashStringView = boost::hash<boost::string_view>;
