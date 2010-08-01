#include <nullvm.h>
#include "assert.h"

int main(int argc, char* argv[]) {
    nvmStartup();

    jclass* StackOpcodes = nvmGetClass("org/nullvm/compiler/tests/opcode/StackOpcodes", "org_nullvm_compiler_tests_opcode_StackOpcodes", NULL);
    jint (*swap_int)(jclass*, jint, jint) = j_get_method_impl(StackOpcodes, "swap_int", "(II)I", StackOpcodes);
    jint (*dup_int)(jclass*, jint) = j_get_method_impl(StackOpcodes, "dup_int", "(I)I", StackOpcodes);
    jint (*dup2_int)(jclass*, jint) = j_get_method_impl(StackOpcodes, "dup2_int", "(I)I", StackOpcodes);
    jdouble (*dup2_double)(jclass*, jdouble) = j_get_method_impl(StackOpcodes, "dup2_double", "(D)D", StackOpcodes);
    jlong (*dup2_long)(jclass*, jlong) = j_get_method_impl(StackOpcodes, "dup2_long", "(J)J", StackOpcodes);
    jint (*dup_x1)(jclass*, jint, jint) = j_get_method_impl(StackOpcodes, "dup_x1", "(II)I", StackOpcodes);
    jint (*dup_x2)(jclass*, jint, jint, jint) = j_get_method_impl(StackOpcodes, "dup_x2", "(III)I", StackOpcodes);
    jint (*dup_x2_long)(jclass*, jlong, jint) = j_get_method_impl(StackOpcodes, "dup_x2", "(JI)I", StackOpcodes);
    jint (*dup2_x1)(jclass*, jint, jint, jint) = j_get_method_impl(StackOpcodes, "dup2_x1", "(III)I", StackOpcodes);
    jint (*dup2_x1_long)(jclass*, jint, jlong) = j_get_method_impl(StackOpcodes, "dup2_x1", "(IJ)I", StackOpcodes);
    jint (*dup2_x2_int)(jclass*, jint, jint, jint, jint) = j_get_method_impl(StackOpcodes, "dup2_x2", "(IIII)I", StackOpcodes);
    jdouble (*dup2_x2_double)(jclass*, jdouble, jdouble) = j_get_method_impl(StackOpcodes, "dup2_x2", "(DD)D", StackOpcodes);
    jint (*dup2_x2_int_int_long)(jclass*, jint, jint, jlong) = j_get_method_impl(StackOpcodes, "dup2_x2", "(IIJ)I", StackOpcodes);
    jint (*dup2_x2_long_int_int)(jclass*, jlong, jint, jint) = j_get_method_impl(StackOpcodes, "dup2_x2", "(JII)I", StackOpcodes);

    assertEqualsInt("swap_int", -1, swap_int(StackOpcodes, 3, 2));

    assertEqualsInt("dup_int", 100, dup_int(StackOpcodes, 10));

    assertEqualsInt("dup2_int", 81, dup2_int(StackOpcodes, 3));
    assertEqualsInt("dup2_int", 0, dup2_int(StackOpcodes, 0x80000000));

    assertEqualsDouble("dup2_double", 9.0, dup2_double(StackOpcodes, 3.0));
    assertEqualsDouble("dup2_double", 1.0/0.0, dup2_double(StackOpcodes, 0x1.fffffffffffffP+1023));
    assertEqualsLong("dup2_long", 9L, dup2_long(StackOpcodes, 3L));
    assertEqualsLong("dup2_long", 0L, dup2_long(StackOpcodes, 0x8000000000000000L));

    assertEqualsInt("dup_x1", -88, dup_x1(StackOpcodes, 9, 11));
    assertEqualsInt("dup_x1", 168, dup_x1(StackOpcodes, -20, 8));

    assertEqualsInt("dup_x2(int, int, int)", -121, dup_x2(StackOpcodes, 9, 11, 13));
    assertEqualsInt("dup_x2(int, int, int)", -34, dup_x2(StackOpcodes, -20, 8, 2));
    assertEqualsInt("dup_x2(long, int)", -88, dup_x2_long(StackOpcodes, 9, 11));

    assertEqualsInt("dup2_x1(int, int, int)", -64, dup2_x1(StackOpcodes, 2, 16, 2));
    assertEqualsInt("dup2_x1(int, long)", -88, dup2_x1_long(StackOpcodes, 9, 11));

    assertEqualsInt("dup2_x2(int, int, int, int)", 8, dup2_x2_int(StackOpcodes, 2, 2, 16, 2));
    assertEqualsDouble("dup2_x2(double, double)", -88.0, dup2_x2_double(StackOpcodes, 9.0, 11.0));
    assertEqualsDouble("dup2_x2(double, double)", 168.0, dup2_x2_double(StackOpcodes, -20.0, 8.0));
    assertEqualsInt("dup2_x2(int, int, long)", -32, dup2_x2_int_int_long(StackOpcodes, 2, 16, 2));
    assertEqualsInt("dup2_x2(long, int, int)", -512, dup2_x2_long_int_int(StackOpcodes, 2, 16, 2));

    print_test_result();

    return 0;
}


