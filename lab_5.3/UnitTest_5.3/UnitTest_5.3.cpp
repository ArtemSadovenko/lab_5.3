#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_5.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
	TEST_CLASS(UnitTest53)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = f(1.8);
			Assert::AreEqual(t, 0.8084);
		}
	};
}
