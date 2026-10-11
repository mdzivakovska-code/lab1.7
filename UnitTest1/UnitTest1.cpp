#include "pch.h"
#include "CppUnitTest.h"
#include"../lab1.7/LongLong.h"
#include"../lab1.7/LongLong.cpp"
#include"../lab1.7/Cursor.h"
#include"../lab1.7/Cursor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LongLong a = LongLong::fromInt64(100);
			LongLong b = LongLong::fromInt64(30);
			LongLong c = a.add(b);
			Assert::AreEqual((long long)130, c.toInt64());
		}
		TEST_METHOD(TestLongLongMul)
		{
			LongLong a = LongLong::fromInt64(10);
			LongLong b = LongLong::fromInt64(25);
			LongLong c = a.mul(b);

			
			Assert::AreEqual((long long)250, c.toInt64());
		}
        TEST_METHOD(TestCursorSetSize)
        {
            Cursor cur;

            bool valid = cur.setSize(10);
            Assert::IsTrue(valid);
            Assert::AreEqual(10, cur.getSize());

            
            bool invalidHigh = cur.setSize(20);
            Assert::IsFalse(invalidHigh);

           
            bool invalidLow = cur.setSize(0);
            Assert::IsFalse(invalidLow);
        }

        
        TEST_METHOD(TestCursorHideAndRestore)
        {
            Cursor cur;
            LongLong x = LongLong::fromInt64(1);
            LongLong y = LongLong::fromInt64(1);
            cur.Init(x, y, "horizontal", 5);

         
            Assert::IsTrue(cur.isVisible());

            cur.hide();
            Assert::IsFalse(cur.isVisible());

        
            cur.restore();
            Assert::IsTrue(cur.isVisible());
        }
    };
}