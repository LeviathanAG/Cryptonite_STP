int64_t (* const)() _init()
{
    if (!__gmon_start__)
        return __gmon_start__;
    
    return __gmon_start__();
}

int64_t sub_401020()
{
    int64_t var_8 = 0;
    /* jump -> 0 */
}

int64_t sub_401030()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401040()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401050()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401060()
{
    int64_t var_8 = 3;
    /* tailcall */
    return sub_401020();
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

void setbuf(FILE* fp, char* buf)
{
    /* tailcall */
    return setbuf(fp, buf);
}

int64_t alarm()
{
    /* tailcall */
    return alarm();
}

ssize_t read(int32_t fd, void* buf, uint64_t nbytes)
{
    /* tailcall */
    return read(fd, buf, nbytes);
}

void _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t stack_end_1;
    int64_t stack_end = stack_end_1;
    void ubp_av;
    __libc_start_main(main, __return_addr, &ubp_av, nullptr, nullptr, arg3, &stack_end);
    /* no return */
}

int64_t _dl_relocate_static_pie() __pure
{
    return;
}

void* deregister_tm_clones()
{
    return &__TMC_END__;
}

int64_t register_tm_clones()
{
    return 0;
}

void __do_global_dtors_aux()
{
    if (completed.0)
        return;
    
    deregister_tm_clones();
    completed.0 = 1;
}

int64_t frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

int64_t __constructor__()
{
    setbuf(stdin, nullptr);
    setbuf(__bss_start, nullptr);
    setbuf(stderr, nullptr);
    return alarm(0x10);
}

int64_t __fini(int64_t arg1 @ rbp) __pure
{
    return arg1;
}

int64_t sub_4011f1()
{
    return syscall();
}

int64_t sub_4011f5() __pure
{
    return;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    puts("Quack off, I");
    void buf;
    read(0, &buf, 0x3e8);
    return 0;
}

int64_t _fini() __pure
{
    return;
}

