#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_3_4/Factory.cpp"
#include "../OOP_3_4/OctString.cpp"
#include "../OOP_3_4/SymString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnTOOP34
{
	TEST_CLASS(UnTOOP34)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			OctString a(64);
			Assert::AreEqual("100", a.GetString().c_str());
		}
	};
}
