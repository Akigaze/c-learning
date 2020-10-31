//
// Created by Akigaze on 10/31/2020.
//

void testLocalVariable() {
    /*
     * 局部常量，不能直接修改，可以使用指针进行修改
     * not allow: localVariable = 300;
     * allow: int *p = &localVariable; *p = 300;
     */
    const int localVariable = 200;
}

void testPointVariable() {
    int n = 100;

    /*
     * 不允许通过指针修改其指向的地址的内容
     * not allow: *p = 200;
     */
    const int *p = &n;
    /*
     * 不允许修改指针指向的地址
     * not allow: q = NULL;
     */
    int *const q = &n;

}

int main(int args, char *argv[]) {
    /*
     * 全局常量，只支持读，不允许修改(直接修改/指针修改)
     * not allow: globalVariable = 300;
     * not allow: int *p = &globalVariable; *p = 300;
     */
    const int globalVariable = 100;

    testLocalVariable();

    testPointVariable();
}

