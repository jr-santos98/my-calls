#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
         // Test 1 - getuserweight
         int user = 1002;
         long int amma = syscall(548, user);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 2 - getuserweight
         user = -1;
         amma = syscall(548, user);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 3 - getuserweight
         user = 70000;
         amma = syscall(548, user);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 4 - setuserweight
         user = 1000;
         int priority = 8;
         amma = syscall(549, user, priority);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 5 - setuserweight
         user = -2;
         priority = 8;
         amma = syscall(549, user, priority);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 6 - setuserweight
         user = 1000;
         priority = -8;
         amma = syscall(549, user, priority);
         printf("System call sys_hello returned %ld\n", amma);

         // Test 7 - setuserweight
         user = -1;
         priority = 11;
         amma = syscall(549, user, priority);
         printf("System call sys_hello returned %ld\n", amma);

         return 0;
}
