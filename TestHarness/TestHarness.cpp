// TestHarness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

// include user defined types
#include "ReverseCharPtr.h"
#include "LinkedList.h"
#include "Vector.h"

// forward function declarations
void RunStringReverseTests();
void RunPalendromeStringTests();
void TestLinkedListImpl();
void TestDotProduct();
void TestCrossProduct();

int main(void)
{
	//RunStringReverseTests();
	//RunPalendromeStringTests();
	//TestLinkedListImpl();

	TestDotProduct();
	TestCrossProduct();

	std::cout << "Console is waiting... press any key to exit." << std::endl;
	getchar();
    return 0;
}

void RunStringReverseTests()
{
	char test[] = "test1";
	std::cout << "test string = " << test << std::endl;
	ReverseStr(test);
	std::cout << "reversed string = " << test << std::endl;

	char test2[] = "testagain";
	std::cout << "test string = " << test2 << std::endl;
	ReverseStr(test2);
	std::cout << "reversed string = " << test2 << std::endl;

	char test3[] = "furthertesting";
	std::cout << "test string = " << test3 << std::endl;
	ReverseStr(test3);
	std::cout << "reversed string = " << test3 << std::endl;
}

void RunPalendromeStringTests()
{
	char test4[] = "tesaset";
	std::cout << "test string = " << test4 << std::endl;
	bool isPal = IsPalendrome(test4);
	std::string result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;

	char test5[] = "redivider";
	std::cout << "test string = " << test5 << std::endl;
	isPal = IsPalendrome(test5);
	result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;

	char test6[] = "deified";
	std::cout << "test string = " << test6 << std::endl;
	isPal = IsPalendrome(test6);
	result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;

	char test7[] = "notpal";
	std::cout << "test string = " << test7 << std::endl;
	isPal = IsPalendrome(test7);
	result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;

	char test8[] = "";
	std::cout << "test string = " << test8 << std::endl;
	isPal = IsPalendrome(test8);
	result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;

	char test9[] = "a";
	std::cout << "test string = " << test9 << std::endl;
	isPal = IsPalendrome(test9);
	result = (isPal == 0) ? "false" : "true";
	std::cout << "string is pal = " << result << std::endl;
}

void TestLinkedListImpl()
{
	LinkedList* theTestList = new LinkedList();
	LinkNode* node = new LinkNode(1);
	theTestList->Insert(node);

	node = new LinkNode(5);
	theTestList->Insert(node);

	node = new LinkNode(7);
	theTestList->Insert(node);

	node = new LinkNode(2);
	theTestList->Insert(node);

	node = new LinkNode(8);
	theTestList->Insert(node);
}

void TestDotProduct()
{
	Vector v1 = Vector(2, 3, 1);
	std::cout << "v1 component values: x = " << v1.X << " y = " << v1.Y << " z =  " << v1.Z << endl;

	Vector v2 = v1.ScaleVector(4);
	std::cout << "v2 component values: x = " << v2.X << " y = " << v2.Y << " z =  " << v2.Z << endl;

	Vector v3 = Vector(-2, -3, 1);
	std::cout << "v3 component values: x = " << v3.X << " y = " << v3.Y << " z =  " << v3.Z << endl;

	v1.NormalizeVector();
	std::cout << "Normalized v1 component values: x = " << v1.X << " y = " << v1.Y << " z =  " << v1.Z << endl;
	std::cout << "v1 component values summed = " << v1.X + v1.Y + v1.Z << endl;
	v2.NormalizeVector();
	std::cout << "Normalized v2 component values: x = " << v2.X << " y = " << v2.Y << " z =  " << v2.Z << endl;
	std::cout << "v2 component values summed = " << v2.X + v2.Y + v2.Z << endl;

	v3.NormalizeVector();
	std::cout << "Normalized v3 component values: x = " << v3.X << " y = " << v3.Y << " z =  " << v3.Z << endl;
	std::cout << "v3 component values summed = " << v3.X + v3.Y + v3.Z << endl;

	std::cout << "Dot product of v1 and v2 = " << v1.DotProduct(v2) << endl;

	std::cout << "Dot product of v1 and v3 = " << v1.DotProduct(v3) << endl;

	std::cout << "Dot product of v1 and v3 = " << Vector::DotProduct(v1, v3) << endl;
}

void TestCrossProduct()
{
	std::cout << "CrossProduct testing 1..." << endl;
	Vector v1 = Vector(2, 3, 1);
	std::cout << "v1 component values: x = " << v1.X << " y = " << v1.Y << " z =  " << v1.Z << endl;

	Vector v2 = Vector(-2, -3, 1);
	std::cout << "v2 component values: x = " << v2.X << " y = " << v2.Y << " z =  " << v2.Z << endl;

	Vector v3 = Vector::CrossProduct(v1, v2);
	std::cout << "v3 component values: x = " << v3.X << " y = " << v3.Y << " z =  " << v3.Z << endl;
	v3.NormalizeVector();
	std::cout << "v3 normalized component values: x = " << v3.X << " y = " << v3.Y << " z =  " << v3.Z << endl;

	std::cout << "CrossProduct testing 2..." << endl;
	Vector vecRight = Vector::CrossProduct(Vector::UpVector, Vector::ForwardVector);
	std::cout << "Vector::UpVector values: x = " << Vector::UpVector.X << " y = " << Vector::UpVector.Y << " z =  " << Vector::UpVector.Z << endl;
	std::cout << "Vector::ForwardVector component values: x = " << Vector::ForwardVector.X << " y = " << Vector::ForwardVector.Y << " z =  " << Vector::ForwardVector.Z << endl;
	std::cout << "vecRight component values: x = " << vecRight.X << " y = " << vecRight.Y << " z =  " << vecRight.Z << endl;
}

