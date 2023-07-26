#include <ucontext.h>
#include <unistd.h>

#include <iostream>

void foo(void) { printf("foo\n"); }

void bar(void) { printf("bar\n"); }

static ucontext_t ctx[3];

static void f1(void) {
    printf("start f1\n");
    // 将当前 context 保存到 ctx[1]，切换到 ctx[2]
    swapcontext(&ctx[1], &ctx[2]);
    printf("finish f1\n");
}

static void f2(void) {
    printf("start f2\n");
    // 将当前 context 保存到 ctx[2]，切换到 ctx[1]
    swapcontext(&ctx[2], &ctx[1]);
    printf("finish f2\n");
}

int main() {
    /*getcontext和setcontext的小测试
    ucontext_t context;
    getcontext(&context);
    std::cout << "ucontext test program" << std::endl;
    sleep(1);
    setcontext(&context);*/

    /*getcontext和makecontext，ucp.uc_link 为 NULL
    ucontext_t context;
    char stack[1024];
    getcontext(&context);
    context.uc_stack.ss_sp = stack;
    context.uc_stack.ss_size = sizeof(stack);
    context.uc_link = NULL;
    makecontext(&context, foo, 0);

    printf("Hello world\n");
    sleep(1);
    setcontext(&context);*/

    /*makecontext和setcontext
    ucontext_t context1, context2;
    char stack1[1024];
    char stack2[1024];

    getcontext(&context1);
    context1.uc_stack.ss_sp = stack1;
    context1.uc_stack.ss_size = sizeof(stack1);
    context1.uc_link = NULL;
    makecontext(&context1, foo, 0);

    getcontext(&context2);
    context2.uc_stack.ss_sp = stack2;
    context2.uc_stack.ss_size = sizeof(stack2);
    context2.uc_link = &context1;
    makecontext(&context2, bar, 0);

    printf("Hello world\n");
    sleep(1);
    setcontext(&context1);*/

    char stack1[8192];
    char stack2[8192];

    getcontext(&ctx[1]);
    ctx[1].uc_stack.ss_sp = stack1;
    ctx[1].uc_stack.ss_size = sizeof(stack1);
    ctx[1].uc_link = &ctx[0];  // 将执行 return 0
    makecontext(&ctx[1], f1, 0);

    getcontext(&ctx[2]);
    ctx[2].uc_stack.ss_sp = stack2;
    ctx[2].uc_stack.ss_size = sizeof(stack2);
    ctx[2].uc_link = &ctx[1];
    makecontext(&ctx[2], f2, 0);

    // 将当前 context 保存到 ctx[0]，切换到 ctx[2]
    swapcontext(&ctx[0], &ctx[2]);

    return 0;
}