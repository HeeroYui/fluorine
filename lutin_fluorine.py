#!/usr/bin/python
import lutin.debug as debug
import lutin.tools as tools


def get_type():
	return "LIBRARY"

def get_desc():
	return "fluorine interface for variant implementation"

def get_licence():
	return "MPL-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def get_version():
	return "version.txt"

def configure(target, my_module):
	my_module.add_depend([
	    'elog',
	    'etk',
	    'ememory'
	    ])
	my_module.add_extra_flags()
	my_module.add_src_file([
	    'fluorine/debug.cpp',
	    'fluorine/variantType.cpp',
	    'fluorine/Variant.cpp',
	    ])
	my_module.add_header_file([
	    'fluorine/debug.hpp',
	    'fluorine/variantType.hpp',
	    'fluorine/Variant.hpp',
	    ])
	my_module.add_path(".")
	return True


