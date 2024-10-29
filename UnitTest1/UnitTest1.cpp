#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1(string).cpp"  // Шлях до вашого коду

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCount)
        {
            Assert::AreEqual(Count("nno"), 1); 
            Assert::AreEqual(Count("nxxo"), 0); 
            Assert::AreEqual(Count("nno nno"), 2); 
            Assert::AreEqual(Count("nxxnno"), 1); 
            Assert::AreEqual(Count("n?o n?o"), 2); 
            Assert::AreEqual(Count("hello n?o world n?o!"), 2); 
        }

        TEST_METHOD(TestChange)
        {
            string str1 = "n?o";
            Change(str1);
            Assert::AreEqual(str1.c_str(), "**"); 

            string str2 = "Hello n?o World";
            Change(str2);
            Assert::AreEqual(str2.c_str(), "Hello ** World"); 

            string str3 = "nno n?o";
            Change(str3);
            Assert::AreEqual(str3.c_str(), "** **"); 

            string str4 = "No match here!";
            Change(str4);
            Assert::AreEqual(str4.c_str(), "No match here!"); 

            string str5 = "nnnoooo";
            Change(str5);
            Assert::AreEqual(str5.c_str(), "n**ooo"); 
        }
    };
}
