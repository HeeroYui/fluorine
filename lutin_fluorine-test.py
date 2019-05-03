#!/usr/bin/python
import realog.debug as debug
import lutin.tools as tools


def get_type():
	return "BINARY"

def get_sub_type():
	return "TEST"

def get_name():
	return "fluorine-test"

def get_desc():
	return "fluorine test application"

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
	my_module.add_src_file([
	    'test/test.cpp',
	    'test/testAll.cpp',
	    ])
	my_module.add_depend([
	    'fluorine',
	    'etest',
	    'test-debug'
	    ])
	return True

