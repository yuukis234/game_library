#include <unity_fixture.h>

static void RunAllTests(void)
{
    RUN_TEST_GROUP( Succ);
}

int main( int argc, char const**argv)
{
    return UnityMain( argc, argv, RunAllTests);
}