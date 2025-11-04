void __mingw_invalidParameterHandler(short unsigned int const* expression, short unsigned int const* function, short unsigned int const* file, unsigned int line, long long unsigned int pReserved) __pure
{
    return;
}

int pre_c_init()
{
    __mingw_initltsdrot_force = 1;
    __mingw_initltsdyn_force = 1;
    __mingw_initltssuo_force = 1;
    int rcx;
    rcx = false;
    managedapp = rcx;
    
    if (!__mingw_app_type)
        __set_app_type(_crt_console_app);
    else
        __set_app_type(_crt_gui_app);
    
    int32_t* rax_1 = __p__fmode();
    *rax_1 = _fmode;
    int32_t* rax_2 = __p__commode();
    *rax_2 = _commode;
    
    if (_MINGW_INSTALL_DEBUG_MATHERR != 1)
        return 0;
    
    __mingw_setusermatherr(_matherr);
    return 0;
}

uint64_t pre_cpp_init()
{
    startinfo.newmode = _newmode;
    return __getmainargs(&argc, &argv, &envp, _dowildcard, &startinfo);
}

int __tmainCRTStartup()
{
    TEB* gsbase;
    void* StackBase = gsbase->NtTib.Self->NtTib.StackBase;
    
    while (true)
    {
        int64_t _.bss_1 = 0;
        
        if (0 == _.bss)
            _.bss = StackBase;
        else
            _.bss_1 = _.bss;
        
        int32_t rdi;
        
        if (_.bss_1)
        {
            if (StackBase != _.bss_1)
            {
                Sleep(0x3e8);
                continue;
            }
            
            rdi = 1;
            
            if (__native_startup_state != 1)
                goto label_1400011f6;
            
            goto label_140001354;
        }
        else
        {
            rdi = 0;
            
            if (__native_startup_state != 1)
            {
            label_1400011f6:
                
                if (!__native_startup_state)
                {
                    __native_startup_state = 1;
                    _initterm(&__xi_a, &__xi_z);
                }
                else
                    has_cctor = 1;
                
                if (__native_startup_state == 1)
                    goto label_140001372;
                
                goto label_140001211;
            }
            
        label_140001354:
            _amsg_exit(0x1f);
            
            if (__native_startup_state != 1)
            {
            label_140001211:
                
                if (rdi)
                    break;
            }
            else
            {
            label_140001372:
                _initterm(&__xc_a, &__xc_z);
                __native_startup_state = 2;
                
                if (rdi)
                    break;
            }
        }
        _.bss;
        _.bss = 0;
        break;
    }
    
    __dyn_tls_init(nullptr, 2, nullptr);
    _pei386_runtime_relocator();
    __mingw_oldexcpt_handler = SetUnhandledExceptionFilter(_gnu_exception_handler);
    mingw_set_invalid_parameter_handler(__mingw_invalidParameterHandler);
    int argc_1 = argc;
    int64_t _Size_1 = (argc_1 + 1) << 3;
    void* rax_5 = malloc(_Size_1);
    char** argv_1 = argv;
    int64_t* r12 = rax_5;
    void* rdi_4;
    
    if (argc_1 <= 0)
        rdi_4 = rax_5;
    else
    {
        int64_t i = 0;
        
        do
        {
            uint64_t _Size = strlen(*(argv_1 + i)) + 1;
            int64_t rax_7 = malloc(_Size);
            *(r12 + i) = rax_7;
            int64_t rdx_1 = *(argv_1 + i);
            i += 8;
            memcpy(rax_7, rdx_1, _Size);
        } while (_Size_1 - 8 != i);
        
        rdi_4 = _Size_1 - 8 + r12;
    }
    
    *rdi_4 = 0;
    argv = r12;
    __main();
    argc;
    *__initenv = envp;
    argv;
    main();
    int managedapp_1 = managedapp;
    mainret = 0;
    
    if (!managedapp_1)
    {
        exit(0);
        /* no return */
    }
    
    if (has_cctor)
        return 0;
    
    _cexit();
    return mainret;
}

int WinMainCRTStartup()
{
    __mingw_app_type = 1;
    return __tmainCRTStartup();
}

int mainCRTStartup()
{
    __mingw_app_type = 0;
    return __tmainCRTStartup();
}

int atexit(void (* func)())
{
    _onexit_t_1 rax = _onexit(func);
    return rax - rax;
}

int64_t __gcc_register_frame()
{
    /* tailcall */
    return atexit(__gcc_deregister_frame);
}

void __gcc_deregister_frame() __pure
{
    return;
}

int64_t printf(char* arg1, int64_t arg2)
{
    int64_t argv = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    int64_t* var_20 = &argv;
    return __mingw_vfprintf(__imp___acrt_iob_func(), arg1, &argv);
}

int64_t sprintf.constprop.0(char* arg1, int64_t arg2, int64_t arg3)
{
    int64_t argv = arg3;
    int64_t r9;
    int64_t arg_20 = r9;
    int64_t* var_10 = &argv;
    return __mingw_vsprintf(arg1, "%02x%s", &argv);
}

int64_t scanf.constprop.0(int64_t arg1, int64_t arg2)
{
    int64_t argp = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    int64_t* var_10 = &argp;
    return __mingw_vfscanf(__imp___acrt_iob_func(), "%1023[^\n]", &argp);
}

int64_t trim(char* arg1)
{
    char* rdi = arg1;
    int64_t rbx = strlen(arg1);
    
    while (isspace(rdi[rbx - 1]))
    {
        rdi[rbx - 1] = 0;
        rbx -= 1;
    }
    
    int32_t _C = *rdi;
    int32_t rbx_2;
    char* rsi;
    
    if (!_C)
    {
        rbx_2 = rbx + 1;
        rsi = rdi;
    }
    else
    {
        rsi = rdi;
        
        do
        {
            rbx_2 = &rdi[rbx] - rsi;
            
            if (!isspace(_C))
            {
                rbx_2 += 1;
                break;
            }
            
            _C = rsi[1];
            rsi = &rsi[1];
        } while (_C);
    }
    
    /* tailcall */
    return memmove(rdi, rsi, rbx_2);
}

uint64_t hexCharToValue(char arg1) __pure
{
    if (arg1 - 0x30 <= 9)
        return arg1 - 0x30;
    
    if (arg1 - 0x61 <= 5)
        return arg1 - 0x57;
    
    if (arg1 - 0x41 >= 6)
        return 0xffffffff;
    
    return arg1 - 0x37;
}

uint64_t hexStringToBytes(char* arg1, char* arg2)
{
    int64_t rsi = 0;
    
    while (true)
    {
        int32_t rdx_2;
        
        if (rsi >= strlen(arg1))
            rdx_2 = 0;
        else
        {
            int32_t rax_4 = arg1[rsi << 1];
            char rax_1;
            char rax_2;
            
            if (rax_4 - 0x30 <= 9)
            {
                rdx_2 = rax_4 - 0x30;
                rax_1 = arg1[(rsi << 1) + 1];
                
                if (rax_1 - 0x30 <= 9)
                {
                label_140001699:
                    rax_2 = rax_1 - 0x30;
                label_140001669:
                    arg2[rsi] = rdx_2 << 4 | rax_2;
                    rsi += 1;
                    continue;
                }
                
            label_14000164f:
                
                if (rax_1 - 0x61 > 5)
                    goto label_140001657;
                
                rax_2 = rax_1 - 0x57;
                goto label_140001669;
            }
            else if (rax_4 - 0x61 <= 5)
            {
                rdx_2 = rax_4 - 0x57;
                rax_1 = arg1[(rsi << 1) + 1];
                
                if (rax_1 - 0x30 <= 9)
                    goto label_140001699;
                
                if (rax_1 - 0x61 <= 5)
                {
                    rax_2 = rax_1 - 0x57;
                    goto label_140001669;
                }
                
            label_140001657:
                
                if (rax_1 - 0x41 > 5)
                    break;
                
                rax_2 = rax_1 - 0x37;
                
                if (rdx_2 != 0xffffffff)
                    goto label_140001669;
            }
            else
            {
                if (rax_4 - 0x41 <= 5)
                {
                    rdx_2 = rax_4 - 0x37;
                    rax_1 = arg1[(rsi << 1) + 1];
                    
                    if (rax_1 - 0x30 <= 9)
                        goto label_140001699;
                    
                    goto label_14000164f;
                }
                
                rax_1 = arg1[(rsi << 1) + 1];
                
                if (rax_1 - 0x30 <= 9)
                    break;
                
                rdx_2 = -1;
                
                if (rax_1 - 0x61 > 5)
                    goto label_140001657;
            }
        }
        
        return rdx_2;
    }
    
    return 0xffffffff;
}

int64_t printBufferAsHex(char* arg1, int64_t arg2)
{
    if (!arg2 || !arg1)
        /* tailcall */
        return printf("(empty buffer)\n", arg2);
    
    uint64_t _Size = arg2 * 3;
    char* i_2 = malloc(_Size);
    
    if (!i_2)
        /* tailcall */
        return perror("malloc failed");
    
    uint64_t r8 = *arg1;
    
    if (arg2 != 1)
    {
        char* i = &i_2[3];
        void* rbx_1 = &arg1[1];
        char* i_1 = i_2;
        
        do
        {
            rbx_1 += 1;
            sprintf.constprop.0(i_1, "%02x%s", r8);
            i_1 = i;
            i = &i[3];
            r8 = *(rbx_1 - 1);
        } while (i != &i_2[_Size]);
    }
    
    sprintf.constprop.0(&i_2[_Size - 3], "%02x%s", r8);
    printf("%s\n", i_2);
    /* tailcall */
    return free(i_2);
}

int32_t* body(void* arg1, int32_t* arg2, int32_t arg3)
{
    int32_t rbx = *(arg1 + 0xc);
    int32_t rsi = *(arg1 + 0x10);
    int32_t var_50 = *(arg1 + 8);
    int32_t* result = arg2;
    int32_t r8 = *(arg1 + 0x14);
    
    do
    {
        int32_t r12_1 = *result;
        int32_t rbp_1 = result[7];
        int32_t rax_9 = ROLD((((rsi ^ r8) & rbx) ^ r8) + r12_1 + var_50 - 0x28955b88, 7) + rbx;
        int32_t r9_7 =
            ROLD((((rbx ^ rsi) & rax_9) ^ rsi) + result[1] + r8 - 0x173848aa, 0xc) + rax_9;
        int32_t rcx_6 =
            RORD((((rbx ^ rax_9) & r9_7) ^ rbx) + result[2] + rsi + 0x242070db, 0xf) + r9_7;
        int32_t rdx_12 =
            RORD((((rax_9 ^ r9_7) & rcx_6) ^ rax_9) + result[3] + rbx - 0x3e423112, 0xa) + rcx_6;
        int32_t rax_16 =
            ROLD((((r9_7 ^ rcx_6) & rdx_12) ^ r9_7) + result[4] + rax_9 - 0xa83f051, 7) + rdx_12;
        int32_t r9_14 =
            ROLD((((rcx_6 ^ rdx_12) & rax_16) ^ rcx_6) + result[5] + r9_7 + 0x4787c62a, 0xc)
            + rax_16;
        int32_t rcx_13 =
            RORD((((rdx_12 ^ rax_16) & r9_14) ^ rdx_12) + result[6] + rcx_6 - 0x57cfb9ed, 0xf)
            + r9_14;
        int32_t rdx_19 =
            RORD((((rax_16 ^ r9_14) & rcx_13) ^ rax_16) + rbp_1 + rdx_12 - 0x2b96aff, 0xa) + rcx_13;
        int32_t rax_23 =
            ROLD((((r9_14 ^ rcx_13) & rdx_19) ^ r9_14) + result[8] + rax_16 + 0x698098d8, 7)
            + rdx_19;
        int32_t r9_21 =
            ROLD((((rcx_13 ^ rdx_19) & rax_23) ^ rcx_13) + result[9] + r9_14 - 0x74bb0851, 0xc)
            + rax_23;
        int32_t rcx_20 =
            RORD((((rdx_19 ^ rax_23) & r9_21) ^ rdx_19) + result[0xa] + rcx_13 - 0xa44f, 0xf)
            + r9_21;
        int32_t r10_10 = result[0xc];
        int32_t rdx_26 =
            RORD((((rax_23 ^ r9_21) & rcx_20) ^ rax_23) + result[0xb] + rdx_19 - 0x76a32842, 0xa)
            + rcx_20;
        int32_t rdi_2 = result[0xe];
        int32_t rax_30 =
            ROLD((((r9_21 ^ rcx_20) & rdx_26) ^ r9_21) + r10_10 + rax_23 + 0x6b901122, 7) + rdx_26;
        int32_t r14_7 =
            ROLD((((rcx_20 ^ rdx_26) & rax_30) ^ rcx_20) + result[0xd] + r9_21 - 0x2678e6d, 0xc)
            + rax_30;
        int32_t r9_24 = result[0xf];
        int32_t rcx_27 =
            RORD((((rdx_26 ^ rax_30) & r14_7) ^ rdx_26) + rdi_2 + rcx_20 - 0x5986bc72, 0xf) + r14_7;
        int32_t rdx_33 =
            RORD((((rax_30 ^ r14_7) & rcx_27) ^ rax_30) + r9_24 + rdx_26 + 0x49b40821, 0xa)
            + rcx_27;
        int32_t r13_8 =
            ROLD((((rcx_27 ^ rdx_33) & r14_7) ^ rcx_27) + result[1] + rax_30 - 0x9e1da9e, 5)
            + rdx_33;
        int32_t rax_38 =
            ROLD((((rdx_33 ^ r13_8) & rcx_27) ^ rdx_33) + result[6] + r14_7 - 0x3fbf4cc0, 9)
            + r13_8;
        int32_t rcx_34 =
            ROLD((((r13_8 ^ rax_38) & rdx_33) ^ r13_8) + result[0xb] + rcx_27 + 0x265e5a51, 0xe)
            + rax_38;
        int32_t rdx_40 =
            RORD((((rax_38 ^ rcx_34) & r13_8) ^ rax_38) + r12_1 + rdx_33 - 0x16493856, 0xc)
            + rcx_34;
        int32_t r13_15 =
            ROLD((((rcx_34 ^ rdx_40) & rax_38) ^ rcx_34) + result[5] + r13_8 - 0x29d0efa3, 5)
            + rdx_40;
        int32_t rax_45 =
            ROLD((((rdx_40 ^ r13_15) & rcx_34) ^ rdx_40) + result[0xa] + rax_38 + 0x2441453, 9)
            + r13_15;
        int32_t rcx_41 =
            ROLD((((r13_15 ^ rax_45) & rdx_40) ^ r13_15) + r9_24 + rcx_34 - 0x275e197f, 0xe)
            + rax_45;
        int32_t rdx_47 =
            RORD((((rax_45 ^ rcx_41) & r13_15) ^ rax_45) + result[4] + rdx_40 - 0x182c0438, 0xc)
            + rcx_41;
        int32_t r13_22 =
            ROLD((((rcx_41 ^ rdx_47) & rax_45) ^ rcx_41) + result[9] + r13_15 + 0x21e1cde6, 5)
            + rdx_47;
        int32_t rax_52 =
            ROLD((((rdx_47 ^ r13_22) & rcx_41) ^ rdx_47) + rdi_2 + rax_45 - 0x3cc8f82a, 9) + r13_22;
        int32_t rcx_48 =
            ROLD((((r13_22 ^ rax_52) & rdx_47) ^ r13_22) + result[3] + rcx_41 - 0xb2af279, 0xe)
            + rax_52;
        int32_t rdx_54 =
            RORD((((rax_52 ^ rcx_48) & r13_22) ^ rax_52) + result[8] + rdx_47 + 0x455a14ed, 0xc)
            + rcx_48;
        int32_t r13_29 =
            ROLD((((rcx_48 ^ rdx_54) & rax_52) ^ rcx_48) + result[0xd] + r13_22 - 0x561c16fb, 5)
            + rdx_54;
        int32_t rax_59 =
            ROLD((((rdx_54 ^ r13_29) & rcx_48) ^ rdx_54) + result[2] + rax_52 - 0x3105c08, 9)
            + r13_29;
        int32_t rcx_55 =
            ROLD((((r13_29 ^ rax_59) & rdx_54) ^ r13_29) + rbp_1 + rcx_48 + 0x676f02d9, 0xe)
            + rax_59;
        int32_t rdx_61 =
            RORD((((rax_59 ^ rcx_55) & r13_29) ^ rax_59) + r10_10 + rdx_54 - 0x72d5b376, 0xc)
            + rcx_55;
        int32_t r14_24 = rcx_55 ^ rdx_61;
        int32_t r13_34 = ROLD((r14_24 ^ rax_59) + result[5] + r13_29 - 0x5c6be, 4) + rdx_61;
        int32_t rax_60 = r13_34 + ROLD((r14_24 ^ r13_34) + result[8] + rax_59 - 0x788e097f, 0xb);
        int32_t r15_25 = r13_34 ^ rax_60;
        int32_t r14_33 = ROLD((r15_25 ^ rdx_61) + result[0xb] + rcx_55 + 0x6d9d6122, 0x10) + rax_60;
        int32_t rcx_57 = r14_33 + RORD((r15_25 ^ r14_33) + rdi_2 + rdx_61 - 0x21ac7f4, 9);
        int32_t rdx_64 = r14_33 ^ rcx_57;
        int32_t r13_39 = ROLD((rdx_64 ^ rax_60) + result[1] + r13_34 - 0x5b4115bc, 4) + rcx_57;
        int32_t rdx_68 = ROLD((rdx_64 ^ r13_39) + result[4] + rax_60 + 0x4bdecfa9, 0xb) + r13_39;
        int32_t rax_63 = r13_39 ^ rdx_68;
        int32_t r15_36 = ROLD((rax_63 ^ rcx_57) + rbp_1 + r14_33 - 0x944b4a0, 0x10) + rdx_68;
        int32_t rax_67 = RORD((rax_63 ^ r15_36) + result[0xa] + rcx_57 - 0x41404390, 9) + r15_36;
        int32_t rcx_60 = r15_36 ^ rax_67;
        int32_t r14_41 = ROLD((rcx_60 ^ rdx_68) + result[0xd] + r13_39 + 0x289b7ec6, 4) + rax_67;
        int32_t rdx_69 = r14_41 + ROLD((rcx_60 ^ r14_41) + r12_1 + rdx_68 - 0x155ed806, 0xb);
        int32_t rcx_65 = r14_41 ^ rdx_69;
        int32_t r13_47 = ROLD((rcx_65 ^ rax_67) + result[3] + r15_36 - 0x2b10cf7b, 0x10) + rdx_69;
        int32_t rcx_69 = RORD((rcx_65 ^ r13_47) + result[6] + rax_67 + 0x4881d05, 9) + r13_47;
        int32_t rax_70 = r13_47 ^ rcx_69;
        int32_t r14_46 = ROLD((rax_70 ^ rdx_69) + result[9] + r14_41 - 0x262b2fc7, 4) + rcx_69;
        int32_t rdx_70 = r14_46 + ROLD((rax_70 ^ r14_46) + r10_10 + rdx_69 - 0x1924661b, 0xb);
        int32_t rax_75 = r14_46 ^ rdx_70;
        int32_t r13_52 = ROLD((rax_75 ^ rcx_69) + r9_24 + r13_47 + 0x1fa27cf8, 0x10) + rdx_70;
        int32_t rax_79 = RORD((rax_75 ^ r13_52) + result[2] + rcx_69 - 0x3b53a99b, 9) + r13_52;
        int32_t rcx_77 =
            ROLD(((~rdx_70 | rax_79) ^ r13_52) + r12_1 + r14_46 - 0xbd6ddbc, 6) + rax_79;
        int32_t rdx_77 =
            ROLD(((~r13_52 | rcx_77) ^ rax_79) + rbp_1 + rdx_70 + 0x432aff97, 0xa) + rcx_77;
        int32_t rdi_9 =
            ROLD(((~rax_79 | rdx_77) ^ rcx_77) + rdi_2 + r13_52 - 0x546bdc59, 0xf) + rdx_77;
        int32_t rax_86 =
            RORD(((~rcx_77 | rdi_9) ^ rdx_77) + result[5] + rax_79 - 0x36c5fc7, 0xb) + rdi_9;
        int32_t rcx_84 =
            ROLD(((~rdx_77 | rax_86) ^ rdi_9) + r10_10 + rcx_77 + 0x655b59c3, 6) + rax_86;
        int32_t rdx_84 =
            ROLD(((~rdi_9 | rcx_84) ^ rax_86) + result[3] + rdx_77 - 0x70f3336e, 0xa) + rcx_84;
        int32_t r10_21 =
            ROLD(((~rax_86 | rdx_84) ^ rcx_84) + result[0xa] + rdi_9 - 0x100b83, 0xf) + rdx_84;
        int32_t rax_93 =
            RORD(((~rcx_84 | r10_21) ^ rdx_84) + result[1] + rax_86 - 0x7a7ba22f, 0xb) + r10_21;
        int32_t rcx_91 =
            ROLD(((~rdx_84 | rax_93) ^ r10_21) + result[8] + rcx_84 + 0x6fa87e4f, 6) + rax_93;
        int32_t rdx_91 =
            ROLD(((~r10_21 | rcx_91) ^ rax_93) + r9_24 + rdx_84 - 0x1d31920, 0xa) + rcx_91;
        int32_t r9_32 =
            ROLD(((~rax_93 | rdx_91) ^ rcx_91) + result[6] + r10_21 - 0x5cfebcec, 0xf) + rdx_91;
        int32_t r10_26 = result[4] + rcx_91 - 0x8ac817e;
        int32_t rax_100 =
            RORD(((~rcx_91 | r9_32) ^ rdx_91) + result[0xd] + rax_93 + 0x4e0811a1, 0xb) + r9_32;
        result = &result[0x10];
        int32_t rcx_98 = ROLD(((~rdx_91 | rax_100) ^ r9_32) + r10_26, 6) + rax_100;
        var_50 += rcx_98;
        int32_t rdx_98 =
            ROLD(((~r9_32 | rcx_98) ^ rax_100) + result[-5] + rdx_91 - 0x42c50dcb, 0xa) + rcx_98;
        r8 += rdx_98;
        int32_t r9_39 =
            ROLD(((~rax_100 | rdx_98) ^ rcx_98) + result[-0xe] + r9_32 + 0x2ad7d2bb, 0xf) + rdx_98;
        rsi += r9_39;
        rbx = rbx + r9_39
            + RORD(((~rcx_98 | r9_39) ^ rdx_98) + result[-7] + rax_100 - 0x14792c6f, 0xb);
    } while (arg3 + arg2 != result);
    
    uint128_t zmm0 = _mm_unpacklo_epi32(rsi, r8);
    *(arg1 + 8) = _mm_unpacklo_epi64(_mm_unpacklo_epi32(var_50, rbx), zmm0);
    return result;
}

int64_t MD5_Init(int64_t arg1)
{
    __builtin_memcpy(arg1, 
        "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10", 
        0x18);
    return 0x1032547698badcfe;
}

int32_t* MD5_Update(int32_t* arg1, char* arg2, int32_t arg3)
{
    int32_t rax = *arg1;
    uint64_t rbx = arg3;
    char* result_1 = arg2;
    void* rbp = &arg1[6];
    int32_t rdx_1 = (rax + rbx) & 0x1fffffff;
    *arg1 = rdx_1;
    int32_t* result = rax & 0x3f;
    arg1[1] = (rbx >> 0x1d) + arg1[1] + 0;
    int32_t rdx_5 = result;
    
    if (!result)
    {
    label_140002088:
        
        if (rbx > 0x3f)
        {
            int32_t r8_1 = rbx;
            rbx = rbx & 0x3f;
            result = body(arg1, result_1, r8_1 & 0xffffffc0);
            result_1 = result;
        }
        
        if (rbx >= 8)
        {
            *(arg1 + 0x18) = *result_1;
            uint64_t rax_3 = rbx;
            void* rsi_2 = &arg1[8] & 0xfffffffffffffff8;
            *(rbp + rax_3 - 8) = *(result_1 + rax_3 - 8);
            result = rbp - rsi_2;
            int64_t rdi = result_1 - result;
            int32_t rbx_2 = (rbx + result) & 0xfffffff8;
            
            if (rbx_2 >= 8)
            {
                result = nullptr;
                
                do
                {
                    uint64_t rdx_8 = result;
                    result = result + 8;
                    *(rsi_2 + rdx_8) = *(rdi + rdx_8);
                } while (result < (rbx_2 & 0xfffffff8));
            }
        }
        else if (rbx & 4)
        {
            arg1[6] = *result_1;
            result = *(result_1 + rbx - 4);
            *(rbp + rbx - 4) = result;
        }
        else if (rbx)
        {
            result = *result_1;
            arg1[6] = result;
            
            if (rbx & 2)
            {
                result = *(result_1 + rbx - 2);
                *(rbp + rbx - 2) = result;
            }
        }
    }
    else
    {
        int32_t rcx_2 = 0x40 - result;
        result = &result[6] + arg1;
        
        if (rbx >= rcx_2)
        {
            uint64_t r10_1 = rcx_2;
            
            if (rcx_2 >= 8)
            {
                void* r9_2 = &result[2] & 0xfffffffffffffff8;
                *result = *result_1;
                *(result + r10_1 - 8) = *(result_1 + r10_1 - 8);
                void* rax_5 = result - r9_2;
                int32_t rcx_8 = (rcx_2 + rax_5) & 0xfffffff8;
                
                if (rcx_8 >= 8)
                {
                    int32_t i = 0;
                    
                    do
                    {
                        uint64_t i_3 = i;
                        i += 8;
                        *(r9_2 + i_3) = *(result_1 - rax_5 + i_3);
                    } while (i < (rcx_8 & 0xfffffff8));
                }
            }
            else if (rcx_2 & 4)
            {
                *result = *result_1;
                *(result + r10_1 - 4) = *(result_1 + r10_1 - 4);
            }
            else if (rcx_2)
            {
                *result = *result_1;
                
                if (rcx_2 & 2)
                    *(result + r10_1 - 2) = *(result_1 + r10_1 - 2);
            }
            
            rbp = &arg1[6];
            rbx = rdx_5 + rbx - 0x40;
            result_1 = &result_1[r10_1];
            result = body(arg1, rbp, 0x40);
            goto label_140002088;
        }
        
        if (rbx >= 8)
        {
            void* r8_6 = &result[2] & 0xfffffffffffffff8;
            *result = *result_1;
            uint64_t rdx_13 = rbx;
            *(result + rdx_13 - 8) = *(result_1 + rdx_13 - 8);
            void* rax_6 = result - r8_6;
            result = (rax_6 + rbx) & 0xfffffff8;
            
            if (result >= 8)
            {
                result = result & 0xfffffff8;
                int32_t i_1 = 0;
                
                do
                {
                    uint64_t i_2 = i_1;
                    i_1 += 8;
                    *(r8_6 + i_2) = *(result_1 - rax_6 + i_2);
                } while (i_1 < result);
            }
        }
        else if (rbx & 4)
        {
            *result = *result_1;
            *(result + rbx - 4) = *(result_1 + rbx - 4);
        }
        else if (rbx)
        {
            *result = *result_1;
            
            if (rbx & 2)
                *(result + rbx - 2) = *(result_1 + rbx - 2);
        }
    }
    
    return result;
}

int64_t MD5_Final(char* arg1, int32_t* arg2)
{
    int32_t rbp_1 = *arg2 & 0x3f;
    *(arg2 + rbp_1 + 0x18) = 0x80;
    void* rbp_3 = rbp_1 + 0x19 + arg2;
    uint64_t rax_2;
    void* rdi;
    
    if (0x40 - (rbp_1 + 1) <= 7)
    {
        if (0x40 - (rbp_1 + 1))
        {
            int32_t i = 0;
            
            do
            {
                uint64_t i_2 = i;
                i += 1;
                *(rbp_3 + i_2) = 0;
            } while (i < 0x40 - (rbp_1 + 1));
        }
        
        rdi = &arg2[6];
        rbp_3 = rdi;
        body(arg2, rdi, 0x40);
        rax_2 = 0x38;
    }
    else
    {
        rdi = &arg2[6];
        rax_2 = 0x38 - (rbp_1 + 1);
    }
    
    uint64_t rdx_1 = rax_2;
    
    if (rax_2 >= 8)
    {
        *rbp_3 = 0;
        *(rbp_3 + rax_2 - 8) = 0;
        void* rcx_8 = (rbp_3 + 8) & 0xfffffffffffffff8;
        int32_t rdx_6 = (rax_2 + rbp_3 - rcx_8) & 0xfffffff8;
        
        if (rdx_6 >= 8)
        {
            int32_t i_1 = 0;
            
            do
            {
                uint64_t i_3 = i_1;
                i_1 += 8;
                *(rcx_8 + i_3) = 0;
            } while (i_1 < (rdx_6 & 0xfffffff8));
        }
    }
    else if (rax_2 & 4)
    {
        *rbp_3 = 0;
        *(rbp_3 + rdx_1 - 4) = 0;
    }
    else if (rdx_1)
    {
        *rbp_3 = 0;
        
        if (rdx_1 & 2)
            *(rbp_3 + rdx_1 - 2) = 0;
    }
    
    int32_t r8 = arg2[1];
    uint32_t rdx_2 = *arg2 << 3;
    *arg2 = rdx_2;
    uint64_t rax_17 =
        (((r8 >> 0x18 << 8 | r8 >> 0x10) << 8 | *r8[1]) << 8 | r8) << 8 | rdx_2 >> 0x18;
    *(arg2 + 0x50) = ((rax_17 << 8 | rdx_2 >> 0x10) << 8 | *rdx_2[1]) << 8 | rdx_2;
    void* rdi_2 = &arg2[2] & 0xfffffffffffffff8;
    body(arg2, rdi, 0x40);
    *arg1 = arg2[2];
    arg1[1] = *arg2[2][1];
    arg1[2] = *(arg2 + 0xa);
    arg1[3] = *(arg2 + 0xb);
    arg1[4] = arg2[3];
    arg1[5] = *arg2[3][1];
    arg1[6] = *(arg2 + 0xe);
    arg1[7] = *(arg2 + 0xf);
    arg1[8] = arg2[4];
    arg1[9] = *arg2[4][1];
    arg1[0xa] = *(arg2 + 0x12);
    arg1[0xb] = *(arg2 + 0x13);
    arg1[0xc] = arg2[5];
    arg1[0xd] = *arg2[5][1];
    arg1[0xe] = *(arg2 + 0x16);
    arg1[0xf] = *(arg2 + 0x17);
    *arg2 = 0;
    *(arg2 + 0x90) = 0;
    __builtin_memset(rdi_2, 0, (arg2 - rdi_2 + 0x98) >> 3 << 3);
    return 0;
}

int64_t Discombobulate(int64_t arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5)
{
    int128_t var_118;
    __builtin_memcpy(&var_118, 
        "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x"
    "17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f", 
        0x20);
    int64_t i = 0;
    int64_t r10 = arg2;
    char var_218[0x100];
    char (* rbx)[0x100] = &var_218;
    int128_t var_f8;
    __builtin_strncpy(&var_f8, 
        " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\"
    "]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7f", 
        0x60);
    int128_t var_98;
    __builtin_memcpy(&var_98, 
        "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95\x96\x"
    "97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae"
    "af\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1\xc2\xc3\xc4\xc5\xc6"
    "c7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde"
    "df\xe0\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6"
    "f7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff", 
        0x80);
    
    do
    {
        var_218[i] = arg3[i % arg4];
        i += 1;
    } while (i != 0x100);
    
    int128_t* i_1 = &var_118;
    uint32_t result_1 = 0;
    int64_t __saved_rbx;
    int64_t result;
    
    do
    {
        uint32_t rax_4 = *i_1;
        i_1 += 1;
        rbx = &(*rbx)[1];
        uint32_t rax_6 = rax_4 + result_1 + (*rbx)[-1];
        uint32_t r8_2 = rax_6 >> 0x1f >> 0x18;
        result_1 = rax_6 + r8_2 - r8_2;
        result = result_1;
        char r8_3 = *(&var_118 + result);
        *(&var_118 + result) = rax_4;
        *(i_1 - 1) = r8_3;
    } while (&__saved_rbx != i_1);
    
    if (r10 > 0)
    {
        int64_t rcx = 0;
        result = 0;
        uint32_t rbx_1 = 0;
        
        do
        {
            int32_t temp8_1;
            char temp9_1;
            temp8_1 = HIGHD(result + 1);
            temp9_1 = LOWD(result + 1);
            uint32_t rdx_6 = temp8_1 >> 0x18;
            result = temp9_1 + rdx_6 - rdx_6;
            int64_t rsi_2 = result;
            uint32_t rdx_7 = *(&var_118 + rsi_2);
            uint32_t rdx_8 = rdx_7 + rbx_1;
            uint32_t r8_6 = rdx_8 >> 0x1f >> 0x18;
            rbx_1 = rdx_8 + r8_6 - r8_6;
            int64_t r8_7 = rbx_1;
            char rdx_11 = *(&var_118 + r8_7);
            *(&var_118 + r8_7) = rdx_7;
            *(&var_118 + rsi_2) = rdx_11;
            arg5[rcx] = *(&var_118 + rdx_11 + *(&var_118 + r8_7)) ^ *(arg1 + rcx);
            rcx += 1;
        } while (r10 != rcx);
    }
    
    arg5[r10 + 1] = 0;
    return result;
}

void __do_global_dtors()
{
    void (* i)() = **&p;
    
    while (i)
    {
        i();
        void (** p_1)() = p;
        i = p_1[1];
        p = &p_1[1];
    }
}

int64_t __do_global_ctors()
{
    int32_t rax_4 = 0;
    int32_t rcx;
    uint64_t r8_2;
    
    do
    {
        r8_2 = rax_4 + 1;
        rcx = rax_4;
        rax_4 = r8_2;
    } while (*(&__CTOR_LIST__ + (r8_2 << 3)));
    
    if (rcx)
    {
        uint64_t rax_1 = rcx;
        void* i = &__CTOR_LIST__ + (rax_1 << 3);
        
        do
        {
            (*i)();
            i -= 8;
        } while (i != ((rax_1 - (rcx - 1)) << 3) + 0x14000fc58);
    }
    
    /* tailcall */
    return atexit(__do_global_dtors);
}

int __main()
{
    int initialized_1 = initialized;
    
    if (initialized_1)
        return initialized_1;
    
    initialized = 1;
    /* tailcall */
    return __do_global_ctors();
}

int _setargv() __pure
{
    return 0;
}

int __dyn_tls_dtor(void* hDllHandle, long unsigned int dwReason, void* lpreserved)
{
    if (dwReason != 3 && dwReason)
        return 1;
    
    __mingw_TLScallback(hDllHandle, dwReason, lpreserved);
    return 1;
}

int __dyn_tls_init(void* hDllHandle, long unsigned int dwReason, void* lpreserved)
{
    if (_CRT_MT != 2)
        _CRT_MT = 2;
    
    if (dwReason != 2 && dwReason == 1)
        __mingw_TLScallback(hDllHandle, dwReason, lpreserved);
    
    return 1;
}

int __tlregdtor(void (* func)()) __pure
{
    return 0;
}

int _matherr(struct _exception* pexcept)
{
    void* const rbx;
    
    if (pexcept->type > 6)
        rbx = "Unknown error";
    else
        switch (pexcept->type)
        {
            case 0:
            {
                rbx = "Unknown error";
                break;
            }
            case 1:
            {
                rbx = "Argument domain error (DOMAIN)";
                break;
            }
            case 2:
            {
                rbx = "Argument singularity (SIGN)";
                break;
            }
            case 3:
            {
                rbx = "Overflow range error (OVERFLOW)";
                break;
            }
            case 4:
            {
                rbx = "The result is too small to be represented (UNDERFLOW)";
                break;
            }
            case 5:
            {
                rbx = "Total loss of significance (TLOSS)";
                break;
            }
            case 6:
            {
                rbx = "Partial loss of significance (PLOSS)";
                break;
            }
        }
    
    fprintf(__acrt_iob_func(2), "_matherr(): %s in %s(%g, %g)  (retval=%g)\n", rbx, pexcept->name, 
        pexcept->arg1, pexcept->arg2, pexcept->retval);
    return 0;
}

void _fpreset() __pure
{
    return;
}

void __report_error(char const* msg, ...) __noreturn
{
    int64_t entry__ArgList;
    int64_t _ArgList = entry__ArgList;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    fwrite("Mingw-w64 runtime failure:\n", 1, 0x1b, __acrt_iob_func(2));
    vfprintf(__acrt_iob_func(2), msg, &_ArgList);
    abort();
    /* no return */
}

unsigned char** mark_section_writable(void* addr)
{
    int64_t maxSections_1 = maxSections;
    unsigned char** Protect;
    
    if (maxSections_1 <= 0)
        maxSections_1 = 0;
    else
    {
        int32_t i = 0;
        Protect = &the_secs->sec_start;
        
        do
        {
            unsigned char* sec_start = ADJ(Protect)->sec_start;
            
            if (addr >= sec_start && addr < &sec_start[*(ADJ(Protect)->hash->Misc + 0)])
                return Protect;
            
            i += 1;
            Protect = &Protect[5];
        } while (i != maxSections_1);
    }
    
    struct Section_Header* rax_2 = __mingw_GetSectionForAddress(addr);
    
    if (!rax_2)
    {
        __report_error("Address %p has no image-section", addr);
        /* no return */
    }
    
    void* rax_4 = &the_secs[maxSections_1];
    *(rax_4 + 0x20) = rax_2;
    *rax_4 = 0;
    void* lpAddress = &_GetPEImageBase()->e_magic[rax_2->virtualAddress];
    the_secs[maxSections_1].sec_start = lpAddress;
    MEMORY_BASIC_INFORMATION b;
    
    if (!VirtualQuery(lpAddress, &b, 0x30))
    {
        __report_error("  VirtualQuery failed for %d bytes at address %p", rax_2->virtualSize, 
            the_secs[maxSections_1].sec_start);
        /* no return */
    }
    
    Protect = b.Protect;
    
    if ((Protect - 4) & 0xfffffffb && &Protect[-8] & 0xffffffbf)
    {
        void* BaseAddress = b.BaseAddress;
        uint64_t RegionSize = b.RegionSize;
        enum PAGE_PROTECTION_FLAGS flNewProtect = PAGE_EXECUTE_READWRITE;
        
        if (Protect == 2)
            flNewProtect = PAGE_READWRITE;
        
        void* lpflOldProtect = &the_secs[maxSections_1];
        *(lpflOldProtect + 8) = BaseAddress;
        *(lpflOldProtect + 0x10) = RegionSize;
        Protect = VirtualProtect(BaseAddress, RegionSize, flNewProtect, lpflOldProtect);
        
        if (!Protect)
        {
            __report_error("  VirtualProtect failed with code 0x%x", GetLastError());
            /* no return */
        }
    }
    
    maxSections += 1;
    return Protect;
}

void _pei386_runtime_relocator()
{
    if (was_init)
        return;
    
    was_init = 1;
    void* rax_5 = (__mingw_GetSectionCount() * 0x28 + 0xf) & 0xfffffffffffffff0;
    ___chkstk_ms(rax_5);
    maxSections = 0;
    void var_88;
    the_secs = &var_88 - rax_5 + 0x30;
}

int (*)() __mingw_raise_matherr(int typ, char const* name, double a1, double a2, double rslt)
{
    int (* stUserMathErr_1)() = stUserMathErr;
    double temp0 = _mm_unpacklo_pd(a1, a2);
    
    if (!stUserMathErr_1)
        return stUserMathErr_1;
    
    struct _exception ex;
    ex.type = typ;
    ex.name = name;
    ex.arg1 = temp0;
    ex.arg2 = temp0;
    ex.retval = rslt;
    return stUserMathErr_1(&ex);
}

int64_t __mingw_setusermatherr(int (* f)())
{
    stUserMathErr = f;
    /* tailcall */
    return __setusermatherr(f);
}

long int _gnu_exception_handler(struct _EXCEPTION_POINTERS* exception_data)
{
    EXCEPTION_RECORD* ExceptionRecord = exception_data->ExceptionRecord;
    uint32_t ExceptionCode = ExceptionRecord->ExceptionCode;
    
    if ((ExceptionCode & 0x20ffffff) == 0x20474343 && !(ExceptionRecord->ExceptionFlags & 1))
        return -1;
    
    if (ExceptionCode <= 0xc0000096)
    {
        if (ExceptionCode > 0xc000008b)
        {
            uint64_t rax = ExceptionCode + 0x3fffff73;
            
            if (rax > 9)
                return -1;
            
            _crt_signal_t rax_3;
            
            switch (rax)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                {
                    rax_3 = signal(8, nullptr);
                    
                    if (rax_3 == 1)
                    {
                        signal(8, 1);
                        return -1;
                    }
                    
                label_140002f9e:
                    
                    if (rax_3)
                    {
                        rax_3(8);
                        return -1;
                    }
                    break;
                }
                case 5:
                case 8:
                {
                    return -1;
                    break;
                }
                case 7:
                {
                    rax_3 = signal(8, nullptr);
                    
                    if (rax_3 != 1)
                        goto label_140002f9e;
                    
                    signal(8, 1);
                    return -1;
                    break;
                }
                case 9:
                {
                label_140002fe2:
                    _crt_signal_t rax_5 = signal(4, nullptr);
                    
                    if (rax_5 == 1)
                    {
                        signal(4, 1);
                        return -1;
                    }
                    
                    if (rax_5)
                    {
                        rax_5(4);
                        return -1;
                    }
                    break;
                }
            }
        }
        else if (ExceptionCode == 0xc0000005)
        {
            _crt_signal_t rax_7 = signal(0xb, nullptr);
            
            if (rax_7 == 1)
            {
                signal(0xb, 1);
                return -1;
            }
            
            if (rax_7)
            {
                rax_7(0xb);
                return -1;
            }
        }
        else
        {
            if (ExceptionCode == 0xc0000008)
                return -1;
            
            if (ExceptionCode == 0xc000001d)
                goto label_140002fe2;
            
            if (ExceptionCode == 0x80000002)
                return -1;
        }
    }
    
    long int (* __mingw_oldexcpt_handler_1)() = __mingw_oldexcpt_handler;
    
    if (!__mingw_oldexcpt_handler_1)
        return 0;
    
    /* tailcall */
    return __mingw_oldexcpt_handler_1();
}

int64_t __mingwthr_run_key_dtors()
{
    EnterCriticalSection(&__mingwthr_cs);
    
    for (struct __mingwthr_key* i = key_dtor_list; i; i = i->next)
    {
        int64_t rax_1 = TlsGetValue(i->key);
        
        if (rax_1 && !GetLastError())
            i->dtor(rax_1);
    }
    
    /* tailcall */
    return LeaveCriticalSection(&__mingwthr_cs);
}

int ___w64_mingwthr_add_key_dtor(long unsigned int key, void (* dtor)())
{
    if (__mingwthr_cs_init)
    {
        long unsigned int* rax_2 = calloc(1, 0x18);
        
        if (!rax_2)
            return -1;
        
        *(rax_2 + 8) = dtor;
        *rax_2 = key;
        EnterCriticalSection(&__mingwthr_cs);
        struct __mingwthr_key* key_dtor_list_1 = key_dtor_list;
        key_dtor_list = rax_2;
        *(rax_2 + 0x10) = key_dtor_list_1;
        LeaveCriticalSection(&__mingwthr_cs);
    }
    
    return 0;
}

int ___w64_mingwthr_remove_key_dtor(long unsigned int key)
{
    if (!__mingwthr_cs_init)
        return 0;
    
    EnterCriticalSection(&__mingwthr_cs);
    struct __mingwthr_key* key_dtor_list_1 = key_dtor_list;
    
    if (key_dtor_list_1)
    {
        struct __mingwthr_key* key_dtor_list_2 = nullptr;
        
        while (true)
        {
            struct __mingwthr_key* next = key_dtor_list_1->next;
            
            if (key_dtor_list_1->key == key)
            {
                if (!key_dtor_list_2)
                    key_dtor_list = next;
                else
                    key_dtor_list_2->next = next;
                
                free(key_dtor_list_1);
                break;
            }
            
            key_dtor_list_2 = key_dtor_list_1;
            
            if (!next)
                break;
            
            key_dtor_list_1 = next;
        }
    }
    
    LeaveCriticalSection(&__mingwthr_cs);
    return 0;
}

int __mingw_TLScallback(void* hDllHandle, long unsigned int reason, void* reserved)
{
    if (reason == 2)
        return 1;
    
    if (reason > 2)
    {
        if (reason == 3 && __mingwthr_cs_init)
            __mingwthr_run_key_dtors();
    }
    else if (!reason)
    {
        if (__mingwthr_cs_init)
            __mingwthr_run_key_dtors();
        
        if (__mingwthr_cs_init == 1)
        {
            struct __mingwthr_key* i = key_dtor_list;
            
            while (i)
            {
                struct __mingwthr_key* i_1 = i;
                i = i->next;
                free(i_1);
            }
            
            key_dtor_list = nullptr;
            __mingwthr_cs_init = 0;
            DeleteCriticalSection(&__mingwthr_cs);
        }
    }
    else
    {
        if (!__mingwthr_cs_init)
            InitializeCriticalSection(&__mingwthr_cs);
        
        __mingwthr_cs_init = 1;
    }
    
    return 1;
}

int _ValidateImageBase(unsigned char* pImageBase)
{
    if (*pImageBase == 0x5a4d)
    {
        void* rcx = &pImageBase[*(pImageBase + 0x3c)];
        
        if (*rcx == 0x4550)
        {
            int32_t result;
            result = *(rcx + 0x18) == 0x20b;
            return result;
        }
    }
    
    return 0;
}

void* _FindPESection(unsigned char* pImageBase, long long unsigned int rva)
{
    void* rcx = &pImageBase[*(pImageBase + 0x3c)];
    uint32_t r8 = *(rcx + 6);
    void* result = rcx + *(rcx + 0x14) + 0x18;
    
    if (r8)
    {
        void* r9_1 = result + (r8 - 1) * 0x28 + 0x28;
        
        do
        {
            uint64_t r8_1 = *(result + 0xc);
            
            if (rva >= r8_1 && rva < r8_1 + *(result + 8))
                return result;
            
            result += 0x28;
        } while (result != r9_1);
    }
    
    return nullptr;
}

struct Section_Header* const _FindPESectionByName(char const* pName)
{
    if (strlen(pName) <= 8)
    {
        for (struct Section_Header* const _Str1 = &__section_headers; _Str1 != 0x140000480; 
            _Str1 = &_Str1[1])
        {
            if (!strncmp(_Str1, pName, 8))
                return _Str1;
        }
    }
    
    return 0;
}

struct Section_Header* const __mingw_GetSectionForAddress(void* p)
{
    for (struct Section_Header* const i = &__section_headers; i != 0x140000480; i = &i[1])
    {
        uint64_t virtualAddress = i->virtualAddress;
        
        if (p - &__dos_header >= virtualAddress
                && p - &__dos_header < virtualAddress + i->virtualSize)
            return i;
    }
    
    return 0;
}

int __mingw_GetSectionCount() __pure
{
    return 0x13;
}

struct Section_Header* const _FindPESectionExec(long long unsigned int eNo)
{
    struct Section_Header* const i = &__section_headers;
    
    do
    {
        if (*i->characteristics[3] & 0x20)
        {
            if (!eNo)
                return i;
            
            eNo -= 1;
        }
        
        i = &i[1];
    } while (0x140000480 != i);
    
    return 0;
}

struct DOS_Header* const _GetPEImageBase() __pure
{
    return &__dos_header;
}

uint32_t _IsNonwritableInCurrentImage(unsigned char* pTarget)
{
    for (struct Section_Header* const i = &__section_headers; i != 0x140000480; i = &i[1])
    {
        uint64_t virtualAddress = i->virtualAddress;
        
        if (pTarget - &__dos_header >= virtualAddress
                && pTarget - &__dos_header < virtualAddress + i->virtualSize)
            return ~i->characteristics >> 0x1f;
    }
    
    return 0;
}

void* __mingw_enum_import_library_names(int i)
{
    int i_2 = i;
    struct Section_Header* const i_1 = &__section_headers;
    
    do
    {
        uint64_t virtualAddress = i_1->virtualAddress;
        
        if (0x16000 >= virtualAddress && 0x16000 < virtualAddress + i_1->virtualSize)
        {
            void* rax_3 = &_.idata$2;
            
            while (*(rax_3 + 4) || *(rax_3 + 0xc))
            {
                if (i_2 <= 0)
                    return &__dos_header.e_magic[*(rax_3 + 0xc)];
                
                i_2 -= 1;
                rax_3 += 0x14;
            }
            
            break;
        }
        
        i_1 = &i_1[1];
    } while (0x140000480 != i_1);
    
    return 0;
}

int64_t ___chkstk_ms(int64_t arg1 @ rax)
{
    int64_t result = arg1;
    void arg_8;
    void* rcx = &arg_8;
    
    if (arg1 >= 0x1000)
    {
        do
        {
            rcx -= 0x1000;
            *rcx = *rcx;
            arg1 -= 0x1000;
        } while (arg1 > 0x1000);
    }
    
    void* rcx_1 = rcx - arg1;
    *rcx_1 = *rcx_1;
    return result;
}

int32_t __mingw_vfprintf(struct _iobuf* stream, char const* fmt, char* argv)
{
    _lock_file(stream);
    int32_t result = __mingw_pformat(0x6000, stream, 0, fmt, argv);
    _unlock_file(stream);
    return result;
}

void optimize_alloc(char** p, char* end, long long unsigned int alloc_sz)
{
    if (!p)
        return;
    
    char* rcx = *p;
    
    if (!rcx)
        return;
    
    uint64_t _Size = end - rcx;
    
    if (_Size == alloc_sz)
        return;
    
    char* rax = realloc(rcx, _Size);
    
    if (rax)
        *p = rax;
}

int64_t release_ptrs(struct gcollect** pt, char** wbuf)
{
    int64_t result = free(*wbuf);
    struct gcollect* next_1 = *pt;
    *wbuf = nullptr;
    
    if (next_1)
    {
        while (true)
        {
            int64_t i = 0;
            
            if (next_1->count)
            {
                do
                {
                    free(*next_1->ptrs[i]);
                    int64_t* rax_1 = next_1->ptrs[i];
                    i += 1;
                    *rax_1 = 0;
                } while (i < next_1->count);
            }
            
            struct gcollect* next = next_1->next;
            result = free(next_1);
            
            if (!next)
                break;
            
            next_1 = next;
        }
        
        *pt = nullptr;
    }
    
    return result;
}

char* resize_wbuf(long long unsigned int wpsz, long long unsigned int* wbuf_max_sz, char* old)
{
    long long unsigned int rbx = *wbuf_max_sz;
    char* result = old;
    
    if (rbx == wpsz)
    {
        uint64_t _Size = rbx * 2;
        
        if (_Size < 0x100)
            _Size = 0x100;
        
        if (!old)
        {
            result = malloc(_Size);
            
            if (!result)
                return nullptr;
        }
        else
        {
            result = realloc(old, _Size);
            
            if (!result)
            {
                free(old);
                return nullptr;
            }
        }
        
        *wbuf_max_sz = _Size;
    }
    
    return result;
}

int cleanup_return(int rval, struct gcollect** pfree, char** strp, char** wbuf)
{
    if (rval == 0xffffffff)
    {
        release_ptrs(pfree, wbuf);
        return rval;
    }
    
    struct gcollect* next = *pfree;
    
    while (next)
    {
        struct gcollect* next_1 = next;
        next = next->next;
        free(next_1);
    }
    
    *pfree = nullptr;
    
    if (strp)
    {
        free(*strp);
        *strp = nullptr;
    }
    
    free(*wbuf);
    *wbuf = nullptr;
    return rval;
}

int32_t in_ch(struct _IFP* s, long long unsigned int* rin)
{
    int back_top = s->back_top;
    
    if (back_top)
    {
        s->back_top = back_top - 1;
        int32_t rax_2 = s->bch[back_top - 1];
        *rin += 1;
        return rax_2;
    }
    
    if (!(s->seen_eof & 1))
    {
        char* fp = *(s-> + 0);
        
        if (!(s->is_string & 1))
        {
            int32_t rax_4 = getc(fp);
            
            if (rax_4 != 0xffffffff)
            {
                *rin += 1;
                return rax_4;
            }
        }
        else
        {
            uint32_t rax_3 = *fp;
            
            if (rax_3)
            {
                *rin += 1;
                *(s-> + 0) = &fp[1];
                return rax_3;
            }
        }
        
        s->seen_eof |= 1;
    }
    
    return -1;
}

void back_ch(int c, struct _IFP* s, long long unsigned int* rin, int not_eof)
{
    if (!(not_eof & 1) && c == 0xffffffff)
        return;
    
    if (!(s->is_string & 1))
    {
        ungetc(c, *(s-> + 0));
        *rin -= 1;
        return;
    }
    
    *rin -= 1;
    int64_t back_top = s->back_top;
    s->bch[back_top] = c;
    s->back_top = back_top + 1;
}

int __mingw_sformat(struct _IFP* s, char const* format, char* argp)
{
    char const* format_1 = format;
    format = !format;
    bool cond:1 = !*(s-> + 0) | format;
    struct gcollect* gcollect = nullptr;
    long long unsigned int read_in = 0;
    long long unsigned int wbuf_max_sz = 0;
    char* wbuf = nullptr;
    
    if (cond:1)
    {
        *_errno() = 0x16;
        return 0xffffffff;
    }
    
    struct _Mbstatet state;
    __builtin_memset(&state, 0, 8);
    char* decimal_point = localeconv()->decimal_point;
    char* thousands_sep = localeconv()->thousands_sep;
    
    if (thousands_sep && !*thousands_sep)
        thousands_sep = nullptr;
    
    char const rax_4 = *format_1;
    int rval;
    char* wbuf_19;
    
    if (!rax_4)
    {
        rval = 0;
        wbuf_19 = nullptr;
    label_140003dc4:
        free(wbuf_19);
    }
    else
    {
        int32_t _Radix = 0;
        int32_t i_4 = 0;
        int32_t r15_1 = 0;
        rval = 0;
        char* argp_1 = argp;
        int64_t* strp_1 = nullptr;
        char* var_d8_1;
        __builtin_memset(&var_d8_1, 0, 0x18);
        long long unsigned int* rin_3 = &read_in;
        char const* format_2 = format_1;
        
        while (true)
        {
            int32_t rax_16;
            
            if (rax_4 < 0)
                rax_16 = mbrlen(format_2, strlen(format_2), &state);
            
            if (rax_4 < 0 && rax_16 > 0)
            {
                while (true)
                {
                    int32_t i_8 = in_ch(s, &read_in);
                    i_4 = i_8;
                    
                    if (i_8 != 0xffffffff)
                    {
                        uint32_t rax_18 = *format_2;
                        format_2 = &format_2[1];
                        
                        if (i_4 == rax_18)
                        {
                            if (format_2 == &format_2[rax_16 - 1 + 1])
                                break;
                            
                            continue;
                        }
                    }
                    
                    long long unsigned int read_in_5 = read_in - 1;
                    
                    if (!(s->is_string & 1))
                    {
                        ungetc(i_4, *(s-> + 0));
                        read_in = read_in_5;
                    }
                    else
                    {
                        int64_t back_top_4 = s->back_top;
                        read_in = read_in_5;
                        s->bch[back_top_4] = i_4;
                        s->back_top = back_top_4 + 1;
                    }
                    
                    if (rval + 1 <= 1)
                        goto label_140004230;
                    
                    struct gcollect* next_7 = gcollect;
                    
                    while (next_7)
                    {
                        struct gcollect* next_23 = next_7;
                        next_7 = next_7->next;
                        free(next_23);
                    }
                    
                    goto label_140003cbe;
                }
                
                goto label_140003d09;
            }
            
            uint32_t _C_9 = *format_2;
            void* wpsz_12 = &format_2[1];
            
            if (_C_9 == 0x25)
            {
                uint32_t rdx_4 = format_2[1];
                uint64_t r11_1 = 0;
                char rax_19 = rdx_4;
                
                if (rdx_4 - 0x30 <= 9)
                {
                    char* rcx_23 = &format_2[2];
                    r11_1 = rax_19 - 0x30;
                    uint32_t rdx_19 = format_2[2];
                    char r8_5 = rdx_19;
                    uint32_t rdx_20;
                    
                    for (int32_t i = rdx_19 - 0x30; i <= 9; i = rdx_20 - 0x30)
                    {
                        rcx_23 = &rcx_23[1];
                        r11_1 = i + ((r11_1 * 5) << 1);
                        rdx_20 = *rcx_23;
                        r8_5 = rdx_20;
                    }
                    
                    if (r8_5 == 0x24)
                    {
                        rax_19 = rcx_23[1];
                        wpsz_12 = &rcx_23[1];
                    }
                    else
                        r11_1 = 0;
                }
                
                int32_t rbx_3 = 0;
                
                while (true)
                {
                    if (rax_19 == 0x2a)
                    {
                        rax_19 = *(wpsz_12 + 1);
                        rbx_3 |= 0x80;
                    }
                    else if (rax_19 != 0x27)
                    {
                        if (rax_19 != 0x49)
                            break;
                        
                        rax_19 = *(wpsz_12 + 1);
                        
                        if (rax_19 == 0x36)
                        {
                            if (*(wpsz_12 + 2) != 0x34)
                            {
                            label_140003eae:
                                rbx_3 |= 0xc;
                                wpsz_12 += 1;
                                break;
                            }
                            
                            rax_19 = *(wpsz_12 + 3);
                            rbx_3 |= 0xc;
                            wpsz_12 += 2;
                        }
                        else if (rax_19 != 0x33)
                            rbx_3 |= 0xc;
                        else
                        {
                            if (*(wpsz_12 + 2) != 0x32)
                                goto label_140003eae;
                            
                            rax_19 = *(wpsz_12 + 3);
                            rbx_3 |= 4;
                            wpsz_12 += 2;
                        }
                    }
                    else
                    {
                        rax_19 = *(wpsz_12 + 1);
                        int32_t rdx_6;
                        *rdx_6[1] = *rbx_3[1] | 1;
                        
                        if (thousands_sep)
                            rbx_3 = rdx_6;
                    }
                    
                    wpsz_12 += 1;
                }
                
                uint64_t r12_1 = 0;
                
                if (rax_19 - 0x30 > 9)
                    r12_1 = 0xffffffff;
                else
                {
                    uint32_t rdx_10;
                    
                    do
                    {
                        wpsz_12 += 1;
                        r12_1 = rax_19 - 0x30 + ((r12_1 * 5) << 1);
                        rdx_10 = *wpsz_12;
                        rax_19 = rdx_10;
                    } while (rdx_10 - 0x30 <= 9);
                    
                    if (!r12_1)
                        r12_1 = 0xffffffff;
                }
                
                if (!rax_19)
                {
                    if (rval != 0xffffffff)
                    {
                        struct gcollect* next_8 = gcollect;
                        
                        while (next_8)
                        {
                            struct gcollect* next_24 = next_8;
                            next_8 = next_8->next;
                            free(next_24);
                        }
                        
                    label_140003cbe:
                        gcollect = nullptr;
                        
                        if (strp_1)
                        {
                            free(*strp_1);
                            *strp_1 = 0;
                        }
                        
                    label_140003cdf:
                        free(wbuf);
                        break;
                        break;
                    }
                }
                else
                {
                    void* wpsz_9;
                    uint32_t r8_1;
                    
                    if (rax_19 - 0x4c > 0x2e)
                    {
                    label_140003f70:
                        wpsz_9 = wpsz_12;
                        r8_1 = *wpsz_12;
                    label_140003f80:
                        
                        if (r8_1)
                            goto label_140003f8d;
                        
                        if (rval != 0xffffffff)
                        {
                            struct gcollect* next_11 = gcollect;
                            
                            while (next_11)
                            {
                                struct gcollect* next_27 = next_11;
                                next_11 = next_11->next;
                                free(next_27);
                            }
                            
                            goto label_140003cbe;
                        }
                    }
                    else
                        switch (rax_19)
                        {
                            case 0x4c:
                            case 0x71:
                            case 0x7a:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                rbx_3 |= 0xc;
                                wpsz_9 = wpsz_12 + 1;
                                goto label_140003f80;
                            }
                            case 0x4d:
                            case 0x4e:
                            case 0x4f:
                            case 0x50:
                            case 0x51:
                            case 0x52:
                            case 0x53:
                            case 0x54:
                            case 0x55:
                            case 0x56:
                            case 0x57:
                            case 0x58:
                            case 0x59:
                            case 0x5a:
                            case 0x5b:
                            case 0x5c:
                            case 0x5d:
                            case 0x5e:
                            case 0x5f:
                            case 0x60:
                            case 0x62:
                            case 0x63:
                            case 0x64:
                            case 0x65:
                            case 0x66:
                            case 0x67:
                            case 0x69:
                            case 0x6b:
                            case 0x6e:
                            case 0x6f:
                            case 0x70:
                            case 0x72:
                            case 0x73:
                            case 0x75:
                            case 0x76:
                            case 0x77:
                            case 0x78:
                            case 0x79:
                            {
                                goto label_140003f70;
                            }
                            case 0x61:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                
                                if ((r8_1 & 0xf7) != 0x53 && r8_1 != 0x73)
                                    goto label_140003f70;
                                
                                *rbx_3[1] |= 2;
                                wpsz_9 = wpsz_12 + 1;
                            label_140003f8d:
                                format_2 = wpsz_9 + 1;
                                uint64_t rax_27;
                                
                                if (!r15_1)
                                    rax_27 = r8_1 - 0x43;
                                
                                bool var_100;
                                int32_t _Size_19;
                                
                                if (r15_1 || rax_27 > 0x2b || TEST_BITQ(-0x80101000002, rax_27))
                                {
                                    var_100 = r8_1;
                                    _Size_19 = r11_1;
                                    int32_t rdi_2 = *_errno();
                                    *_errno() = 0;
                                    long long unsigned int* var_e8_1;
                                    int32_t _Size_24;
                                    bool r15_4;
                                    
                                    if (i_4 != 0xffffffff)
                                    {
                                        int32_t _C_1;
                                        int32_t i_1;
                                        
                                        do
                                        {
                                            _C_1 = in_ch(s, &read_in);
                                            
                                            if (_C_1 == 0xffffffff)
                                            {
                                                _Size_24 = _Size_19;
                                                r15_4 = var_100;
                                                goto label_14000431a;
                                            }
                                            
                                            i_1 = isspace(_C_1);
                                        } while (i_1);
                                        var_e8_1 = _Size_19;
                                        i_4 = _C_1;
                                        _Size_19 = var_100;
                                        r11_1 = var_e8_1;
                                        r8_1 = _Size_19;
                                        *_errno() = rdi_2;
                                        long long unsigned int read_in_9 = read_in - 1;
                                        
                                        if (!(s->is_string & 1))
                                        {
                                            _Size_19 = r8_1;
                                            var_e8_1 = r11_1;
                                            ungetc(i_4, *(s-> + 0));
                                            read_in = read_in_9;
                                            r11_1 = var_e8_1;
                                            r8_1 = _Size_19;
                                        }
                                        else
                                        {
                                            int64_t back_top_2 = s->back_top;
                                            read_in = read_in_9;
                                            s->bch[back_top_2] = i_4;
                                            s->back_top = back_top_2 + 1;
                                        }
                                        
                                    label_14000406c:
                                        
                                        if (r8_1 == 0x63)
                                            goto label_1400043a8;
                                        
                                        if (r8_1 == 0x73)
                                        {
                                            if (rbx_3 & 4)
                                                goto label_140004cc3;
                                            
                                            goto label_14000408c;
                                        }
                                        
                                        if (r8_1 > 0x67)
                                            goto label_140005194;
                                        
                                        if (r8_1 > 0x24 && r8_1 - 0x25 <= 0x42)
                                            goto label_140004384;
                                        
                                        goto label_1400047f3;
                                    }
                                    
                                    _Size_24 = _Size_19;
                                    r15_4 = var_100;
                                label_14000431a:
                                    
                                    while (*_errno() != 4)
                                    {
                                        if (!isspace(0xffffffff))
                                        {
                                            var_e8_1 = _Size_24;
                                            i_4 = -1;
                                            _Size_19 = r15_4;
                                            r11_1 = var_e8_1;
                                            r8_1 = _Size_19;
                                            *_errno() = rdi_2;
                                            goto label_14000406c;
                                        }
                                    }
                                    
                                    if (rval + 1 > 1)
                                    {
                                        struct gcollect* next_3 = gcollect;
                                        
                                        while (next_3)
                                        {
                                            struct gcollect* next_19 = next_3;
                                            next_3 = next_3->next;
                                            free(next_19);
                                        }
                                        
                                        goto label_140003cbe;
                                    }
                                }
                                else
                                {
                                    char* wbuf_max_sz_1;
                                    uint64_t _Size_8;
                                    char* pwc_2;
                                    char buf[0x5];
                                    struct _Mbstatet cstate;
                                    char** strp;
                                    
                                    if (r8_1 == 0x63)
                                    {
                                    label_1400043a8:
                                        
                                        if (!(rbx_3 & 4))
                                        {
                                        label_1400043bd:
                                            
                                            if (r12_1 == 0xffffffff)
                                                r12_1 = 1;
                                            
                                            int32_t r15_6 = rbx_3 & 0x80;
                                            
                                            if (r15_6)
                                            {
                                                int32_t i_2 = in_ch(s, &read_in);
                                                
                                                if (i_2 == 0xffffffff)
                                                {
                                                label_140006b23:
                                                    
                                                    if (rval)
                                                        return cleanup_return(rval, &gcollect, 
                                                            strp_1, &wbuf);
                                                    
                                                    return cleanup_return(0xffffffff, &gcollect, 
                                                        strp_1, &wbuf);
                                                }
                                                
                                                do
                                                {
                                                    r12_1 = r12_1 - 1;
                                                    
                                                    if (r12_1 <= 0)
                                                        break;
                                                    
                                                    i_2 = in_ch(s, &read_in);
                                                } while (i_2 != 0xffffffff);
                                                
                                                i_4 = i_2;
                                                goto label_140004acc;
                                            }
                                            
                                            char* r8_8;
                                            
                                            if (!(*rbx_3[1] & 6))
                                            {
                                                if (r11_1)
                                                {
                                                    char** argp_9 = argp;
                                                    
                                                    if (r11_1 != 1)
                                                        argp_9 = &argp[(r11_1 - 1) << 3];
                                                    
                                                    r8_8 = *argp_9;
                                                }
                                                else
                                                {
                                                    char** argp_29 = argp_1;
                                                    r8_8 = *argp_29;
                                                    argp_1 = &argp_29[1];
                                                }
                                                
                                                if (!r8_8)
                                                    return cleanup_return(rval, &gcollect, strp_1, 
                                                        &wbuf);
                                            }
                                            else
                                            {
                                                if (r11_1)
                                                {
                                                    int64_t** argp_10 = argp;
                                                    
                                                    if (r11_1 != 1)
                                                        argp_10 = &argp[(r11_1 - 1) << 3];
                                                    
                                                    strp_1 = *argp_10;
                                                }
                                                else
                                                {
                                                    int64_t* strp_5 = *argp_1;
                                                    argp_1 = &argp_1[8];
                                                    strp_1 = strp_5;
                                                }
                                                
                                                if (!strp_1)
                                                    return cleanup_return(rval, &gcollect, nullptr, 
                                                        &wbuf);
                                                
                                                int32_t _Size_9 = 0x400;
                                                
                                                if (r12_1 <= 0x400)
                                                    _Size_9 = r12_1;
                                                
                                                uint64_t _Size = _Size_9;
                                                _Size_8 = _Size;
                                                r8_8 = malloc(_Size);
                                                *strp_1 = r8_8;
                                                
                                                if (!r8_8)
                                                {
                                                    int rval_2 = -1;
                                                    
                                                    if (!(rbx_3 & 0x400))
                                                        rval_2 = rval;
                                                    
                                                    return cleanup_return(rval_2, &gcollect, 
                                                        strp_1, &wbuf);
                                                }
                                                
                                                struct gcollect* gcollect_7 = gcollect;
                                                struct gcollect* gcollect_2;
                                                int64_t rcx_25;
                                                long long unsigned int count_1;
                                                
                                                if (gcollect_7)
                                                {
                                                    count_1 = gcollect_7->count;
                                                    gcollect_2 = gcollect_7;
                                                    rcx_25 = count_1 + 1;
                                                }
                                                
                                                if (!gcollect_7 || count_1 > 0x1f)
                                                {
                                                    gcollect_2 = malloc(0x110);
                                                    rcx_25 = 1;
                                                    count_1 = 0;
                                                    gcollect_2->count = 0;
                                                    gcollect_2->next = gcollect_7;
                                                }
                                                
                                                gcollect_2->count = rcx_25;
                                                gcollect = gcollect_2;
                                                gcollect_2->ptrs[count_1] = strp_1;
                                            }
                                            
                                            int32_t i_28 = in_ch(s, &read_in);
                                            char* r8_9 = r8_8;
                                            
                                            if (i_28 == 0xffffffff)
                                                goto label_140006b23;
                                            
                                            wpsz_9 = r15_6;
                                            int32_t i_11 = i_28;
                                            int32_t _Size_23 = r12_1 - 1;
                                            int64_t _Size_10 = _Size_8;
                                            int64_t r12_2 = r12_1;
                                            
                                            while (true)
                                            {
                                                if (rbx_3 & 0x600)
                                                {
                                                    int64_t rcx_28 = *strp_1;
                                                    
                                                    if (r8_9 == rcx_28 + _Size_10)
                                                    {
                                                        int64_t _Size_16 = _Size_23;
                                                        
                                                        if (_Size_10 < r12_2)
                                                            _Size_16 = _Size_10;
                                                        
                                                        int64_t _Size_5 = _Size_16 + _Size_10;
                                                        
                                                        while (true)
                                                        {
                                                            void* rax_58 = realloc(rcx_28, _Size_5);
                                                            
                                                            if (rax_58)
                                                            {
                                                                *strp_1 = rax_58;
                                                                r8_9 = rax_58 + _Size_10;
                                                                _Size_10 = _Size_5;
                                                                break;
                                                            }
                                                            
                                                            if (_Size_10 + 1 >= _Size_5)
                                                                goto label_140004230;
                                                            
                                                            rcx_28 = *strp_1;
                                                            _Size_5 = _Size_10 + 1;
                                                        }
                                                    }
                                                }
                                                
                                                *r8_9 = i_11;
                                                
                                                if (_Size_23 <= 0)
                                                    break;
                                                
                                                _Size_23 -= 1;
                                                r12_2 -= 1;
                                                i_11 = in_ch(s, &read_in);
                                                
                                                if (i_11 == 0xffffffff)
                                                    break;
                                                
                                                r8_9 = &r8_9[1];
                                            }
                                            
                                            r15_1 = wpsz_9;
                                            var_d8_1 = &r8_9[1];
                                            i_4 = i_11;
                                            _Size_8 = _Size_10;
                                            
                                            if (strp_1)
                                            {
                                                int64_t rcx_99 = *strp_1;
                                                
                                                if (rcx_99)
                                                {
                                                    void* _Size_2 = var_d8_1 - rcx_99;
                                                    
                                                    if (_Size_8 != _Size_2)
                                                    {
                                                        int64_t rax_194 = realloc(rcx_99, _Size_2);
                                                        
                                                        if (rax_194)
                                                            *strp_1 = rax_194;
                                                    }
                                                }
                                            }
                                            
                                        label_140005352:
                                            rval += 1;
                                            strp_1 = nullptr;
                                            goto label_140003d09;
                                        }
                                        
                                    label_14000456a:
                                        
                                        if (r12_1 == 0xffffffff)
                                            r12_1 = 1;
                                        
                                        r15_1 = rbx_3 & 0x80;
                                        
                                        if (!r15_1)
                                        {
                                            if (!(*rbx_3[1] & 6))
                                            {
                                                if (r11_1)
                                                {
                                                    char** argp_4 = argp;
                                                    
                                                    if (r11_1 != 1)
                                                        argp_4 = &argp[(r11_1 - 1) << 3];
                                                    
                                                    pwc_2 = *argp_4;
                                                }
                                                else
                                                {
                                                    char** argp_28 = argp_1;
                                                    argp_1 = &argp_28[1];
                                                    pwc_2 = *argp_28;
                                                }
                                                
                                                if (pwc_2)
                                                    goto label_14000462d;
                                                
                                                return cleanup_return(rval, &gcollect, strp_1, 
                                                    &wbuf);
                                            }
                                            
                                            if (r11_1)
                                            {
                                                int64_t** argp_5 = argp;
                                                
                                                if (r11_1 != 1)
                                                    argp_5 = &argp[(r11_1 - 1) << 3];
                                                
                                                strp_1 = *argp_5;
                                            }
                                            else
                                            {
                                                int64_t** argp_27 = argp_1;
                                                argp_1 = &argp_27[1];
                                                strp_1 = *argp_27;
                                            }
                                            
                                            if (!strp_1)
                                                return cleanup_return(rval, &gcollect, nullptr, 
                                                    &wbuf);
                                            
                                            int32_t _Size_20 = 0x400;
                                            
                                            if (r12_1 <= 0x400)
                                                _Size_20 = r12_1;
                                            
                                            uint64_t _Size_11 = _Size_20;
                                            _Size_8 = _Size_11;
                                            char* pwc_3 = malloc(_Size_11 * 2);
                                            strp = strp_1;
                                            pwc_2 = pwc_3;
                                            *strp = pwc_3;
                                            
                                            if (!pwc_3)
                                                goto label_14000565d;
                                            
                                            struct gcollect* gcollect_8 = gcollect;
                                            struct gcollect* gcollect_3;
                                            int64_t rcx_31;
                                            long long unsigned int count_2;
                                            
                                            if (gcollect_8)
                                            {
                                                count_2 = gcollect_8->count;
                                                gcollect_3 = gcollect_8;
                                                rcx_31 = count_2 + 1;
                                            }
                                            
                                            if (!gcollect_8 || count_2 > 0x1f)
                                            {
                                                gcollect_3 = malloc(0x110);
                                                rcx_31 = 1;
                                                count_2 = 0;
                                                gcollect_3->count = 0;
                                                gcollect_3->next = gcollect_8;
                                            }
                                            
                                            gcollect_3->count = rcx_31;
                                            gcollect = gcollect_3;
                                            gcollect_3->ptrs[count_2] = strp_1;
                                            goto label_14000462d;
                                        }
                                        
                                    label_14000462d:
                                        int32_t i_12 = in_ch(s, &read_in);
                                        i_4 = i_12;
                                        
                                        if (i_12 != 0xffffffff)
                                        {
                                            var_100 = rbx_3;
                                            _Size_19 = r12_1 - 1;
                                            __builtin_memset(&cstate, 0, 8);
                                            wbuf_max_sz_1 = r12_1;
                                            long long unsigned int* rin_4 = &read_in;
                                        label_140004672:
                                            buf[0] = i_4;
                                            
                                            if (!r15_1 && var_100 & 0x600)
                                            {
                                                int64_t rcx_33 = *strp_1;
                                                uint64_t rdx_26 = _Size_8 * 2;
                                                
                                                if (pwc_2 == rcx_33 + rdx_26)
                                                {
                                                    int64_t _Size_14 = _Size_19;
                                                    
                                                    if (_Size_8 <= wbuf_max_sz_1)
                                                        _Size_14 = _Size_8;
                                                    
                                                    int64_t _Size_15 = _Size_14 + _Size_8;
                                                    
                                                    while (true)
                                                    {
                                                        int64_t rax_66 =
                                                            realloc(rcx_33, _Size_15 * 2);
                                                        
                                                        if (rax_66)
                                                        {
                                                            _Size_8 = _Size_15;
                                                            *strp_1 = rax_66;
                                                            pwc_2 = rax_66 + rdx_26;
                                                            break;
                                                        }
                                                        
                                                        if (_Size_8 + 1 >= _Size_15)
                                                            goto label_140004230;
                                                        
                                                        _Size_15 = _Size_8 + 1;
                                                        rcx_33 = *strp_1;
                                                    }
                                                }
                                            }
                                            
                                            char* pwc = pwc_2;
                                            long long unsigned int* var_e8_4;
                                            var_e8_4 = r15_1;
                                            
                                            if (r15_1)
                                                pwc = nullptr;
                                            
                                            while (true)
                                            {
                                                int64_t rax_68 = mbrtowc(pwc, &buf, 1, &cstate);
                                                
                                                if (rax_68 != -2)
                                                {
                                                    r15_1 = var_e8_4;
                                                    
                                                    if (rax_68 != 1)
                                                        goto label_140006a89;
                                                    
                                                    pwc_2 = &pwc_2[2];
                                                    
                                                    if (_Size_19 > 0)
                                                    {
                                                        int32_t i_20 = in_ch(s, rin_4);
                                                        wbuf_max_sz_1 -= 1;
                                                        _Size_19 -= 1;
                                                        i_4 = i_20;
                                                        
                                                        if (i_20 != 0xffffffff)
                                                            goto label_140004672;
                                                    }
                                                    
                                                    if (r15_1)
                                                        goto label_140004acc;
                                                    
                                                    optimize_alloc(strp_1, pwc_2, _Size_8 * 2);
                                                    goto label_140005352;
                                                }
                                                
                                                int32_t i_13 = in_ch(s, rin_4);
                                                i_4 = i_13;
                                                
                                                if (i_13 == 0xffffffff)
                                                    break;
                                                
                                                buf[0] = i_13;
                                            }
                                            
                                            *_errno() = 0x2a;
                                            
                                            if (rval != 0xffffffff)
                                            {
                                                struct gcollect* next_4 = gcollect;
                                                
                                                while (next_4)
                                                {
                                                    struct gcollect* next_20 = next_4;
                                                    next_4 = next_4->next;
                                                    free(next_20);
                                                }
                                                
                                                goto label_140003cbe;
                                            }
                                        }
                                        else if (rval + 1 > 1)
                                        {
                                            struct gcollect* next_14 = gcollect;
                                            
                                            while (next_14)
                                            {
                                                struct gcollect* next_30 = next_14;
                                                next_14 = next_14->next;
                                                free(next_30);
                                            }
                                            
                                        label_140006642:
                                            gcollect = nullptr;
                                            
                                            if (strp_1)
                                            {
                                                free(*strp_1);
                                                *strp_1 = 0;
                                            }
                                            
                                            goto label_140003cdf;
                                        }
                                    }
                                    else
                                    {
                                        char* tmp_wbuf_ptr;
                                        int rval_3;
                                        
                                        if (r8_1 > 0x67)
                                        {
                                        label_140005194:
                                            
                                            if (r8_1 - 0x69 <= 0xf)
                                            {
                                                if (!(1 << (r8_1 - 0x69) & 0x90c1))
                                                {
                                                    if (r8_1 == 0x73)
                                                    {
                                                    label_14000408c:
                                                        r15_1 = rbx_3 & 0x80;
                                                        
                                                        if (!r15_1)
                                                        {
                                                            if (!(*rbx_3[1] & 6))
                                                            {
                                                                if (r11_1)
                                                                {
                                                                    char* argp_6 = argp;
                                                                    
                                                                    if (r11_1 != 1)
                                                                        argp_6 = &argp[(r11_1 - 1) << 3];
                                                                    
                                                                    var_d8_1 = *argp_6;
                                                                }
                                                                else
                                                                {
                                                                    char* rdi_36 = *argp_1;
                                                                    argp_1 = &argp_1[8];
                                                                    var_d8_1 = rdi_36;
                                                                }
                                                                
                                                                if (var_d8_1)
                                                                    goto label_140004142;
                                                                
                                                                return cleanup_return(rval, &gcollect, 
                                                                    strp_1, &wbuf);
                                                            }
                                                            
                                                            if (r11_1)
                                                            {
                                                                char* argp_7 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_7 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                strp_1 = *argp_7;
                                                            }
                                                            else
                                                            {
                                                                int64_t* strp_4 = *argp_1;
                                                                argp_1 = &argp_1[8];
                                                                strp_1 = strp_4;
                                                            }
                                                            
                                                            if (!strp_1)
                                                                return cleanup_return(rval, &gcollect, 
                                                                    nullptr, &wbuf);
                                                            
                                                            char* rax_36 = malloc(0x64);
                                                            strp = strp_1;
                                                            var_d8_1 = rax_36;
                                                            *strp = rax_36;
                                                            
                                                            if (!rax_36)
                                                                goto label_14000565d;
                                                            
                                                            struct gcollect* gcollect_6 = gcollect;
                                                            struct gcollect* gcollect_1;
                                                            int64_t rcx_14;
                                                            long long unsigned int count;
                                                            
                                                            if (gcollect_6)
                                                            {
                                                                count = gcollect_6->count;
                                                                gcollect_1 = gcollect_6;
                                                                rcx_14 = count + 1;
                                                            }
                                                            
                                                            if (!gcollect_6 || count > 0x1f)
                                                            {
                                                                gcollect_1 = malloc(0x110);
                                                                rcx_14 = 1;
                                                                count = 0;
                                                                gcollect_1->count = 0;
                                                                gcollect_1->next = gcollect_6;
                                                            }
                                                            
                                                            gcollect_1->count = rcx_14;
                                                            gcollect = gcollect_1;
                                                            gcollect_1->ptrs[count] = strp_1;
                                                            _Size_8 = 0x64;
                                                            goto label_140004142;
                                                        }
                                                        
                                                    label_140004142:
                                                        int32_t i_9 = in_ch(s, &read_in);
                                                        i_4 = i_9;
                                                        
                                                        if (i_9 == 0xffffffff)
                                                            goto label_140006773;
                                                        
                                                        wpsz_9 = rbx_3;
                                                        char* rbx_5 = var_d8_1;
                                                        int32_t rsi_4 = rbx_3 & 0x600;
                                                        
                                                        while (true)
                                                        {
                                                            if (isspace(i_4))
                                                            {
                                                                long long unsigned int read_in_2 =
                                                                    read_in;
                                                                var_d8_1 = rbx_5;
                                                                
                                                                if (!(s->is_string & 1))
                                                                {
                                                                    ungetc(i_4, *(s-> + 0));
                                                                    read_in = read_in_2 - 1;
                                                                }
                                                                else
                                                                {
                                                                    int64_t back_top_6 = s->back_top;
                                                                    read_in = read_in_2 - 1;
                                                                    s->bch[back_top_6] = i_4;
                                                                    s->back_top = back_top_6 + 1;
                                                                }
                                                                
                                                                break;
                                                            }
                                                            
                                                            if (!r15_1)
                                                            {
                                                                *rbx_5 = i_4;
                                                                void* rax_40 = &rbx_5[1];
                                                                
                                                                if (rsi_4)
                                                                {
                                                                    rbx_5 = rax_40;
                                                                    int64_t rcx_17 = *strp_1;
                                                                    
                                                                    if (rax_40 == rcx_17 + _Size_8)
                                                                    {
                                                                        var_d8_1 = rsi_4;
                                                                        uint64_t _Size_6 = _Size_8 * 2;
                                                                        
                                                                        while (true)
                                                                        {
                                                                            void* rax_200 =
                                                                                realloc(rcx_17, _Size_6);
                                                                            
                                                                            if (rax_200)
                                                                            {
                                                                                rsi_4 = var_d8_1;
                                                                                *strp_1 = rax_200;
                                                                                uint64_t _Size_12 = _Size_8;
                                                                                _Size_8 = _Size_6;
                                                                                rbx_5 = rax_200 + _Size_12;
                                                                                goto label_14000418b;
                                                                            }
                                                                            
                                                                            if (_Size_8 + 1 >= _Size_6)
                                                                                break;
                                                                            
                                                                            rcx_17 = *strp_1;
                                                                            _Size_6 = _Size_8 + 1;
                                                                        }
                                                                        
                                                                        rval_3 = -1;
                                                                        
                                                                        if (wpsz_9 & 0x400)
                                                                            goto label_140006e81;
                                                                        
                                                                        goto label_14000700a;
                                                                    }
                                                                }
                                                                else
                                                                    rbx_5 = rax_40;
                                                            }
                                                            
                                                        label_14000418b:
                                                            
                                                            if (r12_1 <= 0)
                                                            {
                                                            label_1400041a0:
                                                                int32_t i_10 = in_ch(s, &read_in);
                                                                i_4 = i_10;
                                                                
                                                                if (i_10 != 0xffffffff)
                                                                    continue;
                                                            }
                                                            else
                                                            {
                                                                int32_t temp0_1 = r12_1;
                                                                r12_1 = r12_1 - 1;
                                                                
                                                                if (temp0_1 != 1)
                                                                    goto label_1400041a0;
                                                            }
                                                            
                                                            var_d8_1 = rbx_5;
                                                            break;
                                                        }
                                                        
                                                        if (r15_1)
                                                            goto label_140004acc;
                                                        
                                                        char* rax_159 = var_d8_1;
                                                        *rax_159 = 0;
                                                        
                                                        if (strp_1)
                                                        {
                                                            int64_t rcx_77 = *strp_1;
                                                            
                                                            if (rcx_77)
                                                            {
                                                                void* _Size_1 = &rax_159[1] - rcx_77;
                                                                
                                                                if (_Size_8 != _Size_1)
                                                                {
                                                                    int64_t rax_160 =
                                                                        realloc(rcx_77, _Size_1);
                                                                    
                                                                    if (rax_160)
                                                                        *strp_1 = rax_160;
                                                                }
                                                            }
                                                        }
                                                        
                                                        rval += 1;
                                                        var_d8_1 = &rax_159[1];
                                                        strp_1 = nullptr;
                                                        goto label_140003d09;
                                                    }
                                                    
                                                    if (r8_1 != 0x6e)
                                                        goto label_1400047f3;
                                                    
                                                    r15_1 = rbx_3 & 0x80;
                                                    
                                                    if (r15_1)
                                                        goto label_140004acc;
                                                    
                                                    long long unsigned int read_in_1 = read_in;
                                                    
                                                    if (!(rbx_3 & 8))
                                                    {
                                                        r15_1 = rbx_3 & 4;
                                                        
                                                        if (r15_1)
                                                        {
                                                            int32_t* rdx_101;
                                                            
                                                            if (r11_1)
                                                            {
                                                                int32_t** argp_22 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_22 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                rdx_101 = *argp_22;
                                                            }
                                                            else
                                                            {
                                                                int32_t** argp_33 = argp_1;
                                                                rdx_101 = *argp_33;
                                                                argp_1 = &argp_33[1];
                                                            }
                                                            
                                                            *rdx_101 = read_in_1;
                                                            r15_1 = 0;
                                                        }
                                                        else if (!(rbx_3 & 2))
                                                        {
                                                            int32_t rbx_31 = rbx_3 & 1;
                                                            r15_1 = rbx_31;
                                                            
                                                            if (rbx_31)
                                                            {
                                                                char* rdx_118;
                                                                
                                                                if (r11_1)
                                                                {
                                                                    char** argp_24 = argp;
                                                                    
                                                                    if (r11_1 != 1)
                                                                        argp_24 = &argp[(r11_1 - 1) << 3];
                                                                    
                                                                    rdx_118 = *argp_24;
                                                                }
                                                                else
                                                                {
                                                                    char** argp_36 = argp_1;
                                                                    rdx_118 = *argp_36;
                                                                    argp_1 = &argp_36[1];
                                                                }
                                                                
                                                                *rdx_118 = read_in_1;
                                                                r15_1 = 0;
                                                            }
                                                            else if (r11_1)
                                                            {
                                                                int32_t** argp_23 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_23 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                **argp_23 = read_in_1;
                                                            }
                                                            else
                                                            {
                                                                int32_t** argp_38 = argp_1;
                                                                argp_1 = &argp_38[1];
                                                                **argp_38 = read_in_1;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            int16_t* rdx_113;
                                                            
                                                            if (r11_1)
                                                            {
                                                                int16_t** argp_26 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_26 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                rdx_113 = *argp_26;
                                                            }
                                                            else
                                                            {
                                                                int16_t** argp_35 = argp_1;
                                                                rdx_113 = *argp_35;
                                                                argp_1 = &argp_35[1];
                                                            }
                                                            
                                                            *rdx_113 = read_in_1;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        long long unsigned int* rdx_51;
                                                        
                                                        if (r11_1)
                                                        {
                                                            long long unsigned int** argp_20 = argp;
                                                            
                                                            if (r11_1 != 1)
                                                                argp_20 = &argp[(r11_1 - 1) << 3];
                                                            
                                                            rdx_51 = *argp_20;
                                                        }
                                                        else
                                                        {
                                                            long long unsigned int** argp_31 =
                                                                argp_1;
                                                            rdx_51 = *argp_31;
                                                            argp_1 = &argp_31[1];
                                                        }
                                                        
                                                        *rdx_51 = read_in_1;
                                                    }
                                                    
                                                    goto label_140003d09;
                                                }
                                                
                                            label_140004adc:
                                                
                                                if (r8_1 - 0x58 <= 0x20)
                                                    switch (r8_1)
                                                    {
                                                        case 0x58:
                                                        case 0x78:
                                                        {
                                                            _Radix = 0x10;
                                                            break;
                                                        }
                                                        case 0x64:
                                                        {
                                                            _Radix = 0xa;
                                                            rbx_3 |= 0x10;
                                                            break;
                                                        }
                                                        case 0x69:
                                                        {
                                                            _Radix = 0;
                                                            rbx_3 |= 0x10;
                                                            break;
                                                        }
                                                        case 0x6f:
                                                        {
                                                            _Radix = 8;
                                                            break;
                                                        }
                                                        case 0x70:
                                                        {
                                                            _Radix = 0x10;
                                                            rbx_3 = (rbx_3 & 0xfffffff1) | 0x2c;
                                                            break;
                                                        }
                                                        case 0x75:
                                                        {
                                                            _Radix = 0xa;
                                                            break;
                                                        }
                                                    }
                                                
                                                wpsz_9 = r11_1;
                                                long long unsigned int* rin_1 = &read_in;
                                                int32_t i_16 = in_ch(s, &read_in);
                                                int32_t r11_5 = wpsz_9;
                                                i_4 = i_16;
                                                
                                                if (i_16 == 0xffffffff)
                                                    goto label_140006773;
                                                
                                                long long unsigned int wpsz = 0;
                                                
                                                if (!((i_16 - 0x2b) & 0xfffffffd))
                                                {
                                                    char* wbuf_8 =
                                                        resize_wbuf(0, &wbuf_max_sz, wbuf);
                                                    *wbuf_8 = i_4;
                                                    wbuf = wbuf_8;
                                                    int32_t rax_213;
                                                    rax_213 = r12_1 > 0;
                                                    r12_1 = r12_1 - rax_213;
                                                    wpsz = 1;
                                                    i_4 = in_ch(s, rin_1);
                                                }
                                                
                                                int32_t rax_101;
                                                rax_101 = r12_1;
                                                
                                                if (i_4 == 0x30 && rax_101)
                                                {
                                                    long long unsigned int wpsz_8 = wpsz;
                                                    char* wbuf_21 = wbuf;
                                                    
                                                    if (r12_1 <= 0)
                                                    {
                                                        char* wbuf_9 = resize_wbuf(wpsz, 
                                                            &wbuf_max_sz, wbuf_21);
                                                        wbuf_9[wpsz] = 0x30;
                                                        wbuf = wbuf_9;
                                                        i_4 = in_ch(s, rin_1);
                                                    label_14000619c:
                                                        wpsz = r11_5;
                                                        r11_5 = wpsz;
                                                        
                                                        if (tolower(i_4) == 0x78)
                                                        {
                                                            if (!(_Radix & 0xffffffef))
                                                            {
                                                                int32_t rax_258;
                                                                rax_258 = r12_1 > 0;
                                                                r12_1 = r12_1 - rax_258;
                                                                _Radix = 0x10;
                                                                r11_5 = wpsz;
                                                                i_4 = in_ch(s, rin_1);
                                                            }
                                                        }
                                                        else if (!_Radix)
                                                            _Radix = 8;
                                                        
                                                        if (!r12_1 || i_4 == 0xffffffff)
                                                            goto label_140004bab;
                                                        
                                                        wpsz = wpsz_8 + 1;
                                                    label_14000591a:
                                                        wbuf_max_sz_1 = rbx_3;
                                                        var_100 = rbx_3 & 0x100;
                                                        _Size_19 = &wbuf_max_sz;
                                                        char* thousands_sep_2;
                                                        
                                                        while (true)
                                                        {
                                                            long long unsigned int wpsz_2;
                                                            
                                                            if (_Radix == 0x10)
                                                            {
                                                                if (isxdigit(i_4))
                                                                {
                                                                label_14000595c:
                                                                    wpsz_2 = wpsz;
                                                                    wpsz += 1;
                                                                label_140005972:
                                                                    char* wbuf_7 =
                                                                        resize_wbuf(wpsz_2, _Size_19, wbuf);
                                                                    wbuf_7[wpsz_2] = i_4;
                                                                    wbuf = wbuf_7;
                                                                    int32_t rax_183;
                                                                    rax_183 = r12_1 > 0;
                                                                    r12_1 = r12_1 - rax_183;
                                                                    int32_t i_24 = in_ch(s, rin_1);
                                                                    i_4 = i_24;
                                                                    
                                                                    if (i_24 != 0xffffffff && r12_1)
                                                                        continue;
                                                                }
                                                            }
                                                            else if (i_4 - 0x30 > 9)
                                                            {
                                                                if (_Radix == 0xa && var_100)
                                                                {
                                                                    thousands_sep_2 = thousands_sep;
                                                                    int32_t rdi_31 = 0x7fffffff;
                                                                    
                                                                    if (r12_1 > 0)
                                                                        rdi_31 = r12_1;
                                                                    
                                                                    uint32_t rdx_77 = *thousands_sep_2;
                                                                    char rax_188 = rdx_77;
                                                                    
                                                                    if (rdx_77 != i_4)
                                                                    {
                                                                        thousands_sep_2 = thousands_sep;
                                                                    label_140005b7f:
                                                                        
                                                                        if (rax_188)
                                                                        {
                                                                            rbx_3 = wbuf_max_sz_1;
                                                                            break;
                                                                        }
                                                                        
                                                                    label_140005ab7:
                                                                        
                                                                        if (r12_1 <= 0)
                                                                            rdi_31 = r12_1;
                                                                        
                                                                        wpsz_2 = wpsz - 1;
                                                                        r12_1 = rdi_31;
                                                                        goto label_140005972;
                                                                    }
                                                                    
                                                                    int32_t i_25 = i_4;
                                                                    
                                                                    while (true)
                                                                    {
                                                                        char* thousands_sep_3 = thousands_sep_2;
                                                                        thousands_sep_2 = &thousands_sep_2[1];
                                                                        
                                                                        if (!*thousands_sep_2)
                                                                        {
                                                                            i_4 = i_25;
                                                                            goto label_140005ab7;
                                                                        }
                                                                        
                                                                        if (!rdi_31)
                                                                        {
                                                                            rbx_3 = wbuf_max_sz_1;
                                                                            i_4 = i_25;
                                                                            break;
                                                                        }
                                                                        
                                                                        i_25 = in_ch(s, rin_1);
                                                                        
                                                                        if (i_25 == 0xffffffff)
                                                                        {
                                                                            i_4 = i_25;
                                                                            rax_188 = thousands_sep_3[1];
                                                                            goto label_140005b7f;
                                                                        }
                                                                        
                                                                        uint32_t rcx_97 = *thousands_sep_2;
                                                                        rdi_31 -= 1;
                                                                        
                                                                        if (i_25 != rcx_97)
                                                                        {
                                                                            i_4 = i_25;
                                                                            rax_188 = rcx_97;
                                                                            goto label_140005b7f;
                                                                        }
                                                                    }
                                                                    
                                                                    break;
                                                                }
                                                            }
                                                            else if (i_4 - 0x2f <= _Radix)
                                                                goto label_14000595c;
                                                            rbx_3 = wbuf_max_sz_1;
                                                            goto label_1400059c2;
                                                        }
                                                        
                                                        if (thousands_sep < thousands_sep_2)
                                                        {
                                                            void* r12_7 = &thousands_sep_2[-1];
                                                            back_ch(i_4, s, rin_1, 0);
                                                            
                                                            if (thousands_sep < r12_7)
                                                            {
                                                                void* rdi_32 = r12_7;
                                                                
                                                                do
                                                                {
                                                                    uint32_t _Character = *rdi_32;
                                                                    long long unsigned int read_in_12 =
                                                                        read_in - 1;
                                                                    
                                                                    if (s->is_string & 1)
                                                                    {
                                                                        int64_t back_top_5 = s->back_top;
                                                                        read_in = read_in_12;
                                                                        s->bch[back_top_5] = _Character;
                                                                        s->back_top = back_top_5 + 1;
                                                                    }
                                                                    else
                                                                    {
                                                                        ungetc(_Character, *(s-> + 0));
                                                                        read_in = read_in_12;
                                                                    }
                                                                    
                                                                    rdi_32 -= 1;
                                                                } while (rdi_32 != thousands_sep);
                                                                
                                                                r12_7 = thousands_sep - thousands_sep_2
                                                                    + r12_7 + 1;
                                                            }
                                                            
                                                            i_4 = *r12_7;
                                                            
                                                            if (!wpsz)
                                                                goto label_1400059cd;
                                                            
                                                            if (wpsz != 1 || (*wbuf - 0x2b) & 0xfd)
                                                                goto label_140004bda;
                                                            
                                                            goto label_140005a3c;
                                                        }
                                                        
                                                    label_1400059c2:
                                                        
                                                        if (!wpsz)
                                                            goto label_1400059cd;
                                                    }
                                                    else
                                                    {
                                                        wpsz = r11_5;
                                                        r12_1 = r12_1 - 1;
                                                        char* wbuf_2 = resize_wbuf(wpsz_8, 
                                                            &wbuf_max_sz, wbuf_21);
                                                        wbuf_2[wpsz_8] = 0x30;
                                                        wbuf = wbuf_2;
                                                        r11_5 = wpsz;
                                                        i_4 = in_ch(s, rin_1);
                                                        
                                                        if (r12_1)
                                                            goto label_14000619c;
                                                        
                                                        if (_Radix)
                                                        {
                                                        label_140004bab:
                                                            wpsz = wpsz_8 + 1;
                                                            goto label_140004baf;
                                                        }
                                                        
                                                        wpsz = wpsz_8 + 1;
                                                        _Radix = 8;
                                                    }
                                                    
                                                label_140004baf:
                                                    
                                                    if (wpsz != 1)
                                                        goto label_140004bd0;
                                                    
                                                    goto label_140004bc0;
                                                }
                                                
                                                int32_t _Radix_1 = 0xa;
                                                
                                                if (_Radix)
                                                    _Radix_1 = _Radix;
                                                
                                                _Radix = _Radix_1;
                                                
                                                if (i_4 != 0xffffffff && rax_101)
                                                    goto label_14000591a;
                                                
                                                char* wbuf_22;
                                                
                                                if (!wpsz)
                                                {
                                                label_1400059cd:
                                                    wpsz = r11_5;
                                                    
                                                    if (!(rbx_3 & 0x20))
                                                    {
                                                    label_140005a3c:
                                                        back_ch(i_4, s, rin_1, 0);
                                                        return cleanup_return(rval, &gcollect, 
                                                            strp_1, &wbuf);
                                                    }
                                                    
                                                    if (tolower(i_4) != 0x28)
                                                        goto label_140005a3c;
                                                    
                                                    char r15_20 = 0x6e;
                                                    char const* const rdi_30 = "nil)";
                                                    
                                                    while (true)
                                                    {
                                                        int32_t _C_3 = in_ch(s, rin_1);
                                                        
                                                        if (_C_3 != 0xffffffff
                                                            && r15_20 == tolower(_C_3))
                                                        {
                                                            r15_20 = rdi_30[1];
                                                            rdi_30 = &rdi_30[1];
                                                            
                                                            if (r15_20)
                                                                continue;
                                                            
                                                            rin_1 = wpsz;
                                                            _Size_19 = &wbuf_max_sz;
                                                            i_4 = _C_3;
                                                            char* wbuf_25 =
                                                                resize_wbuf(0, &wbuf_max_sz, wbuf);
                                                            wpsz = 1;
                                                            r11_5 = rin_1;
                                                            *wbuf_25 = 0x30;
                                                            wbuf_22 = wbuf_25;
                                                            break;
                                                        }
                                                        
                                                        i_4 = _C_3;
                                                        goto label_140005a3c;
                                                    }
                                                }
                                                else
                                                {
                                                label_140004bc0:
                                                    
                                                    if (!((*wbuf - 0x2b) & 0xfd))
                                                        goto label_140005a3c;
                                                    
                                                    wpsz = 1;
                                                label_140004bd0:
                                                    
                                                    if (i_4 == 0xffffffff)
                                                    {
                                                        wbuf_22 = wbuf;
                                                        _Size_19 = &wbuf_max_sz;
                                                    }
                                                    else
                                                    {
                                                    label_140004bda:
                                                        long long unsigned int read_in_10 =
                                                            read_in - 1;
                                                        
                                                        if (!(s->is_string & 1))
                                                        {
                                                            rin_1 = r11_5;
                                                            ungetc(i_4, *(s-> + 0));
                                                            read_in = read_in_10;
                                                            wbuf_22 = wbuf;
                                                            _Size_19 = &wbuf_max_sz;
                                                            r11_5 = rin_1;
                                                        }
                                                        else
                                                        {
                                                            int64_t back_top_3 = s->back_top;
                                                            read_in = read_in_10;
                                                            s->bch[back_top_3] = i_4;
                                                            s->back_top = back_top_3 + 1;
                                                            wbuf_22 = wbuf;
                                                            _Size_19 = &wbuf_max_sz;
                                                        }
                                                    }
                                                }
                                                
                                                rin_1 = r11_5;
                                                char* _String =
                                                    resize_wbuf(wpsz, _Size_19, wbuf_22);
                                                int32_t r11_6 = rin_1;
                                                _String[wpsz] = 0;
                                                wbuf = _String;
                                                int32_t rax_111 = rbx_3 & 0x10;
                                                r15_1 = rbx_3 & 8;
                                                int64_t var_118;
                                                
                                                if (r15_1)
                                                {
                                                    int32_t r11_7;
                                                    
                                                    if (!rax_111)
                                                    {
                                                        rin_1 = r11_6;
                                                        r11_7 = rin_1;
                                                        var_118 = _strtoui64(_String, 
                                                            &tmp_wbuf_ptr, _Radix);
                                                        
                                                        if (_String == tmp_wbuf_ptr)
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        
                                                        if (rbx_3 & 0x80)
                                                            goto label_140004acc;
                                                    }
                                                    else
                                                    {
                                                        r11_7 = rin_1;
                                                        var_118 = _strtoi64(_String, &tmp_wbuf_ptr, 
                                                            _Radix);
                                                        
                                                        if (_String == tmp_wbuf_ptr)
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        
                                                        r15_1 = 0;
                                                        
                                                        if (rbx_3 & 0x80)
                                                            goto label_140003d09;
                                                    }
                                                    
                                                    int64_t* rax_113;
                                                    
                                                    if (r11_7)
                                                    {
                                                        int64_t** argp_8 = argp;
                                                        
                                                        if (r11_7 != 1)
                                                            argp_8 = &argp[(r11_7 - 1) << 3];
                                                        
                                                        rax_113 = *argp_8;
                                                    }
                                                    else
                                                    {
                                                        int64_t** argp_30 = argp_1;
                                                        rax_113 = *argp_30;
                                                        argp_1 = &argp_30[1];
                                                    }
                                                    
                                                    *rax_113 = var_118;
                                                    goto label_140004ca3;
                                                }
                                                
                                                rin_1 = r11_6;
                                                char** _EndPtr = &tmp_wbuf_ptr;
                                                int64_t rax_197;
                                                char** argp_18;
                                                void* argp_19;
                                                char r8_33;
                                                char r8_46;
                                                int32_t r11_13;
                                                
                                                if (!rax_111)
                                                {
                                                    rax_197 = (-0x100000000 & var_118)
                                                        | strtoul(_String, _EndPtr, _Radix);
                                                    var_118 = rax_197;
                                                    
                                                    if (tmp_wbuf_ptr == _String)
                                                        return cleanup_return(rval, &gcollect, 
                                                            strp_1, &wbuf);
                                                    
                                                    r11_13 = rin_1;
                                                    
                                                    if (rbx_3 & 0x80)
                                                        goto label_140004acc;
                                                    
                                                    if (rbx_3 & 4)
                                                    {
                                                    label_140006479:
                                                        
                                                        if (r11_13)
                                                        {
                                                            int32_t** argp_21 = argp;
                                                            
                                                            if (r11_13 != 1)
                                                                argp_21 = &argp[(r11_13 - 1) << 3];
                                                            
                                                            **argp_21 = rax_197;
                                                            goto label_140004ca3;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (rbx_3 & 2)
                                                        {
                                                        label_140006941:
                                                            int16_t* rdx_130;
                                                            
                                                            if (r11_13)
                                                            {
                                                                int16_t** argp_25 = argp;
                                                                
                                                                if (r11_13 != 1)
                                                                    argp_25 = &argp[(r11_13 - 1) << 3];
                                                                
                                                                rdx_130 = *argp_25;
                                                            }
                                                            else
                                                            {
                                                                int16_t** argp_37 = argp_1;
                                                                rdx_130 = *argp_37;
                                                                argp_1 = &argp_37[1];
                                                            }
                                                            
                                                            *rdx_130 = rax_197;
                                                            goto label_140004ca3;
                                                        }
                                                        
                                                        rbx_3 &= 1;
                                                        
                                                        if (rbx_3)
                                                        {
                                                            if (!r11_13)
                                                            {
                                                            label_140005caf:
                                                                char* rdx_84 = *argp_1;
                                                                argp_1 = &argp_1[8];
                                                                *rdx_84 = rax_197;
                                                                goto label_140004ca3;
                                                            }
                                                            
                                                            argp_18 = argp;
                                                            r8_33 = 0;
                                                            int32_t rdx_95 = r11_13;
                                                            
                                                            while (true)
                                                            {
                                                                int32_t temp7_1 = rdx_95;
                                                                rdx_95 -= 1;
                                                                
                                                                if (temp7_1 == 1)
                                                                    break;
                                                                
                                                                r8_33 = 1;
                                                            }
                                                            
                                                        label_140006039:
                                                            
                                                            if (r8_33)
                                                                argp_18 = &argp[(r11_13 - 1) << 3];
                                                            
                                                            **argp_18 = rax_197;
                                                            goto label_140004ca3;
                                                        }
                                                        
                                                        if (r11_13)
                                                        {
                                                            argp_19 = argp;
                                                            r8_46 = 0;
                                                            int32_t rdx_159 = r11_13;
                                                            
                                                            while (true)
                                                            {
                                                                int32_t temp6_1 = rdx_159;
                                                                rdx_159 -= 1;
                                                                
                                                                if (temp6_1 == 1)
                                                                    break;
                                                                
                                                                r8_46 = 1;
                                                            }
                                                            
                                                        label_140006d78:
                                                            
                                                            if (r8_46)
                                                                argp_19 = &argp[(r11_13 - 1) << 3];
                                                            
                                                            **argp_19 = rax_197;
                                                            goto label_140004ca3;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    r11_13 = rin_1;
                                                    rax_197 = (-0x100000000 & var_118)
                                                        | strtol(_String, _EndPtr, _Radix);
                                                    var_118 = rax_197;
                                                    
                                                    if (_String == tmp_wbuf_ptr)
                                                        return cleanup_return(rval, &gcollect, 
                                                            strp_1, &wbuf);
                                                    
                                                    if (rbx_3 & 0x80)
                                                        goto label_140003d09;
                                                    
                                                    if (rbx_3 & 4)
                                                        goto label_140006479;
                                                    
                                                    if (rbx_3 & 2)
                                                        goto label_140006941;
                                                    
                                                    rbx_3 &= 1;
                                                    
                                                    if (rbx_3)
                                                    {
                                                        if (!r11_13)
                                                            goto label_140005caf;
                                                        
                                                        argp_18 = argp;
                                                        r8_33 = 0;
                                                        int32_t rdx_145 = r11_13;
                                                        
                                                        while (true)
                                                        {
                                                            int32_t temp9_1 = rdx_145;
                                                            rdx_145 -= 1;
                                                            
                                                            if (temp9_1 == 1)
                                                                break;
                                                            
                                                            r8_33 = 1;
                                                        }
                                                        
                                                        goto label_140006039;
                                                    }
                                                    
                                                    if (r11_13)
                                                    {
                                                        argp_19 = argp;
                                                        r8_46 = 0;
                                                        int32_t rdx_148 = r11_13;
                                                        
                                                        while (true)
                                                        {
                                                            int32_t temp8_1 = rdx_148;
                                                            rdx_148 -= 1;
                                                            
                                                            if (temp8_1 == 1)
                                                                break;
                                                            
                                                            r8_46 = 1;
                                                        }
                                                        
                                                        goto label_140006d78;
                                                    }
                                                }
                                                int32_t** argp_34 = argp_1;
                                                argp_1 = &argp_34[1];
                                                **argp_34 = rax_197;
                                                goto label_140004ca3;
                                            }
                                            
                                        label_1400047f3:
                                            
                                            if (rval != 0xffffffff)
                                            {
                                                struct gcollect* next_5 = gcollect;
                                                
                                                while (next_5)
                                                {
                                                    struct gcollect* next_21 = next_5;
                                                    next_5 = next_5->next;
                                                    free(next_21);
                                                }
                                                
                                                goto label_140003cbe;
                                            }
                                        }
                                        else
                                        {
                                            if (r8_1 - 0x25 > 0x42)
                                                goto label_1400047f3;
                                            
                                        label_140004384:
                                            
                                            switch (r8_1)
                                            {
                                                case 0x25:
                                                {
                                                    int32_t c = in_ch(s, &read_in);
                                                    i_4 = c;
                                                    
                                                    if (c == 0xffffffff)
                                                    {
                                                    label_140006773:
                                                        
                                                        if (rval)
                                                            i_4 = rval;
                                                        
                                                        return cleanup_return(i_4, &gcollect, 
                                                            strp_1, &wbuf);
                                                    }
                                                    
                                                    if (c != 0x25)
                                                    {
                                                        back_ch(c, s, &read_in, 1);
                                                        return cleanup_return(rval, &gcollect, 
                                                            strp_1, &wbuf);
                                                    }
                                                    
                                                label_140004acc:
                                                    r15_1 = 0;
                                                    goto label_140003d09;
                                                }
                                                case 0x26:
                                                case 0x27:
                                                case 0x28:
                                                case 0x29:
                                                case 0x2a:
                                                case 0x2b:
                                                case 0x2c:
                                                case 0x2d:
                                                case 0x2e:
                                                case 0x2f:
                                                case 0x30:
                                                case 0x31:
                                                case 0x32:
                                                case 0x33:
                                                case 0x34:
                                                case 0x35:
                                                case 0x36:
                                                case 0x37:
                                                case 0x38:
                                                case 0x39:
                                                case 0x3a:
                                                case 0x3b:
                                                case 0x3c:
                                                case 0x3d:
                                                case 0x3e:
                                                case 0x3f:
                                                case 0x40:
                                                case 0x42:
                                                case 0x44:
                                                case 0x48:
                                                case 0x49:
                                                case 0x4a:
                                                case 0x4b:
                                                case 0x4c:
                                                case 0x4d:
                                                case 0x4e:
                                                case 0x4f:
                                                case 0x50:
                                                case 0x51:
                                                case 0x52:
                                                case 0x54:
                                                case 0x55:
                                                case 0x56:
                                                case 0x57:
                                                case 0x59:
                                                case 0x5a:
                                                case 0x5c:
                                                case 0x5d:
                                                case 0x5e:
                                                case 0x5f:
                                                case 0x60:
                                                case 0x62:
                                                {
                                                    goto label_1400047f3;
                                                }
                                                case 0x41:
                                                case 0x45:
                                                case 0x46:
                                                case 0x47:
                                                case 0x61:
                                                case 0x65:
                                                case 0x66:
                                                case 0x67:
                                                {
                                                    wpsz_9 = r11_1;
                                                    int32_t rax_78;
                                                    rax_78 = r12_1 > 0;
                                                    int32_t i_5 = r12_1 - rax_78;
                                                    long long unsigned int* rin = &read_in;
                                                    int32_t rax_79 = in_ch(s, &read_in);
                                                    int32_t r11_3 = wpsz_9;
                                                    
                                                    if (rax_79 == 0xffffffff)
                                                    {
                                                        int32_t rval_4 = rax_79;
                                                        
                                                        if (rval)
                                                            rval_4 = rval;
                                                        
                                                        return cleanup_return(rval_4, &gcollect, 
                                                            strp_1, &wbuf);
                                                    }
                                                    
                                                    if ((rax_79 - 0x2b) & 0xfffffffd)
                                                        i_4 = rax_79;
                                                    else
                                                    {
                                                        if (!i_5)
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        
                                                        wpsz_9 = r11_3;
                                                        int32_t i_14 = in_ch(s, rin);
                                                        i_4 = i_14;
                                                        
                                                        if (i_14 == 0xffffffff)
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        
                                                        r11_3 = wpsz_9;
                                                        int32_t rax_82;
                                                        rax_82 = i_5 > 0;
                                                        i_5 -= rax_82;
                                                    }
                                                    
                                                    wpsz_9 = r11_3;
                                                    int32_t rax_83 = tolower(i_4);
                                                    int32_t r11_4 = wpsz_9;
                                                    int32_t rbx_16;
                                                    void* wpsz_6;
                                                    int32_t r11_10;
                                                    
                                                    if (rax_83 == 0x6e)
                                                    {
                                                        var_100 = r11_4;
                                                        _Size_19 = &wbuf_max_sz;
                                                        void* wpsz_4 = 1;
                                                        char* wbuf_12 =
                                                            resize_wbuf(0, &wbuf_max_sz, wbuf);
                                                        wpsz_9 = rbx_3;
                                                        int32_t i_3 = i_5;
                                                        wbuf = wbuf_12;
                                                        *wbuf_12 = i_4;
                                                        
                                                        while (i_3)
                                                        {
                                                            int32_t _C_5 = in_ch(s, rin);
                                                            i_4 = _C_5;
                                                            
                                                            if (_C_5 == 0xffffffff)
                                                                break;
                                                            
                                                            if (tolower(_C_5)
                                                                    != *(&data_1400116b6 + wpsz_4))
                                                                break;
                                                            
                                                            int32_t rax_268;
                                                            rax_268 = i_3 > 0;
                                                            i_3 -= rax_268;
                                                            char* wbuf_13 =
                                                                resize_wbuf(wpsz_4, _Size_19, wbuf);
                                                            wpsz_6 = wpsz_4 + 1;
                                                            wbuf = wbuf_13;
                                                            *(wbuf_13 + wpsz_4) = i_4;
                                                            
                                                            if (!*(wpsz_4 + 0x1400116b7))
                                                            {
                                                                r11_10 = var_100;
                                                                rbx_16 = wpsz_9;
                                                                goto label_1400056d0;
                                                            }
                                                            
                                                            wpsz_4 = wpsz_6;
                                                        }
                                                        
                                                        if (rval != 0xffffffff)
                                                        {
                                                            struct gcollect* next_15 = gcollect;
                                                            
                                                            while (next_15)
                                                            {
                                                                struct gcollect* next_31 = next_15;
                                                                next_15 = next_15->next;
                                                                free(next_31);
                                                            }
                                                            
                                                            goto label_140006642;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (rax_83 != 0x69)
                                                        {
                                                            wpsz_9 = 0x65;
                                                            long long unsigned int wpsz_11 = 0;
                                                            
                                                            if (i_5 && i_4 == 0x30)
                                                            {
                                                                var_100 = r11_4;
                                                                _Size_19 = &wbuf_max_sz;
                                                                char* wbuf_14 =
                                                                    resize_wbuf(0, &wbuf_max_sz, wbuf);
                                                                *wbuf_14 = 0x30;
                                                                wbuf = wbuf_14;
                                                                int32_t _C_6 = in_ch(s, rin);
                                                                r11_4 = var_100;
                                                                i_4 = _C_6;
                                                                
                                                                if (i_5 <= 0)
                                                                {
                                                                    var_100 = r11_4;
                                                                    r11_4 = var_100;
                                                                    wpsz_11 = 1;
                                                                    
                                                                    if (tolower(_C_6) == 0x78)
                                                                    {
                                                                        *rbx_3[1] &= 0xfe;
                                                                        rbx_3 |= 0x40;
                                                                        char* wbuf_15 =
                                                                            resize_wbuf(1, _Size_19, wbuf_14);
                                                                        wbuf_15[1] = i_4;
                                                                        wbuf = wbuf_15;
                                                                        wpsz_9 = 0x70;
                                                                        r11_4 = var_100;
                                                                        wpsz_11 = 2;
                                                                        i_4 = in_ch(s, rin);
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    var_100 = i_5 - 1;
                                                                    
                                                                    if (i_5 != 1)
                                                                    {
                                                                        wbuf_max_sz_1 = r11_4;
                                                                        r11_4 = wbuf_max_sz_1;
                                                                        
                                                                        if (tolower(i_4) == 0x78)
                                                                        {
                                                                            var_100 = r11_4;
                                                                            *rbx_3[1] &= 0xfe;
                                                                            i_5 -= 2;
                                                                            char* wbuf_16 =
                                                                                resize_wbuf(1, _Size_19, wbuf_14);
                                                                            rbx_3 |= 0x40;
                                                                            wbuf_16[1] = i_4;
                                                                            wbuf = wbuf_16;
                                                                            wpsz_9 = 0x70;
                                                                            r11_4 = var_100;
                                                                            wpsz_11 = 2;
                                                                            i_4 = in_ch(s, rin);
                                                                        }
                                                                        else
                                                                        {
                                                                            i_5 = var_100;
                                                                            wpsz_11 = 1;
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        i_5 = 0;
                                                                        wpsz_11 = 1;
                                                                    }
                                                                }
                                                            }
                                                            
                                                            wbuf_max_sz_1 = &wbuf_max_sz;
                                                            long long unsigned int wpsz_1 = wpsz_11;
                                                            _Size_19 = 0;
                                                            var_100 = false;
                                                            
                                                            while (true)
                                                            {
                                                                char* wbuf_20;
                                                                
                                                                if (i_4 - 0x30 <= 9)
                                                                {
                                                                label_140005068:
                                                                    wbuf_20 = wbuf;
                                                                label_140004a6f:
                                                                    char* wbuf_1 = resize_wbuf(wpsz_1, 
                                                                        wbuf_max_sz_1, wbuf_20);
                                                                    wbuf_1[wpsz_1] = i_4;
                                                                    wpsz_1 += 1;
                                                                    wbuf = wbuf_1;
                                                                label_140004a02:
                                                                    
                                                                    if (!i_5)
                                                                    {
                                                                    label_140005690:
                                                                        wpsz_6 = wpsz_1;
                                                                        rbx_16 = rbx_3;
                                                                        r11_10 = r11_4;
                                                                        break;
                                                                    }
                                                                    
                                                                label_140004a11:
                                                                    int32_t i_15 = in_ch(s, rin);
                                                                    i_4 = i_15;
                                                                    
                                                                    if (i_15 == 0xffffffff)
                                                                        goto label_140005690;
                                                                    
                                                                    int32_t rax_93;
                                                                    rax_93 = i_5 > 0;
                                                                    i_5 -= rax_93;
                                                                    continue;
                                                                }
                                                                
                                                                if (!_Size_19)
                                                                {
                                                                    int32_t rax_89;
                                                                    
                                                                    if (rbx_3 & 0x40)
                                                                        rax_89 = isxdigit(i_4);
                                                                    
                                                                    if (rbx_3 & 0x40 && rax_89)
                                                                        goto label_140005068;
                                                                    
                                                                    if (!wpsz_1)
                                                                        goto label_1400049c7;
                                                                    
                                                                    if (wpsz_9 != tolower(i_4))
                                                                        goto label_1400049c7;
                                                                    
                                                                    char* wbuf_6 =
                                                                        resize_wbuf(wpsz_1, &wbuf_max_sz, wbuf);
                                                                    _Size_19 = 1;
                                                                    wbuf = wbuf_6;
                                                                    wbuf_6[wpsz_1] = wpsz_9;
                                                                    wpsz_1 += 1;
                                                                    var_100 = true;
                                                                    goto label_140004a02;
                                                                }
                                                                
                                                                wbuf_20 = wbuf;
                                                                
                                                                if (wbuf_20[wpsz_1 - 1] == wpsz_9
                                                                        && !((i_4 - 0x2b) & 0xfffffffd))
                                                                    goto label_140004a6f;
                                                                
                                                            label_1400049c7:
                                                                char rax_92 = *decimal_point;
                                                                int32_t i_27;
                                                                
                                                                if (i_5 > 0)
                                                                {
                                                                    if (!var_100)
                                                                    {
                                                                        i_27 = i_5;
                                                                        goto label_140005369;
                                                                    }
                                                                    
                                                                    i_27 = i_5;
                                                                    
                                                                    if (!rax_92)
                                                                        goto label_140004a11;
                                                                    
                                                                    goto label_1400049e4;
                                                                }
                                                                
                                                                char* thousands_sep_1;
                                                                
                                                                if (var_100)
                                                                {
                                                                    i_27 = 0x7fffffff;
                                                                    
                                                                    if (!rax_92)
                                                                    {
                                                                    label_14000511d:
                                                                        var_100 = true;
                                                                        goto label_140004a02;
                                                                    }
                                                                    
                                                                label_1400049e4:
                                                                    thousands_sep_1 = thousands_sep;
                                                                    
                                                                    if (thousands_sep_1)
                                                                    {
                                                                    label_1400049f1:
                                                                        
                                                                        if (!*thousands_sep_1)
                                                                        {
                                                                            if (i_5 > 0)
                                                                                i_5 = i_27;
                                                                            
                                                                            goto label_140004a02;
                                                                        }
                                                                    }
                                                                    
                                                                    wpsz_6 = wpsz_1;
                                                                    rbx_16 = rbx_3;
                                                                    r11_10 = r11_4;
                                                                    
                                                                    if (i_4 != 0xffffffff)
                                                                    {
                                                                        long long unsigned int read_in_11 =
                                                                            read_in - 1;
                                                                        
                                                                        if (!(s->is_string & 1))
                                                                        {
                                                                            wpsz_9 = r11_10;
                                                                            ungetc(i_4, *(s-> + 0));
                                                                            read_in = read_in_11;
                                                                            r11_10 = wpsz_9;
                                                                        }
                                                                        else
                                                                        {
                                                                            int64_t back_top_7 = s->back_top;
                                                                            read_in = read_in_11;
                                                                            s->bch[back_top_7] = i_4;
                                                                            s->back_top = back_top_7 + 1;
                                                                        }
                                                                    }
                                                                    
                                                                    break;
                                                                }
                                                                
                                                                i_27 = 0x7fffffff;
                                                            label_140005369:
                                                                char* decimal_point_1 = decimal_point;
                                                                
                                                                if (rax_92 != i_4)
                                                                {
                                                                label_140005438:
                                                                    
                                                                    if (!rax_92)
                                                                    {
                                                                    label_1400053c6:
                                                                        
                                                                        if (*decimal_point)
                                                                        {
                                                                            void* rax_147 = decimal_point - wpsz_1;
                                                                            char* wbuf_23 = wbuf;
                                                                            
                                                                            do
                                                                            {
                                                                                char* wbuf_4 = resize_wbuf(wpsz_1, 
                                                                                    wbuf_max_sz_1, wbuf_23);
                                                                                wbuf_23 = wbuf_4;
                                                                                wbuf = wbuf_4;
                                                                                long long unsigned int wpsz_10 = wpsz_1;
                                                                                wpsz_1 += 1;
                                                                                wbuf_23[wpsz_10] =
                                                                                    *(rax_147 + wpsz_1 - 1);
                                                                            } while (*(rax_147 + wpsz_1));
                                                                        }
                                                                        
                                                                        if (i_5 > 0)
                                                                            i_5 = i_27;
                                                                        
                                                                        goto label_14000511d;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    while (true)
                                                                    {
                                                                        char* decimal_point_2 = decimal_point_1;
                                                                        decimal_point_1 = &decimal_point_1[1];
                                                                        
                                                                        if (!*decimal_point_1)
                                                                            goto label_1400053c6;
                                                                        
                                                                        if (!i_27)
                                                                            break;
                                                                        
                                                                        int32_t i_21 = in_ch(s, rin);
                                                                        i_4 = i_21;
                                                                        
                                                                        if (i_21 == 0xffffffff)
                                                                        {
                                                                            rax_92 = decimal_point_2[1];
                                                                            goto label_140005438;
                                                                        }
                                                                        
                                                                        uint32_t rdx_58 = *decimal_point_1;
                                                                        i_27 -= 1;
                                                                        rax_92 = rdx_58;
                                                                        
                                                                        if (i_4 != rdx_58)
                                                                            goto label_140005438;
                                                                    }
                                                                }
                                                                
                                                                if (!(rbx_3 & 0x100))
                                                                    goto label_1400049e4;
                                                                
                                                                thousands_sep_1 = thousands_sep;
                                                                void* r8_19 =
                                                                    decimal_point_1 - decimal_point;
                                                                void* rax_152 = nullptr;
                                                                
                                                                if (r8_19 > 0)
                                                                {
                                                                    while (*thousands_sep_1
                                                                        == *(decimal_point + rax_152))
                                                                    {
                                                                        thousands_sep_1 = &thousands_sep_1[1];
                                                                        rax_152 =
                                                                            thousands_sep_1 - thousands_sep;
                                                                        
                                                                        if (rax_152 >= r8_19)
                                                                            break;
                                                                    }
                                                                    
                                                                    if (r8_19 != rax_152
                                                                            || *thousands_sep_1 != i_4)
                                                                        goto label_1400049f1;
                                                                    
                                                                    goto label_1400054c9;
                                                                }
                                                                
                                                                if (r8_19)
                                                                    goto label_1400049e4;
                                                                
                                                                if (*thousands_sep_1 != i_4)
                                                                    goto label_1400049f1;
                                                                
                                                            label_1400054c9:
                                                                
                                                                do
                                                                {
                                                                    thousands_sep_1 = &thousands_sep_1[1];
                                                                    
                                                                    if (!*thousands_sep_1)
                                                                        break;
                                                                    
                                                                    if (!i_27)
                                                                        break;
                                                                    
                                                                    int32_t i_22 = in_ch(s, rin);
                                                                    i_4 = i_22;
                                                                    
                                                                    if (i_22 == 0xffffffff)
                                                                        break;
                                                                    
                                                                    i_27 -= 1;
                                                                } while (i_4 == *thousands_sep_1);
                                                                
                                                                goto label_1400049f1;
                                                            }
                                                            
                                                            if (!wpsz_6
                                                                    || (rbx_16 & 0x40 && wpsz_6 == 2))
                                                                return cleanup_return(rval, &gcollect, 
                                                                    strp_1, &wbuf);
                                                            
                                                            _Size_19 = &wbuf_max_sz;
                                                        label_1400056d0:
                                                            wpsz_9 = r11_10;
                                                            char* wbuf_5 =
                                                                resize_wbuf(wpsz_6, _Size_19, wbuf);
                                                            int32_t rdi_24 = rbx_16 & 0x80;
                                                            wbuf = wbuf_5;
                                                            int32_t r11_11 = wpsz_9;
                                                            *(wbuf_5 + wpsz_6) = 0;
                                                            void* var_e8_9;
                                                            long double var_98;
                                                            
                                                            if (rbx_16 & 8)
                                                            {
                                                                var_e8_9 = r11_11;
                                                                __strtold(&var_98, wbuf_5);
                                                                long double x87_r7_2 = var_98;
                                                                
                                                                if (!rdi_24)
                                                                {
                                                                    int32_t r11_15 = var_e8_9;
                                                                    
                                                                    if (wbuf_5 == tmp_wbuf_ptr)
                                                                        return cleanup_return(rval, &gcollect, 
                                                                            strp_1, &wbuf);
                                                                    
                                                                    if (rax_79 == 0x2d)
                                                                        x87_r7_2 = -(x87_r7_2);
                                                                    
                                                                    if (!r11_15)
                                                                    {
                                                                        long double** argp_32 = argp_1;
                                                                        **argp_32 = x87_r7_2;
                                                                        argp_1 = &argp_32[1];
                                                                    label_140004ca3:
                                                                        rval += 1;
                                                                        r15_1 = 0;
                                                                        goto label_140003d09;
                                                                    }
                                                                    
                                                                    long double** argp_11 = argp;
                                                                    
                                                                    if (r11_15 != 1)
                                                                        argp_11 = &argp[(r11_15 - 1) << 3];
                                                                    
                                                                    **argp_11 = x87_r7_2;
                                                                    
                                                                    if (wbuf_5 != tmp_wbuf_ptr)
                                                                        goto label_140004ca3;
                                                                    
                                                                    return cleanup_return(rval, &gcollect, 
                                                                        strp_1, &wbuf);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if (!(rbx_16 & 4))
                                                                {
                                                                    var_e8_9 = r11_11;
                                                                    int128_t zmm0_2 =
                                                                        __strtof(wbuf_5, &tmp_wbuf_ptr);
                                                                    
                                                                    if (rdi_24)
                                                                        goto label_140005e9e;
                                                                    
                                                                    if (wbuf_5 == tmp_wbuf_ptr)
                                                                        return cleanup_return(rval, &gcollect, 
                                                                            strp_1, &wbuf);
                                                                    
                                                                    int32_t r11_14 = var_e8_9;
                                                                    
                                                                    if (rax_79 == 0x2d)
                                                                        zmm0_2 ^= data_140011920;
                                                                    
                                                                    if (!r11_14)
                                                                    {
                                                                        **argp_1 = zmm0_2;
                                                                        argp_1 = &argp_1[8];
                                                                        goto label_140004ca3;
                                                                    }
                                                                    
                                                                    char* argp_14 = argp;
                                                                    
                                                                    if (r11_14 != 1)
                                                                        argp_14 = &argp[(r11_14 - 1) << 3];
                                                                    
                                                                    char* tmp_wbuf_ptr_1 = tmp_wbuf_ptr;
                                                                    **argp_14 = zmm0_2;
                                                                    
                                                                    if (wbuf_5 != tmp_wbuf_ptr_1)
                                                                        goto label_140004ca3;
                                                                    
                                                                    return cleanup_return(rval, &gcollect, 
                                                                        strp_1, &wbuf);
                                                                }
                                                                
                                                                wpsz_9 = r11_11;
                                                                __strtold(&var_98, wbuf_5);
                                                                
                                                                if (!rdi_24)
                                                                {
                                                                    if (wbuf_5 == tmp_wbuf_ptr)
                                                                        return cleanup_return(rval, &gcollect, 
                                                                            strp_1, &wbuf);
                                                                    
                                                                    int32_t r11_12 = wpsz_9;
                                                                    uint128_t zmm0_1 = var_98;
                                                                    
                                                                    if (rax_79 == 0x2d)
                                                                        zmm0_1 = __xorpd_xmmxuq_memxuq(zmm0_1, 
                                                                            data_140011910);
                                                                    
                                                                    if (!r11_12)
                                                                    {
                                                                        **argp_1 = zmm0_1;
                                                                        argp_1 = &argp_1[8];
                                                                        goto label_140004ca3;
                                                                    }
                                                                    
                                                                    uint64_t** argp_15 = argp;
                                                                    
                                                                    if (r11_12 != 1)
                                                                        argp_15 = &argp[(r11_12 - 1) << 3];
                                                                    
                                                                    char* tmp_wbuf_ptr_2 = tmp_wbuf_ptr;
                                                                    **argp_15 = zmm0_1;
                                                                    
                                                                    if (wbuf_5 != tmp_wbuf_ptr_2)
                                                                        goto label_140004ca3;
                                                                    
                                                                    return cleanup_return(rval, &gcollect, 
                                                                        strp_1, &wbuf);
                                                                }
                                                            }
                                                        label_140005e9e:
                                                            
                                                            if (wbuf_5 != tmp_wbuf_ptr)
                                                                goto label_140004acc;
                                                            
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        }
                                                        
                                                        var_100 = r11_4;
                                                        _Size_19 = &wbuf_max_sz;
                                                        void* wpsz_3 = 1;
                                                        char* wbuf_10 =
                                                            resize_wbuf(0, &wbuf_max_sz, wbuf);
                                                        wpsz_9 = rbx_3;
                                                        *wbuf_10 = i_4;
                                                        wbuf = wbuf_10;
                                                        
                                                        while (i_5)
                                                        {
                                                            int32_t _C_4 = in_ch(s, rin);
                                                            
                                                            if (_C_4 == 0xffffffff)
                                                                break;
                                                            
                                                            if (tolower(_C_4)
                                                                    != *(&data_1400116ba + wpsz_3))
                                                                break;
                                                            
                                                            int32_t rax_226;
                                                            rax_226 = i_5 > 0;
                                                            i_5 -= rax_226;
                                                            char* wbuf_11 =
                                                                resize_wbuf(wpsz_3, _Size_19, wbuf);
                                                            wpsz_6 = wpsz_3 + 1;
                                                            wbuf = wbuf_11;
                                                            *(wbuf_11 + wpsz_3) = _C_4;
                                                            
                                                            if (!*(wpsz_3 + 0x1400116bb))
                                                            {
                                                                r11_10 = var_100;
                                                                i_4 = _C_4;
                                                                rbx_16 = wpsz_9;
                                                                
                                                                if (i_5)
                                                                {
                                                                    var_100 = r11_10;
                                                                    wpsz_9 = wpsz_6;
                                                                    int32_t _C_7 = in_ch(s, rin);
                                                                    wpsz_6 = wpsz_9;
                                                                    r11_10 = var_100;
                                                                    i_4 = _C_7;
                                                                    
                                                                    if (_C_7 != 0xffffffff)
                                                                    {
                                                                        long long unsigned int wpsz_7 = wpsz_9;
                                                                        int32_t r11_16 = var_100;
                                                                        
                                                                        if (tolower(_C_7) == 0x69)
                                                                        {
                                                                            if (i_5 > 0)
                                                                                i_5 -= 1;
                                                                            
                                                                            long long unsigned int wpsz_5 =
                                                                                wpsz_3 + 2;
                                                                            wbuf_max_sz_1 = r11_16;
                                                                            char* wbuf_17 =
                                                                                resize_wbuf(wpsz_7, _Size_19, wbuf_11);
                                                                            var_100 = rbx_16;
                                                                            wbuf = wbuf_17;
                                                                            wbuf_17[wpsz_7] = i_4;
                                                                            wpsz_9 = "inity";
                                                                            int32_t _C_8;
                                                                            
                                                                            while (true)
                                                                            {
                                                                                if (!i_5)
                                                                                    return cleanup_return(rval, &gcollect, 
                                                                                        strp_1, &wbuf);
                                                                                
                                                                                _C_8 = in_ch(s, rin);
                                                                                
                                                                                if (_C_8 == 0xffffffff)
                                                                                    return cleanup_return(rval, &gcollect, 
                                                                                        strp_1, &wbuf);
                                                                                
                                                                                if (tolower(_C_8) != *(wpsz_9 + 1))
                                                                                    return cleanup_return(rval, &gcollect, 
                                                                                        strp_1, &wbuf);
                                                                                
                                                                                if (i_5 > 0)
                                                                                    i_5 -= 1;
                                                                                
                                                                                char* wbuf_18 =
                                                                                    resize_wbuf(wpsz_5, _Size_19, wbuf);
                                                                                wpsz_9 += 1;
                                                                                wpsz_6 = wpsz_5 + 1;
                                                                                wbuf = wbuf_18;
                                                                                wbuf_18[wpsz_5] = _C_8;
                                                                                
                                                                                if (!*(wpsz_9 + 1))
                                                                                    break;
                                                                                
                                                                                wpsz_5 = wpsz_6;
                                                                            }
                                                                            
                                                                            r11_10 = wbuf_max_sz_1;
                                                                            i_4 = _C_8;
                                                                            rbx_16 = var_100;
                                                                        }
                                                                        else
                                                                        {
                                                                            var_100 = r11_16;
                                                                            back_ch(i_4, s, rin, 0);
                                                                            wpsz_6 = wpsz_7;
                                                                            r11_10 = var_100;
                                                                        }
                                                                    }
                                                                }
                                                                
                                                                goto label_1400056d0;
                                                            }
                                                            
                                                            wpsz_3 = wpsz_6;
                                                        }
                                                        
                                                        if (rval != 0xffffffff)
                                                        {
                                                            struct gcollect* next_12 = gcollect;
                                                            
                                                            while (next_12)
                                                            {
                                                                struct gcollect* next_28 = next_12;
                                                                next_12 = next_12->next;
                                                                free(next_28);
                                                            }
                                                            
                                                            goto label_140003cbe;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 0x43:
                                                {
                                                    goto label_14000456a;
                                                }
                                                case 0x53:
                                                {
                                                label_140004cc3:
                                                    r15_1 = rbx_3 & 0x80;
                                                    
                                                    if (!r15_1)
                                                    {
                                                        if (!(*rbx_3[1] & 6))
                                                        {
                                                            if (r11_1)
                                                            {
                                                                char* argp_3 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_3 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                pwc_2 = *argp_3;
                                                            }
                                                            else
                                                            {
                                                                char* pwc_6 = *argp_1;
                                                                argp_1 = &argp_1[8];
                                                                pwc_2 = pwc_6;
                                                            }
                                                            
                                                            if (pwc_2)
                                                                goto label_140004d75;
                                                            
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        }
                                                        
                                                        if (r11_1)
                                                        {
                                                            char* argp_2 = argp;
                                                            
                                                            if (r11_1 != 1)
                                                                argp_2 = &argp[(r11_1 - 1) << 3];
                                                            
                                                            strp_1 = *argp_2;
                                                        }
                                                        else
                                                        {
                                                            int64_t* strp_6 = *argp_1;
                                                            argp_1 = &argp_1[8];
                                                            strp_1 = strp_6;
                                                        }
                                                        
                                                        if (!strp_1)
                                                            return cleanup_return(rval, &gcollect, 
                                                                nullptr, &wbuf);
                                                        
                                                        char* pwc_4 = malloc(0xc8);
                                                        strp = strp_1;
                                                        pwc_2 = pwc_4;
                                                        *strp = pwc_4;
                                                        
                                                        if (!pwc_4)
                                                        {
                                                        label_14000565d:
                                                            int rval_1 = -1;
                                                            
                                                            if (!(rbx_3 & 0x400))
                                                                rval_1 = rval;
                                                            
                                                            return cleanup_return(rval_1, 
                                                                &gcollect, strp, &wbuf);
                                                        }
                                                        
                                                        struct gcollect* gcollect_9 = gcollect;
                                                        struct gcollect* gcollect_4;
                                                        int64_t rcx_53;
                                                        long long unsigned int count_3;
                                                        
                                                        if (gcollect_9)
                                                        {
                                                            count_3 = gcollect_9->count;
                                                            gcollect_4 = gcollect_9;
                                                            rcx_53 = count_3 + 1;
                                                        }
                                                        
                                                        if (!gcollect_9 || count_3 > 0x1f)
                                                        {
                                                            gcollect_4 = malloc(0x110);
                                                            rcx_53 = 1;
                                                            count_3 = 0;
                                                            gcollect_4->count = 0;
                                                            gcollect_4->next = gcollect_9;
                                                        }
                                                        
                                                        gcollect_4->count = rcx_53;
                                                        gcollect = gcollect_4;
                                                        gcollect_4->ptrs[count_3] = strp_1;
                                                        _Size_8 = 0x64;
                                                        goto label_140004d75;
                                                    }
                                                    
                                                label_140004d75:
                                                    long long unsigned int* rin_2 = &read_in;
                                                    int32_t i_17 = in_ch(s, &read_in);
                                                    i_4 = i_17;
                                                    
                                                    if (i_17 != 0xffffffff)
                                                    {
                                                        __builtin_memset(&cstate, 0, 8);
                                                        wpsz_9 = r12_1;
                                                        
                                                        while (true)
                                                        {
                                                            if (isspace(i_4))
                                                            {
                                                                long long unsigned int read_in_6 =
                                                                    read_in - 1;
                                                                
                                                                if (!(s->is_string & 1))
                                                                {
                                                                    ungetc(i_4, *(s-> + 0));
                                                                    read_in = read_in_6;
                                                                }
                                                                else
                                                                {
                                                                    int64_t back_top_9 = s->back_top;
                                                                    read_in = read_in_6;
                                                                    s->bch[back_top_9] = i_4;
                                                                    s->back_top = back_top_9 + 1;
                                                                }
                                                            }
                                                            else
                                                            {
                                                                char* pwc_1 = nullptr;
                                                                
                                                                if (!r15_1)
                                                                    pwc_1 = pwc_2;
                                                                
                                                                int32_t i_18 = i_4;
                                                                int64_t rax_117;
                                                                
                                                                while (true)
                                                                {
                                                                    buf[0] = i_18;
                                                                    rax_117 =
                                                                        mbrtowc(pwc_1, &buf, 1, &cstate);
                                                                    
                                                                    if (rax_117 != -2)
                                                                        break;
                                                                    
                                                                    i_18 = in_ch(s, rin_2);
                                                                    i_4 = i_18;
                                                                    
                                                                    if (i_18 == 0xffffffff)
                                                                    {
                                                                        *_errno() = 0x2a;
                                                                        
                                                                        if (rval == 0xffffffff)
                                                                            goto label_140004230;
                                                                        
                                                                        struct gcollect* next_6 = gcollect;
                                                                        
                                                                        while (next_6)
                                                                        {
                                                                            struct gcollect* next_22 = next_6;
                                                                            next_6 = next_6->next;
                                                                            free(next_22);
                                                                        }
                                                                        
                                                                        goto label_140003cbe;
                                                                    }
                                                                }
                                                                
                                                                if (rax_117 != 1)
                                                                    goto label_140006a89;
                                                                
                                                                pwc_2 = &pwc_2[2];
                                                                
                                                                if (!r15_1 && rbx_3 & 0x600)
                                                                {
                                                                    uint64_t _Size_21 = _Size_8 * 2;
                                                                    
                                                                    if (pwc_2 == *strp_1 + _Size_21)
                                                                    {
                                                                        uint64_t _Size_17 = _Size_21;
                                                                        
                                                                        while (true)
                                                                        {
                                                                            int64_t rax_280 =
                                                                                realloc(*strp_1, _Size_17 * 2);
                                                                            
                                                                            if (rax_280)
                                                                            {
                                                                                _Size_8 = _Size_17;
                                                                                *strp_1 = rax_280;
                                                                                pwc_2 = rax_280 + _Size_21;
                                                                                goto label_140005272;
                                                                            }
                                                                            
                                                                            if (_Size_8 + 1 >= _Size_17)
                                                                            {
                                                                                rval_3 = -1;
                                                                                
                                                                                if (!(rbx_3 & 0x400))
                                                                                {
                                                                                    int64_t* strp_2 = strp_1;
                                                                                    strp_1 = nullptr;
                                                                                    rval_3 = rval + 1;
                                                                                    *(*strp_2 + _Size_21 - 2) = 0;
                                                                                }
                                                                                
                                                                                break;
                                                                            }
                                                                            
                                                                            _Size_17 = _Size_8 + 1;
                                                                        }
                                                                        
                                                                        goto label_140006e81;
                                                                    }
                                                                }
                                                                
                                                            label_140005272:
                                                                int32_t rax_141 = wpsz_9;
                                                                
                                                                if (rax_141 > 0)
                                                                    wpsz_9 = rax_141 - 1;
                                                                
                                                                if (rax_141 <= 0 || rax_141 != 1)
                                                                {
                                                                    int32_t i_19 = in_ch(s, rin_2);
                                                                    i_4 = i_19;
                                                                    
                                                                    if (i_19 != 0xffffffff)
                                                                        continue;
                                                                }
                                                            }
                                                            
                                                            if (r15_1)
                                                                break;
                                                            
                                                            *pwc_2 = 0;
                                                            optimize_alloc(strp_1, &pwc_2[2], 
                                                                _Size_8 * 2);
                                                            rval += 1;
                                                            pwc_2 = &pwc_2[2];
                                                            strp_1 = nullptr;
                                                            goto label_140003d09;
                                                        }
                                                        
                                                        goto label_140004acc;
                                                    }
                                                    
                                                    if (rval + 1 > 1)
                                                    {
                                                        struct gcollect* next_13 = gcollect;
                                                        
                                                        while (next_13)
                                                        {
                                                            struct gcollect* next_29 = next_13;
                                                            next_13 = next_13->next;
                                                            free(next_29);
                                                        }
                                                        
                                                        goto label_140006642;
                                                    }
                                                    break;
                                                }
                                                case 0x58:
                                                case 0x64:
                                                {
                                                    goto label_140004adc;
                                                }
                                                case 0x5b:
                                                {
                                                    int32_t rax_120 = rbx_3 & 0x80;
                                                    int32_t r15_16 = rbx_3 & 4;
                                                    
                                                    if (!r15_16)
                                                    {
                                                        if (rax_120)
                                                        {
                                                        label_140004efc:
                                                            char* wbuf_24 = wbuf;
                                                            char r13_3 = *(wpsz_9 + 1);
                                                            
                                                            if (r13_3 == 0x5e)
                                                                format_2 = wpsz_9 + 2;
                                                            
                                                            if (r12_1 < 0)
                                                                r12_1 = 0x7fffffff;
                                                            
                                                            if (wbuf_max_sz <= 0xff)
                                                            {
                                                                wbuf_max_sz = 0x100;
                                                                
                                                                if (wbuf_24)
                                                                    free(wbuf_24);
                                                                
                                                                char* wbuf_3 = malloc(0x100);
                                                                wbuf = wbuf_3;
                                                                wbuf_24 = wbuf_3;
                                                            }
                                                            
                                                            *wbuf_24 = 0;
                                                            *(wbuf_24 + 0xf8) = 0;
                                                            void* rdi_20 =
                                                                &wbuf_24[8] & 0xfffffffffffffff8;
                                                            __builtin_memset(rdi_20, 0, 
                                                                (wbuf_24 - rdi_20 + 0x100) >> 3 << 3);
                                                            int64_t rdx_47 = *format_2;
                                                            uint64_t rax_125 = rdx_47;
                                                            
                                                            if (rdx_47 == 0x5d || rdx_47 == 0x2d)
                                                            {
                                                                wbuf_24[rdx_47] = 1;
                                                                format_2 = &format_2[1];
                                                                rax_125 = *format_2;
                                                            }
                                                            
                                                            while (true)
                                                            {
                                                                format_2 = &format_2[1];
                                                                
                                                                if (!rax_125)
                                                                {
                                                                    char* wbuf_26 = wbuf_24;
                                                                    
                                                                    if (rval == 0xffffffff)
                                                                        goto label_140004230;
                                                                    
                                                                    struct gcollect* next_10 = gcollect;
                                                                    
                                                                    if (next_10)
                                                                    {
                                                                        do
                                                                        {
                                                                            struct gcollect* next_26 = next_10;
                                                                            next_10 = next_10->next;
                                                                            free(next_26);
                                                                        } while (next_10);
                                                                        
                                                                        wbuf_26 = wbuf_24;
                                                                    }
                                                                    
                                                                    gcollect = nullptr;
                                                                    
                                                                    if (strp_1)
                                                                    {
                                                                        free(*strp_1);
                                                                        *strp_1 = 0;
                                                                    }
                                                                    
                                                                    free(wbuf_26);
                                                                    goto label_140003cfa;
                                                                }
                                                                
                                                                if (rax_125 == 0x5d)
                                                                    break;
                                                                
                                                                while (true)
                                                                {
                                                                    if (rax_125 == 0x2d)
                                                                    {
                                                                        char const rcx_64 = *format_2;
                                                                        
                                                                        if (rcx_64 && rcx_64 != 0x5d)
                                                                        {
                                                                            uint32_t rdx_48 = format_2[-2];
                                                                            
                                                                            if (rcx_64 >= rdx_48)
                                                                            {
                                                                                if (rdx_48 >= rcx_64)
                                                                                {
                                                                                    format_2 = &format_2[1];
                                                                                    rax_125 = rcx_64;
                                                                                    continue;
                                                                                }
                                                                                
                                                                                do
                                                                                {
                                                                                    uint64_t rax_126 = rdx_48;
                                                                                    rdx_48 += 1;
                                                                                    wbuf_24[rax_126] = 1;
                                                                                    rax_125 = *format_2;
                                                                                } while (rdx_48 < rax_125);
                                                                                
                                                                                break;
                                                                            }
                                                                        }
                                                                    }
                                                                    
                                                                    wbuf_24[rax_125] = 1;
                                                                    rax_125 = *format_2;
                                                                    break;
                                                                }
                                                            }
                                                            
                                                            var_100 = r13_3 == 0x5e;
                                                            wbuf_max_sz_1 = read_in;
                                                            
                                                            if (!r15_16)
                                                            {
                                                                int32_t var_120;
                                                                var_120 = wbuf_24;
                                                                int32_t i_26 = in_ch(s, &read_in);
                                                                i_4 = i_26;
                                                                
                                                                if (i_26 == 0xffffffff)
                                                                    goto label_140006773;
                                                                
                                                                char* rbx_23 = var_d8_1;
                                                                wpsz_9 = r15_16;
                                                                int32_t rdi_42 = rbx_3 & 0x600;
                                                                
                                                                while (true)
                                                                {
                                                                    if (var_120[i_26] == var_100)
                                                                    {
                                                                        i_4 = i_26;
                                                                        long long unsigned int read_in_3 =
                                                                            read_in;
                                                                        var_d8_1 = rbx_23;
                                                                        r15_1 = wpsz_9;
                                                                        
                                                                        if (!(s->is_string & 1))
                                                                        {
                                                                            ungetc(i_4, *(s-> + 0));
                                                                            read_in = read_in_3 - 1;
                                                                        }
                                                                        else
                                                                        {
                                                                            int64_t back_top_8 = s->back_top;
                                                                            read_in = read_in_3 - 1;
                                                                            s->bch[back_top_8] = i_4;
                                                                            s->back_top = back_top_8 + 1;
                                                                        }
                                                                        
                                                                        break;
                                                                    }
                                                                    
                                                                    if (!rax_120)
                                                                    {
                                                                        *rbx_23 = i_26;
                                                                        void* rdx_93 = &rbx_23[1];
                                                                        
                                                                        if (rdi_42)
                                                                        {
                                                                            int64_t rcx_106 = *strp_1;
                                                                            rbx_23 = rdx_93;
                                                                            
                                                                            if (rdx_93 == rcx_106 + _Size_8)
                                                                            {
                                                                                var_d8_1 = rdi_42;
                                                                                uint64_t _Size_7 = _Size_8 * 2;
                                                                                
                                                                                while (true)
                                                                                {
                                                                                    int64_t rax_248 =
                                                                                        realloc(rcx_106, _Size_7);
                                                                                    
                                                                                    if (rax_248)
                                                                                    {
                                                                                        rdi_42 = var_d8_1;
                                                                                        *strp_1 = rax_248;
                                                                                        uint64_t _Size_13 = _Size_8;
                                                                                        _Size_8 = _Size_7;
                                                                                        rbx_23 = rax_248 + _Size_13;
                                                                                        goto label_140005f85;
                                                                                    }
                                                                                    
                                                                                    if (_Size_8 + 1 >= _Size_7)
                                                                                    {
                                                                                        rval_3 = -1;
                                                                                        
                                                                                        if (!(rbx_3 & 0x400))
                                                                                        {
                                                                                        label_14000700a:
                                                                                            *(*strp_1 + _Size_8 - 1) = 0;
                                                                                            strp_1 = nullptr;
                                                                                            rval_3 = rval + 1;
                                                                                        }
                                                                                        
                                                                                        break;
                                                                                    }
                                                                                    
                                                                                    rcx_106 = *strp_1;
                                                                                    _Size_7 = _Size_8 + 1;
                                                                                }
                                                                                
                                                                                goto label_140006e81;
                                                                            }
                                                                        }
                                                                        else
                                                                            rbx_23 = rdx_93;
                                                                    }
                                                                    
                                                                label_140005f85:
                                                                    int32_t temp4_1 = r12_1;
                                                                    r12_1 = r12_1 - 1;
                                                                    
                                                                    if (temp4_1 != 1)
                                                                    {
                                                                        i_26 = in_ch(s, &read_in);
                                                                        
                                                                        if (i_26 != 0xffffffff)
                                                                            continue;
                                                                    }
                                                                    
                                                                    var_d8_1 = rbx_23;
                                                                    r15_1 = wpsz_9;
                                                                    i_4 = i_26;
                                                                    break;
                                                                }
                                                                
                                                                if (read_in == wbuf_max_sz_1)
                                                                    return cleanup_return(rval, &gcollect, 
                                                                        strp_1, &wbuf);
                                                                
                                                                if (!rax_120)
                                                                {
                                                                    char* rax_235 = var_d8_1;
                                                                    *rax_235 = 0;
                                                                    
                                                                    if (strp_1)
                                                                    {
                                                                        int64_t rcx_117 = *strp_1;
                                                                        
                                                                        if (rcx_117)
                                                                        {
                                                                            void* _Size_3 = &rax_235[1] - rcx_117;
                                                                            
                                                                            if (_Size_8 != _Size_3)
                                                                            {
                                                                                int64_t rax_236 =
                                                                                    realloc(rcx_117, _Size_3);
                                                                                
                                                                                if (rax_236)
                                                                                    *strp_1 = rax_236;
                                                                            }
                                                                        }
                                                                    }
                                                                    
                                                                    rval += 1;
                                                                    r15_1 = 0;
                                                                    var_d8_1 = &rax_235[1];
                                                                    strp_1 = nullptr;
                                                                }
                                                                
                                                                goto label_140003d09;
                                                            }
                                                            
                                                            int32_t i_23 = in_ch(s, &read_in);
                                                            i_4 = i_23;
                                                            
                                                            if (i_23 == 0xffffffff)
                                                                goto label_140006773;
                                                            
                                                            int64_t rdi_27 = 0;
                                                            bool rsi_15 = var_100;
                                                            __builtin_memset(&cstate, 0, 8);
                                                            var_100 = &buf;
                                                            int32_t i_6;
                                                            
                                                            do
                                                            {
                                                                if (wbuf_24[i_4] == rsi_15)
                                                                {
                                                                    long long unsigned int read_in_7 =
                                                                        read_in - 1;
                                                                    
                                                                    if (!(s->is_string & 1))
                                                                    {
                                                                        ungetc(i_4, *(s-> + 0));
                                                                        read_in = read_in_7;
                                                                    }
                                                                    else
                                                                    {
                                                                        int64_t back_top_10 = s->back_top;
                                                                        read_in = read_in_7;
                                                                        s->bch[back_top_10] = i_4;
                                                                        s->back_top = back_top_10 + 1;
                                                                    }
                                                                    
                                                                    break;
                                                                }
                                                                
                                                                if (rax_120)
                                                                {
                                                                label_140005820:
                                                                    r12_1 = r12_1 - 1;
                                                                    
                                                                    if (r12_1 <= 0)
                                                                        break;
                                                                }
                                                                else
                                                                {
                                                                    buf[0] = i_4;
                                                                    rdi_27 += 1;
                                                                    
                                                                    if (mbrtowc(pwc_2, var_100, 1, &cstate)
                                                                        != -2)
                                                                    {
                                                                        pwc_2 = &pwc_2[2];
                                                                        
                                                                        if (!(rbx_3 & 0x600))
                                                                            rdi_27 = 0;
                                                                        else
                                                                        {
                                                                            rdi_27 = 0;
                                                                            int64_t rcx_87 = *strp_1;
                                                                            uint64_t _Size_22 = _Size_8 * 2;
                                                                            
                                                                            if (pwc_2 == rcx_87 + _Size_22)
                                                                            {
                                                                                uint64_t _Size_18 = _Size_22;
                                                                                
                                                                                while (true)
                                                                                {
                                                                                    int64_t rax_175 =
                                                                                        realloc(rcx_87, _Size_18 * 2);
                                                                                    
                                                                                    if (rax_175)
                                                                                    {
                                                                                        _Size_8 = _Size_18;
                                                                                        rdi_27 = 0;
                                                                                        *strp_1 = rax_175;
                                                                                        pwc_2 = rax_175 + _Size_22;
                                                                                        break;
                                                                                    }
                                                                                    
                                                                                    if (_Size_8 + 1 >= _Size_18)
                                                                                    {
                                                                                        rval_3 = -1;
                                                                                        
                                                                                        if (!(rbx_3 & 0x400))
                                                                                        {
                                                                                            int64_t* strp_3 = strp_1;
                                                                                            strp_1 = nullptr;
                                                                                            rval_3 = rval + 1;
                                                                                            *(*strp_3 + _Size_22 - 2) = 0;
                                                                                        }
                                                                                        
                                                                                    label_140006e81:
                                                                                        return cleanup_return(rval_3, 
                                                                                            &gcollect, strp_1, &wbuf);
                                                                                    }
                                                                                    
                                                                                    rcx_87 = *strp_1;
                                                                                    _Size_18 = _Size_8 + 1;
                                                                                }
                                                                            }
                                                                        }
                                                                        
                                                                        goto label_140005820;
                                                                    }
                                                                }
                                                                
                                                                i_6 = in_ch(s, &read_in);
                                                                i_4 = i_6;
                                                            } while (i_6 != 0xffffffff);
                                                            
                                                            if (rdi_27)
                                                            {
                                                            label_140006a89:
                                                                *_errno() = 0x2a;
                                                                return cleanup_return(rval, &gcollect, 
                                                                    strp_1, &wbuf);
                                                            }
                                                            
                                                            if (read_in == wbuf_max_sz_1)
                                                                return cleanup_return(rval, &gcollect, 
                                                                    strp_1, &wbuf);
                                                            
                                                            r15_1 = 0;
                                                            
                                                            if (!rax_120)
                                                            {
                                                                *pwc_2 = 0;
                                                                
                                                                if (strp_1)
                                                                {
                                                                    int64_t rcx_118 = *strp_1;
                                                                    
                                                                    if (rcx_118)
                                                                    {
                                                                        void* _Size_4 = &pwc_2[2] - rcx_118;
                                                                        
                                                                        if (_Size_8 * 2 != _Size_4)
                                                                        {
                                                                            int64_t rax_241 =
                                                                                realloc(rcx_118, _Size_4);
                                                                            
                                                                            if (rax_241)
                                                                                *strp_1 = rax_241;
                                                                        }
                                                                    }
                                                                }
                                                                
                                                                rval += 1;
                                                                r15_1 = 0;
                                                                pwc_2 = &pwc_2[2];
                                                                strp_1 = nullptr;
                                                            }
                                                            
                                                            goto label_140003d09;
                                                        }
                                                        
                                                        if (!(*rbx_3[1] & 6))
                                                        {
                                                            if (r11_1)
                                                            {
                                                                char* argp_16 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_16 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                var_d8_1 = *argp_16;
                                                            }
                                                            else
                                                            {
                                                                char* rdi_46 = *argp_1;
                                                                argp_1 = &argp_1[8];
                                                                var_d8_1 = rdi_46;
                                                            }
                                                            
                                                            if (var_d8_1)
                                                                goto label_140004efc;
                                                            
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        }
                                                        
                                                        if (r11_1)
                                                        {
                                                            char* argp_12 = argp;
                                                            
                                                            if (r11_1 != 1)
                                                                argp_12 = &argp[(r11_1 - 1) << 3];
                                                            
                                                            strp_1 = *argp_12;
                                                        }
                                                        else
                                                        {
                                                            int64_t* strp_8 = *argp_1;
                                                            argp_1 = &argp_1[8];
                                                            strp_1 = strp_8;
                                                        }
                                                        
                                                        if (!strp_1)
                                                            return cleanup_return(rval, &gcollect, 
                                                                nullptr, &wbuf);
                                                        
                                                        char* rax_163 = malloc(0x64);
                                                        strp = strp_1;
                                                        var_d8_1 = rax_163;
                                                        *strp = rax_163;
                                                        
                                                        if (!rax_163)
                                                            goto label_14000565d;
                                                    }
                                                    else
                                                    {
                                                        if (rax_120)
                                                            goto label_140004efc;
                                                        
                                                        if (!(*rbx_3[1] & 6))
                                                        {
                                                            if (r11_1)
                                                            {
                                                                char* argp_17 = argp;
                                                                
                                                                if (r11_1 != 1)
                                                                    argp_17 = &argp[(r11_1 - 1) << 3];
                                                                
                                                                pwc_2 = *argp_17;
                                                            }
                                                            else
                                                            {
                                                                char* pwc_7 = *argp_1;
                                                                argp_1 = &argp_1[8];
                                                                pwc_2 = pwc_7;
                                                            }
                                                            
                                                            if (pwc_2)
                                                                goto label_140004efc;
                                                            
                                                            return cleanup_return(rval, &gcollect, 
                                                                strp_1, &wbuf);
                                                        }
                                                        
                                                        if (r11_1)
                                                        {
                                                            char* argp_13 = argp;
                                                            
                                                            if (r11_1 != 1)
                                                                argp_13 = &argp[(r11_1 - 1) << 3];
                                                            
                                                            strp_1 = *argp_13;
                                                        }
                                                        else
                                                        {
                                                            int64_t* strp_7 = *argp_1;
                                                            argp_1 = &argp_1[8];
                                                            strp_1 = strp_7;
                                                        }
                                                        
                                                        if (!strp_1)
                                                            return cleanup_return(rval, &gcollect, 
                                                                nullptr, &wbuf);
                                                        
                                                        char* pwc_5 = malloc(0xc8);
                                                        strp = strp_1;
                                                        pwc_2 = pwc_5;
                                                        *strp = pwc_5;
                                                        
                                                        if (!pwc_5)
                                                            goto label_14000565d;
                                                    }
                                                    
                                                    struct gcollect* gcollect_10 = gcollect;
                                                    struct gcollect* gcollect_5;
                                                    int64_t rcx_58;
                                                    long long unsigned int count_4;
                                                    
                                                    if (gcollect_10)
                                                    {
                                                        count_4 = gcollect_10->count;
                                                        gcollect_5 = gcollect_10;
                                                        rcx_58 = count_4 + 1;
                                                    }
                                                    
                                                    if (!gcollect_10 || count_4 > 0x1f)
                                                    {
                                                        gcollect_5 = malloc(0x110);
                                                        rcx_58 = 1;
                                                        count_4 = 0;
                                                        gcollect_5->count = 0;
                                                        gcollect_5->next = gcollect_10;
                                                    }
                                                    
                                                    gcollect = gcollect_5;
                                                    gcollect_5->count = rcx_58;
                                                    gcollect_5->ptrs[count_4] = strp_1;
                                                    _Size_8 = 0x64;
                                                    goto label_140004efc;
                                                }
                                                case 0x63:
                                                {
                                                    goto label_1400043bd;
                                                }
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                            case 0x68:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                
                                if (r8_1 == 0x68)
                                {
                                    r8_1 = *(wpsz_12 + 2);
                                    rbx_3 |= 1;
                                    wpsz_9 = wpsz_12 + 2;
                                }
                                else
                                {
                                    rbx_3 |= 2;
                                    wpsz_9 = wpsz_12 + 1;
                                }
                                
                                goto label_140003f80;
                            }
                            case 0x6a:
                            case 0x74:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                rbx_3 |= 8;
                                wpsz_9 = wpsz_12 + 1;
                                goto label_140003f80;
                            }
                            case 0x6c:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                
                                if (r8_1 == 0x6c)
                                {
                                    r8_1 = *(wpsz_12 + 2);
                                    rbx_3 |= 0xc;
                                    wpsz_9 = wpsz_12 + 2;
                                }
                                else
                                {
                                    rbx_3 |= 4;
                                    wpsz_9 = wpsz_12 + 1;
                                }
                                
                                goto label_140003f80;
                            }
                            case 0x6d:
                            {
                                r8_1 = *(wpsz_12 + 1);
                                
                                if (r8_1 == 0x6c)
                                {
                                    r8_1 = *(wpsz_12 + 2);
                                    rbx_3 |= 0x404;
                                    wpsz_9 = wpsz_12 + 2;
                                }
                                else
                                {
                                    *rbx_3[1] |= 4;
                                    wpsz_9 = wpsz_12 + 1;
                                }
                                
                                goto label_140003f80;
                            }
                        }
                }
            }
            else if (isspace(_C_9))
            {
                format_2 = wpsz_12;
                r15_1 = 1;
            label_140003d09:
                rax_4 = *format_2;
                
                if (rax_4)
                    continue;
                else
                {
                    if (r15_1)
                    {
                        int32_t rax_11;
                        int32_t i_7;
                        
                        do
                        {
                            rax_11 = in_ch(s, &read_in);
                            i_7 = isspace(rax_11);
                        } while (i_7);
                        
                        if (rax_11 != 0xffffffff)
                        {
                            long long unsigned int read_in_8 = read_in - 1;
                            
                            if (!(s->is_string & 1))
                            {
                                ungetc(rax_11, *(s-> + 0));
                                read_in = read_in_8;
                            }
                            else
                            {
                                int64_t back_top_1 = s->back_top;
                                read_in = read_in_8;
                                s->bch[back_top_1] = rax_11;
                                s->back_top = back_top_1 + 1;
                            }
                        }
                    }
                    
                    if (rval != 0xffffffff)
                    {
                        struct gcollect* next_1 = gcollect;
                        wbuf_19 = wbuf;
                        
                        while (next_1)
                        {
                            struct gcollect* next_17 = next_1;
                            next_1 = next_1->next;
                            free(next_17);
                        }
                        
                        gcollect = nullptr;
                        
                        if (strp_1)
                        {
                            free(*strp_1);
                            *strp_1 = 0;
                        }
                        
                        goto label_140003dc4;
                    }
                }
            }
            else
            {
                int32_t _C = in_ch(s, rin_3);
                i_4 = _C;
                
                if (_C != 0xffffffff)
                {
                    int32_t rax_6;
                    
                    if (r15_1)
                        rax_6 = isspace(_C);
                    
                    if (r15_1 && rax_6)
                    {
                        while (true)
                        {
                            int32_t _C_2 = in_ch(s, rin_3);
                            i_4 = _C_2;
                            
                            if (_C_2 == 0xffffffff)
                                break;
                            
                            if (!isspace(_C_2))
                                goto label_140003c53;
                        }
                        
                        if (rval + 1 > 1)
                        {
                            struct gcollect* next_2 = gcollect;
                            
                            while (next_2)
                            {
                                struct gcollect* next_18 = next_2;
                                next_2 = next_2->next;
                                free(next_18);
                            }
                            
                            goto label_140003cbe;
                        }
                    }
                    else
                    {
                    label_140003c53:
                        
                        if (_C_9 == i_4)
                        {
                            r15_1 = 0;
                            format_2 = wpsz_12;
                            goto label_140003d09;
                        }
                        
                        long long unsigned int read_in_4 = read_in - 1;
                        
                        if (!(s->is_string & 1))
                        {
                            ungetc(i_4, *(s-> + 0));
                            read_in = read_in_4;
                        }
                        else
                        {
                            int64_t back_top = s->back_top;
                            read_in = read_in_4;
                            s->bch[back_top] = i_4;
                            s->back_top = back_top + 1;
                        }
                        
                        if (rval != 0xffffffff)
                        {
                            struct gcollect* next = gcollect;
                            
                            while (next)
                            {
                                struct gcollect* next_16 = next;
                                next = next->next;
                                free(next_16);
                            }
                            
                            goto label_140003cbe;
                        }
                    }
                }
                else if (rval + 1 > 1)
                {
                    struct gcollect* next_9 = gcollect;
                    
                    while (next_9)
                    {
                        struct gcollect* next_25 = next_9;
                        next_9 = next_9->next;
                        free(next_25);
                    }
                    
                    goto label_140003cbe;
                }
            }
            
        label_140004230:
            release_ptrs(&gcollect, &wbuf);
            return 0xffffffff;
        }
    }
label_140003cfa:
    return rval;
}

int __mingw_vfscanf(struct _iobuf* s, char const* format, char* argp)
{
    ___chkstk_ms(0x1048);
    struct _IFP ifp;
    __builtin_memset(&ifp, 0, 0x1018);
    *(ifp. + 0) = s;
    int result;
    int80_t st0;
    result = __mingw_sformat(&ifp, format, argp);
    return result;
}

int __mingw_vsscanf(char const* s, char const* format, char* argp)
{
    ___chkstk_ms(0x1048);
    struct _IFP ifp;
    __builtin_memset(&ifp, 0, 0x1018);
    *(ifp. + 0) = s;
    ifp.is_string = 1;
    int result;
    int80_t st0;
    result = __mingw_sformat(&ifp, format, argp);
    return result;
}

int32_t __mingw_vsprintf(char* buf, char const* fmt, char* argv)
{
    int32_t result = __mingw_pformat(0x4000, buf, 0, fmt, argv);
    buf[result] = 0;
    return result;
}

long unsigned int __strtof(char const* s, char** sp)
{
    long unsigned int bits;
    long int expo;
    int rax = __strtodg(s, sp, &fpi0, &expo, &bits);
    uint64_t rdx_1 = rax & 7;
    long unsigned int result;
    
    if (rdx_1 > 5)
        result = 0;
    else
        switch (rdx_1)
        {
            case 0:
            {
                result = 0;
                break;
            }
            case 1:
            case 5:
            {
                result = (expo + 0x96) << 0x17 | (bits & 0x7fffff);
                break;
            }
            case 2:
            {
                result = bits;
                break;
            }
            case 3:
            {
                result = 0x7f800000;
                break;
            }
            case 4:
            {
                result = 0x7fc00000;
                break;
            }
        }
    
    if (rax & 8)
        return result | 0x80000000;
    
    return result;
}

float128 __strtold(char const* src, char** endptr)
{
    union lD ret;
    *(ret + 0) = 0;
    long int expo;
    long unsigned int bits[0x2];
    int rax;
    char** entry_se;
    int128_t result;
    rax = __strtodg(endptr, entry_se, &fpi0, &expo, &bits);
    uint64_t rdx_2 = rax & 7;
    
    if (rdx_2 > 5)
        goto label_140007346;
    
    switch (rdx_2)
    {
        case 0:
        {
            goto label_140007346;
        }
        case 1:
        case 5:
        {
            *(ret + 8) = expo + 0x403e;
        label_14000733e:
            long unsigned int bits_1[0x2] = bits;
            *(ret + 0) = bits_1[0];
            *(ret + 4) = bits_1[1];
        label_140007346:
            
            if (rax & 8)
                *(ret + 8) |= 0x8000;
            break;
        }
        case 2:
        {
            goto label_14000733e;
        }
        case 3:
        {
            *(ret + 6) = 0x7fff8000;
            
            if (rax & 8)
                *(ret + 8) |= 0x8000;
            break;
        }
        case 4:
        {
            *(ret + 6) = 0x7fffc000;
            
            if (rax & 8)
                *(ret + 8) |= 0x8000;
            break;
        }
    }
    
    *src = *(ret + 0);
    return result;
}

char* __pformat_cvt(int mode, float128 val, int nd, int* dp, int* sign)
{
    int64_t* entry_rdx;
    int64_t rax = *entry_rdx;
    int32_t rdx = entry_rdx[1];
    union x;
    *(x + 0) = rax;
    *(x + 8) = rdx;
    int16_t r11 = rdx & 0x7fff;
    int k;
    int rcx_1;
    int be;
    
    if (!r11)
    {
        uint32_t rdx_2 = rax >> 0x20;
        
        if (!(rax | rdx_2))
        {
            be = 0;
            k = 0;
            rcx_1 = rdx & 0x8000;
        }
        else
        {
            if (rdx_2 < 0)
                goto label_1400073c4;
            
            be = -0x403d;
            k = 2;
            rcx_1 = rdx & 0x8000;
        }
    }
    else if (r11 != 0x7fff)
    {
    label_1400073c4:
        be = r11 - 0x403e;
        k = 1;
        rcx_1 = rdx & 0x8000;
    }
    else if (!((rax >> 0x20 & 0x7fffffff) | rax))
    {
        be = 0;
        k = 3;
        rcx_1 = rdx & 0x8000;
    }
    else
    {
        k = 4;
        be = 0;
        rcx_1 = 0;
    }
    
    *sign = rcx_1;
    char* ep;
    return __gdtoa(&fpi, be, &x, &k, mode, nd, dp, &ep);
}

int __pformat_putc(int c, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int16_t flags = stream->flags;
    int count;
    
    if (!(*flags[1] & 0x40))
        count = stream->count;
    
    if (*flags[1] & 0x40 || stream->quota > count)
    {
        void* dest = stream->dest;
        *flags[1] &= 0x20;
        
        if (*flags[1])
        {
            fputc(c, dest);
            int result = stream->count + 1;
            stream->count = result;
            return result;
        }
        
        *(dest + stream->count) = c;
        count = stream->count;
    }
    
    stream->count = count + 1;
    return count + 1;
}

int __pformat_wputchars(short unsigned int const* s, int count, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int count_2 = count;
    struct _Mbstatet state;
    char buf[0x10];
    wcrtomb(&buf, 0, &state);
    int precision = stream->precision;
    int precision_1 = precision;
    
    if (count_2 <= precision)
        precision_1 = count_2;
    
    int width = stream->width;
    
    if (precision >= 0)
        count_2 = precision_1;
    
    int32_t r13;
    
    if (width > count_2)
    {
        int32_t rax_7 = width - count_2;
        stream->width = rax_7;
        
        if (!(*stream->flags[1] & 4))
        {
            stream->width = rax_7 - 1;
            int width_1;
            
            do
            {
                __pformat_putc(0x20, stream);
                width_1 = stream->width;
                stream->width = width_1 - 1;
            } while (width_1);
            r13 = count_2 - 1;
            
            if (count_2 <= 0)
                goto label_1400075ed;
            
            goto label_140007533;
        }
        
        r13 = count_2 - 1;
        
        if (count_2 > 0)
            goto label_140007533;
        
        stream->width -= 1;
    label_1400075f8:
        
        do
        {
            __pformat_putc(0x20, stream);
        label_1400075ed:
            width = stream->width;
            stream->width = width - 1;
        } while (width > 0);
        
        return width;
    }
    
    stream->width = 0xffffffff;
    r13 = count_2 - 1;
    
    if (count_2 <= 0)
        stream->width = 0xfffffffe;
    else
    {
    label_140007533:
        int64_t rsi = 0;
        
        while (true)
        {
            int32_t rax = wcrtomb(&buf, s[rsi], &state);
            
            if (rax <= 0)
                goto label_1400075ed;
            
            char (* r15_1)[0x10] = &buf;
            
            while (true)
            {
                int16_t flags = stream->flags;
                r15_1 = &(*r15_1)[1];
                int count_1;
                
                if (!(*flags[1] & 0x40))
                    count_1 = stream->count;
                
                if (*flags[1] & 0x40 || stream->quota > count_1)
                {
                    int32_t _Character = (*r15_1)[-1];
                    void* dest = stream->dest;
                    *flags[1] &= 0x20;
                    
                    if (!*flags[1])
                    {
                        *(dest + stream->count) = _Character;
                        count_1 = stream->count;
                    }
                    else
                    {
                        fputc(_Character, dest);
                        stream->count += 1;
                        
                        if (r15_1 == &buf[rax - 1 + 1])
                            break;
                        
                        continue;
                    }
                }
                
                stream->count = count_1 + 1;
                
                if (r15_1 == &buf[rax - 1 + 1])
                    break;
            }
            
            rsi += 1;
            
            if (r13 + 1 - rsi <= 0)
                break;
        }
        
        width = stream->width;
        stream->width = width - 1;
        
        if (width > 0)
            goto label_1400075f8;
    }
    
    return width;
}

int __pformat_putchars(char const* s, int count, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int precision = stream->precision;
    int count_3 = count;
    int precision_1 = precision;
    char const* s_1 = s;
    
    if (count <= precision)
        precision_1 = count_3;
    
    int width = stream->width;
    
    if (precision >= 0)
        count_3 = precision_1;
    
    int32_t rdx;
    
    if (width <= count_3)
    {
        stream->width = 0xffffffff;
        rdx = count_3 - 1;
        
        if (count_3)
            goto label_1400076b4;
        
        stream->width = 0xfffffffe;
        return width;
    }
    
    int32_t rax_2 = width - count_3;
    stream->width = rax_2;
    int16_t flags = stream->flags;
    
    if (*flags[1] & 4)
    {
        rdx = count_3 - 1;
        
        if (count_3)
            goto label_1400076ba;
        
        stream->width -= 1;
        goto label_140007721;
    }
    
    stream->width = rax_2 - 1;
    int width_1;
    
    do
    {
        __pformat_putc(0x20, stream);
        width_1 = stream->width;
        stream->width = width_1 - 1;
    } while (width_1);
    rdx = count_3 - 1;
    
    if (count_3)
    {
    label_1400076b4:
        flags = stream->flags;
    label_1400076ba:
        
        while (true)
        {
            s_1 = &s_1[1];
            int count_1;
            
            if (!(*flags[1] & 0x40))
                count_1 = stream->count;
            
            if (*flags[1] & 0x40 || stream->quota > count_1)
            {
                int32_t _Character = s_1[-1];
                void* dest = stream->dest;
                
                if (!(*flags[1] & 0x20))
                {
                    *(dest + stream->count) = _Character;
                    count_1 = stream->count;
                }
                else
                {
                    fputc(_Character, dest);
                    count_1 = stream->count;
                }
            }
            
            stream->count = count_1 + 1;
            
            if (s_1 == &s_1[rdx + 1])
                break;
            
            flags = stream->flags;
        }
    }
    
    while (true)
    {
        width = stream->width;
        stream->width = width - 1;
        
        if (width <= 0)
            return width;
        
        flags = stream->flags;
    label_140007721:
        int count_2;
        
        if (!(*flags[1] & 0x40))
            count_2 = stream->count;
        
        if (*flags[1] & 0x40 || stream->quota > count_2)
        {
            char* dest_1 = stream->dest;
            
            if (!(*flags[1] & 0x20))
            {
                dest_1[stream->count] = 0x20;
                count_2 = stream->count;
            }
            else
            {
                fputc(0x20, dest_1);
                count_2 = stream->count;
            }
        }
        
        stream->count = count_2 + 1;
    }
}

int64_t __pformat_puts(char const* s, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    char const* s_1 = s;
    int64_t precision = stream->precision;
    
    if (!s)
        s_1 = "(null)";
    
    int rax;
    
    if (precision < 0)
        rax = strlen(s_1);
    else
        rax = strnlen(s_1, precision);
    
    /* tailcall */
    return __pformat_putchars(s_1, rax, stream);
}

int64_t __pformat_emit_inf_or_nan(int sign, char* value, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int flags = stream->flags;
    stream->precision = 0xffffffff;
    char buf[0x4];
    char* r9;
    
    if (sign)
    {
        buf[0] = 0x2d;
        r9 = &buf[1];
    }
    else if (flags & 0x100)
    {
        buf[0] = 0x2b;
        r9 = &buf[1];
    }
    else if (!(flags & 0x40))
        r9 = &buf;
    else
    {
        r9 = &buf[1];
        buf[0] = 0x20;
    }
    
    for (int64_t i = 0; i != 3; i += 1)
        r9[i] = (value[i] & 0xdf) | (flags & 0x20);
    
    return __pformat_putchars(&buf, r9 + 3 - &buf, stream);
}

char* __pformat_xint(int fmt, union value, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    void var_78;
    int32_t rax_1;
    char rcx;
    int32_t rdi;
    FILE** entry_stream;
    char r9_1;
    void* result_5;
    int32_t r14;
    int32_t r15;
    
    if (fmt != 0x6f)
    {
        r14 = entry_stream[2];
        int32_t rax = 0;
        rdi = entry_stream[1];
        
        if (r14 >= 0)
            rax = r14;
        
        rax_1 = rax + 0x12;
        
        if (rdi & 0x1000)
        {
            rcx = 4;
            goto label_1400078fe;
        }
        
        r15 = *(entry_stream + 0xc);
        
        if (r15 >= rax_1)
            rax_1 = r15;
        
        int64_t rax_8 = (rax_1 + 0xf) & 0xfffffffffffffff0;
        ___chkstk_ms(rax_8);
        rcx = 4;
        r9_1 = 0xf;
        result_5 = &var_78 - rax_8 + 0x20;
        goto label_140007a05;
    }
    
    r14 = entry_stream[2];
    int32_t rax_21 = 0;
    rdi = entry_stream[1];
    
    if (r14 >= 0)
        rax_21 = r14;
    
    rax_1 = rax_21 + 0x18;
    
    if (rdi & 0x1000)
    {
        rcx = 3;
    label_1400078fe:
        
        if (entry_stream[4])
            rax_1 += rax_1 / 3;
        
        r15 = *(entry_stream + 0xc);
        
        if (r15 >= rax_1)
            rax_1 = r15;
        
        int64_t rax_4 = (rax_1 + 0xf) & 0xfffffffffffffff0;
        ___chkstk_ms(rax_4);
        int64_t r9;
        r9 = fmt != 0x6f;
        result_5 = &var_78 - rax_4 + 0x20;
        r9_1 = (r9 << 3) + 7;
        
        if (stream)
            goto label_140007a15;
        
        goto label_14000795e;
    }
    
    r15 = *(entry_stream + 0xc);
    
    if (r15 >= rax_1)
        rax_1 = r15;
    
    int64_t rax_26 = (rax_1 + 0xf) & 0xfffffffffffffff0;
    ___chkstk_ms(rax_26);
    rcx = 3;
    r9_1 = 7;
    result_5 = &var_78 - rax_26 + 0x20;
label_140007a05:
    char* result;
    int32_t rdx;
    void* result_1;
    int32_t rdi_2;
    int32_t r15_1;
    
    if (!stream)
    {
    label_14000795e:
        entry_stream[1] = rdi & 0xfffff7ff;
        
        if (r14 > 0)
        {
            rdi_2 = r14 - 1;
            result_1 = result_5;
        label_140007974:
            void* result_2 = result_1;
            int64_t _Size = rdi_2 + 1;
            result_1 += _Size;
            memset(result_2, 0x30, _Size);
        label_14000798a:
            
            if (result_1 == result_5 && r14)
                goto label_140007c3c;
            
            goto label_140007996;
        }
        
        result_1 = result_5;
        
        if (!r14)
        {
        label_140007996:
            result = result_1 - result_5;
            rdx = result;
            
            if (result < r15)
                goto label_140007c57;
            
            goto label_1400079a4;
        }
        
    label_140007c3c:
        void* result_3 = result_1 + 1;
        *result_1 = 0x30;
        result_1 = result_3;
        result = result_3 - result_5;
        rdx = result;
        
        if (result >= r15)
        {
        label_1400079a4:
            *(entry_stream + 0xc) = 0xffffffff;
            
            if (fmt == 0x6f)
                goto label_1400079b5;
            
            rdi = entry_stream[1];
        label_140007d1d:
            result = result_1;
            r15_1 = -1;
            
            if (rdi & 0x800)
            {
                *result_1 = fmt;
                result = result_1 + 2;
                r15_1 = -1;
                *(result_1 + 1) = 0x30;
            }
            
            goto label_140007cf8;
        }
        
    label_140007c57:
        rdi = entry_stream[1];
    label_140007c5a:
        r15_1 = r15 - rdx;
        *(entry_stream + 0xc) = r15_1;
        
        if (fmt != 0x6f)
            goto label_140007a8f;
        
        if (r14 >= 0 || (rdi & 0x600) != 0x200)
            goto label_140007aa4;
        
        uint64_t _Size_1 = r15_1;
        memset(result_1, 0x30, _Size_1);
        result = result_1 + _Size_1;
    label_140007c9d:
        r15_1 = -1;
        goto label_140007cf8;
    }
    
label_140007a15:
    result_1 = result_5;
    void* result_4;
    
    do
    {
        result_4 = result_1;
        result_1 += 1;
        char rax_10 = r9_1 & stream;
        char rax_12 = (rax_10 + 0x37) | (fmt & 0x20);
        
        if (rax_10 + 0x30 <= 0x39)
            rax_12 = rax_10 + 0x30;
        
        stream u>>= rcx;
        *(result_1 - 1) = rax_12;
    } while (stream);
    
    if (result_1 == result_5)
        goto label_14000795e;
    
    if (r14 > 0)
    {
        int32_t rdx_2 = result_1 - result_5;
        int32_t rax_14 = r14 - rdx_2;
        
        if (rax_14 > 0)
        {
            rdi_2 = rax_14 - 1;
            goto label_140007974;
        }
        
        if (fmt == 0x6f)
            goto label_140007ca8;
        
        if (rdx_2 >= r15)
            goto label_140007d10;
        
        r15_1 = r15 - rdx_2;
        *(entry_stream + 0xc) = r15_1;
        goto label_140007a8f;
    }
    
    int32_t r13_1;
    
    if (fmt == 0x6f)
    {
    label_140007ca8:
        
        if (rdi & 0x800)
        {
            *result_1 = 0x30;
            result_1 = result_4 + 2;
            goto label_14000798a;
        }
        
        result = result_1 - result_5;
        rdx = result;
        
        if (r15 > result)
            goto label_140007c5a;
        
        *(entry_stream + 0xc) = 0xffffffff;
    label_1400079b5:
        
        if (result_5 < result_1)
        {
            rdi = entry_stream[1];
            r13_1 = -2;
            r15_1 = -1;
        label_140007b00:
            
            while (true)
            {
                result_1 -= 1;
                int32_t rax_16;
                
                if (!(rdi & 0x4000))
                    rax_16 = *(entry_stream + 0x24);
                
                if (!(rdi & 0x4000) && entry_stream[5] <= rax_16)
                    goto label_140007af2;
                
                int32_t _Character = *result_1;
                FILE* _Stream = *entry_stream;
                
                if (!(rdi & 0x2000))
                {
                    *(_Stream + *(entry_stream + 0x24)) = _Character;
                    rax_16 = *(entry_stream + 0x24);
                label_140007af2:
                    result = rax_16 + 1;
                    *(entry_stream + 0x24) = result;
                    
                    if (result_5 >= result_1)
                        break;
                }
                else
                {
                    fputc(_Character, _Stream);
                    result = *(entry_stream + 0x24) + 1;
                    *(entry_stream + 0x24) = result;
                    
                    if (result_5 >= result_1)
                        break;
                }
                
            label_140007afd:
                rdi = entry_stream[1];
            }
            
            if (r15_1 > 0)
            {
                while (true)
                {
                    rdi = entry_stream[1];
                label_140007b5a:
                    int32_t rax_19;
                    
                    if (!(rdi & 0x4000))
                        rax_19 = *(entry_stream + 0x24);
                    
                    if (rdi & 0x4000 || entry_stream[5] > rax_19)
                    {
                        char* _Stream_1 = *entry_stream;
                        
                        if (!(rdi & 0x2000))
                        {
                            _Stream_1[*(entry_stream + 0x24)] = 0x20;
                            rax_19 = *(entry_stream + 0x24);
                        }
                        else
                        {
                            fputc(0x20, _Stream_1);
                            result = *(entry_stream + 0x24) + 1;
                            *(entry_stream + 0x24) = result;
                            int32_t temp1_1 = r13_1;
                            r13_1 -= 1;
                            
                            if (temp1_1 < 1)
                                return result;
                            
                            continue;
                        }
                    }
                    
                    result = rax_19 + 1;
                    *(entry_stream + 0x24) = result;
                    int32_t temp2_1 = r13_1;
                    r13_1 -= 1;
                    
                    if (temp2_1 < 1)
                        return result;
                }
            }
        }
    }
    else
    {
        int32_t rax_23 = result_1 - result_5;
        
        if (rax_23 >= r15)
        {
        label_140007d10:
            *(entry_stream + 0xc) = 0xffffffff;
            goto label_140007d1d;
        }
        
        r15_1 = r15 - rax_23;
        *(entry_stream + 0xc) = r15_1;
    label_140007a8f:
        
        if (!(rdi & 0x800))
        {
            if (r14 >= 0 || (rdi & 0x600) != 0x200)
                goto label_140007aa4;
            
        label_140007d6b:
            uint64_t _Size_2 = r15_1;
            memset(result_1, 0x30, _Size_2);
            result = result_1 + _Size_2;
            
            if (!(rdi & 0x800))
                goto label_140007c9d;
            
            *result = fmt;
            r15_1 = -1;
            result = &result[2];
            result[-1] = 0x30;
            goto label_140007cf8;
        }
        
        r15_1 -= 2;
        
        if (r15_1 > 0)
        {
            if (r14 < 0 && (rdi & 0x600) == 0x200)
                goto label_140007d6b;
            
            *result_1 = fmt;
            result_1 += 2;
            *(result_1 - 1) = 0x30;
        label_140007aa4:
            r13_1 = r15_1 - 1;
            
            if (rdi & 0x400)
            {
                if (result_5 >= result_1)
                    goto label_140007b5a;
                
                goto label_140007b00;
            }
            
            r15_1 = r13_1;
            int32_t i;
            
            do
            {
                result = __pformat_putc(0x20, entry_stream);
                i = r15_1;
                r15_1 -= 1;
            } while (i >= 1);
            r13_1 = -2;
            
            if (result_5 < result_1)
                goto label_140007afd;
        }
        else
        {
            *result_1 = fmt;
            result = result_1 + 2;
            *(result_1 + 1) = 0x30;
        label_140007cf8:
            
            if (result_5 < result)
            {
                rdi = entry_stream[1];
                r13_1 = r15_1 - 1;
                result_1 = result;
                goto label_140007b00;
            }
        }
    }
    return result;
}

int64_t __pformat_int(union value, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int32_t _Size_5 = 0;
    char** entry_stream;
    int32_t _Size_4 = entry_stream[2];
    int32_t rdi = entry_stream[1];
    
    if (_Size_4 >= 0)
        _Size_5 = _Size_4;
    
    int32_t rax = _Size_5 + 0x17;
    
    if (rdi & 0x1000 && entry_stream[4])
        rax += rax / 3;
    
    int32_t rsi = *(entry_stream + 0xc);
    
    if (rsi >= rax)
        rax = rsi;
    
    int64_t rax_3 = (rax + 0xf) & 0xfffffffffffffff0;
    ___chkstk_ms(rax_3);
    
    if (!(rdi & 0x80))
        goto label_140007e43;
    
    void var_68;
    void* r13_1;
    int32_t _Size_3;
    
    if (stream < 0)
    {
        stream = -(stream);
    label_140007e59:
        void* r8 = &var_68 - rax_3 + 0x20;
        
        while (true)
        {
            if (&var_68 - rax_3 + 0x20 != r8 && rdi & 0x1000 && entry_stream[4]
                && ((r8 - (&var_68 - rax_3 + 0x20)) & 0x8000000000000003) == 3)
            {
                *r8 = 0x2c;
                r8 += 1;
            }
            
            r13_1 = r8 + 1;
            uint64_t stream_1 = stream / 0xa;
            *r8 = stream - (stream_1 + (stream_1 << 2)) * 2 + 0x30;
            
            if (stream <= 9)
                break;
            
            stream = stream_1;
            r8 = r13_1;
        }
        
        if (_Size_4 <= 0)
            goto label_140007f03;
        
        _Size_3 = _Size_4 - (r13_1 - (&var_68 - rax_3 + 0x20));
        
        if (_Size_3 > 0)
            goto label_140007eea;
        
        if (&var_68 - rax_3 + 0x20 == r13_1)
        {
            void* rax_22 = &var_68 - rax_3 + 0x20;
            *rax_22 = 0x30;
            r13_1 = rax_22 + 1;
        }
    }
    else
    {
        rdi &= 0x7f;
        entry_stream[1] = rdi;
    label_140007e43:
        
        if (stream)
            goto label_140007e59;
        
        r13_1 = &var_68 - rax_3 + 0x20;
        _Size_3 = _Size_4;
        bool rax_11 = true;
        
        if (_Size_4 > 0)
        {
        label_140007eea:
            int64_t _Size_1 = _Size_3;
            void* rcx = r13_1;
            r13_1 += _Size_1;
            memset(rcx, 0x30, _Size_1);
        label_140007f03:
            rax_11 = &var_68 - rax_3 + 0x20 == r13_1;
        }
        
        if (_Size_4 && rax_11)
        {
            *r13_1 = 0x30;
            r13_1 += 1;
        }
    }
    
    if (rsi > 0)
    {
        int32_t rsi_1 = rsi - (r13_1 - (&var_68 - rax_3 + 0x20));
        *(entry_stream + 0xc) = rsi_1;
        
        if (rsi_1 > 0)
        {
            if (!(rdi & 0x1c0))
            {
                if (_Size_4 < 0 && (rdi & 0x600) == 0x200)
                    goto label_1400080e1;
                
                goto label_140007f3b;
            }
            
            *(entry_stream + 0xc) = rsi_1 - 1;
            
            if (_Size_4 >= 0 || (rdi & 0x600) != 0x200)
            {
            label_140007f3b:
                
                if (!(rdi & 0x400))
                {
                    int32_t rax_25 = *(entry_stream + 0xc);
                    *(entry_stream + 0xc) = rax_25 - 1;
                    
                    if (rax_25 > 0)
                    {
                        int32_t i;
                        
                        do
                        {
                            __pformat_putc(0x20, entry_stream);
                            i = *(entry_stream + 0xc);
                            *(entry_stream + 0xc) = i - 1;
                        } while (i > 0);
                        rdi = entry_stream[1];
                    }
                }
            }
            else
            {
            label_1400080e1:
                int32_t _Size_2 = *(entry_stream + 0xc);
                *(entry_stream + 0xc) = _Size_2 - 1;
                
                if (_Size_2 > 0)
                {
                    uint64_t _Size = _Size_2;
                    void* rcx_2 = r13_1;
                    r13_1 += _Size;
                    memset(rcx_2, 0x30, _Size);
                    *(entry_stream + 0xc) = 0xffffffff;
                }
            }
        }
    }
    
    void* rsi_2;
    
    if (rdi & 0x80)
    {
        *r13_1 = 0x2d;
        rsi_2 = r13_1 + 1;
    }
    else if (!(rdi & 0x100))
    {
        rsi_2 = r13_1;
        
        if (rdi & 0x40)
        {
            *r13_1 = 0x20;
            rsi_2 += 1;
        }
    }
    else
    {
        *r13_1 = 0x2b;
        rsi_2 = r13_1 + 1;
    }
    
    if (&var_68 - rax_3 + 0x20 < rsi_2)
    {
        while (true)
        {
            rsi_2 -= 1;
            int32_t rax_17;
            
            if (!(rdi & 0x4000))
                rax_17 = *(entry_stream + 0x24);
            
            if (!(rdi & 0x4000) && entry_stream[5] <= rax_17)
                goto label_140007f7d;
            
            int32_t _Character = *rsi_2;
            FILE* _Stream = *entry_stream;
            
            if (!(rdi & 0x2000))
            {
                *(_Stream + *(entry_stream + 0x24)) = _Character;
                rax_17 = *(entry_stream + 0x24);
            label_140007f7d:
                *(entry_stream + 0x24) = rax_17 + 1;
                
                if (&var_68 - rax_3 + 0x20 == rsi_2)
                    break;
            }
            else
            {
                fputc(_Character, _Stream);
                *(entry_stream + 0x24) += 1;
                
                if (&var_68 - rax_3 + 0x20 == rsi_2)
                    break;
            }
            
            rdi = entry_stream[1];
        }
    }
    
    int32_t result = *(entry_stream + 0xc);
    
    while (true)
    {
        int32_t result_1 = result;
        result -= 1;
        *(entry_stream + 0xc) = result;
        
        if (result_1 <= 0)
            break;
        
        int16_t rcx_1 = entry_stream[1];
        int32_t rdx_1;
        
        if (!(*rcx_1[1] & 0x40))
            rdx_1 = *(entry_stream + 0x24);
        
        if (*rcx_1[1] & 0x40 || entry_stream[5] > rdx_1)
        {
            char* _Stream_1 = *entry_stream;
            *rcx_1[1] &= 0x20;
            
            if (!*rcx_1[1])
            {
                _Stream_1[*(entry_stream + 0x24)] = 0x20;
                rdx_1 = *(entry_stream + 0x24);
                result = *(entry_stream + 0xc);
            }
            else
            {
                fputc(0x20, _Stream_1);
                rdx_1 = *(entry_stream + 0x24);
                result = *(entry_stream + 0xc);
            }
        }
        
        *(entry_stream + 0x24) = rdx_1 + 1;
    }
    
    return result;
}

int64_t __pformat_emit_radix_point(struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    struct _Mbstatet state;
    short unsigned int rpchr_1;
    
    if (stream->rplen == 0xfffffffd)
    {
        __builtin_memset(&state, 0, 8);
        short unsigned int rpchr;
        int rax_9 = mbrtowc(&rpchr, *localeconv(), 0x10, &state);
        
        if (rax_9 <= 0)
            rpchr_1 = stream->rpchr;
        else
        {
            rpchr_1 = rpchr;
            stream->rpchr = rpchr_1;
        }
        
        stream->rplen = rax_9;
    }
    else
        rpchr_1 = stream->rpchr;
    
    if (!rpchr_1)
        return __pformat_putc(0x2e, stream);
    
    int64_t rax_3 = (stream->rplen + 0xf) & 0xfffffffffffffff0;
    ___chkstk_ms(rax_3);
    __builtin_memset(&state, 0, 8);
    void var_58;
    char* rsi = &var_58 - rax_3 + 0x20;
    int32_t rax_4 = wcrtomb(rsi, rpchr_1, &state);
    
    if (rax_4 <= 0)
        return __pformat_putc(0x2e, stream);
    
    void* r12_1 = &rsi[rax_4 - 1 + 1];
    int result;
    
    while (true)
    {
        int16_t flags = stream->flags;
        rsi = &rsi[1];
        int count;
        
        if (!(*flags[1] & 0x40))
            count = stream->count;
        
        if (*flags[1] & 0x40 || stream->quota > count)
        {
            int32_t _Character = rsi[-1];
            FILE* dest = stream->dest;
            *flags[1] &= 0x20;
            
            if (!*flags[1])
            {
                *(dest + stream->count) = _Character;
                count = stream->count;
            }
            else
            {
                fputc(_Character, dest);
                result = stream->count + 1;
                stream->count = result;
                
                if (r12_1 == rsi)
                    break;
                
                continue;
            }
        }
        
        result = count + 1;
        stream->count = result;
        
        if (r12_1 == rsi)
            break;
    }
    
    return result;
}

int __pformat_emit_float(int sign, char* value, int len, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int width = stream->width;
    char* value_1 = value;
    int rsi = len;
    int32_t rax;
    int32_t i_2;
    int precision_3;
    
    if (len <= 0)
    {
        if (width > 0)
        {
            precision_3 = stream->precision;
            rax = width - 1;
            
            if (rax <= precision_3)
                goto label_140008457;
            
        label_14000830c:
            i_2 = rax - precision_3;
            stream->width = i_2;
            
            if (precision_3 > 0)
                goto label_140008319;
            
            int16_t flags_1 = stream->flags;
            
            if (*flags_1[1] & 8)
                goto label_140008319;
            
            if (rsi <= 0)
                goto label_140008334;
            
            *flags_1[1] &= 0x10;
            
            if (!*flags_1[1])
                goto label_140008334;
            
            if (!stream->thousands_chr)
                goto label_140008330;
            
            goto label_1400085be;
        }
        
        int flags;
        
        if (width)
        {
        label_140008457:
            stream->width = 0xffffffff;
            
            if (!sign)
            {
            label_14000837c:
                flags = stream->flags;
            label_14000837f:
                
                if (*flags[1] & 1)
                    __pformat_putc(0x2b, stream);
                else if (flags & 0x40)
                    __pformat_putc(0x20, stream);
            }
            else
                __pformat_putc(0x2d, stream);
        }
        else
        {
            int precision_2 = stream->precision;
            
            if (precision_2 >= 0)
                goto label_140008457;
            
            i_2 = -(precision_2);
            stream->width = i_2;
            
            if (*stream->flags[1] & 8)
            {
            label_140008319:
                i_2 -= 1;
                stream->width = i_2;
                
                if (rsi <= 0 || !(*stream->flags[1] & 0x10) || !stream->thousands_chr)
                    goto label_140008330;
                
                goto label_1400085be;
            }
            
        label_140008334:
            int rax_4;
            
            if (sign)
            {
                stream->width = i_2 - 1;
                
                if (i_2 != 1 && !(stream->flags & 0x600))
                {
                label_140008533:
                    rax_4 = i_2 - 2;
                    goto label_140008536;
                }
                
                __pformat_putc(0x2d, stream);
            }
            else
            {
                flags = stream->flags;
                
                if (flags & 0x1c0)
                {
                    stream->width = i_2 - 1;
                    
                    if (i_2 == 1 || *flags[1] & 6)
                        goto label_14000837f;
                    
                    goto label_140008533;
                }
                
                *flags[1] &= 6;
                
                if (!*flags[1])
                {
                    rax_4 = i_2 - 1;
                label_140008536:
                    stream->width = rax_4;
                    int width_2;
                    
                    do
                    {
                        __pformat_putc(0x20, stream);
                        width_2 = stream->width;
                        stream->width = width_2 - 1;
                    } while (width_2 > 0);
                    goto label_140008373;
                }
            }
        }
    }
    else
    {
        if (len <= width)
        {
            precision_3 = stream->precision;
            rax = width - len;
            
            if (rax > precision_3)
                goto label_14000830c;
            
            stream->width = 0xffffffff;
            i_2 = -1;
            
            if (*stream->flags[1] & 0x10 && stream->thousands_chr)
                goto label_1400085be;
            
        label_140008330:
            
            if (i_2 <= 0)
                goto label_140008373;
            
            goto label_140008334;
        }
        
        stream->width = 0xffffffff;
        
        if (*stream->flags[1] & 0x10 && stream->thousands_chr)
        {
            i_2 = -1;
        label_1400085be:
            int32_t i = i_2;
            uint32_t r8_3 = (rsi + 2) / 3;
            
            if (r8_3 == 1)
                goto label_140008330;
            
            while (i > 0)
            {
                i -= 1;
                stream->width = i;
                
                if (r8_3 - 1 - i_2 == -(i))
                {
                    i_2 = i;
                    goto label_140008330;
                }
            }
            
            goto label_140008373;
        }
        
    label_140008373:
        
        if (!sign)
            goto label_14000837c;
        
        __pformat_putc(0x2d, stream);
    }
    int width_1 = stream->width;
    
    if (width_1 > 0 && (stream->flags & 0x600) == 0x200)
    {
        stream->width = width_1 - 1;
        int width_3;
        
        do
        {
            __pformat_putc(0x30, stream);
            width_3 = stream->width;
            stream->width = width_3 - 1;
        } while (width_3 > 0);
    }
    
    int precision;
    
    if (rsi <= 0)
    {
        __pformat_putc(0x30, stream);
        precision = stream->precision;
        
        if (precision <= 0 && !(*stream->flags[1] & 8))
        {
            if (rsi)
                goto label_1400084f9;
            
            stream->precision = precision - 1;
            return precision - 1;
        }
        
    label_1400084eb:
        __pformat_emit_radix_point(stream);
        
        if (rsi)
        {
            precision = stream->precision;
        label_1400084f9:
            stream->precision = precision + rsi;
            int i_1;
            
            do
            {
                __pformat_putc(0x30, stream);
                i_1 = rsi;
                rsi += 1;
            } while (i_1 != 0xffffffff);
        }
    }
    else
    {
        while (true)
        {
            char c_2 = *value_1;
            int32_t c = 0x30;
            
            if (c_2)
            {
                value_1 = &value_1[1];
                c = c_2;
            }
            
            __pformat_putc(c, stream);
            int temp2_1 = rsi;
            rsi -= 1;
            
            if (temp2_1 == 1)
                break;
            
            if (*stream->flags[1] & 0x10 && stream->thousands_chr && rsi * 0xaaaaaaab <= 0x55555555)
                __pformat_wputchars(&stream->thousands_chr, 1, stream);
        }
        
        precision = stream->precision;
        
        if (precision <= 0)
        {
            if (*stream->flags[1] & 8)
                goto label_1400084eb;
            
            stream->precision = precision - 1;
            return precision - 1;
        }
        
        __pformat_emit_radix_point(stream);
    }
    int precision_1;
    
    while (true)
    {
        precision_1 = stream->precision;
        stream->precision = precision_1 - 1;
        
        if (precision_1 <= 0)
            break;
        
        char c_3 = *value_1;
        int c_1 = 0x30;
        
        if (c_3)
        {
            value_1 = &value_1[1];
            c_1 = c_3;
        }
        
        __pformat_putc(c_1, stream);
    }
    
    return precision_1;
}

int64_t __pformat_emit_efloat(int sign, char* value, int e, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int expmin_1 = 1;
    int64_t rsi = e - 1;
    int32_t r8_1 = (e - 1) >> 0x1f;
    int32_t rcx_1 = (rsi * 0x66666667) >> 0x22;
    int32_t rcx_2 = rcx_1 - r8_1;
    
    if (rcx_1 != r8_1)
    {
        int32_t rax_3;
        int32_t rcx_3;
        
        do
        {
            rcx_3 = rcx_2 >> 0x1f;
            expmin_1 += 1;
            rax_3 = (rcx_2 * 0x66666667) >> 0x22;
            rcx_2 s/= 0xa;
        } while (rax_3 != rcx_3);
    }
    
    int expmin = stream->expmin;
    
    if (expmin == 0xffffffff)
    {
        stream->expmin = 2;
        expmin = 2;
    }
    
    int width = stream->width;
    
    if (expmin_1 >= expmin)
        expmin = expmin_1;
    
    int rax_6 = width - (expmin + 2);
    
    if (width <= expmin + 2)
        rax_6 = -1;
    
    stream->width = rax_6;
    __pformat_emit_float(sign, value, 1, stream);
    int flags = stream->flags;
    stream->precision = stream->expmin;
    stream->flags = flags | 0x1c0;
    __pformat_putc((flags & 0x20) | 0x45, stream);
    stream->width += expmin + 1;
    /* tailcall */
    return __pformat_int(rsi);
}

int64_t __pformat_efloat(float128 x, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int precision = stream->precision;
    int80_t* entry_rcx;
    int80_t x87_r7 = *entry_rcx;
    int nd;
    
    if (precision < 0)
    {
        stream->precision = 6;
        nd = 7;
    }
    else
        nd = precision + 1;
    
    int80_t var_38 = x87_r7;
    int sign;
    int intlen;
    float128 entry_val;
    char* rax = __pformat_cvt(2, entry_val, nd, &intlen, &sign);
    int e = intlen;
    
    if (e == 0xffff8000)
    {
        __pformat_emit_inf_or_nan(sign, rax, stream);
        return __freedtoa(rax);
    }
    
    __pformat_emit_efloat(sign, rax, e, stream);
    return __freedtoa(rax);
}

int64_t __pformat_float(float128 x, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int precision = stream->precision;
    int80_t* entry_rcx;
    int80_t x87_r7 = *entry_rcx;
    
    if (precision < 0)
    {
        stream->precision = 6;
        precision = 6;
    }
    
    int80_t var_38 = x87_r7;
    int sign;
    int intlen;
    float128 entry_val;
    char* rax = __pformat_cvt(3, entry_val, precision, &intlen, &sign);
    int len = intlen;
    
    if (len == 0xffff8000)
        __pformat_emit_inf_or_nan(sign, rax, stream);
    else
    {
        __pformat_emit_float(sign, rax, len, stream);
        int width = stream->width;
        
        while (true)
        {
            int width_1 = width;
            width -= 1;
            stream->width = width;
            
            if (width_1 <= 0)
                break;
            
            int16_t flags = stream->flags;
            int count;
            
            if (!(*flags[1] & 0x40))
                count = stream->count;
            
            if (*flags[1] & 0x40 || stream->quota > count)
            {
                void* dest = stream->dest;
                *flags[1] &= 0x20;
                
                if (!*flags[1])
                {
                    *(dest + stream->count) = 0x20;
                    count = stream->count;
                    width = stream->width;
                }
                else
                {
                    fputc(0x20, dest);
                    count = stream->count;
                    width = stream->width;
                }
            }
            
            stream->count = count + 1;
        }
    }
    
    return __freedtoa(rax);
}

int64_t __pformat_gfloat(float128 x, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    int precision_1 = stream->precision;
    int80_t* entry_rcx;
    int80_t x87_r7 = *entry_rcx;
    
    if (precision_1 < 0)
    {
        stream->precision = 6;
        precision_1 = 6;
    }
    else if (!precision_1)
    {
        stream->precision = 1;
        precision_1 = 1;
    }
    
    int80_t var_48 = x87_r7;
    int sign;
    int intlen;
    float128 entry_val;
    char* rax = __pformat_cvt(2, entry_val, precision_1, &intlen, &sign);
    int intlen_1 = intlen;
    
    if (intlen_1 == 0xffff8000)
        __pformat_emit_inf_or_nan(sign, rax, stream);
    else
    {
        int32_t rax_2 = stream->flags & 0x800;
        int precision;
        
        if (intlen_1 >= 0xfffffffd)
            precision = stream->precision;
        
        if (intlen_1 < 0xfffffffd || intlen_1 > precision)
        {
            int rax_4;
            
            if (rax_2)
                rax_4 = stream->precision - 1;
            else
                rax_4 = strlen(rax) - 1;
            
            stream->precision = rax_4;
            __pformat_emit_efloat(sign, rax, intlen_1, stream);
        }
        else
        {
            if (!rax_2)
            {
                int32_t rax_7 = strlen(rax);
                int rax_8 = rax_7 - intlen_1;
                stream->precision = rax_8;
                
                if (rax_7 - intlen_1 < 0)
                {
                    int width_1 = stream->width;
                    
                    if (width_1 > 0)
                        stream->width = rax_8 + width_1;
                }
            }
            else
                stream->precision = precision - intlen_1;
            
            __pformat_emit_float(sign, rax, intlen_1, stream);
            
            while (true)
            {
                int width = stream->width;
                stream->width = width - 1;
                
                if (width <= 0)
                    break;
                
                __pformat_putc(0x20, stream);
            }
        }
    }
    
    return __freedtoa(rax);
}

int64_t __pformat_emit_xfloat(union value, struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota; int expmin; }* stream)
{
    struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr;
         __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr;
         __padding char _22[0x2];int count; int quota; int expmin; }* entry_stream;
    int precision_4 = entry_stream->precision;
    struct { void* dest; int flags; int width; int precision; int rplen; short unsigned int rpchr;
         __padding char _1a[0x2];int thousands_chr_len; short unsigned int thousands_chr;
         __padding char _22[0x2];int count; int quota; int expmin; }* stream_1 = stream;
    int16_t entry_rdx;
    int32_t i_3;
    int64_t rdx_1;
    int16_t r8;
    int flags;
    int64_t r12;
    
    if (entry_rdx || stream)
    {
        r8 = entry_rdx - 3;
        
        if (precision_4 > 0xe)
        {
            r12 = r8;
            i_3 = 0x10;
            
            if (!stream_1 && precision_4 <= 0)
            {
                flags = entry_stream->flags;
                goto label_140008bd1;
            }
            
            goto label_140008abd;
        }
        
        uint64_t r9 = stream_1 >> 1;
        int64_t rdx = 4 << (0xe - precision_4) << 2;
        rdx_1 = rdx + r9;
        
        if (rdx + r9 >= 0)
        {
            r12 = r8;
            goto label_140008bb9;
        }
        
        r8 = entry_rdx + 1;
        r12 = r8;
        stream_1 = rdx_1 >> 3 >> (0xf - precision_4) << 2;
    label_140008b7c:
        i_3 = precision_4 + 1;
        goto label_140008abd;
    }
    
    if (precision_4 <= 0xe)
    {
        r12 = 0;
        r8 = 0;
        rdx_1 = 4 << (0xe - precision_4) << 2;
    label_140008bb9:
        struct { void* dest; int flags; int width; int precision; int rplen;
             short unsigned int rpchr; __padding char _1a[0x2];int thousands_chr_len;
             short unsigned int thousands_chr; __padding char _22[0x2];int count; int quota;
             int expmin; }* stream_2 = (rdx_1 * 2) >> (0xf - precision_4) << 2;
        stream_1 = stream_2;
        
        if (stream_2 || precision_4)
            goto label_140008b7c;
        
        flags = entry_stream->flags;
        goto label_140008bd1;
    }
    
    char buf[0x18];
    char (* i_1)[0x18];
    int width_3;
    int32_t r13_3;
    
    if (precision_4 > 0)
    {
        r12 = 0;
        r8 = 0;
        stream_1 = nullptr;
        i_3 = 0x10;
    label_140008abd:
        flags = entry_stream->flags;
        i_1 = &buf;
        int32_t i;
        
        do
        {
            int32_t rax_3 = stream_1 & 0xf;
            char (* i_2)[0x18];
            
            if (i_3 != 1)
            {
                int precision_1 = entry_stream->precision;
                
                if (precision_1 > 0)
                    entry_stream->precision = precision_1 - 1;
                
                i_2 = i_1;
                goto label_140008b25;
            }
            
            int precision_2;
            
            if (&buf >= i_1 && !(flags & 0x800))
                precision_2 = entry_stream->precision;
            
            if (&buf >= i_1 && !(flags & 0x800) && precision_2 <= 0)
            {
                if (rax_3)
                {
                    i_2 = i_1;
                    goto label_140008b29;
                }
                
                if (!precision_2)
                {
                    *i_1 = 0x30;
                    i_1 = &(*i_1)[1];
                }
                
                break;
            }
            
            *i_1 = 0x2e;
            i_2 = &(*i_1)[1];
        label_140008b25:
            
            if (rax_3)
            {
            label_140008b29:
                
                if (rax_3 <= 9)
                    goto label_140008af0;
                
                *i_2 = (rax_3 + 0x37) | (flags & 0x20);
                i_1 = &(*i_2)[1];
            }
            else if (&buf < i_2 || entry_stream->precision >= 0)
            {
            label_140008af0:
                *i_2 = rax_3 + 0x30;
                i_1 = &(*i_2)[1];
            }
            else
                i_1 = i_2;
            
            stream_1 u>>= 4;
            i = i_3;
            i_3 -= 1;
        } while (i != 1);
        
        if (i_1 == &buf)
        {
            if (entry_stream->precision > 0)
                goto label_140008bdd;
            
            goto label_140008bd1;
        }
        
        width_3 = entry_stream->width;
        r13_3 = 2;
        
        if (width_3 <= 0)
            goto label_140008bff;
        
        goto label_140008d0c;
    }
    
    flags = entry_stream->flags;
    r12 = 0;
    r8 = 0;
label_140008bd1:
    char* rax_5 = &buf;
    
    if (!(flags & 0x800))
        goto label_140008be5;
    
label_140008bdd:
    buf[0] = 0x2e;
    rax_5 = &buf[1];
label_140008be5:
    width_3 = entry_stream->width;
    *rax_5 = 0x30;
    i_1 = &rax_5[1];
    r13_3 = 2;
    
    if (width_3 <= 0)
        goto label_140008bff;
    
label_140008d0c:
    int precision_3 = entry_stream->precision;
    int32_t rcx_13 = i_1 - &buf;
    
    if (precision_3 > 0)
        rcx_13 += precision_3;
    
    int32_t rcx_14 = rcx_13 + 6;
    int32_t rax_8 = r8 >> 0x1f;
    int32_t r11_4 = rcx_14;
    int32_t r8_3 = (r8 * 0x66666667) >> 0x22;
    int32_t r8_4 = r8_3 - rax_8;
    
    if (r8_3 != rax_8)
    {
        int32_t rax_11;
        int32_t rdx_13;
        
        do
        {
            r11_4 += 1;
            rdx_13 = r8_4 >> 0x1f;
            rax_11 = (r8_4 * 0x66666667) >> 0x22;
            r8_4 s/= 0xa;
        } while (rax_11 != rdx_13);
        r13_3 = r11_4 - rcx_14 + 2;
    }
    
    int r9_1;
    
    if (width_3 <= r11_4)
    {
        r9_1 = -1;
    label_140008e76:
        entry_stream->width = r9_1;
    label_140008bff:
        
        if (flags & 0x80)
            __pformat_putc(0x2d, entry_stream);
        else
        {
        label_140008c09:
            
            if (flags & 0x100)
                __pformat_putc(0x2b, entry_stream);
            else if (flags & 0x40)
                __pformat_putc(0x20, entry_stream);
        }
    }
    else
    {
        r9_1 = width_3 - r11_4;
        
        if (flags & 0x600)
            goto label_140008e76;
        
        entry_stream->width = r9_1 - 1;
        int width_2;
        
        do
        {
            __pformat_putc(0x20, entry_stream);
            width_2 = entry_stream->width;
            entry_stream->width = width_2 - 1;
        } while (width_2 > 0);
        flags = entry_stream->flags;
        
        if (!(flags & 0x80))
            goto label_140008c09;
        
        __pformat_putc(0x2d, entry_stream);
    }
    __pformat_putc(0x30, entry_stream);
    __pformat_putc((entry_stream->flags & 0x20) | 0x58, entry_stream);
    int width = entry_stream->width;
    
    if (width > 0 && *entry_stream->flags[1] & 2)
    {
        entry_stream->width = width - 1;
        int width_1;
        
        do
        {
            __pformat_putc(0x30, entry_stream);
            width_1 = entry_stream->width;
            entry_stream->width = width_1 - 1;
        } while (width_1 > 0);
    }
    
    if (&buf < i_1)
    {
        do
        {
            int32_t c = (*i_1)[-1];
            i_1 -= 1;
            
            if (c == 0x2e)
                __pformat_emit_radix_point(entry_stream);
            else if (c == 0x2c)
            {
                short unsigned int thousands_chr = entry_stream->thousands_chr;
                short unsigned int wcs = thousands_chr;
                
                if (thousands_chr)
                    __pformat_wputchars(&wcs, 1, entry_stream);
            }
            else
                __pformat_putc(c, entry_stream);
        } while (i_1 != &buf);
    }
    
    while (true)
    {
        int precision = entry_stream->precision;
        entry_stream->precision = precision - 1;
        
        if (precision <= 0)
            break;
        
        __pformat_putc(0x30, entry_stream);
    }
    
    __pformat_putc((entry_stream->flags & 0x20) | 0x50, entry_stream);
    entry_stream->width += r13_3;
    entry_stream->flags |= 0x1c0;
    /* tailcall */
    return __pformat_int(value, r12);
}

int32_t __mingw_pformat(int flags, void* dest, int max, char const* fmt, char* argv)
{
    char* argv_1 = argv;
    int32_t* rax;
    float128 x;
    rax = _errno();
    int32_t rdi_1 = flags & 0x6000;
    struct stream;
    stream.quota = max;
    stream.rpchr = 0;
    int32_t _ErrorMessage = *rax;
    stream.precision = 0xffffffff;
    stream.rplen = 0xfffffffd;
    stream.thousands_chr = 0;
    int32_t _Character = *fmt;
    stream.dest = dest;
    stream.flags = rdi_1;
    char _Character_1 = _Character;
    stream.width = 0xffffffff;
    stream.thousands_chr_len = 0;
    stream.count = 0;
    stream.expmin = 0xffffffff;
    
    if (!_Character)
        return _Character;
    
    void* r15_1 = &fmt[1];
    
    do
    {
        if (_Character != 0x25)
        {
            int16_t flags_1 = stream.flags;
            int count_1 = stream.count;
            
            if (*flags_1[1] & 0x40 || stream.quota > count_1)
            {
                FILE* dest_1 = stream.dest;
                
                if (*flags_1[1] & 0x20)
                    x = fputc(_Character, dest_1);
                else
                    *(dest_1 + count_1) = _Character_1;
            }
            
            stream.count = count_1 + 1;
        }
        else
        {
            char fmt_2 = *r15_1;
            stream.flags = rdi_1;
            stream.width = 0xffffffff;
            stream.precision = 0xffffffff;
            
            if (!fmt_2)
                break;
            
            int* r10_1 = &stream.width;
            void* rsi_2 = r15_1;
            int32_t r11_1 = 0;
            int32_t rbx_2 = 0;
            
            while (true)
            {
                int32_t fmt_1 = fmt_2;
                struct _Mbstatet cstate;
                int flags_2;
                uint64_t* rdx_7;
                double rdx_11;
                double rdx_13;
                double rdx_15;
                void* argv_2;
                void* argv_3;
                
                if (fmt_2 - 0x20 > 0x5a)
                {
                label_140009063:
                    
                    if (fmt_2 - 0x30 > 9 || rbx_2 > 3)
                    {
                    label_140009273:
                        x = __pformat_putc(0x25, &stream);
                        break;
                        break;
                    }
                    
                    if (rbx_2)
                        goto label_14000974f;
                    
                    rbx_2 = 1;
                label_140009082:
                    
                    if (!r10_1)
                    {
                        fmt_2 = *(rsi_2 + 1);
                        rsi_2 += 1;
                    }
                    else
                    {
                        uint64_t rax_6 = *r10_1;
                        
                        if (rax_6 < 0)
                        {
                            fmt_2 = *(rsi_2 + 1);
                            rsi_2 += 1;
                            *r10_1 = fmt_1 - 0x30;
                        }
                        else
                        {
                            *r10_1 = fmt_1 + ((rax_6 * 5) << 1) - 0x30;
                            fmt_2 = *(rsi_2 + 1);
                            rsi_2 += 1;
                        }
                    }
                }
                else
                    switch (fmt_2)
                    {
                        case 0x20:
                        {
                            if (rbx_2)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                rsi_2 += 1;
                            }
                            else
                            {
                                fmt_2 = *(rsi_2 + 1);
                                stream.flags |= 0x40;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x21:
                        case 0x22:
                        case 0x24:
                        case 0x26:
                        case 0x28:
                        case 0x29:
                        case 0x2c:
                        case 0x2f:
                        case 0x31:
                        case 0x32:
                        case 0x33:
                        case 0x34:
                        case 0x35:
                        case 0x36:
                        case 0x37:
                        case 0x38:
                        case 0x39:
                        case 0x3a:
                        case 0x3b:
                        case 0x3c:
                        case 0x3d:
                        case 0x3e:
                        case 0x3f:
                        case 0x40:
                        case 0x42:
                        case 0x44:
                        case 0x48:
                        case 0x4a:
                        case 0x4b:
                        case 0x4d:
                        case 0x4e:
                        case 0x4f:
                        case 0x50:
                        case 0x51:
                        case 0x52:
                        case 0x54:
                        case 0x55:
                        case 0x56:
                        case 0x57:
                        case 0x59:
                        case 0x5a:
                        case 0x5b:
                        case 0x5c:
                        case 0x5d:
                        case 0x5e:
                        case 0x5f:
                        case 0x60:
                        case 0x62:
                        case 0x6b:
                        case 0x71:
                        case 0x72:
                        case 0x76:
                        case 0x77:
                        case 0x79:
                        {
                            goto label_140009063;
                        }
                        case 0x23:
                        {
                            if (rbx_2)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                rsi_2 += 1;
                            }
                            else
                            {
                                fmt_2 = *(rsi_2 + 1);
                                stream.flags |= 0x800;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x25:
                        {
                            r15_1 = rsi_2 + 1;
                            x = __pformat_putc(0x25, &stream);
                            break;
                            break;
                            break;
                        }
                        case 0x27:
                        {
                            if (rbx_2)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                rsi_2 += 1;
                            }
                            else
                            {
                                stream.flags |= 0x1000;
                                cstate._Wchar = 0;
                                short unsigned int rpchr;
                                int32_t rax_29;
                                rax_29 =
                                    mbrtowc(&rpchr, localeconv()->thousands_sep, 0x10, &cstate);
                                
                                if (rax_29 > 0)
                                    stream.thousands_chr = rpchr;
                                
                                fmt_2 = *(rsi_2 + 1);
                                stream.thousands_chr_len = rax_29;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x2a:
                        {
                            if (!r10_1)
                                goto label_140009448;
                            
                            if (rbx_2 & 0xfffffffd)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                r10_1 = nullptr;
                                rsi_2 += 1;
                                rbx_2 = 4;
                            }
                            else
                            {
                                int rax_30 = *argv_1;
                                *r10_1 = rax_30;
                                
                                if (rax_30 >= 0)
                                    goto label_14000966d;
                                
                                if (rbx_2)
                                {
                                    fmt_2 = *(rsi_2 + 1);
                                    argv_1 = &argv_1[8];
                                    rsi_2 += 1;
                                    r10_1 = nullptr;
                                    stream.precision = 0xffffffff;
                                    rbx_2 = 2;
                                }
                                else
                                {
                                    stream.flags |= 0x400;
                                    stream.width = -(stream.width);
                                label_14000966d:
                                    fmt_2 = *(rsi_2 + 1);
                                    argv_1 = &argv_1[8];
                                    rsi_2 += 1;
                                    r10_1 = nullptr;
                                }
                            }
                            break;
                        }
                        case 0x2b:
                        {
                            if (rbx_2)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                rsi_2 += 1;
                            }
                            else
                            {
                                fmt_2 = *(rsi_2 + 1);
                                stream.flags |= 0x100;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x2d:
                        {
                            if (rbx_2)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                rsi_2 += 1;
                            }
                            else
                            {
                                fmt_2 = *(rsi_2 + 1);
                                stream.flags |= 0x400;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x2e:
                        {
                            if (rbx_2 <= 1)
                            {
                                fmt_2 = *(rsi_2 + 1);
                                stream.precision = 0;
                                rsi_2 += 1;
                                r10_1 = &stream.precision;
                                rbx_2 = 2;
                            }
                            else
                            {
                            label_140009448:
                                fmt_2 = *(rsi_2 + 1);
                                rbx_2 = 4;
                                rsi_2 += 1;
                            }
                            break;
                        }
                        case 0x30:
                        {
                            if (rbx_2)
                            {
                                if (rbx_2 > 3)
                                    goto label_140009273;
                                
                                fmt_1 = 0x30;
                            label_14000974f:
                                
                                if (rbx_2 != 2)
                                    goto label_140009082;
                                
                                rbx_2 = 3;
                                goto label_140009082;
                            }
                            
                            fmt_2 = *(rsi_2 + 1);
                            stream.flags |= 0x200;
                            rsi_2 += 1;
                            break;
                        }
                        case 0x41:
                        {
                            flags_2 = stream.flags;
                            rdx_7 = *argv_1;
                            
                            if (flags_2 & 4)
                                goto label_1400092a9;
                            
                            goto label_140009487;
                        }
                        case 0x43:
                        {
                            stream.precision = 0xffffffff;
                            argv_2 = &argv_1[8];
                        label_140009523:
                            int16_t rax_24 = *argv_1;
                            argv_1 = argv_2;
                            r15_1 = rsi_2 + 1;
                            cstate._Wchar = rax_24;
                            x = __pformat_wputchars(&cstate, 1, &stream);
                            break;
                            break;
                            break;
                        }
                        case 0x45:
                        {
                            rdx_15 = *argv_1;
                            
                            if (stream.flags & 4)
                                goto label_140009402;
                            
                            goto label_140009564;
                        }
                        case 0x46:
                        {
                            rdx_13 = *argv_1;
                            
                            if (stream.flags & 4)
                                goto label_1400093da;
                            
                            goto label_14000958e;
                        }
                        case 0x47:
                        {
                            rdx_11 = *argv_1;
                            
                            if (stream.flags & 4)
                                goto label_14000939f;
                            
                            goto label_1400095b8;
                        }
                        case 0x49:
                        {
                            fmt_2 = *(rsi_2 + 1);
                            
                            if (fmt_2 == 0x36)
                            {
                                if (*(rsi_2 + 2) != 0x34)
                                    goto label_140009273;
                                
                                fmt_2 = *(rsi_2 + 3);
                                r11_1 = 3;
                                rsi_2 += 3;
                                rbx_2 = 4;
                            }
                            else if (fmt_2 != 0x33)
                            {
                                rsi_2 += 1;
                                r11_1 = 3;
                                rbx_2 = 4;
                            }
                            else
                            {
                                if (*(rsi_2 + 2) != 0x32)
                                    goto label_140009273;
                                
                                fmt_2 = *(rsi_2 + 3);
                                r11_1 = 2;
                                rsi_2 += 3;
                                rbx_2 = 4;
                            }
                            break;
                        }
                        case 0x4c:
                        {
                            fmt_2 = *(rsi_2 + 1);
                            stream.flags |= 4;
                            rsi_2 += 1;
                            rbx_2 = 4;
                            break;
                        }
                        case 0x53:
                        {
                            argv_3 = &argv_1[8];
                        label_140009701:
                            short unsigned int* r14 = *argv_1;
                            
                            if (!r14)
                                r14 = u"(null)";
                            
                            int precision = stream.precision;
                            
                            if (precision < 0)
                                x = __pformat_wputchars(r14, wcslen(r14), &stream);
                            else
                                x = __pformat_wputchars(r14, wcsnlen(r14, precision), &stream);
                            
                            argv_1 = argv_3;
                            r15_1 = rsi_2 + 1;
                            break;
                            break;
                            break;
                        }
                        case 0x58:
                        case 0x6f:
                        case 0x75:
                        case 0x78:
                        {
                            stream.flags &= 0xfffffeff;
                            uint64_t value;
                            
                            if (r11_1 == 3)
                                value = *argv_1;
                            else if (r11_1 == 2)
                                value = *argv_1;
                            else
                            {
                                int32_t value_4 = *argv_1;
                                value = value_4;
                                
                                if (r11_1 != 1)
                                {
                                    value = value_4;
                                    
                                    if (r11_1 == 5)
                                        value = value_4;
                                }
                            }
                            
                            cstate._Wchar = value;
                            cstate._Byte = *value[4];
                            cstate._State = *value[6];
                            
                            if (fmt_1 == 0x75)
                                x = __pformat_int(value);
                            else
                                x = __pformat_xint(fmt_1, value);
                            
                            goto label_1400093b0;
                        }
                        case 0x61:
                        {
                            rdx_7 = *argv_1;
                            flags_2 = stream.flags | 0x20;
                            stream.flags = flags_2;
                            
                            if (flags_2 & 4)
                            {
                            label_1400092a9:
                                uint64_t value_3 = *rdx_7;
                                int16_t r9 = rdx_7[1];
                                int32_t r11_2 = r9;
                                int32_t r10_5 = (value_3 >> 0x20 & 0x7fffffff) | value_3;
                                
                                if ((0xfffe - ((-(r10_5) | r10_5) >> 0x1f | (r11_2 * 2))) >> 0x10)
                                {
                                    x = __pformat_emit_inf_or_nan(0, "NaN", &stream);
                                    goto label_1400093b0;
                                }
                                
                                if (r9 < 0)
                                {
                                    flags_2 |= 0x80;
                                    stream.flags = flags_2;
                                }
                                
                                int16_t rdx_8 = r9 & 0x7fff;
                                
                                if (!rdx_8)
                                {
                                    x = __pformat_emit_xfloat(value_3);
                                    goto label_1400093b0;
                                }
                                
                                if (rdx_8 != 0x7fff || r10_5)
                                {
                                    x = __pformat_emit_xfloat(value_3);
                                    goto label_1400093b0;
                                }
                                
                                x = __pformat_emit_inf_or_nan(r11_2 & 0x8000, "Inf", &stream);
                                goto label_1400093b0;
                            }
                            
                        label_140009487:
                            uint32_t r8_3 = rdx_7 >> 0x20;
                            
                            if (0x7ff00000 - ((-(rdx_7) | rdx_7) >> 0x1f | (r8_3 & 0x7fffffff)) < 0)
                            {
                                x = __pformat_emit_inf_or_nan(0, "NaN", &stream);
                                goto label_1400093b0;
                            }
                            
                            double var_c8_1;
                            var_c8_1 = rdx_7;
                            int32_t var_c0;
                            
                            if (var_c0 < 0)
                            {
                                flags_2 |= 0x80;
                                stream.flags = flags_2;
                            }
                            
                            int32_t r8_4 = r8_3 & 0x7ff00000;
                            int32_t rax_22 = (r8_3 & 0xfffff) | rdx_7;
                            rdx_7 = rax_22;
                            
                            if (!(r8_4 != 0x7ff00000 | rdx_7) && rax_22 | r8_4)
                            {
                                x = __pformat_emit_inf_or_nan(var_c0 & 0x8000, "Inf", &stream);
                                goto label_1400093b0;
                            }
                            
                            double rax_31 = var_c8_1;
                            int32_t rdx_23;
                            rdx_23 = var_c0 & 0x7fff;
                            
                            if (!rdx_23)
                            label_1400098b4:
                            else if (rdx_23 <= 0x3c00)
                                rax_31 u>>= (0x3c01 - rdx_23);
                            else if (!rdx_23)
                                goto label_1400098b4;
                            
                            x = __pformat_emit_xfloat(rax_31 >> 3);
                            goto label_1400093b0;
                        }
                        case 0x63:
                        {
                            stream.precision = 0xffffffff;
                            argv_2 = &argv_1[8];
                            
                            if (r11_1 - 2 <= 1)
                                goto label_140009523;
                            
                            cstate._Wchar = *argv_1;
                            x = __pformat_putchars(&cstate, 1, &stream);
                            argv_1 = argv_2;
                            r15_1 = rsi_2 + 1;
                            break;
                            break;
                        }
                        case 0x64:
                        case 0x69:
                        {
                            stream.flags |= 0x80;
                            int16_t value_1;
                            
                            if (r11_1 == 3)
                                value_1 = *argv_1;
                            else
                            {
                                value_1 = *argv_1;
                                
                                if (r11_1 != 2 && r11_1 != 1 && r11_1 == 5)
                                    value_1 = value_1;
                            }
                            
                            argv_1 = &argv_1[8];
                            r15_1 = rsi_2 + 1;
                            x = __pformat_int(value_1);
                            break;
                            break;
                            break;
                        }
                        case 0x65:
                        {
                            rdx_15 = *argv_1;
                            int32_t rax_19 = stream.flags | 0x20;
                            stream.flags = rax_19;
                            
                            if (!(rax_19 & 4))
                            {
                            label_140009564:
                                long double var_a8_4 = rdx_15;
                                x = __pformat_efloat(x, &stream);
                                goto label_1400093b0;
                            }
                            
                        label_140009402:
                            int80_t var_a8_3 = *rdx_15;
                            x = __pformat_efloat(x, &stream);
                            goto label_1400093b0;
                        }
                        case 0x66:
                        {
                            rdx_13 = *argv_1;
                            int32_t rax_17 = stream.flags | 0x20;
                            stream.flags = rax_17;
                            
                            if (!(rax_17 & 4))
                            {
                            label_14000958e:
                                long double var_a8_5 = rdx_13;
                                x = __pformat_float(x, &stream);
                                goto label_1400093b0;
                            }
                            
                        label_1400093da:
                            int80_t var_a8_2 = *rdx_13;
                            x = __pformat_float(x, &stream);
                            goto label_1400093b0;
                        }
                        case 0x67:
                        {
                            rdx_11 = *argv_1;
                            int32_t rax_15 = stream.flags | 0x20;
                            stream.flags = rax_15;
                            
                            if (rax_15 & 4)
                            {
                            label_14000939f:
                                int80_t var_a8_1 = *rdx_11;
                                x = __pformat_gfloat(x, &stream);
                                goto label_1400093b0;
                            }
                            
                        label_1400095b8:
                            long double var_a8_6 = rdx_11;
                            x = __pformat_gfloat(x, &stream);
                        label_1400093b0:
                            argv_1 = &argv_1[8];
                            r15_1 = rsi_2 + 1;
                            break;
                            break;
                            break;
                        }
                        case 0x68:
                        {
                            fmt_2 = *(rsi_2 + 1);
                            
                            if (fmt_2 == 0x68)
                            {
                                fmt_2 = *(rsi_2 + 2);
                                r11_1 = 5;
                                rsi_2 += 2;
                                rbx_2 = 4;
                            }
                            else
                            {
                                rsi_2 += 1;
                                r11_1 = 1;
                                rbx_2 = 4;
                            }
                            break;
                        }
                        case 0x6a:
                        case 0x74:
                        case 0x7a:
                        {
                            fmt_2 = *(rsi_2 + 1);
                            r11_1 = 3;
                            rsi_2 += 1;
                            rbx_2 = 4;
                            break;
                        }
                        case 0x6c:
                        {
                            fmt_2 = *(rsi_2 + 1);
                            
                            if (fmt_2 == 0x6c)
                            {
                                fmt_2 = *(rsi_2 + 2);
                                r11_1 = 3;
                                rsi_2 += 2;
                                rbx_2 = 4;
                            }
                            else
                            {
                                rsi_2 += 1;
                                r11_1 = 2;
                                rbx_2 = 4;
                            }
                            break;
                        }
                        case 0x6d:
                        {
                            r15_1 = rsi_2 + 1;
                            x = __pformat_puts(strerror(_ErrorMessage), &stream);
                            break;
                            break;
                            break;
                        }
                        case 0x6e:
                        {
                            int64_t* rcx_2 = *argv_1;
                            int64_t count = stream.count;
                            
                            if (r11_1 == 5)
                                *rcx_2 = count;
                            else if (r11_1 == 1)
                                *rcx_2 = count;
                            else if (r11_1 == 2 || r11_1 != 3)
                                *rcx_2 = count;
                            else
                                *rcx_2 = count;
                            
                            goto label_1400093b0;
                        }
                        case 0x70:
                        {
                            if (!rbx_2 && stream.flags == rdi_1)
                            {
                                stream.precision = 0x10;
                                int32_t rax_34;
                                *rax_34[1] = *rdi_1[1] | 2;
                                stream.flags = rax_34;
                            }
                            
                            int64_t value_2 = *argv_1;
                            argv_1 = &argv_1[8];
                            r15_1 = rsi_2 + 1;
                            x = __pformat_xint(0x78, value_2);
                            break;
                            break;
                            break;
                        }
                        case 0x73:
                        {
                            char* s = *argv_1;
                            argv_3 = &argv_1[8];
                            
                            if (r11_1 - 2 <= 1)
                                goto label_140009701;
                            
                            argv_1 = argv_3;
                            r15_1 = rsi_2 + 1;
                            x = __pformat_puts(s, &stream);
                            break;
                            break;
                        }
                    }
                
                if (!fmt_2)
                    return stream.count;
            }
        }
        
        _Character_1 = *r15_1;
        r15_1 += 1;
        _Character = _Character_1;
    } while (_Character);
    
    return stream.count;
}

void* __rv_alloc_D2A(int i)
{
    int k = 0;
    
    if (i > 0x1b)
    {
        int32_t rax_1 = 4;
        
        do
        {
            rax_1 *= 2;
            k += 1;
        } while (rax_1 + 0x17 < i);
    }
    
    int64_t* rax_2 = __Balloc_D2A(k);
    *rax_2 = k;
    return rax_2 + 4;
}

void* __nrv_alloc_D2A(char* s, char** rve, int n)
{
    int k;
    
    if (n <= 0x1b)
        k = 0;
    else
    {
        int32_t rax_1 = 4;
        k = 0;
        
        do
        {
            rax_1 *= 2;
            k += 1;
        } while (n > rax_1 + 0x17);
    }
    
    int64_t* rax_2 = __Balloc_D2A(k);
    char* rdx_1 = &s[1];
    *rax_2 = k;
    char rcx_1 = *s;
    *(rax_2 + 4) = rcx_1;
    char* rax_3 = rax_2 + 4;
    
    if (rcx_1)
    {
        char i;
        
        do
        {
            i = *rdx_1;
            rax_3 = &rax_3[1];
            rdx_1 = &rdx_1[1];
            *rax_3 = i;
        } while (i);
    }
    
    if (rve)
        *rve = rax_3;
    
    return rax_2 + 4;
}

int64_t __freedtoa(char* s)
{
    int32_t rcx = *(s - 4);
    *(s + 4) = _mm_unpacklo_epi32(rcx, 1 << rcx);
    /* tailcall */
    return __Bfree_D2A(&s[-4]);
}

uint32_t __quorem_D2A(struct __Bigint* b, struct __Bigint* S)
{
    int wds = S->wds;
    
    if (b->wds < wds)
        return 0;
    
    int rsi = wds - 1;
    long unsigned int (* rbx_1)[0x1] = &S->x;
    void* rdi_1 = &rbx_1[rsi];
    void* r10_3 = &(&b->x)[rsi];
    int32_t r8_1 = *r10_3;
    int32_t rcx = *rdi_1 + 1;
    uint32_t result = COMBINE(0, r8_1) / rcx;
    
    if (r8_1 >= rcx)
    {
        long unsigned int (* r9_1)[0x1] = rbx_1;
        long unsigned int (* r8_2)[0x1] = &b->x;
        uint64_t r14_1 = 0;
        uint64_t rcx_1 = 0;
        
        do
        {
            uint64_t x = ADJ(r9_1)->x;
            uint64_t x_2 = ADJ(r8_2)->x;
            r9_1 = &r9_1[1];
            r8_2 = &r8_2[1];
            int64_t rax_5 = x * result + r14_1;
            r14_1 = rax_5 >> 0x20;
            uint64_t rax_8 = x_2 - rax_5 - rcx_1;
            ADJ(r8_2)->wds = rax_8;
            rcx_1 = rax_8 >> 0x20 & 1;
        } while (rdi_1 >= r9_1);
    }
    
    if (r8_1 >= rcx && !*r10_3)
    {
        while (true)
        {
            r10_3 -= 4;
            
            if (&b->x >= r10_3)
                break;
            
            if (*r10_3)
                break;
            
            rsi -= 1;
        }
        
        b->wds = rsi;
        
        if (__cmp_D2A(b, S) < 0)
            return result;
    }
    else if (__cmp_D2A(b, S) < 0)
        return result;
    
    long unsigned int (* rcx_5)[0x1] = &b->x;
    uint64_t rdx_3 = 0;
    
    do
    {
        uint64_t x_1 = ADJ(rcx_5)->x;
        uint64_t x_3 = ADJ(rbx_1)->x;
        rbx_1 = &rbx_1[1];
        rcx_5 = &rcx_5[1];
        uint64_t rax_11 = x_1 - x_3 - rdx_3;
        ADJ(rcx_5)->wds = rax_11;
        rdx_3 = rax_11 >> 0x20 & 1;
    } while (rdi_1 >= rbx_1);
    
    void* rax_13 = &(&b->x)[rsi];
    
    if (*rax_13)
        return result + 1;
    
    while (true)
    {
        rax_13 -= 4;
        
        if (&b->x >= rax_13 || *rax_13)
        {
            b->wds = rsi;
            return result + 1;
        }
        
        rsi -= 1;
    }
}

char* __gdtoa(struct FPI* fpi, int be, long unsigned int* bits, int* kindp, int mode, int ndigits, int* decpt, char** rve)
{
    int rdi = *kindp;
    int mode_1 = mode;
    int* kindp_1 = kindp;
    int var_7c = ndigits;
    *kindp = rdi & 0xffffffcf;
    int32_t rax_7 = rdi & 7;
    char* rcx_6;
    char** rve_1;
    int r8_4;
    
    if (rax_7 == 3)
    {
        rve_1 = rve;
        r8_4 = 8;
        rcx_6 = "Infinity";
        *decpt = 0xffff8000;
    }
    else
    {
        int32_t rbx_2 = rdi & 4;
        int32_t var_88_1 = rbx_2;
        
        if (!rbx_2)
        {
            if (!rax_7)
            {
                *decpt = 1;
                return __nrv_alloc_D2A(U"0", rve, 1);
            }
            
            int nbits = fpi->nbits;
            int32_t rax_8 = 0x20;
            int k_4 = 0;
            
            if (nbits > 0x20)
            {
                do
                {
                    rax_8 *= 2;
                    k_4 += 1;
                } while (nbits > rax_8);
            }
            
            int64_t* rax_9 = __Balloc_D2A(k_4);
            int64_t* rbx_3 = rax_9;
            void* rdx = &rax_9[3];
            long unsigned int* bits_1 = bits;
            int64_t r8_2 = (nbits - 1) >> 5;
            void* rcx = &bits[r8_2];
            
            do
            {
                long unsigned int r9 = *bits_1;
                bits_1 = &bits_1[1];
                rdx += 4;
                *(rdx - 4) = r9;
            } while (rcx >= bits_1);
            
            void* rax_10 = (r8_2 << 2) + 4;
            
            if (rcx + 1 < bits + 1)
                rax_10 = 4;
            
            void* rax_11 = rax_10 + rbx_3;
            int32_t r14_2 = rax_10 >> 2;
            
            while (true)
            {
                int32_t rdx_2 = r14_2;
                r14_2 -= 1;
                
                if (*(rax_11 + 0x14))
                {
                    *(rbx_3 + 0x14) = rdx_2;
                    uint64_t rflags_1;
                    int32_t temp0_1;
                    temp0_1 = __bsr_gprv_memv(*(rbx_3 + (r14_2 << 2) + 0x18));
                    r14_2 = (rdx_2 << 5) - (temp0_1 ^ 0x1f);
                    break;
                }
                
                rax_11 -= 4;
                
                if (!r14_2)
                {
                    *(rbx_3 + 0x14) = 0;
                    break;
                }
            }
            
            int k_1 = __trailz_D2A(rbx_3);
            int i = k_1;
            int be_1 = be;
            
            if (k_1)
            {
                __rshift_D2A(rbx_3, k_1);
                int i_3 = i;
                r14_2 -= i_3;
                be_1 = be + i_3;
            }
            
            if (!*(rbx_3 + 0x14))
            {
                __Bfree_D2A(rbx_3);
                *decpt = 1;
                return __nrv_alloc_D2A(U"0", rve, 1);
            }
            
            double zmm0_1 = __b2d_D2A(rbx_3, &i);
            int32_t r8_3 = be_1 + r14_2;
            uint128_t zmm1;
            zmm1 = r8_3 - 1;
            zmm1 = zmm1 * 0.30102999566398098;
            uint64_t rdx_9 = (zmm0_1 >> 0x20 & 0xfffff) | 0x3ff00000;
            uint64_t rax_16 = zmm0_1 | rdx_9 << 0x20;
            int32_t r9_3 = 1 - r8_3;
            
            if (r8_3 - 1 >= 0)
                r9_3 = r8_3 - 1;
            
            zmm0_1 = (rax_16 - 1.5) * 0.28952965460216801 + 0.1760912590558 + zmm1;
            
            if (r9_3 - 0x435 > 0)
            {
                zmm1 = r9_3 - 0x435;
                zmm1 = zmm1 * 7.0000000000000003e-17;
                zmm0_1 = zmm0_1 + zmm1;
            }
            
            int32_t k_13 = zmm0_1;
            
            if (0.0 > zmm0_1)
            {
                zmm1 = k_13;
                zmm1 - zmm0_1;
                
                if (FCMP_UO(zmm1, zmm0_1) || !(zmm1 == zmm0_1))
                    k_13 -= 1;
            }
            
            uint64_t rax_18 = rax_16 | (rdx_9 + ((r8_3 - 1) << 0x14)) << 0x20;
            int32_t rax_20 = r14_2 - (r8_3 - 1);
            int i_17 = rax_20 - 1;
            int32_t var_c4_1;
            int i_21;
            
            if (k_13 > 0x16)
                var_c4_1 = 1;
            else
            {
                if (!(__tens_D2A[k_13] > rax_18))
                {
                    var_c4_1 = 0;
                    i_21 = 0;
                    
                    if (rax_20 <= 0)
                    {
                        i_17 = 0;
                        i_21 = 1 - rax_20;
                    }
                    
                    goto label_140009e38;
                }
                
                var_c4_1 = 0;
                k_13 -= 1;
            }
            
            i_21 = 0;
            
            if (i_17 < 0)
            {
                i_17 = 0;
                i_21 = 1 - rax_20;
            }
            
            int k;
            int32_t k_14;
            
            if (k_13 >= 0)
            {
            label_140009e38:
                i_17 += k_13;
                k_14 = k_13;
                k = 0;
            }
            else
            {
                i_21 -= k_13;
                int k_8 = -(k_13);
                k_14 = k_13;
                k_13 = 0;
                k = k_8;
            }
            
            int32_t i_2;
            char var_d4_1;
            int32_t var_c0_1;
            char* result_1;
            uint64_t var_90;
            int32_t var_80_1;
            uint64_t r10_5;
            int k_12;
            
            if (mode_1 <= 9)
            {
                if (mode_1 <= 5)
                {
                    var_d4_1 = r8_3 + 0x3fd <= 0x7f7;
                    
                    if (mode_1 == 4)
                        goto label_14000a5f4;
                    
                    if (mode_1 == 5)
                        goto label_14000aa0f;
                    
                    var_c0_1 = 0;
                    
                    if (mode_1 == 2)
                        goto label_14000a5fe;
                    
                    if (mode_1 != 3)
                        goto label_14000a210;
                    
                    goto label_140009fd6;
                }
                
                var_d4_1 = 0;
                int mode_2 = mode_1 - 4;
                mode_1 = mode_2;
                int i_4;
                int i_1;
                
                if (mode_2 == 4)
                {
                label_14000a5f4:
                    var_c0_1 = 1;
                label_14000a5fe:
                    i_1 = 1;
                    
                    if (var_7c > 0)
                        i_1 = var_7c;
                    
                    i_2 = i_1;
                    i_4 = i_1;
                    var_90 = i_1;
                    var_7c = i_1;
                }
                else
                {
                    if (mode_2 != 5)
                    {
                        var_c0_1 = 0;
                        
                        if (mode_2 == 2)
                            goto label_14000a5fe;
                        
                        mode_1 = 3;
                        goto label_140009fd6;
                    }
                    
                label_14000aa0f:
                    var_c0_1 = 1;
                label_140009fd6:
                    int32_t i_18 = k_14 + var_7c;
                    i_2 = i_18;
                    i_4 = 1;
                    var_90 = i_18 + 1;
                    
                    if (i_18 + 1 > 0)
                        i_4 = i_18 + 1;
                    
                    i_1 = i_4;
                }
                
                i = i_4;
                k_12 = k_13;
                r10_5 = rax_18;
                result_1 = __rv_alloc_D2A(i_1);
                int rounding = fpi->rounding;
                var_80_1 = rounding - 1;
                
                if (rounding == 1)
                    goto label_14000a044;
                
                goto label_14000a022;
            }
            
            mode_1 = 0;
            var_d4_1 = r8_3 + 0x3fd <= 0x7f7;
        label_14000a210:
            i = nbits * 0.30103000000000002 + 3;
            k_12 = k_13;
            r10_5 = rax_18;
            result_1 = __rv_alloc_D2A(nbits * 0.30103000000000002 + 3);
            int rounding_1 = fpi->rounding;
            var_80_1 = rounding_1 - 1;
            int32_t k_15;
            char* result;
            struct __Bigint* rdi_5;
            int k_6;
            struct __Bigint* r9_10;
            int i_20;
            uint128_t zmm2;
            
            if (rounding_1 == 1)
            {
                var_7c = 0;
                
                if (be_1 < 0)
                {
                    i_2 = 0xffffffff;
                    var_90 = 0xffffffff;
                label_14000a429:
                    int32_t r13_1 = nbits - r14_2;
                    int emin = fpi->emin;
                    int i_5 = r13_1 + 1;
                    i = i_5;
                    int k_11;
                    int k_9;
                    
                    if (be_1 - r13_1 < emin)
                    {
                        if (!((mode_1 - 3) & 0xfffffffd))
                            goto label_14000a9da;
                        
                        int32_t rdi_9 = var_90;
                        i_5 = be_1 - emin + 1;
                        int rcx_27;
                        rcx_27 = mode_1 > 1;
                        i = i_5;
                        emin = rdi_9 > 0;
                        
                        if (!(rcx_27 & emin) || i_5 <= rdi_9)
                            goto label_14000a47b;
                        
                        int i_14 = var_90;
                        k_9 = i_14 - 1;
                        
                        if (k < k_9)
                            goto label_14000abf9;
                        
                        i_17 += i_14;
                        i = i_14;
                        k_11 = k - k_9;
                        i_20 = i_21;
                        i_21 += i_14;
                    }
                    else if (mode_1 <= 1)
                    {
                    label_14000a47b:
                        i_17 += i_5;
                        k_11 = k;
                        i_20 = i_21;
                        i_21 += i_5;
                    }
                    else
                    {
                    label_14000a9da:
                        int i_10 = var_90;
                        k_9 = i_10 - 1;
                        
                        if (k < k_9)
                        {
                        label_14000abf9:
                            int k_10 = k;
                            k = k_9;
                            k_11 = 0;
                            int i_13 = var_90;
                            i_17 += i_13;
                            k_12 += k_9 - k_10;
                            i = i_13;
                            i_20 = i_21;
                            i_21 += i_13;
                        }
                        else
                        {
                            k_11 = k - k_9;
                            
                            if (i_10 >= 0)
                            {
                                i_17 += i_10;
                                i = i_10;
                                i_20 = i_21;
                                i_21 += i_10;
                            }
                            else
                            {
                                i = 0;
                                i_20 = i_21 - var_90;
                            }
                        }
                    }
                    var_c0_1 = 1;
                    k_6 = k_11;
                    rdi_5 = __i2b_D2A(1);
                    goto label_14000a4b8;
                }
                
                var_c0_1 = 1;
                i_2 = 0xffffffff;
                var_90 = 0xffffffff;
                
                if (fpi->int_max < k_14)
                {
                label_14000a41e:
                    
                    if (var_c0_1)
                        goto label_14000a429;
                    
                    k_6 = k;
                    i_20 = i_21;
                    rdi_5 = nullptr;
                label_14000a4b8:
                    
                    if (i_20 > 0 && i_17 > 0)
                    {
                        int i_6 = i_17;
                        
                        if (i_20 <= i_17)
                            i_6 = i_20;
                        
                        i_21 -= i_6;
                        i = i_6;
                        i_20 -= i_6;
                        i_17 -= i_6;
                    }
                    
                    if (k)
                    {
                        if (!var_c0_1 || !k_6)
                            rbx_3 = __pow5mult_D2A(rbx_3, k);
                        else
                        {
                            uint64_t var_d0;
                            var_d0 = k_12;
                            struct __Bigint* a = __pow5mult_D2A(rdi_5, k_6);
                            rdi_5 = a;
                            be_1 = __mult_D2A(a, rbx_3);
                            __Bfree_D2A(rbx_3);
                            rbx_3 = be_1;
                            k_12 = var_d0;
                            
                            if (k != k_6)
                                rbx_3 = __pow5mult_D2A(rbx_3, k - k_6);
                        }
                    }
                    
                    struct __Bigint* b = __i2b_D2A(1);
                    int k_7 = k_12;
                    r9_10 = b;
                    int32_t r12_2;
                    
                    if (k_7)
                    {
                        r9_10 = __pow5mult_D2A(b, k_7);
                        
                        if (mode_1 <= 1 && r14_2 == 1 && fpi->emin + 1 < be)
                        {
                            i_21 += 1;
                            k_7 = 1;
                            i_17 += 1;
                        }
                        else
                            k_7 = 0;
                        
                        uint64_t rflags_2;
                        int32_t temp0_4;
                        temp0_4 = __bsr_gprv_memv((&r9_10->x)[r9_10->wds - 1]);
                        r12_2 = temp0_4 ^ 0x1f;
                    }
                    else
                    {
                        if (mode_1 <= 1 && r14_2 == 1 && be > fpi->emin + 1)
                        {
                            i_21 += 1;
                            k_7 = 1;
                            i_17 += 1;
                        }
                        
                        r12_2 = 0x1f;
                    }
                    
                    int i_16 = (r12_2 - i_17 - 4) & 0x1f;
                    int k_2 = i_21 + i_16;
                    i = i_16;
                    int i_12 = i_16;
                    
                    if (k_2 > 0)
                    {
                        int var_a0_2;
                        var_a0_2 = r9_10;
                        int64_t* rax_65 = __lshift_D2A(rbx_3, k_2);
                        i_12 = i;
                        r9_10 = var_a0_2;
                        rbx_3 = rax_65;
                    }
                    
                    int k_3 = i_17 + i_12;
                    
                    if (k_3 > 0)
                        r9_10 = __lshift_D2A(r9_10, k_3);
                    
                    r14_2 = mode_1 > 2;
                    
                    if (!var_c4_1)
                    {
                    label_14000a5a3:
                        
                        if (var_90 <= 0 && r14_2)
                            goto label_14000a5b7;
                        
                        k_15 = k_14 + 1;
                        
                        if (!var_c0_1)
                            goto label_14000a8c0;
                        
                        goto label_14000a664;
                    }
                    
                    int var_78;
                    var_78 = r9_10;
                    int rax_96 = __cmp_D2A(rbx_3, r9_10);
                    r9_10 = var_78;
                    
                    if (rax_96 >= 0)
                        goto label_14000a5a3;
                    
                    var_90 = r9_10;
                    r9_10 = var_90;
                    rbx_3 = __multadd_D2A(rbx_3, 0xa, 0);
                    int32_t rax_100;
                    rax_100 = i_2 <= 0;
                    char r14_5 = r14_2 & rax_100;
                    char* result_4;
                    struct __Bigint* v;
                    int32_t r8_10;
                    struct __Bigint* v_1;
                    void* result_6;
                    void* result_7;
                    
                    if (var_c0_1)
                    {
                        r9_10 = var_90;
                        rdi_5 = __multadd_D2A(rdi_5, 0xa, 0);
                        
                        if (r14_5)
                        {
                        label_14000af97:
                            k_14 -= 1;
                            var_90 = i_2;
                        label_14000a5b7:
                            
                            if (var_90)
                                goto label_14000a623;
                            
                            struct __Bigint* b_1 = __multadd_D2A(r9_10, 5, 0);
                            mode_1 = b_1;
                            r9_10 = mode_1;
                            
                            if (__cmp_D2A(rbx_3, b_1) <= 0)
                                goto label_14000a623;
                            
                            result = result_1;
                            k_15 = k_14 + 2;
                            goto label_14000a362;
                        }
                        
                        k_15 = k_14;
                        var_90 = i_2;
                    label_14000a664:
                        int k_5 = i_16 + i_20;
                        
                        if (k_5 > 0)
                        {
                            i_17 = r9_10;
                            r9_10 = i_17;
                            rdi_5 = __lshift_D2A(rdi_5, k_5);
                        }
                        
                        struct __Bigint* b_4 = rdi_5;
                        
                        if (k_7)
                        {
                            var_78 = r9_10;
                            int64_t* b_3 = __Balloc_D2A(rdi_5->k);
                            memcpy(&b_3[2], &rdi_5->sign, (rdi_5->wds << 2) + 8);
                            r9_10 = var_78;
                            b_4 = __lshift_D2A(b_3, 1);
                        }
                        
                        k_14 = kindp_1;
                        int i_7 = 1;
                        var_78 = r9_10;
                        i_17 = bits;
                        char* result_8 = result_1;
                        
                        while (true)
                        {
                            i = i_7;
                            uint32_t rax_86 = __quorem_D2A(rbx_3, var_78);
                            int rax_87 = __cmp_D2A(rbx_3, rdi_5);
                            int64_t* rax_88 = __diff_D2A(var_78, b_4);
                            int rdx_36;
                            char* result_9;
                            
                            if (rax_88[2])
                            {
                                __Bfree_D2A(rax_88);
                                rdx_36 = 1;
                            }
                            else
                            {
                                i_21 = rax_88;
                                int rax_90 = __cmp_D2A(rbx_3, rax_88);
                                __Bfree_D2A(i_21);
                                rdx_36 = rax_90 | mode_1;
                                
                                if (rdx_36)
                                    rdx_36 = rax_90;
                                else
                                {
                                    int32_t rax_93 = *i_17;
                                    int32_t var_a0_4 = rax_93;
                                    
                                    if (!((rax_93 & 1) | var_80_1))
                                    {
                                        result_9 = result_8;
                                        v_1 = var_78;
                                        kindp_1 = k_14;
                                        char r8_9 = (rax_86 + 0x30);
                                        
                                        if (rax_86 == 9)
                                        {
                                            result_6 = &result_9[1];
                                            goto label_14000b155;
                                        }
                                        
                                        if (rax_87 <= 0)
                                        {
                                            var_88_1 = 0x10;
                                            
                                            if (*(rbx_3 + 0x14) <= 1)
                                            {
                                                int32_t rax_152;
                                                rax_152 = rbx_3[3];
                                                var_88_1 = rax_152 << 4;
                                            }
                                        }
                                        else
                                        {
                                            var_88_1 = 0x20;
                                            r8_9 = rax_86 + 0x31;
                                        }
                                        
                                        *result_9 = r8_9;
                                        v = rdi_5;
                                        result_6 = &result_9[1];
                                        rdi_5 = b_4;
                                        goto label_14000a803;
                                    }
                                }
                            }
                            
                            if (rax_87 >= 0 && (rax_87 | mode_1 || *i_17 & 1))
                            {
                                result_6 = &result_8[1];
                                result_7 = result_6;
                                
                                if (rdx_36 <= 0 || var_80_1 == 2)
                                {
                                    *(result_6 - 1) = (rax_86 + 0x30);
                                    
                                    if (i == var_90)
                                    {
                                        r8_10 = rax_86 + 0x30;
                                        v_1 = var_78;
                                        v = rdi_5;
                                        kindp_1 = k_14;
                                        rdi_5 = b_4;
                                        break;
                                    }
                                    
                                    rbx_3 = __multadd_D2A(rbx_3, 0xa, 0);
                                    
                                    if (rdi_5 == b_4)
                                    {
                                        struct __Bigint* b_5 = __multadd_D2A(rdi_5, 0xa, 0);
                                        rdi_5 = b_5;
                                        b_4 = b_5;
                                    }
                                    else
                                    {
                                        rdi_5 = __multadd_D2A(rdi_5, 0xa, 0);
                                        b_4 = __multadd_D2A(b_4, 0xa, 0);
                                    }
                                    
                                    result_8 = result_6;
                                    i_7 = i + 1;
                                    continue;
                                }
                                else
                                {
                                    result_9 = result_8;
                                    v_1 = var_78;
                                    kindp_1 = k_14;
                                    
                                    if (rax_86 != 9)
                                    {
                                        v = rdi_5;
                                        var_88_1 = 0x20;
                                        rdi_5 = b_4;
                                        *result_9 = (rax_86 + 0x30) + 1;
                                        goto label_14000a803;
                                    }
                                }
                                
                                goto label_14000b155;
                            }
                            
                            result_9 = result_8;
                            v_1 = var_78;
                            int32_t r8_15 = rax_86 + 0x30;
                            kindp_1 = k_14;
                            
                            if (!var_80_1)
                            {
                                if (rdx_36 <= 0)
                                    goto label_14000af5e;
                                
                            label_14000af15:
                                mode_1 = v_1;
                                var_88_1 = result_9;
                                int64_t* a_2 = __lshift_D2A(rbx_3, 1);
                                rbx_3 = a_2;
                                int rax_135 = __cmp_D2A(a_2, mode_1);
                                v_1 = mode_1;
                                result_9 = var_88_1;
                                
                                if (rax_135 <= 0 && (rax_135 || !(r8_15 & 1)))
                                {
                                    var_80_1 = 0x20;
                                label_14000af5e:
                                    
                                    if (*(rbx_3 + 0x14) > 1)
                                    {
                                    label_14000af68:
                                        v = rdi_5;
                                        var_88_1 = 0x10;
                                        rdi_5 = b_4;
                                        result_6 = &result_9[1];
                                        *result_9 = r8_15;
                                        goto label_14000a803;
                                    }
                                    
                                    v = rdi_5;
                                    rdi_5 = b_4;
                                    
                                    if (!rbx_3[3])
                                    {
                                        result_6 = &result_9[1];
                                        var_88_1 = var_80_1;
                                    }
                                    else
                                    {
                                        var_88_1 = 0x10;
                                        result_6 = &result_9[1];
                                    }
                                    
                                    *result_9 = r8_15;
                                    goto label_14000a803;
                                }
                                
                                if (r8_15 != 0x39)
                                {
                                    var_80_1 = 0x20;
                                    r8_15 = rax_86 + 0x31;
                                    goto label_14000af5e;
                                }
                                
                                v = rdi_5;
                                result_6 = &result_9[1];
                                rdi_5 = b_4;
                            }
                            else
                            {
                                if (*(rbx_3 + 0x14) <= 1 && !rbx_3[3])
                                {
                                    if (rdx_36 > 0)
                                        goto label_14000af15;
                                    
                                    v = rdi_5;
                                    result_6 = &result_9[1];
                                    rdi_5 = b_4;
                                    *result_9 = r8_15;
                                    goto label_14000a803;
                                }
                                
                                if (var_80_1 == 2)
                                    goto label_14000af68;
                                
                                var_78 = kindp_1;
                                int32_t r14_6 = r8_15;
                                void* result_10 = result_9;
                                mode_1 = v_1;
                                
                                while (true)
                                {
                                    result_6 = result_10 + 1;
                                    
                                    if (__cmp_D2A(mode_1, b_4) <= 0)
                                        break;
                                    
                                    *(result_6 - 1) = r14_6;
                                    result_10 = result_6;
                                    struct __Bigint* b_6 = __multadd_D2A(b_4, 0xa, 0);
                                    
                                    if (rdi_5 == b_4)
                                        rdi_5 = b_6;
                                    
                                    struct __Bigint* b_2 = __multadd_D2A(rbx_3, 0xa, 0);
                                    b_4 = b_6;
                                    rbx_3 = b_2;
                                    r14_6 = __quorem_D2A(b_2, mode_1) + 0x30;
                                }
                                
                                result_9 = result_10;
                                v_1 = mode_1;
                                kindp_1 = var_78;
                                
                                if (r14_6 != 0x39)
                                {
                                    var_88_1 = 0x20;
                                    v = rdi_5;
                                    rdi_5 = b_4;
                                    *result_9 = (r14_6 + 1);
                                    goto label_14000a803;
                                }
                                
                            label_14000b155:
                                v = rdi_5;
                                rdi_5 = b_4;
                            }
                            
                            *result_9 = 0x39;
                            result_4 = result_1;
                            result_7 = result_6;
                            goto label_14000abc9;
                        }
                    }
                    else
                    {
                        if (r14_5)
                            goto label_14000af97;
                        
                        k_15 = k_14;
                        var_90 = i_2;
                    label_14000a8c0:
                        result_7 = result_1;
                        int i_8 = 1;
                        
                        while (true)
                        {
                            i = i_8;
                            result_7 += 1;
                            r8_10 = __quorem_D2A(rbx_3, r9_10) + 0x30;
                            *(result_7 - 1) = r8_10;
                            
                            if (i >= var_90)
                                break;
                            
                            rbx_3 = __multadd_D2A(rbx_3, 0xa, 0);
                            i_8 = i + 1;
                        }
                        
                        v_1 = r9_10;
                        v = nullptr;
                    }
                    
                    int32_t rax_107;
                    
                    if (var_80_1)
                    {
                        if (var_80_1 == 2)
                            goto label_14000ad0e;
                        
                        if (*(rbx_3 + 0x14) > 1)
                            goto label_14000abb6;
                        
                        rax_107 = rbx_3[3];
                        
                        if (rax_107)
                            goto label_14000abb6;
                        
                        goto label_14000a943;
                    }
                    
                    mode_1 = v_1;
                    int64_t* a_1 = __lshift_D2A(rbx_3, 1);
                    rbx_3 = a_1;
                    int rax_126 = __cmp_D2A(a_1, mode_1);
                    v_1 = mode_1;
                    
                    if (rax_126 > 0 || (!rax_126 && r8_10 & 1))
                    {
                    label_14000abb6:
                        result_4 = result_1;
                    label_14000abc9:
                        
                        while (true)
                        {
                            result_6 = result_7;
                            result_7 -= 1;
                            char rax_120 = *(result_6 - 1);
                            
                            if (rax_120 != 0x39)
                            {
                                var_88_1 = 0x20;
                                *result_7 = rax_120 + 1;
                                break;
                            }
                            
                            if (result_7 == result_4)
                            {
                                k_15 += 1;
                                var_88_1 = 0x20;
                                *result_1 = 0x31;
                                break;
                            }
                        }
                    }
                    else
                    {
                    label_14000ad0e:
                        var_88_1 = 0x10;
                        
                        if (*(rbx_3 + 0x14) <= 1)
                        {
                            rax_107 = rbx_3[3];
                        label_14000a943:
                            rax_107 = rax_107;
                            var_88_1 = rax_107 << 4;
                        }
                        
                        do
                        {
                            result_6 = result_7;
                            result_7 -= 1;
                        } while (*result_7 == 0x30);
                    }
                    
                label_14000a803:
                    __Bfree_D2A(v_1);
                    
                    if (!rdi_5)
                    {
                        result = result_1;
                        result_1 = result_6;
                    }
                    else
                    {
                        if (v && v != rdi_5)
                            __Bfree_D2A(v);
                        
                        result = result_1;
                        result_1 = result_6;
                        __Bfree_D2A(rdi_5);
                    }
                }
                else
                {
                label_14000a319:
                    int64_t k_16 = k_14;
                    zmm2 = __tens_D2A[k_16];
                    
                    if (var_7c >= 0)
                        goto label_14000aadc;
                    
                    int32_t rax_48 = var_90;
                    
                    if (rax_48 > 0)
                        goto label_14000aadc;
                    
                    if (rax_48)
                    {
                    label_14000a61b:
                        r9_10 = nullptr;
                        rdi_5 = nullptr;
                    label_14000a623:
                        result = result_1;
                        var_88_1 = 0x10;
                        k_15 = -(var_7c);
                    }
                    else
                    {
                        zmm2 = zmm2 * 5.0;
                        
                        if (zmm2 >= rax_18)
                            goto label_14000a61b;
                        
                        r9_10 = nullptr;
                        rdi_5 = nullptr;
                        k_15 = k_16 + 2;
                        result = result_1;
                    label_14000a362:
                        result_1 = &result_1[1];
                        *result = 0x31;
                        var_88_1 = 0x20;
                    }
                    
                    __Bfree_D2A(r9_10);
                    
                    if (rdi_5)
                        __Bfree_D2A(rdi_5);
                }
            }
            else
            {
                var_7c = 0;
                var_c0_1 = 1;
                i_2 = 0xffffffff;
                var_90 = 0xffffffff;
            label_14000a022:
                int32_t rax_34 = 2;
                
                if (var_80_1 >= 0)
                    rax_34 = var_80_1;
                
                var_80_1 = rax_34;
                
                if (!(rdi & 8))
                    goto label_14000a413;
                
                var_80_1 = 3 - rax_34;
            label_14000a044:
                int32_t rcx_12 = var_90;
                int32_t rax_33;
                rax_33 = rcx_12 <= 0xe;
                char rdi_2 = var_d4_1 & rax_33;
                
                if (!rdi_2 || k_14 | var_80_1)
                    goto label_14000a413;
                
                i = 0;
                uint128_t zmm0_3 = rax_18;
                int32_t i_19;
                uint64_t rdx_26;
                int32_t k_17;
                
                if (var_c4_1 && 0x3ff0000000000000 > zmm0_3)
                {
                    if (!rcx_12)
                    {
                        zmm1 = zmm0_3 + zmm0_3;
                        zmm1 = zmm1 + 7.0;
                        int64_t rdx_30 = zmm1;
                        rdx_26 = rdx_30 | ((rdx_30 >> 0x20) - 0x3400000) << 0x20;
                    label_14000a3df:
                        zmm0_3 = zmm0_3 - 5.0;
                        zmm1 = rdx_26;
                        
                        if (zmm0_3 > zmm1)
                        {
                            k_15 = 2;
                            result = result_1;
                            r9_10 = nullptr;
                            rdi_5 = nullptr;
                            goto label_14000a362;
                        }
                        
                        if (__xorpd_xmmxuq_memxuq(zmm1, data_140011b70) > zmm0_3)
                            goto label_14000a61b;
                    }
                    else if (i_2 > 0)
                    {
                        zmm0_3 = zmm0_3 * 10.0;
                        k_17 = -1;
                        zmm1 = 0x4008000000000000 * zmm0_3;
                        r10_5 = zmm0_3;
                        zmm1 = zmm1 + 7.0;
                        int64_t rdx_55 = zmm1;
                        rdx_26 = rdx_55 | ((rdx_55 >> 0x20) - 0x3400000) << 0x20;
                        i_19 = i_2;
                        goto label_14000a0d5;
                    }
                    
                label_14000a408:
                    var_80_1 = 0;
                label_14000a413:
                    
                    if (be_1 >= 0 && fpi->int_max >= k_14)
                        goto label_14000a319;
                    
                    goto label_14000a41e;
                }
                
                zmm1 = zmm0_3 + zmm0_3;
                zmm1 = zmm1 + 7.0;
                int64_t rdx_24 = zmm1;
                rdx_26 = rdx_24 | ((rdx_24 >> 0x20) - 0x3400000) << 0x20;
                
                if (!var_90)
                    goto label_14000a3df;
                
                i_19 = var_90;
                k_17 = 0;
            label_14000a0d5:
                zmm2 = rdx_26;
                double zmm3 = __tens_D2A[i_19 - 1];
                char rcx_18;
                void* result_3;
                
                if (!var_c0_1)
                {
                    zmm0_3 = r10_5;
                    result_3 = result_1;
                    char r9_12 = 0;
                    uint128_t zmm4_2;
                    zmm4_2 = zmm2 * zmm3;
                    i = 1;
                    zmm1 = zmm0_3;
                    
                    while (true)
                    {
                        int32_t rcx_54 = zmm1;
                        
                        if (rcx_54)
                        {
                            r9_12 = rdi_2;
                            zmm1 = zmm1 - rcx_54;
                        }
                        
                        result_3 += 1;
                        rcx_18 = rcx_54 + 0x30;
                        *(result_3 - 1) = rcx_18;
                        int i_15 = i;
                        
                        if (i_15 == i_19)
                            break;
                        
                        zmm1 = zmm1 * 0x4024000000000000;
                        r9_12 = rdi_2;
                        i = i_15 + 1;
                    }
                    
                    if (!r9_12)
                        zmm1 = zmm0_3;
                    
                    zmm0_3 = 0x3fe0000000000000;
                    zmm2 = zmm4_2 + zmm0_3;
                    
                    if (zmm1 > zmm2)
                    {
                        result = result_1;
                        goto label_14000a1af;
                    }
                    
                    zmm0_3 = zmm0_3 - zmm4_2;
                    
                    if (zmm0_3 > zmm1)
                    {
                        result = result_1;
                        zmm1 - 0.0;
                        int32_t rax_147;
                        rax_147 = FCMP_UO(zmm1, 0.0);
                        
                        if (zmm1 != 0.0)
                            rax_147 = 1;
                        
                        var_88_1 = rax_147 << 4;
                        goto label_14000afeb;
                    }
                    
                    if (be_1 < 0 || fpi->int_max < 0)
                    {
                        var_80_1 = 0;
                        k_6 = k;
                        rdi_5 = nullptr;
                        i_20 = i_21;
                        goto label_14000a4b8;
                    }
                    
                    var_80_1 = 0;
                    zmm2 = 0x3ff0000000000000;
                label_14000aadc:
                    zmm0_3 = rax_18;
                    char* result_5 = result_1;
                    i = 1;
                    result_3 = &result_5[1];
                    zmm1 = zmm0_3 / zmm2;
                    int32_t rax_119 = zmm1;
                    zmm1 = rax_119;
                    *result_5 = rax_119 + 0x30;
                    zmm1 = zmm1 * zmm2;
                    k_15 = k_14 + 1;
                    zmm0_3 = zmm0_3 - zmm1;
                    zmm1 = {0};
                    zmm0_3 - zmm1;
                    
                    if (FCMP_UO(zmm0_3, zmm1) || !(zmm0_3 == zmm1))
                    {
                        zmm3 = {0};
                        
                        while (true)
                        {
                            int i_11 = i;
                            
                            if (i_11 == var_90)
                                break;
                            
                            zmm0_3 = zmm0_3 * 0x4024000000000000;
                            result_3 += 1;
                            i = i_11 + 1;
                            zmm1 = zmm0_3 / zmm2;
                            rax_119 = zmm1;
                            zmm1 = rax_119;
                            *(result_3 - 1) = rax_119 + 0x30;
                            zmm1 = zmm1 * zmm2;
                            zmm0_3 = zmm0_3 - zmm1;
                            zmm0_3 - zmm3;
                            
                            if (!FCMP_UO(zmm0_3, zmm3))
                            {
                                if (zmm0_3 == zmm3)
                                    goto label_14000acbd;
                            }
                        }
                        
                        if (!var_80_1)
                        {
                            zmm0_3 = zmm0_3 + zmm0_3;
                            rcx_18 = *(result_3 - 1);
                            
                            if (zmm0_3 > zmm2)
                            {
                                result = result_1;
                                k_17 = k_14;
                            label_14000a1af:
                                char rcx_19;
                                
                                while (true)
                                {
                                    if (rcx_18 != 0x39)
                                    {
                                        result_1 = result_3;
                                        rcx_19 = rcx_18 + 1;
                                        break;
                                    }
                                    
                                    if (result_3 - 1 == result)
                                    {
                                        result_1 = result_3;
                                        k_17 += 1;
                                        rcx_19 = 0x31;
                                        break;
                                    }
                                    
                                    rcx_18 = *(result_3 - 2);
                                    result_3 -= 1;
                                }
                                
                                *(result_3 - 1) = rcx_19;
                                k_15 = k_17 + 1;
                                var_88_1 = 0x20;
                            }
                            else
                            {
                                zmm0_3 - zmm2;
                                result = result_1;
                                k_17 = k_14;
                                
                                if (!FCMP_UO(zmm0_3, zmm2) && !(zmm0_3 != zmm2) && rax_119 & 1)
                                    goto label_14000a1af;
                                
                                var_88_1 = 0x10;
                            label_14000afeb:
                                void* result_2;
                                
                                do
                                {
                                    result_2 = result_3;
                                    result_3 -= 1;
                                } while (*(result_2 - 1) == 0x30);
                                
                                result_1 = result_2;
                                k_15 = k_17 + 1;
                            }
                        }
                        else
                        {
                            if (var_80_1 == 1)
                            {
                                rcx_18 = *(result_3 - 1);
                                result = result_1;
                                k_17 = k_14;
                                goto label_14000a1af;
                            }
                            
                            result = result_1;
                            var_88_1 = 0x10;
                            result_1 = result_3;
                        }
                    }
                    else
                    {
                    label_14000acbd:
                        result = result_1;
                        result_1 = result_3;
                    }
                }
                else
                {
                    int32_t rcx_14 = zmm0_3;
                    zmm1 = 0x3fe0000000000000 / zmm3;
                    result_3 = &result_1[1];
                    zmm1 = zmm1 - zmm2;
                    zmm2 = rcx_14;
                    *result_1 = rcx_14 + 0x30;
                    zmm0_3 = zmm0_3 - zmm2;
                    
                    if (!(zmm1 > zmm0_3))
                    {
                        zmm3 = 10.0;
                        
                        while (true)
                        {
                            zmm2 = 0x3ff0000000000000 - zmm0_3;
                            
                            if (!(zmm1 <= zmm2))
                            {
                                rcx_18 = *(result_3 - 1);
                                result = result_1;
                                break;
                            }
                            
                            int i_9 = i + 1;
                            i = i_9;
                            
                            if (i_9 >= i_19)
                                goto label_14000a408;
                            
                            zmm0_3 = zmm0_3 * zmm3;
                            result_3 += 1;
                            zmm1 = zmm1 * zmm3;
                            int32_t rcx_16 = zmm0_3;
                            zmm2 = rcx_16;
                            *(result_3 - 1) = rcx_16 + 0x30;
                            zmm0_3 = zmm0_3 - zmm2;
                            
                            if (zmm1 > zmm0_3)
                                goto label_14000b008;
                        }
                        
                        goto label_14000a1af;
                    }
                    
                label_14000b008:
                    result = result_1;
                    zmm0_3 - 0.0;
                    result_1 = result_3;
                    int32_t rax_139;
                    rax_139 = FCMP_UO(zmm0_3, 0.0);
                    
                    if (zmm0_3 != 0.0)
                        rax_139 = 1;
                    
                    var_88_1 = rax_139 << 4;
                    k_15 = k_17 + 1;
                }
            }
            __Bfree_D2A(rbx_3);
            *result_1 = 0;
            *decpt = k_15;
            
            if (rve)
                *rve = result_1;
            
            *kindp_1 |= var_88_1;
            return result;
        }
        
        if (rax_7 != 4)
            return nullptr;
        
        rve_1 = rve;
        r8_4 = 3;
        rcx_6 = &data_140011b09;
        *decpt = 0xffff8000;
    }
    
    /* tailcall */
    return __nrv_alloc_D2A(rcx_6, rve_1, r8_4);
}

void __rshift_D2A(struct __Bigint* b, int k)
{
    int64_t wds = b->wds;
    int32_t r12_1 = k >> 5;
    
    if (wds > r12_1)
    {
        int64_t r12_2 = r12_1;
        void* r11_1 = &(&b->x)[wds];
        void* rsi_1 = &(&b->x)[r12_2];
        int32_t rdx = k & 0x1f;
        long unsigned int (* rax_4)[0x1];
        
        if (!rdx)
        {
            int32_t* rdi_2 = &b->x;
            
            if (rsi_1 < r11_1)
            {
                do
                {
                    *rdi_2 = *rsi_1;
                    rdi_2 = &rdi_2[1];
                    rsi_1 += 4;
                } while (rsi_1 < r11_1);
                
                rax_4 = &(&b->x)[wds - r12_2];
                goto label_14000b2a9;
            }
            
            b->wds = 0;
        }
        else
        {
            void* r8_1 = rsi_1 + 4;
            long unsigned int r9_2[0x1] = *rsi_1 >> rdx;
            
            if (r8_1 < r11_1)
            {
                long unsigned int (* rsi_2)[0x1] = &b->x;
                
                do
                {
                    int32_t rax_1 = *r8_1;
                    rsi_2 = &rsi_2[1];
                    r8_1 += 4;
                    rsi_2[-1] = rax_1 << (0x20 - rdx) | r9_2;
                    r9_2 = *(r8_1 - 4) >> rdx;
                } while (r8_1 < r11_1);
                
                rax_4 = &(&b->x)[wds - r12_2 - 1];
                *rax_4 = r9_2;
                
                if (!r9_2)
                    goto label_14000b2a9;
                
                goto label_14000b27b;
            }
            
            b->x = r9_2;
            
            if (!r9_2)
                b->wds = 0;
            else
            {
                rax_4 = &b->x;
            label_14000b27b:
                rax_4 = &rax_4[1];
            label_14000b2a9:
                int rax = (rax_4 - &b->x) >> 2;
                b->wds = rax;
                
                if (rax)
                    return;
            }
        }
    }
    else
        b->wds = 0;
    
    b->x = 0;
}

int __trailz_D2A(struct __Bigint* b)
{
    long unsigned int (* rax)[0x1] = &b->x;
    void* rcx = &rax[b->wds];
    int32_t result = 0;
    
    if (rax < rcx)
    {
        do
        {
            if (ADJ(rax)->x)
            {
                if (rax < rcx)
                    return result + _tzcnt_u32(ADJ(rax)->x);
                
                break;
            }
            
            rax = &rax[1];
            result += 0x20;
        } while (rax < rcx);
    }
    
    return result;
}

long int dtoa_lock(int n)
{
    long int dtoa_CS_init_1 = dtoa_CS_init;
    
    if (dtoa_CS_init_1 != 2)
    {
        if (dtoa_CS_init_1)
        {
            if (dtoa_CS_init_1 != 1)
                return dtoa_CS_init_1;
            
        label_14000b360:
            
            do
            {
                Sleep(1);
                dtoa_CS_init_1 = dtoa_CS_init;
            } while (dtoa_CS_init_1 == 1);
            
            goto label_14000b362;
        }
        
        long int dtoa_CS_init_2 = dtoa_CS_init;
        dtoa_CS_init = 1;
        
        if (!dtoa_CS_init_2)
        {
            InitializeCriticalSection(&dtoa_CritSec);
            InitializeCriticalSection(&dtoa_CritSec[1]);
            atexit(dtoa_lock_cleanup);
            dtoa_CS_init = 2;
        }
        else if (dtoa_CS_init_2 == 2)
            dtoa_CS_init = 2;
        else
        {
            dtoa_CS_init_1 = dtoa_CS_init;
            
            if (dtoa_CS_init_1 == 1)
                goto label_14000b360;
            
        label_14000b362:
            
            if (dtoa_CS_init_1 != 2)
                return dtoa_CS_init_1;
        }
    }
    
    /* tailcall */
    return EnterCriticalSection((-(n) & 0x28) + &dtoa_CritSec);
}

void dtoa_lock_cleanup()
{
    long int dtoa_CS_init_1 = dtoa_CS_init;
    dtoa_CS_init = 3;
    
    if (dtoa_CS_init_1 != 2)
        return;
    
    DeleteCriticalSection(&dtoa_CritSec);
    /* tailcall */
    return DeleteCriticalSection(&dtoa_CritSec[1]);
}

int64_t* __Balloc_D2A(int k)
{
    dtoa_lock(0);
    int64_t* pmem_next_1;
    uint64_t rcx_3;
    int32_t rsi_1;
    
    if (k > 9)
    {
        rsi_1 = 1 << k;
        rcx_3 = (((rsi_1 - 1) << 2) + 0x27) >> 3;
    label_14000b4d8:
        pmem_next_1 = malloc(rcx_3 << 3);
        
        if (pmem_next_1)
            goto label_14000b4e2;
    }
    else
    {
        int64_t k_1 = k;
        pmem_next_1 = freelist[k_1];
        
        if (!pmem_next_1)
        {
            rsi_1 = 1 << k;
            pmem_next_1 = pmem_next;
            rcx_3 = (((rsi_1 - 1) << 2) + 0x27) >> 3;
            
            if (((pmem_next_1 - &private_mem) >> 3) + rcx_3 > 0x120)
                goto label_14000b4d8;
            
            pmem_next = &pmem_next_1[rcx_3];
        label_14000b4e2:
            bool cond:0_1 = dtoa_CS_init == 2;
            pmem_next_1[1] = k;
            *(pmem_next_1 + 0xc) = rsi_1;
            
            if (cond:0_1)
            {
                LeaveCriticalSection(&dtoa_CritSec);
                pmem_next_1[2] = 0;
            }
            else
                pmem_next_1[2] = 0;
        }
        else
        {
            bool cond:1_1 = dtoa_CS_init != 2;
            freelist[k_1] = *pmem_next_1;
            
            if (cond:1_1)
                pmem_next_1[2] = 0;
            else
            {
                LeaveCriticalSection(&dtoa_CritSec);
                pmem_next_1[2] = 0;
            }
        }
    }
    return pmem_next_1;
}

void __Bfree_D2A(struct __Bigint* v)
{
    if (!v)
        return;
    
    if (v->k > 9)
        /* tailcall */
        return free(v);
    
    dtoa_lock(0);
    int64_t k = v->k;
    bool cond:0_1 = dtoa_CS_init == 2;
    int64_t rcx_1 = freelist[k];
    freelist[k] = v;
    v->next = rcx_1;
    
    if (cond:0_1)
        /* tailcall */
        return LeaveCriticalSection(&dtoa_CritSec);
}

struct __Bigint* __multadd_D2A(struct __Bigint* b, int m, int a)
{
    int wds = b->wds;
    int64_t a_1 = a;
    int64_t rcx = 0;
    
    do
    {
        int64_t rax_3 = (&b->x)[rcx] * m + a_1;
        (&b->x)[rcx] = rax_3;
        rcx += 1;
        a_1 = rax_3 >> 0x20;
    } while (wds > rcx);
    
    struct __Bigint* result = b;
    
    if (a_1)
    {
        if (b->maxwds <= wds)
        {
            struct __Bigint* result_1 = __Balloc_D2A(b->k + 1);
            result = result_1;
            
            if (result_1)
            {
                memcpy(&result_1->sign, &b->sign, (b->wds << 2) + 8);
                struct __Bigint* result_2 = result;
                __Bfree_D2A(b);
                result = result_2;
                (&result_2->x)[wds] = a_1;
                result_2->wds = wds + 1;
            }
        }
        else
        {
            result = b;
            (&b->x)[wds] = a_1;
            b->wds = wds + 1;
        }
    }
    
    return result;
}

struct __Bigint* __i2b_D2A(int i)
{
    dtoa_lock(0);
    struct __Bigint* pmem_next_1 = freelist[1];
    
    if (!pmem_next_1)
    {
        pmem_next_1 = pmem_next;
        
        if (((pmem_next_1 - &private_mem) >> 3) + 5 <= 0x120)
        {
            pmem_next = pmem_next_1 + 0x28;
        label_14000b71b:
            bool cond:1_1 = dtoa_CS_init != 2;
            pmem_next_1->k = 1;
            pmem_next_1->maxwds = 2;
            
            if (cond:1_1)
                goto label_14000b6ca;
            
            goto label_14000b733;
        }
        
        pmem_next_1 = malloc(0x28);
        
        if (pmem_next_1)
            goto label_14000b71b;
    }
    else
    {
        bool cond:0_1 = dtoa_CS_init == 2;
        freelist[1] = pmem_next_1->next;
        
        if (!cond:0_1)
            goto label_14000b6ca;
        
    label_14000b733:
        LeaveCriticalSection(&dtoa_CritSec);
    label_14000b6ca:
        pmem_next_1->x = i;
        pmem_next_1->sign = 0;
        pmem_next_1->wds = 1;
    }
    
    return pmem_next_1;
}

int64_t* __mult_D2A(struct __Bigint* a, struct __Bigint* b)
{
    int64_t wds_1 = a->wds;
    int64_t wds = b->wds;
    struct __Bigint* r9 = a;
    struct __Bigint* r15 = b;
    
    if (wds_1 >= wds)
    {
        int32_t wds_2 = wds;
        r15 = a;
        wds = wds_1;
        r9 = b;
        wds_1 = wds_2;
    }
    
    int k = r15->k;
    int32_t i_1 = wds + wds_1;
    
    if (r15->maxwds < i_1)
        k += 1;
    
    int64_t* result = __Balloc_D2A(k);
    
    if (result)
    {
        void* r12_1 = &result[3];
        void* rsi_1 = r12_1 + (i_1 << 2);
        
        if (r12_1 < rsi_1)
            memset(r12_1, 0, ((rsi_1 - result - 0x19) >> 2 << 2) + 4);
        
        long unsigned int (* r9_2)[0x1] = &r9->x;
        void* r14 = &r9_2[wds_1];
        void* r13 = &(&r15->x)[wds];
        
        if (r9_2 < r14)
        {
            void* rax_10 = 4;
            
            if (r13 >= &r15->x[0] + 1)
                rax_10 = ((r13 - r15 - 0x19) >> 2 << 2) + 4;
            
            while (true)
            {
                uint64_t x_1 = ADJ(r9_2)->x;
                r9_2 = &r9_2[1];
                
                if (!x_1)
                {
                    r12_1 += 4;
                    
                    if (r9_2 >= r14)
                        break;
                }
                else
                {
                    void* rcx_1 = r12_1;
                    long unsigned int (* rdx_1)[0x1] = &r15->x;
                    uint64_t r8_2 = 0;
                    
                    do
                    {
                        uint64_t x = ADJ(rdx_1)->x;
                        uint64_t r15_1 = *rcx_1;
                        rdx_1 = &rdx_1[1];
                        rcx_1 += 4;
                        int64_t rax_13 = x * x_1 + r15_1 + r8_2;
                        *(rcx_1 - 4) = rax_13;
                        r8_2 = rax_13 >> 0x20;
                    } while (rdx_1 < r13);
                    
                    r12_1 += 4;
                    *(r12_1 + rax_10 - 4) = r8_2;
                    
                    if (r9_2 >= r14)
                        break;
                }
            }
        }
        
        if (i_1 > 0)
        {
            int32_t i;
            
            do
            {
                int32_t rax_15 = *(rsi_1 - 4);
                rsi_1 -= 4;
                
                if (rax_15)
                    break;
                
                i = i_1;
                i_1 -= 1;
            } while (i != 1);
        }
        
        *(result + 0x14) = i_1;
    }
    
    return result;
}

struct __Bigint* __pow5mult_D2A(struct __Bigint* b, int k)
{
    struct __Bigint* rsi = b;
    int32_t rax_1 = k & 3;
    struct __Bigint* rax_5;
    
    if (rax_1)
    {
        rax_5 = __multadd_D2A(b, p05[rax_1 - 1], 0);
        rsi = rax_5;
    }
    
    if (!rax_1 || rax_5)
    {
        int32_t rbx_1 = k >> 2;
        
        if (!rbx_1)
            return rsi;
        
        struct __Bigint* p5s_1 = p5s;
        
        if (p5s_1)
            goto label_14000b8f7;
        
        dtoa_lock(1);
        p5s_1 = p5s;
        
        if (p5s_1)
            goto label_14000b9e6;
        
        struct __Bigint* p5s_2 = __Balloc_D2A(1);
        p5s_1 = p5s_2;
        
        if (!p5s_2)
            p5s = nullptr;
        else
        {
            p5s = p5s_1;
            p5s_1->wds = 1;
            p5s_1->x = 0x271;
            p5s_1->next = 0;
        label_14000b9e6:
            
            if (dtoa_CS_init != 2)
                goto label_14000b8f7;
            
            LeaveCriticalSection(&dtoa_CritSec[1]);
        label_14000b8f7:
            struct __Bigint* a = rsi;
            
            while (true)
            {
                if (!(rbx_1 & 1))
                {
                    rbx_1 s>>= 1;
                    
                    if (!rbx_1)
                        return a;
                }
                else
                {
                    int64_t* a_1 = __mult_D2A(a, p5s_1);
                    
                    if (!a_1)
                        return nullptr;
                    
                    struct __Bigint* v = a;
                    a = a_1;
                    __Bfree_D2A(v);
                    rbx_1 s>>= 1;
                    
                    if (!rbx_1)
                        return a;
                }
                
                int64_t* next = p5s_1->next;
                
                if (!next)
                {
                    dtoa_lock(1);
                    next = p5s_1->next;
                    
                    if (!next)
                    {
                        int64_t* next_1 = __mult_D2A(p5s_1, p5s_1);
                        p5s_1->next = next_1;
                        next = next_1;
                        
                        if (!next_1)
                            return nullptr;
                        
                        *next_1 = 0;
                    }
                    
                    if (dtoa_CS_init == 2)
                        LeaveCriticalSection(&dtoa_CritSec[1]);
                }
                
                p5s_1 = next;
            }
        }
    }
    
    return nullptr;
}

int64_t* __lshift_D2A(struct __Bigint* b, int k)
{
    int k_1 = b->k;
    uint64_t rsi_1 = k >> 5;
    int maxwds = b->maxwds;
    int32_t rbx_1 = b->wds + rsi_1;
    int32_t r12 = rbx_1 + 1;
    
    while (r12 > maxwds)
    {
        maxwds *= 2;
        k_1 += 1;
    }
    
    int64_t* result = __Balloc_D2A(k_1);
    
    if (result)
    {
        void* rdi_1 = &result[3];
        
        if (rsi_1 > 0)
        {
            uint64_t _Size = rsi_1 << 2;
            void* rcx = rdi_1;
            rdi_1 += _Size;
            memset(rcx, 0, _Size);
        }
        
        void* rsi_2 = &b->x;
        void* r8_2 = rsi_2 + (b->wds << 2);
        int32_t r14_1 = k & 0x1f;
        
        if (!r14_1)
        {
            do
            {
                *rdi_1 = *rsi_2;
                void* rdi_2 = rdi_1 + 4;
                void* rsi_3 = rsi_2 + 4;
                
                if (rsi_3 >= r8_2)
                    break;
                
                *rdi_2 = *rsi_3;
                rdi_1 = rdi_2 + 4;
                rsi_2 = rsi_3 + 4;
            } while (rsi_2 < r8_2);
            
            r12 = rbx_1;
        }
        else
        {
            void* r9_1 = rdi_1;
            uint32_t rdx = 0;
            
            do
            {
                int32_t rax_1 = *rsi_2;
                r9_1 += 4;
                rsi_2 += 4;
                *(r9_1 - 4) = rax_1 << r14_1 | rdx;
                rdx = *(rsi_2 - 4) >> (0x20 - r14_1);
            } while (rsi_2 < r8_2);
            
            void* rax_8 = ((r8_2 - b - 0x19) >> 2 << 2) + 4;
            
            if (r8_2 < &b->x[0] + 1)
                rax_8 = 4;
            
            *(rdi_1 + rax_8) = rdx;
            
            if (!rdx)
                r12 = rbx_1;
        }
        
        *(result + 0x14) = r12;
        __Bfree_D2A(b);
    }
    
    return result;
}

int __cmp_D2A(struct __Bigint* a, struct __Bigint* b)
{
    int64_t wds = b->wds;
    int wds_1 = a->wds;
    int32_t result = wds_1 - wds;
    
    if (wds_1 == wds)
    {
        void* i = &(&a->x)[wds];
        void* rdx = &(&b->x)[wds];
        
        do
        {
            i -= 4;
            rdx -= 4;
            int32_t r10_1 = *rdx;
            int32_t temp1_1 = *i;
            
            if (temp1_1 != r10_1)
                return (result - result) | 1;
        } while (&a->x < i);
    }
    
    return result;
}

int64_t* __diff_D2A(struct __Bigint* a, struct __Bigint* b)
{
    int64_t wds = b->wds;
    struct __Bigint* a_1 = a;
    struct __Bigint* b_1 = b;
    int wds_2 = a->wds;
    int64_t* result;
    int32_t rdi_2;
    
    if (wds_2 != wds)
    {
        rdi_2 = 1;
        
        if (wds_2 - wds >= 0)
        {
        label_14000bc2e:
            struct __Bigint* rax = b_1;
            rdi_2 = 0;
            b_1 = a_1;
            a_1 = rax;
        }
        
    label_14000bc3c:
        int64_t* result_1 = __Balloc_D2A(b_1->k);
        result = result_1;
        
        if (result_1)
        {
            result_1[2] = rdi_2;
            int64_t wds_1 = b_1->wds;
            long unsigned int (* r13_1)[0x1] = &b_1->x;
            void* rcx_2 = 0x18;
            uint64_t rdx_2 = 0;
            int32_t r10_1 = wds_1;
            void* r11_1 = &r13_1[wds_1];
            void* i = &(&a_1->x)[a_1->wds];
            int32_t rdi_4;
            
            do
            {
                uint64_t rax_4 = *(b_1 + rcx_2) - *(a_1 + rcx_2) - rdx_2;
                *(result + rcx_2) = rax_4;
                rcx_2 += 4;
                rdi_4 = rax_4;
                rdx_2 = rax_4 >> 0x20 & 1;
            } while (rcx_2 + a_1 < i);
            
            b_1 = i >= &a_1->x[0] + 1;
            uint64_t r14_2 = (i - a_1 - 0x19) >> 2;
            void* rax_7 = (r14_2 << 2) + 4;
            
            if (!b_1)
                rax_7 = 4;
            
            void* r13_2 = r13_1 + rax_7;
            void* r8_2 = &result[3] + rax_7;
            void* rbx = r8_2;
            void* rcx_3 = r13_2;
            void* rax_10;
            
            if (r13_2 >= r11_1)
            {
                uint64_t r14_3 = r14_2 << 2;
                
                if (!b_1)
                    r14_3 = 0;
                
                rax_10 = &result[3] + r14_3;
            }
            else
            {
                do
                {
                    uint64_t rax_8 = *rcx_3;
                    rcx_3 += 4;
                    rbx += 4;
                    uint64_t rax_9 = rax_8 - rdx_2;
                    *(rbx - 4) = rax_9;
                    rdi_4 = rax_9;
                    rdx_2 = rax_9 >> 0x20 & 1;
                } while (rcx_3 < r11_1);
                
                rax_10 = r8_2 + ((r11_1 - 1 - r13_2) & 0xfffffffffffffffc);
            }
            
            if (!rdi_4)
            {
                int32_t i_1;
                
                do
                {
                    i_1 = *(rax_10 - 4);
                    rax_10 -= 4;
                    r10_1 -= 1;
                } while (!i_1);
            }
            
            *(result + 0x14) = r10_1;
        }
    }
    else
    {
        void* i_2 = &(&a->x)[wds];
        void* rdx_1 = &(&b_1->x)[wds];
        
        do
        {
            i_2 -= 4;
            rdx_1 -= 4;
            int32_t rdi_1 = *rdx_1;
            int32_t temp1_1 = *i_2;
            
            if (temp1_1 != rdi_1)
            {
                rdi_2 = 1;
                
                if (temp1_1 < rdi_1)
                    goto label_14000bc3c;
                
                goto label_14000bc2e;
            }
        } while (&a->x < i_2);
        
        int64_t* result_2 = __Balloc_D2A(0);
        result = result_2;
        
        if (result_2)
            *(result_2 + 0x14) = 1;
    }
    return result;
}

uint64_t __b2d_D2A(struct __Bigint* a, int* e)
{
    void* r10 = &(&a->x)[a->wds];
    int32_t r9 = *(r10 - 4);
    uint64_t rflags;
    int32_t temp0;
    temp0 = _bit_scan_reverse(r9);
    int32_t rdi_1 = temp0 ^ 0x1f;
    *e = 0x20 - rdi_1;
    
    if (rdi_1 <= 0xa)
    {
        uint32_t r8_2 = 0;
        
        if (&a->x < r10 - 4)
            r8_2 = *(r10 - 8) >> (0xb - rdi_1);
        
        return (r9 >> (0xb - rdi_1) | 0x3ff00000) << 0x20 | r9 << (rdi_1 + 0x15) | r8_2;
    }
    
    uint64_t rax_5;
    uint64_t rdx;
    
    if (&a->x >= r10 - 4)
    {
        rdx = 0;
        
        if (rdi_1 != 0xb)
            return (r9 << (rdi_1 - 0xb) | 0x3ff00000) << 0x20;
        
        rax_5 = (r9 | 0x3ff00000) << 0x20;
    }
    else
    {
        rdx = *(r10 - 8);
        
        if (rdi_1 == 0xb)
            rax_5 = (r9 | 0x3ff00000) << 0x20;
        else
        {
            int32_t rax_3 = r9 << (rdi_1 - 0xb) | rdx >> (0x20 - (rdi_1 - 0xb));
            rdx = rdx << (rdi_1 - 0xb);
            rax_5 = (rax_3 | 0x3ff00000) << 0x20;
            
            if (&a->x < r10 - 8)
                return rax_5 | rdx | *(r10 - 0xc) >> (0x20 - (rdi_1 - 0xb));
        }
    }
    
    return rax_5 | rdx;
}

int64_t* __d2b_D2A(double dd, int* e, int* bits)
{
    int64_t* result = __Balloc_D2A(1);
    
    if (result)
    {
        int64_t rax = dd;
        uint32_t rcx_2 = rax >> 0x20;
        uint32_t r9_2 = rcx_2 & 0xfffff;
        int32_t rcx_4 = rcx_2 >> 0x14 & 0x7ff;
        
        if (rcx_4)
            r9_2 |= 0x100000;
        
        int32_t rax_2;
        uint32_t r8_2;
        
        if (!rax)
        {
            rax_2 = 1;
            uint32_t temp0_3 = _tzcnt_u32(r9_2);
            *(result + 0x14) = 1;
            r8_2 = temp0_3 + 0x20;
            result[3] = r9_2 >> temp0_3;
            
            if (rcx_4)
            {
            label_14000bfaf:
                *e = rcx_4 + r8_2 - 0x433;
                *bits = 0x35 - r8_2;
                return result;
            }
        }
        else
        {
            r8_2 = _tzcnt_u32(rax);
            uint32_t rax_1 = rax >> r8_2;
            
            if (r8_2)
            {
                rax_1 |= r9_2 << (0x20 - r8_2);
                r9_2 u>>= r8_2;
            }
            
            result[3] = rax_1;
            rax_2 = 1 + 1;
            *(result + 0x1c) = r9_2;
            *(result + 0x14) = rax_2;
            
            if (rcx_4)
                goto label_14000bfaf;
        }
        
        uint64_t rflags_1;
        int32_t temp0_2;
        temp0_2 = __bsr_gprv_memv(*(result + (rax_2 << 2) + 0x14));
        *e = r8_2 - 0x432;
        *bits = (rax_2 << 5) - (temp0_2 ^ 0x1f);
    }
    
    return result;
}

char* __strcp_D2A(char* a, char const* b)
{
    char* result = a;
    void* rcx = &b[1];
    char const rdx = *b;
    *result = rdx;
    
    if (rdx)
    {
        char i;
        
        do
        {
            i = *rcx;
            result = &result[1];
            rcx += 1;
            *result = i;
        } while (i);
    }
    
    return result;
}

struct __Bigint* __increment_D2A(struct __Bigint* b)
{
    int64_t wds = b->wds;
    int32_t r8 = wds;
    long unsigned int (* i)[0x1] = &b->x;
    struct __Bigint* result = b;
    
    do
    {
        long unsigned int x[0x1] = ADJ(i)->x;
        
        if (x != 0xffffffff)
        {
            ADJ(i)->x = x + 1;
            return result;
        }
        
        i = &i[1];
        ADJ(i)->wds = 0;
    } while (i < &i[wds]);
    
    if (r8 >= result->maxwds)
    {
        int64_t* result_1 = __Balloc_D2A(result->k + 1);
        memcpy(&result_1[2], &result->sign, (result->wds << 2) + 8);
        struct __Bigint* v = result;
        result = result_1;
        __Bfree_D2A(v);
        wds = *(result_1 + 0x14);
        r8 = wds;
    }
    
    result->wds = r8 + 1;
    (&result->x)[wds] = 1;
    return result;
}

int rvOK(union _dbl_union* d, struct FPI* fpi, long int* expo, long unsigned int* bits, int exact, int rd, int* irv)
{
    int bdif;
    long int e;
    double entry_dd;
    int64_t* rax = __d2b_D2A(entry_dd, &e, &bdif);
    int bdif_1 = bdif;
    int nbits = fpi->nbits;
    int64_t* rbx = rax;
    int32_t k = bdif_1 - nbits;
    long int rax_2 = e + k;
    bdif = k;
    e = rax_2;
    int sudden_underflow;
    int32_t r9;
    long unsigned int r13_1;
    
    if (k <= 0)
    {
        sudden_underflow = 0;
        
        if (exact)
        {
            if (k)
            {
                rbx = __lshift_D2A(rbx, nbits - bdif_1);
                rax_2 = e;
            }
            
            r13_1 = 0;
            r9 = 0;
            goto label_14000c1fa;
        }
    }
    else if (nbits == 0x35)
    {
        sudden_underflow = 0;
        
        if (exact && fpi->rounding == 1)
        {
            long unsigned int rax_32 = __any_on_D2A(rbx, k);
            r13_1 = rax_32;
            int32_t r9_6;
            r9_6 = rax_32;
            __rshift_D2A(rbx, bdif);
            rax_2 = e;
            r9 = r9_6 << 4;
        label_14000c1fa:
            long int emin = fpi->emin;
            int32_t rsi_3;
            
            if (emin <= rax_2)
            {
                int emax = fpi->emax;
                
                if (emax < rax_2)
                {
                    rsi_3 = 0;
                    e = emax + 1;
                    *irv = 0xa3;
                    *_errno() = 0x22;
                    emin = e;
                    *(rbx + 0x14) = 0;
                }
                else
                {
                    rsi_3 = r9;
                    emin = rax_2;
                }
                
                goto label_14000c29e;
            }
            
            e = emin;
            int32_t k_2 = emin - rax_2;
            
            if (nbits >= k_2)
                sudden_underflow = fpi->sudden_underflow;
            
            if (nbits < k_2 || sudden_underflow)
            {
                *(rbx + 0x14) = 0;
                rsi_3 = 0;
                *irv = 0x50;
            label_14000c29e:
                *expo = emin;
                sudden_underflow = 1;
                __copybits_D2A(bits, nbits, rbx);
                *irv |= rsi_3;
            }
            else
            {
                int k_1 = k_2 - 1;
                
                if (k_1 > 0 && !r13_1)
                    r13_1 = __any_on_D2A(rbx, k_1);
                
                if (r13_1 | exact)
                {
                    int32_t rsi_2 = 1 << k_1 & *(rbx + (k_1 >> 5 << 2) + 0x18);
                    __rshift_D2A(rbx, k_2);
                    *irv = 2;
                    
                    if (rsi_2)
                    {
                        rsi_3 = 0x60;
                        struct __Bigint* rax_34 = __increment_D2A(rbx);
                        emin = e;
                        rbx = rax_34;
                    }
                    else
                    {
                        rsi_3 = 0x50;
                        emin = e;
                        
                        if (!r13_1)
                            rsi_3 = r9;
                    }
                    
                    goto label_14000c29e;
                }
            }
        }
    }
    else
    {
        if (rd == 1)
        {
            long unsigned int rax_21 = __any_on_D2A(rbx, k);
            r13_1 = rax_21;
            int32_t r9_2;
            r9_2 = rax_21;
            __rshift_D2A(rbx, bdif);
            r9 = r9_2 << 4;
        label_14000c33b:
            rax_2 = e;
            goto label_14000c1fa;
        }
        
        if (rd == 2)
        {
            r13_1 = __any_on_D2A(rbx, k);
            __rshift_D2A(rbx, bdif);
        label_14000c14d:
            rbx = __increment_D2A(rbx);
            int32_t rax_6 = nbits & 0x1f;
            
            if (rax_6)
                rax_6 = 0x20 - rax_6;
            
            uint64_t rflags_1;
            int32_t temp0_1;
            temp0_1 = __bsr_gprv_memv(*(rbx + ((*(rbx + 0x14) - 1) << 2) + 0x18));
            
            if ((temp0_1 ^ 0x1f) == rax_6)
            {
                rax_2 = e;
                r9 = 0x20;
            }
            else
            {
                if (!r13_1)
                    r13_1 = rbx[3] & 1;
                
                __rshift_D2A(rbx, 1);
                r9 = 0x20;
                rax_2 = e + 1;
                e = rax_2;
            }
            
            goto label_14000c1fa;
        }
        
        int32_t r15_1;
        
        if (k != 1)
        {
            r15_1 = *(rbx + ((k - 1) >> 5 << 2) + 0x18) >> (k - 1) & 1;
        label_14000c3a6:
            long unsigned int rax_31 = __any_on_D2A(rbx, k);
            r13_1 = rax_31;
            int32_t r9_4;
            r9_4 = rax_31;
            __rshift_D2A(rbx, bdif);
            r9 = r9_4 << 4;
            
            if (!r15_1)
                goto label_14000c33b;
            
            goto label_14000c14d;
        }
        
        sudden_underflow = 0;
        
        if (exact)
        {
            r15_1 = rbx[3] >> 1 & 1;
            goto label_14000c3a6;
        }
    }
    __Bfree_D2A(rbx);
    return sudden_underflow;
}

long unsigned int (*)[0x1] __decrement_D2A(struct __Bigint* b)
{
    long unsigned int (* result)[0x1] = &b->x;
    void* rcx = &result[b->wds];
    
    do
    {
        long unsigned int x[0x1] = ADJ(result)->x;
        
        if (x)
        {
            ADJ(result)->x = x - 1;
            break;
        }
        
        result = &result[1];
        ADJ(result)->wds = 0xffffffff;
    } while (result < rcx);
    
    return result;
}

struct __Bigint* __set_ones_D2A(struct __Bigint* b, int n)
{
    struct __Bigint* result = b;
    int32_t k = (n + 0x1f) >> 5;
    
    if (b->k < k)
    {
        __Bfree_D2A(b);
        result = __Balloc_D2A(k);
    }
    
    int32_t rax_2 = n >> 5;
    int32_t rsi_1 = n & 0x1f;
    
    if (!rsi_1)
    {
        result->wds = rax_2;
        void* rdx = &(&result->x)[rax_2];
        
        if (&result->x < rdx)
        {
            uint64_t _Size_1 = ((rdx - 1 - &result->x) >> 2 << 2) + 4;
            
            if (rdx < &result->x[0] + 1)
                _Size_1 = 4;
            
            memset(&result->x, 0xff, _Size_1);
        }
        
        return result;
    }
    
    long unsigned int (* r9)[0x1] = &result->x;
    result->wds = rax_2 + 1;
    void* rdx_1 = &r9[rax_2 + 1];
    
    if (r9 < rdx_1)
    {
        void* _Size = ((rdx_1 - 1 - r9) >> 2 << 2) + 4;
        
        if (rdx_1 < &result->x[0] + 1)
            _Size = 4;
        
        r9 = memset(r9, 0xff, _Size) + _Size;
    }
    
    ADJ(r9)->wds u>>= 0x20 - rsi_1;
    return result;
}

int __strtodg(char const* s00, char** se, struct FPI* fpi, long int* expo, long unsigned int* bits)
{
    uint128_t zmm6;
    uint128_t var_98 = zmm6;
    uint128_t zmm7;
    uint128_t var_88 = zmm7;
    uint128_t zmm8;
    uint128_t var_78 = zmm8;
    uint128_t zmm9;
    uint128_t var_68 = zmm9;
    uint128_t zmm10;
    uint128_t var_58 = zmm10;
    char const* r12 = s00;
    char* decimal_point = localeconv()->decimal_point;
    int dplen = strlen(decimal_point);
    int irv = 0;
    struct __Bigint* rvb = nullptr;
    int nbits = fpi->nbits;
    char const* s_2 = r12;
    int sign;
    char const* s;
    void* s_1;
    char const i;
    int32_t r10_1;
    
    while (true)
    {
        s = s_2;
        i = *s_2;
        s_1 = s_2;
        
        switch (i)
        {
            case 0:
            {
            label_14000c6e0:
                
                if (se)
                    *se = r12;
                
                return 6;
                break;
            }
            case 9:
            case 0xa:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0x20:
            {
                s_2 = &s_2[1];
                continue;
            }
            case 0x2b:
            {
                sign = 0;
            label_14000c6c2:
                s_1 = &s_2[1];
                s = s_1;
                i = s_2[1];
                
                if (!i)
                    goto label_14000c6e0;
                
                r10_1 = 0;
                break;
                break;
            }
            case 0x2d:
            {
                sign = 1;
                goto label_14000c6c2;
            }
            default:
            {
                sign = 0;
                r10_1 = 0;
                break;
            }
        }
    }
    
    struct __Bigint* b_8;
    
    if (i == 0x30)
    {
        void* s_3 = s_1 + 1;
        
        if ((*(s_1 + 1) & 0xdf) != 0x58)
        {
            do
            {
                s = s_3;
                s_1 = s_3;
                i = *s_3;
                s_3 += 1;
            } while (i == 0x30);
            
            r10_1 = 1;
            
            if (i)
                goto label_14000c658;
            
            goto label_14000c978;
        }
        
        int irv_3 = __gethex_D2A(&s, fpi, expo, &rvb, sign);
        irv = irv_3;
        
        if (irv_3 != 6)
            goto label_14000c978;
        
        s = r12;
        
        if (se)
            *se = r12;
        
        b_8 = rvb;
    }
    else
    {
    label_14000c658:
        void* s_4 = s_1;
        uint64_t rdi_1 = 0;
        int nd0 = 0;
        int sudden_underflow = fpi->sudden_underflow;
        int32_t i_2 = i;
        uint64_t rdx_4 = 0;
        
        if (i_2 - 0x30 <= 9)
        {
            do
            {
                if (nd0 <= 8)
                    rdi_1 = i_2 + ((rdi_1 * 5) << 1) - 0x30;
                else if (nd0 <= 0xf)
                    rdx_4 = i_2 + ((rdx_4 * 5) << 1) - 0x30;
                
                s_4 += 1;
                nd0 += 1;
                s = s_4;
                i_2 = *s_4;
                i = i_2;
            } while (i_2 - 0x30 <= 9);
        }
        
        int32_t var_e0_1;
        int32_t var_d8_1;
        int32_t var_d0;
        int r11_1;
        int32_t r14;
        
        if (*decimal_point == i)
        {
            char i_1 = decimal_point[1];
            int64_t r8_10 = 1;
            
            for (; i_1; i_1 = decimal_point[r8_10])
            {
                if (*(s_4 + r8_10) != i_1)
                    goto label_14000c739;
                
                r8_10 += 1;
            }
            
            void* s_6 = s_4 + r8_10;
            s = s_6;
            i_2 = *s_6;
            int32_t rcx_15;
            
            if (!nd0)
            {
                if (i_2 != 0x30)
                    r14 = 0;
                else
                {
                    void* s_9 = s_6;
                    int32_t r9_8;
                    
                    do
                    {
                        r9_8 = s_9;
                        s_9 += 1;
                        s = s_9;
                        i_2 = *s_9;
                    } while (i_2 == 0x30);
                    
                    r14 = r9_8 - s_6 + 1;
                }
                
                if (i_2 - 0x31 > 8)
                {
                    var_e0_1 = 0;
                    r11_1 = 0;
                }
                else
                {
                    char const* s_10 = s;
                    r11_1 = 1;
                    var_d0 = i_2 - 0x30;
                    var_e0_1 = r14 + 1;
                    s_1 = s_10;
                    
                    while (true)
                    {
                        r14 = 0;
                        rdi_1 = var_d0 + ((rdi_1 * 5) << 1);
                        
                        while (true)
                        {
                            s = &s_10[1];
                            i_2 = s_10[1];
                            rcx_15 = i_2 - 0x30;
                            
                            if (rcx_15 > 9)
                                goto label_14000cbb7;
                            
                        label_14000cb8f:
                            var_d0 = rcx_15;
                            s_10 = s;
                            r14 += 1;
                            
                            if (rcx_15)
                            {
                                int rax_152;
                                
                                if (r14 <= 1)
                                    rax_152 = r11_1 + 1;
                                else
                                {
                                    rax_152 = r11_1 + r14;
                                label_14000dc87:
                                    int rbx_6 = r11_1;
                                    r11_1 += 1;
                                    
                                    if (rbx_6 <= 8)
                                        rdi_1 = rdi_1 * 5 * 2;
                                    else if (r11_1 <= 0x10)
                                        rdx_4 = rdx_4 * 5 * 2;
                                    
                                    if (rax_152 - 1 != r11_1)
                                        goto label_14000dc87;
                                }
                                
                                var_e0_1 += r14;
                                
                                if (r11_1 <= 8)
                                {
                                    r11_1 = rax_152;
                                    break;
                                }
                                
                                r14 = 0;
                                r11_1 = rax_152;
                                
                                if (rax_152 <= 0x10)
                                    rdx_4 = rcx_15 + ((rdx_4 * 5) << 1);
                            }
                        }
                    }
                }
            }
            else
            {
                rcx_15 = i_2 - 0x30;
                var_e0_1 = 0;
                r11_1 = nd0;
                r14 = 0;
                
                if (rcx_15 <= 9)
                    goto label_14000cb8f;
            }
        label_14000cbb7:
            var_d8_1 = 1;
        }
        else
        {
        label_14000c739:
            var_e0_1 = 0;
            r11_1 = nd0;
            r14 = 0;
            var_d8_1 = 0;
        }
        
        if ((i_2 & 0xffffffdf) == 0x45)
        {
            if (r11_1 | r14 | r10_1)
            {
                r12 = s;
                s = &r12[1];
                i_2 = r12[1];
                int32_t var_e4_1;
                
                if (i_2 == 0x2b)
                {
                    var_e4_1 = 0;
                    s = &r12[2];
                    i_2 = r12[2];
                }
                else if (i_2 != 0x2d)
                    var_e4_1 = 0;
                else
                {
                    var_e4_1 = 1;
                    s = &r12[2];
                    i_2 = r12[2];
                }
                
                uint64_t r9_1 = i_2 - 0x30;
                
                if (r9_1 > 9)
                {
                    s = r12;
                    var_d0 = 0;
                }
                else
                {
                    char const* s_5 = s;
                    
                    if (i_2 != 0x30)
                        goto label_14000c8b1;
                    
                    void* s_7 = &s_5[1];
                    
                    do
                    {
                        s = s_7;
                        i_2 = *s_7;
                        s_5 = s_7;
                        s_7 += 1;
                    } while (i_2 == 0x30);
                    
                    var_d0 = 0;
                    
                    if (i_2 - 0x31 <= 8)
                    {
                        r9_1 = i_2 - 0x30;
                    label_14000c8b1:
                        s = &s_5[1];
                        i_2 = s_5[1];
                        int32_t var_d0_1;
                        
                        if (i_2 - 0x30 > 9)
                        {
                        label_14000dafe:
                            int32_t rcx_83 = 0x4e1f;
                            
                            if (r9_1 <= 0x4e1f)
                                rcx_83 = r9_1;
                            
                            var_d0_1 = rcx_83;
                        }
                        else
                        {
                            var_d0 = s_5;
                            void* s_8 = &s_5[2];
                            void* s_11;
                            
                            do
                            {
                                s = s_8;
                                s_11 = s_8;
                                s_8 += 1;
                                r9_1 = i_2 + ((r9_1 * 5) << 1) - 0x30;
                                i_2 = *(s_8 - 1);
                            } while (i_2 - 0x30 <= 9);
                            
                            var_d0_1 = 0x4e1f;
                            
                            if (s_11 - var_d0 <= 8)
                                goto label_14000dafe;
                        }
                        
                        int32_t rcx_9 = -(var_d0_1);
                        
                        if (!var_e4_1)
                            rcx_9 = var_d0_1;
                        
                        var_d0 = rcx_9;
                    }
                }
                
                goto label_14000c762;
            }
            
        label_14000cb20:
            irv = 6;
            b_8 = rvb;
            s = r12;
        }
        else
        {
            var_d0 = 0;
        label_14000c762:
            
            if (r11_1)
            {
                irv = 1;
                int k_10 = var_d0 - var_e0_1;
                int32_t rax_19 = fpi->rounding & 3;
                uint64_t d = rax_19 - sign;
                uint32_t rd_1 = d;
                
                if (rax_19 != 2)
                {
                    d = sign + 1;
                    rd_1 = d;
                    
                    if (rax_19 != 3)
                    {
                        rax_19 = !rax_19;
                        rd_1 = rax_19;
                    }
                }
                
                int r14_1 = 0x10;
                uint128_t zmm0_1;
                zmm0_1 = rdi_1;
                
                if (!nd0)
                    nd0 = r11_1;
                
                if (r11_1 <= 0x10)
                    r14_1 = r11_1;
                
                double r12_1 = zmm0_1;
                uint64_t zmm1[0x2];
                
                if (r11_1 > 9)
                {
                    d = &__tens_D2A;
                    zmm1 = {0};
                    zmm1[0] = rdx_4;
                    zmm0_1 = zmm0_1 * __tens_D2A[r14_1 - 9];
                    zmm0_1 = zmm0_1 + zmm1[0];
                    r12_1 = zmm0_1;
                }
                
                int k_14;
                
                if (nbits > 0x35 || r11_1 > 0xf)
                    k_14 = k_10;
                else if (!k_10)
                {
                    if (rvOK(d, fpi, expo, bits, 1, rd_1, &irv))
                        goto label_14000c978;
                    
                    k_14 = 0;
                }
                else
                {
                    int exact;
                    int rd;
                    int* irv_1;
                    int var_d8_2;
                    
                    if (k_10 <= 0)
                    {
                        k_14 = k_10;
                        
                        if (k_10 >= 0xffffffea)
                        {
                            var_d8_2 = r11_1;
                            zmm0_1 = r12_1 / __tens_D2A[var_e0_1 - var_d0];
                        label_14000d3c0:
                            exact = 0;
                            r12_1 = zmm0_1;
                            irv_1 = &irv;
                            rd = rd_1;
                        label_14000caff:
                            r11_1 = var_d8_2;
                            
                            if (rvOK(d, fpi, expo, bits, exact, rd, irv_1))
                                goto label_14000c978;
                            
                            k_14 = 0;
                        }
                    }
                    else
                    {
                        int64_t k_13 = k_10;
                        
                        if (k_13 <= 0x16)
                        {
                            int32_t r8_7 = fivesbits[k_13];
                            
                            if (r12_1)
                                d = 0x35 - _tzcnt_u32(r12_1);
                            else
                                d = 0x15 - _tzcnt_u32(r12_1 >> 0x20 | 0x100000);
                            
                            var_d8_2 = r11_1;
                            zmm0_1 = r12_1 * __tens_D2A[k_13];
                            irv_1 = &irv;
                            rd = rd_1;
                            int exact_1;
                            exact_1 = r8_7 + d <= 0x35;
                            exact = exact_1;
                            r12_1 = zmm0_1;
                            goto label_14000caff;
                        }
                        
                        k_14 = k_10;
                        
                        if (0x25 - r11_1 >= k_10)
                        {
                            var_d8_2 = r11_1;
                            zmm0_1 = r12_1 * __tens_D2A[0xf - r11_1];
                            d = k_10 - (0xf - r11_1);
                            zmm0_1 = zmm0_1 * __tens_D2A[d];
                            goto label_14000d3c0;
                        }
                    }
                }
                
                int32_t r14_2 = r11_1 - r14_1 + k_14;
                
                if (r14_2 > 0)
                {
                    int32_t rax_29 = r14_2 & 0xf;
                    
                    if (rax_29)
                        r12_1 = r12_1 * __tens_D2A[rax_29];
                    
                    r14_2 &= 0xfffffff0;
                    
                    if (r14_2)
                    {
                        int32_t i_4 = r14_2 >> 4;
                        int32_t r8_21;
                        
                        if (r14_2 <= 0xff)
                            r8_21 = 0;
                        else
                        {
                            int32_t i_3 = i_4;
                            int32_t r9_7 = 0;
                            
                            do
                            {
                                i_3 -= 0x10;
                                r8_21 = r9_7 + (r12_1 >> 0x34 & 0x7ff) - 0x3ff;
                                r9_7 = r8_21;
                                r12_1 = (r12_1
                                    | ((r12_1 >> 0x20 & 0x800fffff) | 0x3ff00000) << 0x20)
                                    * 0x75154fdd7f73bf3c;
                            } while (i_3 > 0xf);
                            
                            i_4 &= 0xf;
                        }
                        
                        r14_2 = r8_21 + (r12_1 >> 0x34 & 0x7ff) - 0x3ff;
                        zmm0_1 = r12_1 | ((r12_1 >> 0x20 & 0x800fffff) | 0x3ff00000) << 0x20;
                        
                        if (i_4)
                        {
                            int64_t* rax_90 = &__bigtens_D2A;
                            zmm1 = zmm0_1;
                            char rcx_51 = 0;
                            
                            do
                            {
                                if (i_4 & 1)
                                {
                                    zmm1[0] = zmm1[0] * *rax_90;
                                    rcx_51 = 1;
                                }
                                
                                rax_90 = &rax_90[1];
                                i_4 s>>= 1;
                            } while (i_4);
                            
                            if (rcx_51)
                                zmm0_1 = zmm1;
                        }
                    }
                    else
                        zmm0_1 = r12_1;
                }
                else if (!r14_2)
                    zmm0_1 = r12_1;
                else
                {
                    int32_t r14_5 = -(r14_2);
                    int32_t rax_66 = r14_5 & 0xf;
                    
                    if (rax_66)
                        r12_1 = r12_1 / __tens_D2A[rax_66];
                    
                    r14_2 = r14_5 & 0xfffffff0;
                    
                    if (!r14_2)
                        zmm0_1 = r12_1;
                    else
                    {
                        int32_t i_6 = r14_2 >> 4;
                        int32_t r8_18;
                        
                        if (r14_2 <= 0xff)
                            r8_18 = 0;
                        else
                        {
                            int32_t i_5 = i_6;
                            int32_t r9_6 = 0;
                            
                            do
                            {
                                i_5 -= 0x10;
                                r8_18 = r9_6 + (r12_1 >> 0x34 & 0x7ff) - 0x3ff;
                                r9_6 = r8_18;
                                r12_1 = (r12_1
                                    | ((r12_1 >> 0x20 & 0x800fffff) | 0x3ff00000) << 0x20)
                                    * 0xac8062864ac6f43;
                            } while (i_5 > 0xf);
                            
                            i_6 &= 0xf;
                        }
                        
                        r14_2 = r8_18 + (r12_1 >> 0x34 & 0x7ff) - 0x3ff;
                        uint64_t rax_78 =
                            ((r12_1 >> 0x20 & 0x800fffff) | 0x3ff00000) << 0x20 | r12_1;
                        zmm0_1 = rax_78;
                        
                        if (i_6)
                        {
                            int64_t* rax_79 = &__tinytens_D2A;
                            char rcx_47 = 0;
                            
                            do
                            {
                                if (i_6 & 1)
                                {
                                    zmm0_1 = zmm0_1 * *rax_79;
                                    rcx_47 = 1;
                                }
                                
                                rax_79 = &rax_79[1];
                                i_6 s>>= 1;
                            } while (i_6);
                            
                            if (!rcx_47)
                                zmm0_1 = rax_78;
                        }
                    }
                }
                
                int rvbits;
                int rve;
                int64_t* b = __d2b_D2A(zmm0_1, &rve, &rvbits);
                int rdx_19 = rvbits;
                int32_t rve_2 = r14_2 + rve;
                int nd = r11_1;
                rvb = b;
                rve = rve_2;
                int32_t k_6 = rdx_19 - nbits;
                
                if (k_6 > 0)
                {
                    __rshift_D2A(b, k_6);
                    rdx_19 = nbits;
                    nd = r11_1;
                    rve_2 = rve + k_6;
                    rvbits = rdx_19;
                    rve = rve_2;
                }
                
                int32_t emin_3 = rve_2 + rdx_19 - nbits;
                int emin_1 = emin_3;
                struct __Bigint* rax_117;
                int irv_2;
                int k_4;
                
                if (fpi->emax + 1 < emin_3)
                {
                    k_4 = 0;
                label_14000d90a:
                    struct __Bigint* rvb_4 = rvb;
                    irv = 0xa3;
                    rvb_4->wds = 0;
                    *_errno() = 0x22;
                    *expo = fpi->emax + 1;
                label_14000d6f8:
                    b_8 = rvb;
                    
                    if (k_4)
                    {
                        rax_117 = b_8;
                        
                        if (sudden_underflow)
                            goto label_14000d7c0;
                        
                        int32_t rax_118;
                        rax_118 = b_8->wds > 0;
                        int32_t rdx_53 = irv & 0xfffffff8;
                        irv_2 = (rax_118 * 2) | rdx_53;
                        
                        if (rdx_53 & 0x30)
                            goto label_14000d893;
                        
                        irv = irv_2;
                    }
                }
                else
                {
                    int emin = fpi->emin;
                    int var_d8_4;
                    
                    if (emin_3 >= emin)
                    {
                        var_d8_4 = 0;
                    label_14000cd15:
                        struct __Bigint* v = __s2b_D2A(s_1, nd0, nd, rdi_1, dplen);
                        int k_1 = 0;
                        
                        if (k_10 < 0)
                            k_1 = var_e0_1 - var_d0;
                        
                        int k = 0;
                        
                        if (k_10 >= 0)
                            k = k_10;
                        
                        int rsi_6 = 0;
                        int rve_1;
                        int64_t* a_2;
                        int64_t* r15_1;
                        
                        while (true)
                        {
                            int64_t* rax_41 = __Balloc_D2A(v->k);
                            var_e0_1 = rax_41;
                            memcpy(&rax_41[2], &v->sign, (v->wds << 2) + 8);
                            int64_t* rax_44 = __Balloc_D2A(rvb->k);
                            struct __Bigint* rvb_7 = rvb;
                            r15_1 = rax_44;
                            memcpy(&rax_44[2], &rvb_7->sign, (rvb_7->wds << 2) + 8);
                            int rvbits_4 = rvbits;
                            int rve_3 = rve;
                            int32_t r12_5 = rve_3 + rsi_6;
                            var_d0 = __i2b_D2A(1);
                            int sudden_underflow_1 = rvbits_4 - rsi_6;
                            int k_8;
                            int k_12;
                            
                            if (r12_5 < 0)
                            {
                                k_12 = k - r12_5;
                                k_8 = k_1;
                            }
                            else
                            {
                                k_12 = k;
                                k_8 = r12_5 + k_1;
                            }
                            
                            int32_t rax_49 = rvbits_4 + rve_3 - nbits;
                            int32_t rdx_25 = nbits + 1 - sudden_underflow_1;
                            
                            if (emin > rax_49)
                                rdx_25 += rax_49 - emin;
                            
                            int k_15 = k_8 + rdx_25;
                            int k_9 = k_12 + rdx_25;
                            int k_11 = k_9;
                            
                            if (k_15 <= k_9)
                                k_11 = k_15;
                            
                            if (k_11 > k_8)
                                k_11 = k_8;
                            
                            if (k_11 > 0)
                            {
                                k_15 -= k_11;
                                k_9 -= k_11;
                                k_8 -= k_11;
                            }
                            
                            if (k_1 > 0)
                            {
                                struct __Bigint* a = __pow5mult_D2A(var_d0, k_1);
                                var_d0 = a;
                                int64_t* rax_51 = __mult_D2A(a, r15_1);
                                __Bfree_D2A(r15_1);
                                r15_1 = rax_51;
                            }
                            
                            int k_2 = k_15 - rsi_6;
                            
                            if (k_2 > 0)
                            {
                                r15_1 = __lshift_D2A(r15_1, k_2);
                                
                                if (k_10 > 0)
                                    var_e0_1 = __pow5mult_D2A(var_e0_1, k);
                            }
                            else
                            {
                                if (k_2)
                                    __rshift_D2A(r15_1, rsi_6 - k_15);
                                
                                if (k_10 > 0)
                                    var_e0_1 = __pow5mult_D2A(var_e0_1, k);
                            }
                            
                            if (k_9 > 0)
                                var_e0_1 = __lshift_D2A(var_e0_1, k_9);
                            
                            if (k_8 > 0)
                                var_d0 = __lshift_D2A(var_d0, k_8);
                            
                            int64_t* a_3 = __diff_D2A(r15_1, var_e0_1);
                            a_2 = a_3;
                            
                            if (*(a_3 + 0x14) > 1 || a_3[3])
                            {
                                int32_t r12_6 = a_2[2];
                                a_2[2] = 0;
                                int rax_54 = __cmp_D2A(a_2, var_d0);
                                int32_t var_ec_1;
                                int n;
                                struct __Bigint* b_9;
                                int r13_1;
                                int32_t r14_4;
                                
                                if (rd_1 && rax_54 <= 0)
                                {
                                    int32_t rax_56 = rd_1 & 1;
                                    rsi_6 = rax_56 ^ r12_6;
                                    
                                    if (rax_56 == r12_6)
                                        irv = ((rax_56 - rax_56) & 0x10) + 0x11;
                                    else
                                    {
                                        if (!r12_6)
                                        {
                                            irv = 0x11;
                                            
                                            if (emin_1 == emin)
                                                goto label_14000cf6d;
                                            
                                            int nbits_2 = nbits;
                                            b_9 = rvb;
                                            
                                            if (nbits_2 > 0x1f)
                                            {
                                                int64_t rdx_34 = 1;
                                                
                                                while (!(&b_9->wds)[rdx_34])
                                                {
                                                    nbits_2 -= 0x20;
                                                    
                                                    if (nbits_2 <= 0x1f)
                                                    {
                                                        r12_6 = rdx_34;
                                                        goto label_14000d8b3;
                                                    }
                                                    
                                                    rdx_34 += 1;
                                                }
                                                
                                                goto label_14000cf6d;
                                            }
                                            
                                            nbits_2 = nbits;
                                        label_14000d8b3:
                                            uint32_t temp0_8;
                                            
                                            if (nbits_2 > 1)
                                            {
                                                uint32_t rdx_59 = (&b_9->x)[r12_6];
                                                temp0_8 = _tzcnt_u32(rdx_59);
                                                (&b_9->x)[r12_6] = rdx_59 >> temp0_8;
                                            }
                                            
                                            if (nbits_2 > 1 && nbits_2 - 1 > temp0_8)
                                                goto label_14000cf6d;
                                            
                                            rve = emin_1 - 1;
                                            n = nbits;
                                            goto label_14000d8f4;
                                        }
                                        
                                        irv = 0x21;
                                        r14_4 = 0x20;
                                        r13_1 = 0;
                                        zmm7 = 0x3ff0000000000000;
                                        var_ec_1 = 0;
                                    label_14000cf99:
                                        int rvbits_1 = rvbits;
                                        int32_t rdi_6 = rve + rvbits_1;
                                        
                                        if (rvbits_1 < nbits && !(var_d8_4 & 1))
                                        {
                                            int k_5 = nbits - rvbits_1;
                                            int64_t* rvb_3 = __lshift_D2A(rvb, k_5);
                                            rve -= k_5;
                                            rvb = rvb_3;
                                            rvbits = nbits;
                                        }
                                        
                                        int abe;
                                        int abits;
                                        struct __Bigint* b_1;
                                        b_1 = __d2b_D2A(zmm7, &abe, &abits);
                                        int k_3 = abe;
                                        struct __Bigint* b_10 = b_1;
                                        
                                        if (k_3 < 0)
                                            __rshift_D2A(b_1, -(k_3));
                                        else if (k_3)
                                            b_10 = __lshift_D2A(b_1, k_3);
                                        
                                        struct __Bigint* rvb_8 = rvb;
                                        
                                        if (!r13_1)
                                        {
                                            int64_t* b_3 = __sum_D2A(rvb_8, b_10);
                                            rvb = b_3;
                                            int32_t rax_99 = *(b_3 + 0x14) - 1;
                                            int32_t temp0_6;
                                            int32_t temp0_7;
                                            
                                            if (rvb_8->wds > rax_99)
                                            {
                                                uint64_t rflags_3;
                                                temp0_6 = __bsr_gprv_memv(
                                                    *(b_3 + ((rax_99 + 4) << 2) + 8));
                                                uint64_t rflags_4;
                                                temp0_7 = __bsr_gprv_memv((&rvb_8->k)[rax_99 + 4]);
                                            }
                                            
                                            if (rvb_8->wds > rax_99
                                                    && (temp0_7 ^ 0x1f) <= (temp0_6 ^ 0x1f))
                                                goto label_14000d042;
                                            
                                            if (var_d8_4)
                                            {
                                                bool cond:16_1 = rvbits + 1 != nbits;
                                                rvbits += 1;
                                                int rax_105;
                                                rax_105 = cond:16_1;
                                                var_d8_4 = rax_105;
                                                goto label_14000d042;
                                            }
                                            
                                            __rshift_D2A(b_3, 1);
                                            rve += 1;
                                            emin_1 += 1;
                                            __Bfree_D2A(b_10);
                                            __Bfree_D2A(rvb_8);
                                            
                                            if (!rsi_6)
                                                goto label_14000d512;
                                            
                                            goto label_14000d83b;
                                        }
                                        
                                        int64_t* b_2 = __diff_D2A(rvb_8, b_10);
                                        rvb = b_2;
                                        
                                        if (var_d8_4)
                                            goto label_14000d03b;
                                        
                                        int32_t rax_58 = rvb_8->wds - 1;
                                        int32_t temp0_3;
                                        int32_t temp0_4;
                                        
                                        if (*(b_2 + 0x14) > rax_58)
                                        {
                                            uint64_t rflags_1;
                                            temp0_3 =
                                                __bsr_gprv_memv(*(b_2 + ((rax_58 + 4) << 2) + 8));
                                            uint64_t rflags_2;
                                            temp0_4 = __bsr_gprv_memv((&rvb_8->k)[rax_58 + 4]);
                                        }
                                        
                                        if (*(b_2 + 0x14) > rax_58
                                                && (temp0_4 ^ 0x1f) >= (temp0_3 ^ 0x1f))
                                            goto label_14000d042;
                                        
                                        if (emin_1 != emin)
                                        {
                                            int64_t* rvb_2 = __lshift_D2A(b_2, 1);
                                            rve -= 1;
                                            emin_1 -= 1;
                                            rvb = rvb_2;
                                            __Bfree_D2A(b_10);
                                            __Bfree_D2A(rvb_8);
                                        label_14000d512:
                                            var_d8_4 = 0;
                                            rsi_6 = __trailz_D2A(rvb);
                                        label_14000d0ac:
                                            __Bfree_D2A(r15_1);
                                            __Bfree_D2A(var_e0_1);
                                            __Bfree_D2A(var_d0);
                                            __Bfree_D2A(a_2);
                                            continue;
                                            continue;
                                        }
                                        else
                                        {
                                            rvbits -= 1;
                                        label_14000d03b:
                                            var_d8_4 = r13_1;
                                        label_14000d042:
                                            __Bfree_D2A(b_10);
                                            __Bfree_D2A(rvb_8);
                                            
                                            if (!rsi_6)
                                            {
                                                if (rvbits + rve != rdi_6 || !var_ec_1)
                                                {
                                                label_14000d0a1:
                                                    
                                                    if (!var_d8_4)
                                                        goto label_14000d512;
                                                    
                                                    goto label_14000d0ac;
                                                }
                                                
                                                zmm7 = zmm7 * 5.0000000000000004e-16;
                                                double zmm0_3 = zmm6 - 0.5;
                                                
                                                if (!(_mm_xor_pd(zmm7, -0x8000000000000000)[0]
                                                    <= zmm0_3))
                                                {
                                                    if (zmm6 > zmm7)
                                                        goto label_14000d600;
                                                    
                                                    goto label_14000d0a1;
                                                }
                                                
                                                if (zmm0_3 <= zmm7 || 1.0 - zmm7 <= zmm6)
                                                    goto label_14000d0a1;
                                                
                                            label_14000d600:
                                                irv |= r14_4;
                                            }
                                        }
                                    }
                                }
                                else if (rax_54 < 0)
                                {
                                    if (r12_6)
                                        goto label_14000dd38;
                                    
                                    irv = 0x21;
                                    
                                    if (sudden_underflow_1 <= 1 && emin_1 != emin
                                        && !(var_d8_4 & 1))
                                    {
                                        int64_t* a_1 = __lshift_D2A(a_2, 1);
                                        a_2 = a_1;
                                        
                                        if (__cmp_D2A(a_1, var_d0) <= 0)
                                            goto label_14000d83b;
                                        
                                        irv = 0x11;
                                        var_d8_4 = 0;
                                        b_9 = rvb;
                                    label_14000db8b:
                                        n = nbits;
                                        rve -= n;
                                    label_14000d8f4:
                                        rvbits = n;
                                        rvb = __set_ones_D2A(b_9, n);
                                    }
                                }
                                else
                                {
                                    if (rax_54)
                                    {
                                        uint128_t zmm0_2 = __ratio_D2A(a_2, var_d0);
                                        
                                        if (!(0x4000000000000000 < zmm0_2))
                                        {
                                            if (!r12_6)
                                            {
                                                rsi_6 = 0;
                                            label_14000cf6d:
                                                
                                                if (sudden_underflow_1 > 1 || !(var_d8_4 & 1))
                                                {
                                                    zmm7 = 0x3ff0000000000000;
                                                    var_ec_1 = 0;
                                                    r14_4 = 0x10;
                                                    r13_1 = 1;
                                                    goto label_14000cf99;
                                                }
                                                
                                                struct __Bigint* rvb_5 = rvb;
                                                irv = 0x50;
                                                rvb_5->wds = 0;
                                                rve = emin;
                                            label_14000d61b:
                                                rve_1 = rve;
                                                k_4 = 1;
                                                break;
                                                break;
                                            }
                                            
                                            zmm7 = 0x3ff0000000000000;
                                            var_ec_1 = 0;
                                            rsi_6 = 0;
                                            r13_1 = 0;
                                            r14_4 = 0x20;
                                            goto label_14000cf99;
                                        }
                                        
                                        zmm6 = zmm0_2 * 0.5;
                                        r14_4 = ((k_15 - k_15) & 0x10) + 0x10;
                                        r13_1 = r12_6 < 1;
                                        
                                        if (0x41dfffffffc00000 <= zmm6)
                                        {
                                            var_ec_1 = 0;
                                            zmm7 = zmm6;
                                            rsi_6 = 0;
                                        }
                                        else
                                        {
                                            int32_t rax_110 = zmm6;
                                            zmm7 = rax_110;
                                            var_ec_1 = rax_110;
                                            zmm6 = zmm6 - zmm7;
                                            
                                            if (rd_1 == 1)
                                            {
                                                if (r13_1)
                                                {
                                                    if (!(zmm6 <= 0.0))
                                                        goto label_14000d5af;
                                                    
                                                    rsi_6 = 0;
                                                }
                                                else
                                                    rsi_6 = 0;
                                            }
                                            else if (rd_1 != 2)
                                            {
                                                if (zmm6 >= 0.5)
                                                    goto label_14000d5af;
                                                
                                                rsi_6 = 0;
                                            }
                                            else if (r13_1 || zmm6 <= 0.0)
                                                rsi_6 = 0;
                                            else
                                            {
                                            label_14000d5af:
                                                var_ec_1 += 1;
                                                zmm7 = var_ec_1;
                                                r14_4 = 0x30 - r14_4;
                                                rsi_6 = 0;
                                            }
                                        }
                                        
                                        goto label_14000cf99;
                                    }
                                    
                                    if (r12_6)
                                    {
                                        struct __Bigint* b_7;
                                        
                                        if (var_d8_4)
                                        {
                                            int rvbits_2 = rvbits;
                                            b_7 = rvb;
                                            long unsigned int (* rax_148)[0x1] = &b_7->x;
                                            
                                            do
                                            {
                                                if (rax_148 >= &rax_148[rvbits_2 >> 5])
                                                {
                                                    int32_t rcx_87 = rvbits_2 & 0x1f;
                                                    
                                                    if (rcx_87 && (0xffffffff << rcx_87
                                                            | ADJ(rax_148)->x) != 0xffffffff)
                                                        goto label_14000de35;
                                                    
                                                    rvbits = 1;
                                                    b_7->wds = 1;
                                                    b_7->x = 1;
                                                    irv = 0x21;
                                                    rve = nbits + emin - 1;
                                                    goto label_14000d844;
                                                }
                                                
                                                rax_148 = &rax_148[1];
                                            } while (ADJ(rax_148)->wds == 0xffffffff);
                                            
                                        label_14000de35:
                                            irv = 0x11;
                                            
                                            if (b_7->x[0] & 1)
                                                goto label_14000dda2;
                                            
                                            rve_1 = rve;
                                            k_4 = var_d8_4;
                                            break;
                                        }
                                        
                                        irv = 0x11;
                                        
                                        if (nbits > sudden_underflow_1)
                                            goto label_14000d83b;
                                        
                                        b_7 = rvb;
                                        
                                        if (!(b_7->x[0] & 1))
                                            goto label_14000d83b;
                                        
                                    label_14000dda2:
                                        struct __Bigint* rvb_6 = __increment_D2A(b_7);
                                        int rvbits_3 = rvbits;
                                        int wds = rvb_6->wds;
                                        rvb = rvb_6;
                                        uint64_t rflags_5;
                                        int32_t temp0_10;
                                        temp0_10 = __bsr_gprv_memv((&rvb_6->x)[wds - 1]);
                                        
                                        if ((-(rvbits_3) & 0x1f) != (temp0_10 ^ 0x1f))
                                            rvbits = rvbits_3 + 1;
                                        
                                        irv = 0x21;
                                    }
                                    else if (sudden_underflow_1 == 1)
                                    {
                                        irv = 1;
                                        b_9 = rvb;
                                        
                                        if (emin_1 != emin)
                                            goto label_14000db8b;
                                        
                                        bool cond:14_1 = b_9->wds != 1;
                                        irv = 0x21;
                                        
                                        if (!cond:14_1)
                                        {
                                            if (b_9->x != 1)
                                                sudden_underflow_1 = sudden_underflow;
                                            
                                            sudden_underflow = sudden_underflow_1;
                                        }
                                    }
                                    else
                                    {
                                        irv = 0x21;
                                        
                                        if (nbits <= sudden_underflow_1 || var_d8_4 & 1)
                                        {
                                            struct __Bigint* b_6 = rvb;
                                            
                                            if (b_6->x[0] & 1)
                                            {
                                                __decrement_D2A(b_6);
                                            label_14000dd38:
                                                irv = 0x11;
                                                goto label_14000d613;
                                            }
                                        }
                                    }
                                }
                            }
                            
                        label_14000d613:
                            
                            if (var_d8_4)
                                goto label_14000d61b;
                            
                        label_14000d83b:
                            var_d8_4 = rvbits;
                        label_14000d844:
                            k_4 = nbits - var_d8_4;
                            
                            if (k_4)
                            {
                                struct __Bigint* b_5 = rvb;
                                
                                if (k_4 <= 0)
                                    __rshift_D2A(b_5, var_d8_4 - nbits);
                                else
                                    rvb = __lshift_D2A(b_5, k_4);
                                
                                rve_1 = rve - k_4;
                                k_4 = 0;
                                rve = rve_1;
                            }
                            else
                                rve_1 = rve;
                            
                            break;
                        }
                        
                        *expo = rve_1;
                        __Bfree_D2A(r15_1);
                        __Bfree_D2A(var_e0_1);
                        __Bfree_D2A(var_d0);
                        __Bfree_D2A(v);
                        __Bfree_D2A(a_2);
                        
                        if (fpi->emax >= rve)
                            goto label_14000d6f8;
                        
                        int32_t rax_116 = fpi->rounding & 3;
                        
                        if (rax_116 == 2)
                        {
                            if (!sign)
                                goto label_14000d90a;
                        }
                        else if (rax_116 == 3)
                        {
                            if (sign)
                                goto label_14000d90a;
                        }
                        else if (rax_116 == 1)
                            goto label_14000d90a;
                        
                        __Bfree_D2A(rvb);
                        int nbits_1 = fpi->nbits;
                        rvb = nullptr;
                        int emax_1 = fpi->emax;
                        irv = 0x11;
                        *expo = emax_1;
                        void* rdi_14 = &bits[(nbits_1 + 0x1f) >> 5];
                        
                        if (bits < rdi_14)
                            memset(bits, 0xff, (nbits_1 + 0x1f) >> 5 << 2);
                        
                        int32_t rbx_4 = nbits_1 & 0x1f;
                        
                        if (rbx_4)
                            *(rdi_14 - 4) u>>= 0x20 - rbx_4;
                        
                        goto label_14000d6f8;
                    }
                    
                    int k_7 = rve_2 - emin;
                    
                    if (k_7 > 0)
                    {
                        int64_t* rvb_1 = __lshift_D2A(rvb, k_7);
                        rvbits += k_7;
                        rvb = rvb_1;
                    label_14000ccd4:
                        rve = emin;
                        
                        if (!sudden_underflow)
                        {
                            emin_1 = emin;
                            var_d8_4 = 1;
                            goto label_14000cd15;
                        }
                        
                        int emin_2 = emin_1;
                        var_d8_4 = 1;
                        emin_1 = emin;
                        
                        if (emin_2 + 1 >= emin)
                            goto label_14000cd15;
                        
                        rax_117 = rvb;
                        rax_117->wds = 0;
                        rax_117->x = 0;
                        *expo = emin;
                    label_14000d7c0:
                        rax_117->wds = 0;
                        irv = 0x50;
                        int32_t* rax_120 = _errno();
                        b_8 = rvb;
                        *rax_120 = 0x22;
                    }
                    else
                    {
                        if (!k_7)
                            goto label_14000ccd4;
                        
                        int rvbits_5 = k_7 + rdx_19;
                        struct __Bigint* b_4 = rvb;
                        rvbits = rvbits_5;
                        
                        if (rvbits_5 > 0)
                        {
                            __rshift_D2A(b_4, emin - rve_2);
                            goto label_14000ccd4;
                        }
                        
                        if (rvbits_5 >= 0xffffffff)
                        {
                            rvbits = 1;
                            b_4->wds = 1;
                            b_4->x = 1;
                            goto label_14000ccd4;
                        }
                        
                        rax_117 = b_4;
                        b_4->wds = 0;
                        b_4->x = 0;
                        irv = 0x50;
                        *expo = emin;
                        
                        if (sudden_underflow)
                            goto label_14000d7c0;
                        
                        int32_t rax_123;
                        rax_123 = b_4->wds > 0;
                        irv_2 = (rax_123 * 2) | 0x50;
                    label_14000d893:
                        irv = irv_2 | 0x40;
                        *_errno() = 0x22;
                    label_14000c978:
                        b_8 = rvb;
                    }
                }
            }
            else
            {
                if (r10_1 | r14)
                    goto label_14000c978;
                
                if (var_d8_1)
                    goto label_14000cb20;
                
                if (i_2 == 0x69)
                {
                label_14000da4e:
                    
                    if (!__match_D2A(&s, "nf"))
                        goto label_14000cb20;
                    
                    s -= 1;
                    
                    if (!__match_D2A(&s, "inity"))
                        s = &s[1];
                    
                    irv = 3;
                    b_8 = rvb;
                    *expo = fpi->emax + 1;
                }
                else
                {
                    if (i_2 <= 0x69)
                    {
                        if (i_2 == 0x49)
                            goto label_14000da4e;
                        
                        if (i_2 != 0x4e)
                            goto label_14000cb20;
                    }
                    else if (i_2 != 0x6e)
                        goto label_14000cb20;
                    
                    if (!__match_D2A(&s, "an"))
                        goto label_14000cb20;
                    
                    int emax = fpi->emax;
                    b_8 = rvb;
                    irv = 4;
                    *expo = emax + 1;
                    
                    if (*s == 0x28)
                    {
                        irv = __hexnan_D2A(&s, fpi, bits);
                        b_8 = rvb;
                        *expo = fpi->emax + 1;
                    }
                }
            }
        }
        
        if (se)
            *se = s;
        
        if (sign)
            irv |= 8;
    }
    
    if (b_8)
    {
        __copybits_D2A(bits, nbits, b_8);
        __Bfree_D2A(rvb);
    }
    
    return irv;
}

int64_t* __sum_D2A(struct __Bigint* a, struct __Bigint* b)
{
    struct __Bigint* rsi = a;
    struct __Bigint* rbx = b;
    
    if (a->wds >= b->wds)
    {
        rbx = a;
        rsi = b;
    }
    
    int64_t* result_1 = __Balloc_D2A(rbx->k);
    int wds_1 = rbx->wds;
    int64_t r9 = 0x18;
    uint32_t r10 = 0;
    int64_t* result = result_1;
    *(result_1 + 0x14) = wds_1;
    int64_t wds = rsi->wds;
    void* rcx_1 = &result_1[3];
    void* r12 = &result_1[3] + (wds << 2);
    
    do
    {
        int32_t rax_1 = *(rbx + r9);
        int32_t r8_1 = *(rsi + r9);
        rcx_1 += 4;
        r9 += 4;
        uint32_t rdx_2 = rax_1 + r8_1 + r10;
        *(rcx_1 - 4) = rdx_2;
        uint32_t rax_4 = (rax_1 >> 0x10) + (r8_1 >> 0x10) + (rdx_2 >> 0x10);
        *(rcx_1 - 2) = rax_4;
        r10 = rax_4 >> 0x10;
    } while (rcx_1 < r12);
    
    int64_t wds_2 = wds_1;
    void* rax_9 = ((r12 - result - 0x19) >> 2 << 2) + 4;
    
    if (r12 < result + 0x19)
        rax_9 = 4;
    
    void* r9_1 = &rbx->x + rax_9;
    void* i = rax_9 + &result_1[3];
    
    while (i < r12 + ((wds_2 - wds) << 2))
    {
        int32_t r8_5 = *r9_1;
        i += 4;
        r9_1 += 4;
        uint32_t rdx_8 = r8_5 + r10;
        *(i - 4) = rdx_8;
        uint32_t rcx_4 = (rdx_8 >> 0x10) + (r8_5 >> 0x10);
        *(i - 2) = rcx_4;
        r10 = rcx_4 >> 0x10;
    }
    
    if (r10)
    {
        if (wds_2 == *(result + 0xc))
        {
            int64_t* result_2 = __Balloc_D2A(result[1] + 1);
            memcpy(&result_2[2], &result[2], (*(result + 0x14) << 2) + 8);
            int64_t* v = result;
            result = result_2;
            __Bfree_D2A(v);
            wds_2 = *(result_2 + 0x14);
        }
        
        *(result + 0x14) = wds_2 + 1;
        *(result + (wds_2 << 2) + 0x18) = 1;
    }
    
    return result;
}

long long unsigned int strnlen(char const* s, long long unsigned int maxlen)
{
    int64_t result = 0;
    char const* s_1 = s;
    
    if (maxlen)
    {
        while (*s_1)
        {
            s_1 = &s_1[1];
            result = s_1 - s;
            
            if (result >= maxlen)
                break;
        }
    }
    
    return result;
}

long long unsigned int wcsnlen(short unsigned int const* w, long long unsigned int ncnt)
{
    long long unsigned int r8 = 0;
    
    if (ncnt)
    {
        do
        {
            if (!w[r8])
                return r8;
            
            r8 += 1;
        } while (ncnt != r8);
    }
    
    return ncnt;
}

int __gethex_D2A(char const** sp, struct FPI* fpi, long int* expo, struct __Bigint** bp, int sign)
{
    char* decimal_point = localeconv()->decimal_point;
    
    if (!__hexdig_D2A[0x30])
        __mingw_hexdig_init_D2A();
    
    *bp = nullptr;
    char const* rax_2 = *sp;
    char i = rax_2[2];
    void* rsi_1;
    int32_t r9;
    
    if (i != 0x30)
    {
        rsi_1 = &rax_2[2];
        r9 = 0;
    }
    else
    {
        void* rax_3 = &rax_2[3];
        
        do
        {
            rsi_1 = rax_3;
            i = *rax_3;
            rax_3 += 1;
        } while (i == 0x30);
        
        r9 = rsi_1 - (&rax_2[3]) + 1;
    }
    
    char i_6 = *decimal_point;
    int32_t result;
    long int emin;
    void* rax_8;
    int emin_1;
    char i_4;
    void* rbx;
    int32_t r11;
    int64_t* r15_2;
    
    if (__hexdig_D2A[i])
    {
        r9 += 1;
        rax_8 = nullptr;
    label_14000e1ce:
        rbx = rsi_1;
        uint64_t rcx_1;
        
        do
        {
            rcx_1 = *(rbx + 1);
            rbx += 1;
            i_4 = rcx_1;
        } while (__hexdig_D2A[rcx_1]);
        
        if (rcx_1 != i_6)
        {
            r11 = 0;
            
            if (rax_8)
                goto label_14000e207;
            
            emin = 0;
        label_14000e20d:
            
            if ((i_4 & 0xdf) == 0x50)
                goto label_14000e300;
            
            goto label_14000e216;
        }
        
        r11 = 0;
        
        if (rax_8)
            goto label_14000e2eb;
        
        char i_1 = decimal_point[1];
        void* rax_39 = 1;
        
        if (!i_1)
        {
        label_14000e886:
            rax_8 = rax_39 + rbx;
            uint64_t rcx_26 = *rax_8;
            rbx = rax_8;
            i_4 = rcx_26;
            
            if (!__hexdig_D2A[rcx_26])
            {
                emin = 0;
                r11 = 0;
                goto label_14000e20d;
            }
            
            uint64_t rcx_27;
            
            do
            {
                rcx_27 = *(rbx + 1);
                rbx += 1;
                i_4 = rcx_27;
            } while (__hexdig_D2A[rcx_27]);
            r11 = 0;
            goto label_14000e207;
        }
        
        while (*(rbx + rax_39) == i_1)
        {
            rax_39 += 1;
            i_1 = *(decimal_point + rax_39);
            
            if (!i_1)
                goto label_14000e886;
        }
        
        if ((*rbx & 0xdf) == 0x50)
        {
            emin = 0;
            r11 = 0;
            goto label_14000e300;
        }
        
        *sp = rbx;
        emin = 0;
    label_14000e226:
        int k = 0;
        int32_t i_2 = rbx - rsi_1 - 1;
        
        while (i_2 > 7)
        {
            i_2 s>>= 1;
            k += 1;
        }
        
        int64_t* rax_15 = __Balloc_D2A(k);
        r15_2 = rax_15;
        void* r13_1 = &rax_15[3];
        int64_t r10_2;
        
        if (!decimal_point[1])
            r10_2 = 0;
        else
            r10_2 = strlen(&decimal_point[2]) + 1;
        
        int32_t rax_25;
        void* rdx_3;
        int32_t r11_1;
        
        if (rsi_1 >= rbx)
        {
            rdx_3 = r13_1;
            rax_25 = 0x20;
            r11_1 = 0;
        }
        else
        {
            rdx_3 = r13_1;
            r11_1 = 0;
            int32_t r8_1 = 0;
            
            while (true)
            {
                uint64_t rax_20 = *(rbx - 1);
                
                if (rax_20 == decimal_point[r10_2])
                {
                    rbx = rbx - 1 - r10_2;
                    
                    if (rsi_1 >= rbx)
                        break;
                }
                else
                {
                    char rcx_3;
                    
                    if (r8_1 != 0x20)
                    {
                        rcx_3 = r8_1;
                        r8_1 += 4;
                    }
                    else
                    {
                        *rdx_3 = r11_1;
                        r8_1 = 4;
                        rax_20 = *(rbx - 1);
                        r11_1 = 0;
                        rdx_3 += 4;
                        rcx_3 = 0;
                    }
                    
                    rbx -= 1;
                    r11_1 |= (__hexdig_D2A[rax_20] & 0xf) << rcx_3;
                    
                    if (rsi_1 >= rbx)
                        break;
                }
            }
            
            uint64_t rflags_1;
            int32_t temp0_1;
            temp0_1 = _bit_scan_reverse(r11_1);
            rax_25 = temp0_1 ^ 0x1f;
        }
        
        *rdx_3 = r11_1;
        int nbits_1 = fpi->nbits;
        int32_t rdx_11 = (rdx_3 + 4 - r13_1) >> 2;
        *(r15_2 + 0x14) = rdx_11;
        int32_t rdx_13 = (rdx_11 << 5) - rax_25;
        long unsigned int rsi_2;
        
        if (rdx_13 > nbits_1)
        {
            int k_4 = rdx_13 - nbits_1;
            long unsigned int rax_43 = __any_on_D2A(r15_2, k_4);
            rsi_2 = rax_43;
            
            if (rax_43)
            {
                rsi_2 = 1;
                
                if (1 << (k_4 - 1) & *(r13_1 + ((k_4 - 1) >> 5 << 2)))
                {
                    long unsigned int rax_57;
                    
                    if (k_4 != 1)
                        rax_57 = __any_on_D2A(r15_2, k_4 - 1);
                    
                    rsi_2 = k_4 == 1 || !rax_57 ? 2 : 3;
                }
            }
            
            __rshift_D2A(r15_2, k_4);
            emin += k_4;
        }
        else
        {
            rsi_2 = 0;
            
            if (rdx_13 < nbits_1)
            {
                int k_3 = nbits_1 - rdx_13;
                int64_t* rax_38 = __lshift_D2A(r15_2, k_3);
                emin -= k_3;
                r15_2 = rax_38;
                r13_1 = &rax_38[3];
            }
        }
        
        if (fpi->emax < emin)
        {
        label_14000e63f:
            __Bfree_D2A(r15_2);
            result = 0xa3;
            *_errno() = 0x22;
        }
        else
        {
            emin_1 = fpi->emin;
            
            if (emin_1 > emin)
            {
                int32_t k_2 = emin_1 - emin;
                
                if (nbits_1 > k_2)
                {
                    if (rsi_2)
                        rsi_2 = 1;
                    else if (k_2 != 1)
                        rsi_2 = __any_on_D2A(r15_2, k_2 - 1);
                    
                    if (1 << (k_2 - 1) & *(r13_1 + ((k_2 - 1) >> 5 << 2)))
                        rsi_2 |= 2;
                    
                    nbits_1 -= k_2;
                    result = 2;
                    __rshift_D2A(r15_2, k_2);
                    emin = fpi->emin;
                    goto label_14000e3ff;
                }
                
                int rounding_2 = fpi->rounding;
                
                if (rounding_2 != 2)
                {
                    if (rounding_2 == 3)
                    {
                        if (!sign)
                            goto label_14000e5bb;
                        
                        goto label_14000e835;
                    }
                    
                    if (rounding_2 != 1 || nbits_1 != k_2)
                        goto label_14000e5bb;
                    
                    if (nbits_1 == 1)
                        goto label_14000e835;
                    
                    if (!__any_on_D2A(r15_2, nbits_1 - 1))
                        goto label_14000e5bb;
                    
                    emin_1 = fpi->emin;
                label_14000e835:
                    *(r15_2 + 0x14) = 1;
                    *r13_1 = 1;
                    goto label_14000e184;
                }
                
                if (!sign)
                    goto label_14000e835;
                
            label_14000e5bb:
                __Bfree_D2A(r15_2);
                result = 0x50;
                *_errno() = 0x22;
            }
            else
            {
                result = 1;
            label_14000e3ff:
                
                if (!rsi_2)
                {
                    *bp = r15_2;
                    *expo = emin;
                }
                else
                {
                    int rounding_1 = fpi->rounding;
                    
                    if (rounding_1 == 2)
                        sign = 1 - sign;
                    else if (rounding_1 != 3)
                    {
                        if (rounding_1 == 1 && rsi_2 & 2 && (rsi_2 | *r13_1) & 1)
                            goto label_14000e77e;
                        
                        goto label_14000e423;
                    }
                    
                    if (!sign)
                    {
                    label_14000e423:
                        result |= 0x10;
                        *bp = r15_2;
                        *expo = emin;
                    }
                    else
                    {
                    label_14000e77e:
                        int64_t rsi_5 = *(r15_2 + 0x14);
                        struct __Bigint* rax_51 = __increment_D2A(r15_2);
                        r15_2 = rax_51;
                        
                        if (result == 2)
                        {
                            result = 0x22;
                            
                            if (fpi->nbits - 1 == nbits_1)
                                result = 0x21 + 0;
                            
                            *bp = r15_2;
                            *expo = emin;
                        }
                        else
                        {
                            if (*(r15_2 + 0x14) > rsi_5)
                            {
                            label_14000e7bd:
                                __rshift_D2A(r15_2, 1);
                                emin += 1;
                                
                                if (fpi->emax < emin)
                                    goto label_14000e63f;
                            }
                            else
                            {
                                int32_t rdi_6 = nbits_1 & 0x1f;
                                
                                if (rdi_6)
                                {
                                    uint64_t rflags_2;
                                    int32_t temp0_2;
                                    temp0_2 = __bsr_gprv_memv((&rax_51->x)[rsi_5 - 1]);
                                    
                                    if (0x20 - rdi_6 > (temp0_2 ^ 0x1f))
                                        goto label_14000e7bd;
                                }
                            }
                            
                            result = 0x21;
                            *bp = r15_2;
                            *expo = emin;
                        }
                    }
                }
            }
        }
    }
    else
    {
        char i_3 = i_6;
        void* rax_7 = nullptr;
        
        if (i_6)
        {
            do
            {
                if (*(rsi_1 + rax_7) != i_3)
                    goto label_14000e0f0;
                
                rax_7 += 1;
                i_3 = *(decimal_point + rax_7);
            } while (i_3);
            
            rax_8 = rax_7 + rsi_1;
            uint64_t rcx_11 = *rax_8;
            i = rcx_11;
            
            if (!__hexdig_D2A[rcx_11])
                goto label_14000e0f6;
            
            rsi_1 = rax_8;
            
            if (rcx_11 == 0x30)
            {
                do
                {
                    i_4 = *(rsi_1 + 1);
                    rsi_1 += 1;
                } while (i_4 == 0x30);
            }
            
            if (rcx_11 != 0x30 || __hexdig_D2A[i_4])
            {
                r9 = 1;
                goto label_14000e1ce;
            }
            
            if (i_4 != i_6)
            {
                rbx = rsi_1;
                r9 = 1;
                r11 = 1;
            label_14000e207:
                emin = (rax_8 - rbx) << 2;
                goto label_14000e20d;
            }
            
            rbx = rsi_1;
            r9 = 1;
            r11 = 1;
        label_14000e2eb:
            emin = (rax_8 - rbx) << 2;
            
            if ((*rbx & 0xdf) == 0x50)
                goto label_14000e300;
            
        label_14000e216:
            *sp = rbx;
            
            if (r11)
                return 0;
            
            goto label_14000e226;
        }
        
    label_14000e0f0:
        rax_8 = rsi_1;
    label_14000e0f6:
        rbx = rax_8;
        int32_t r8;
        int32_t r15_1;
        
        if ((i & 0xdf) == 0x50)
        {
            emin = 0;
            r11 = 1;
        label_14000e300:
            uint64_t rax_23 = *(rbx + 1);
            void* rcx_4;
            
            if (rax_23 == 0x2b)
            {
                r15_1 = 0;
                rax_23 = *(rbx + 2);
                rcx_4 = rbx + 2;
            }
            else if (rax_23 != 0x2d)
            {
                rcx_4 = rbx + 1;
                r15_1 = 0;
            }
            else
            {
                r15_1 = 1;
                rax_23 = *(rbx + 2);
                rcx_4 = rbx + 2;
            }
            
            uint32_t rdx_6 = __hexdig_D2A[rax_23];
            r8 = 0;
            rax_8 = rbx;
            
            if (rdx_6 - 1 <= 0x18)
            {
                rax_8 = rcx_4 + 1;
                uint64_t rdx_7 = rdx_6 - 0x10;
                uint64_t rcx_5 = *(rcx_4 + 1);
                
                while (true)
                {
                    uint32_t r10_4 = __hexdig_D2A[rcx_5];
                    
                    if (r10_4 - 1 > 0x18)
                        break;
                    
                    if (rdx_7 >= 0x8000000)
                        r8 = 1;
                    
                    rcx_5 = *(rax_8 + 1);
                    rax_8 += 1;
                    rdx_7 = r10_4 + ((rdx_7 * 5) << 1) - 0x10;
                }
                
                if (r15_1)
                    rdx_7 = -(rdx_7);
                
                emin += rdx_7;
            }
            
            goto label_14000e11c;
        }
        
        emin = 0;
        r11 = 1;
        r15_1 = 0;
        r8 = 0;
    label_14000e11c:
        
        if (!r9)
            rax_8 = rsi_1 - 1;
        
        *sp = rax_8;
        
        if (r11)
            return 0;
        
        if (!r8)
            goto label_14000e226;
        
        int rounding = fpi->rounding;
        
        if (!r15_1)
        {
            if (rounding == 2)
            {
                if (!sign)
                {
                    result = 0xa3;
                    *_errno() = 0x22;
                }
                else
                {
                label_14000e4db:
                    int nbits = fpi->nbits;
                    int32_t rbx_2 = nbits & 0x1f;
                    int32_t r13_3 = nbits >> 5;
                    int32_t rsi_4 = r13_3 + 1;
                    int k_1 = 0;
                    
                    for (int32_t i_5 = rsi_4 >> 1; i_5; i_5 s>>= 1)
                        k_1 += 1;
                    
                    int64_t* rax_31 = __Balloc_D2A(k_1);
                    *bp = rax_31;
                    *(rax_31 + 0x14) = rsi_4;
                    
                    if (r13_3 > 0)
                    {
                        r15_1 = r13_3;
                        memset(&rax_31[3], 0xff, r13_3 << 2);
                    }
                    
                    if (rsi_4 > r13_3)
                        *(rax_31 + (r15_1 << 2) + 0x18) = 0x20 >> (0x20 - rbx_2);
                    
                    result = 0x11;
                    *expo = fpi->emin;
                }
            }
            else if (rounding == 3)
            {
                if (!sign)
                    goto label_14000e4db;
                
                result = 0xa3;
                *_errno() = 0x22;
            }
            else
            {
                if (rounding != 1)
                    goto label_14000e4db;
                
                result = 0xa3;
                *_errno() = 0x22;
            }
        }
        else if (rounding != 2)
        {
            if (rounding == 3 && sign)
                goto label_14000e16a;
            
            result = 0x50;
            *_errno() = 0x22;
        }
        else if (sign)
        {
            result = 0x50;
            *_errno() = 0x22;
        }
        else
        {
        label_14000e16a:
            r15_2 = __Balloc_D2A(0);
            *(r15_2 + 0x14) = 0x100000001;
            emin_1 = fpi->emin;
        label_14000e184:
            result = 0x62;
            *bp = r15_2;
            *expo = emin_1;
            *_errno() = 0x22;
        }
    }
    return result;
}

uint64_t __mingw_hexdig_init_D2A()
{
    char const* const rdx = "0123456789";
    uint64_t rax = 0x30;
    
    do
    {
        rdx = &rdx[1];
        __hexdig_D2A[rax] = &rdx[0xbffee190];
        rax = *rdx;
    } while (rax);
    
    char const* const rdx_1 = "abcdef";
    uint64_t rax_1 = 0x61;
    
    do
    {
        rdx_1 = &rdx_1[1];
        __hexdig_D2A[rax_1] = &rdx_1[0xbffee18f];
        rax_1 = *rdx_1;
    } while (rax_1);
    
    char const* const rdx_2 = "ABCDEF";
    uint64_t result = 0x41;
    
    do
    {
        rdx_2 = &rdx_2[1];
        __hexdig_D2A[result] = &rdx_2[0xbffee188];
        result = *rdx_2;
    } while (result);
    
    return result;
}

int __hexnan_D2A(char const** sp, struct FPI* fpi, long unsigned int* x0)
{
    if (!__hexdig_D2A[0x30])
        __mingw_hexdig_init_D2A();
    
    int nbits = fpi->nbits;
    int32_t rax = nbits & 0x1f;
    void* rdx_3 = &x0[nbits >> 5];
    void* r12;
    void* r14;
    
    if (rax)
    {
        r14 = rdx_3 + 4;
        r12 = rdx_3;
    }
    else
    {
        r12 = rdx_3 - 4;
        r14 = rdx_3;
    }
    
    *(r14 - 4) = 0;
    char const* r9 = *sp;
    uint32_t rax_2 = r9[1];
    char rdx_4 = rax_2;
    
    if (rax_2)
    {
        while (true)
        {
            if (rax_2 <= 0x20)
            {
                rax_2 = r9[2];
                r9 = &r9[1];
                rdx_4 = rax_2;
                
                if (rax_2)
                    continue;
                
                goto label_14000eaa8;
            }
            
            void* rax_5;
            uint32_t i_1;
            
            if (rdx_4 != 0x30 || (r9[2] & 0xdf) != 0x58)
            {
            label_14000eaa8:
                i_1 = r9[1];
                rax_5 = &r9[1];
                
                if (!i_1)
                    break;
            }
            else
            {
                i_1 = r9[3];
                
                if (i_1 <= 0x20)
                    goto label_14000eaa8;
                
                rax_5 = &r9[3];
                r9 = &r9[2];
            }
            
            int32_t r10_1 = 0;
            void* rsi_1 = r12;
            void* r14_1 = r9;
            void* rbx_1 = r12;
            int32_t rdi_1 = 0;
            int32_t rcx = 0;
            
            while (true)
            {
                uint32_t r8_2 = __hexdig_D2A[i_1];
                int32_t rax_15;
                int32_t r8_4;
                int32_t r11_3;
                void* r14_4;
                
                if (r8_2)
                {
                    r10_1 += 1;
                    rdi_1 += 1;
                    
                    if (r10_1 <= 8)
                        *rbx_1 = (r8_2 & 0xf) | *rbx_1 << 4;
                    else if (x0 < rbx_1)
                    {
                        *(rbx_1 - 4) = 0;
                        rbx_1 -= 4;
                        r10_1 = 1;
                        *rbx_1 = r8_2 & 0xf;
                    }
                    
                label_14000ec6c:
                    i_1 = *(rax_5 + 1);
                    r14_1 = rax_5;
                label_14000eb7b:
                    rax_5 += 1;
                    
                    if (i_1)
                        continue;
                    
                    r14_4 = r14;
                    r8_4 = rax;
                    r11_3 = r10_1;
                    
                    if (!rdi_1)
                        break;
                    
                    if (rbx_1 >= rsi_1 || r11_3 > 7)
                        goto label_14000eba7;
                    
                    goto label_14000edaa;
                }
                else
                {
                    if (i_1 <= 0x20)
                    {
                        if (rdi_1 > rcx)
                        {
                            if (rbx_1 < rsi_1 && r10_1 <= 7)
                            {
                                uint32_t rdx_5 = *rbx_1;
                                void* r8_3 = rbx_1;
                                char r14_3 = (8 - r10_1) << 2;
                                
                                do
                                {
                                    int32_t r9_2 = *(r8_3 + 4);
                                    r8_3 += 4;
                                    *(r8_3 - 4) = rdx_5 | r9_2 << (0x20 - r14_3);
                                    rdx_5 = r9_2 >> r14_3;
                                    *r8_3 = rdx_5;
                                } while (r8_3 < rsi_1);
                            }
                            
                            if (x0 >= rbx_1)
                            {
                                i_1 = *(rax_5 + 1);
                                r14_1 = rax_5;
                                r10_1 = 8;
                                goto label_14000eb7b;
                            }
                            
                            rsi_1 = rbx_1 - 4;
                            *(rbx_1 - 4) = 0;
                            rcx = rdi_1;
                            r10_1 = 0;
                            rbx_1 = rsi_1;
                        }
                        
                        char i = *(rax_5 + 1);
                        
                        while (i <= 0x20)
                        {
                            i = *(rax_5 + 2);
                            rax_5 += 1;
                        }
                        
                        if (i == 0x30 && (*(rax_5 + 2) & 0xdf) == 0x58)
                        {
                            i_1 = *(rax_5 + 3);
                            
                            if (i_1 > 0x20)
                            {
                                r14_1 = rax_5 + 2;
                                rax_5 += 3;
                                continue;
                            }
                        }
                        
                        goto label_14000ec6c;
                    }
                    
                    r8_4 = rax;
                    r14_4 = r14;
                    r11_3 = r10_1;
                    
                    if (i_1 != 0x29 || !rdi_1)
                    {
                        do
                        {
                            rax_5 += 1;
                            
                            if (i_1 == 0x29)
                            {
                                *sp = rax_5;
                                break;
                            }
                            
                            i_1 = *rax_5;
                        } while (i_1);
                        
                        break;
                    }
                    
                    *sp = r14_1 + 2;
                    
                    if (rbx_1 < rsi_1 && r11_3 <= 7)
                    {
                    label_14000edaa:
                        void* r9_6 = rbx_1;
                        uint8_t r11_4 = (8 - r11_3) << 2;
                        uint32_t rdx_13 = *rbx_1;
                        
                        do
                        {
                            int32_t r10_3 = *(r9_6 + 4);
                            r9_6 += 4;
                            int32_t rax_22 = r10_3 << (0x20 - r11_4) | rdx_13;
                            rdx_13 = r10_3 >> r11_4;
                            *(r9_6 - 4) = rax_22;
                            *r9_6 = rdx_13;
                        } while (r9_6 < rsi_1);
                        
                        if (x0 < rbx_1)
                            goto label_14000ebb0;
                        
                        goto label_14000ed08;
                    }
                    
                label_14000eba7:
                    
                    if (x0 >= rbx_1)
                    {
                    label_14000ed08:
                        rax_15 = *(r14_4 - 4);
                        
                        if (r8_4)
                        {
                            rax_15 &= 0xffffffff >> (0x20 - r8_4);
                            *(r14_4 - 4) = rax_15;
                        }
                    }
                    else
                    {
                    label_14000ebb0:
                        int32_t* x0_1 = x0;
                        void* rsi_2 = rbx_1;
                        
                        do
                        {
                            *x0_1 = *rsi_2;
                            x0_1 = &x0_1[1];
                            rsi_2 += 4;
                        } while (r12 >= rsi_2);
                        
                        void* rcx_3 = ((r12 - rbx_1) >> 2 << 2) + 4;
                        
                        if (r12 + 1 < rbx_1 + 1)
                            rcx_3 = 4;
                        
                        void* rcx_4 = rcx_3 + x0;
                        void* _Size = ((r12 - rcx_4) >> 2 << 2) + 4;
                        
                        if (r12 + 1 < rcx_4 + 1)
                            _Size = 4;
                        
                        memset(rcx_4, 0, _Size);
                        rax_15 = *(r14_4 - 4);
                    }
                }
                
                if (!rax_15)
                {
                    int32_t i_2;
                    
                    do
                    {
                        if (x0 == r12)
                        {
                            *r12 = 1;
                            break;
                        }
                        
                        i_2 = *(r12 - 4);
                        r12 -= 4;
                    } while (!i_2);
                }
                
                return 5;
            }
            
            break;
        }
    }
    
    return 4;
}

struct __Bigint* __s2b_D2A(char const* s, int nd0, int nd, long unsigned int y9, int dplen)
{
    int nd0_1 = nd0;
    int k;
    
    if (nd <= 9)
        k = 0;
    else
    {
        int32_t i = 1;
        k = 0;
        
        do
        {
            i *= 2;
            k += 1;
        } while ((nd + 8) / 9 > i);
    }
    
    int64_t* b_1 = __Balloc_D2A(k);
    int64_t dplen_1 = dplen;
    b_1[3] = y9;
    struct __Bigint* b = b_1;
    *(b_1 + 0x14) = 1;
    void* rbx_1;
    
    if (nd0_1 <= 9)
    {
        rbx_1 = &s[dplen_1 + 9];
        nd0_1 = 9;
    }
    else
    {
        void* i_1 = &s[9];
        
        do
        {
            int32_t r8 = *i_1;
            i_1 += 1;
            b = __multadd_D2A(b, 0xa, r8 - 0x30);
        } while (i_1 != &s[nd0_1]);
        
        rbx_1 = i_1 + dplen_1;
    }
    
    if (nd > nd0_1)
    {
        void* rsi_2 = nd - nd0_1 + rbx_1;
        
        do
        {
            int32_t r8_2 = *rbx_1;
            rbx_1 += 1;
            b = __multadd_D2A(b, 0xa, r8_2 - 0x30);
        } while (rbx_1 != rsi_2);
    }
    
    return b;
}

uint64_t __ratio_D2A(struct __Bigint* a, struct __Bigint* b)
{
    int ka;
    uint128_t zmm0 = __b2d_D2A(a, &ka);
    uint128_t zmm6 = zmm0;
    int64_t rbx = zmm0;
    int kb;
    uint64_t zmm0_1 = __b2d_D2A(b, &kb);
    int32_t rax_4 = ((a->wds - b->wds) << 5) + ka - kb;
    
    if (rax_4 <= 0)
        zmm0_1 = zmm0_1 | ((zmm0_1 >> 0x20) - (rax_4 << 0x14)) << 0x20;
    else
        zmm6 = rbx | ((rbx >> 0x20) + (rax_4 << 0x14)) << 0x20;
    
    zmm6 = zmm6 / zmm0_1;
    return zmm6;
}

int __match_D2A(char const** sp, char* t)
{
    char const* r8 = *sp;
    int32_t rax_1;
    int32_t r9_1;
    
    do
    {
        r9_1 = *t;
        t = &t[1];
        r8 = &r8[1];
        
        if (!r9_1)
        {
            *sp = r8;
            return 1;
        }
        
        rax_1 = *r8;
        
        if (rax_1 - 0x41 < 0x1a)
            rax_1 += 0x20;
    } while (rax_1 == r9_1);
    return 0;
}

void* __copybits_D2A(long unsigned int* c, int n, struct __Bigint* b)
{
    long unsigned int (* rsi)[0x1] = &b->x;
    void* rdx = &c[((n - 1) >> 5) + 1];
    void* result = &rsi[b->wds];
    
    if (rsi < result)
    {
        long unsigned int* c_1 = c;
        
        do
        {
            *c_1 = ADJ(rsi)->x;
            c_1 = &c_1[1];
            rsi = &rsi[1];
        } while (rsi < result);
        
        result = (result - b - 0x19) >> 2;
        c = &c[result + 1];
    }
    
    if (c >= rdx)
        return result;
    
    /* tailcall */
    return memset(c, 0, ((rdx - 1 - c) >> 2 << 2) + 4);
}

long unsigned int __any_on_D2A(struct __Bigint* b, int k)
{
    int64_t wds = b->wds;
    int32_t r9_1 = k >> 5;
    void* rax;
    
    if (wds >= r9_1)
    {
        rax = &(&b->x)[r9_1];
        
        if (wds > r9_1)
        {
            int32_t rdx_1 = k & 0x1f;
            
            if (rdx_1)
            {
                int32_t r10_1 = *rax;
                char rcx = rdx_1;
                
                if (r10_1 != r10_1 >> rcx << rcx)
                    return 1;
            }
        }
    }
    else
        rax = &(&b->x)[wds];
    
    int32_t i;
    
    do
    {
        if (&b->x >= rax)
            return 0;
        
        i = *(rax - 4);
        rax -= 4;
    } while (!i);
    return 1;
}

int* __p__fmode() __pure
{
    return _fmode;
}

int* __p__commode() __pure
{
    return _commode;
}

int64_t _lock_file(struct _iobuf* pf)
{
    if (pf >= __acrt_iob_func(0) && pf <= __acrt_iob_func(0x13))
    {
        int64_t result = _lock(((pf - __acrt_iob_func(0)) >> 4) * 0xaaaaaaab + 0x10);
        *(pf + 0x18) |= 0x8000;
        return result;
    }
    
    /* tailcall */
    return EnterCriticalSection(&pf[6]);
}

int64_t _unlock_file(struct _iobuf* pf)
{
    if (pf >= __acrt_iob_func(0) && pf <= __acrt_iob_func(0x13))
    {
        *(pf + 0x18) &= 0xffff7fff;
        /* tailcall */
        return _unlock(((pf - __acrt_iob_func(0)) >> 4) * 0xaaaaaaab + 0x10);
    }
    
    /* tailcall */
    return LeaveCriticalSection(&pf[6]);
}

void (*)() mingw_get_invalid_parameter_handler()
{
    return handler;
}

void (*)() mingw_set_invalid_parameter_handler(void (* new_handler)())
{
    void (* handler_1)() = handler;
    handler = new_handler;
    return handler_1;
}

void* __acrt_iob_func(unsigned int index)
{
    return &__iob_func()[index * 6];
}

int32_t __wcrtomb_cp(char* dst, short unsigned int wc, unsigned int const cp, unsigned int const mb_max)
{
    short unsigned int wideCharStr = wc;
    
    if (cp)
    {
        BOOL invalid_char = 0;
        int32_t result =
            WideCharToMultiByte(cp, 0, &wideCharStr, 1, dst, mb_max, nullptr, &invalid_char);
        
        if (result && !invalid_char)
            return result;
    }
    else if (wc <= 0xff)
    {
        *dst = wc;
        return 1;
    }
    
    *_errno() = 0x2a;
    return 0xffffffff;
}

int64_t wcrtomb(char* dst, short unsigned int wc, int* ps)
{
    char* dst_1 = dst;
    char byte_bucket[0x5];
    
    if (!dst)
        dst_1 = &byte_bucket;
    int32_t mb_max = ___mb_cur_max_func();
    return __wcrtomb_cp(dst_1, wc, ___lc_codepage_func(), mb_max);
}

long long unsigned int wcsrtombs(char* dst, short unsigned int const** src, long long unsigned int len, int* ps)
{
    int64_t result = 0;
    char* dst_1 = dst;
    uint32_t cp = ___lc_codepage_func();
    int32_t mb_max = ___mb_cur_max_func();
    short unsigned int const* r13 = *src;
    
    if (r13)
    {
        if (!dst_1)
        {
            while (true)
            {
                char byte_bucket[0x5];
                int32_t rax_5 = __wcrtomb_cp(&byte_bucket, *r13, cp, mb_max);
                
                if (rax_5 <= 0)
                    break;
                
                result += rax_5;
                
                if (!byte_bucket[rax_5 - 1])
                    return result - 1;
                
                r13 = &r13[1];
            }
            
            return -1;
        }
        
        if (len)
        {
            do
            {
                int32_t rax_1 = __wcrtomb_cp(dst_1, *r13, cp, mb_max);
                
                if (rax_1 <= 0)
                    return -1;
                
                int64_t rax = rax_1;
                dst_1 = &dst_1[rax];
                result += rax;
                
                if (!dst_1[-1])
                {
                    *src = nullptr;
                    return result - 1;
                }
                
                r13 = &r13[1];
            } while (result < len);
        }
        
        *src = r13;
    }
    
    return result;
}

int __mbrtowc_cp(short unsigned int* pwc, char const* s, long long unsigned int n, int* ps, unsigned int const cp, unsigned int const mb_max)
{
    if (s)
    {
        if (!n)
            return -2;
        
        int shift_state_1 = *ps;
        char const TestChar = *s;
        *ps = 0;
        int shift_state = shift_state_1;
        
        if (TestChar)
        {
            if (mb_max <= 1)
            {
            label_14000f4e3:
                
                if (!cp)
                {
                    *pwc = *s;
                    return 1;
                }
                
                if (MultiByteToWideChar(cp, MB_ERR_INVALID_CHARS, s, 1, pwc, 1))
                    return 1;
                
                *_errno() = 0x2a;
                return -1;
            }
            
            short unsigned int* lpWideCharStr;
            char const* lpMultiByteStr;
            
            if (shift_state_1)
            {
                *shift_state[1] = TestChar;
                lpMultiByteStr = &shift_state;
                int32_t var_30_2 = 1;
                lpWideCharStr = pwc;
            label_14000f4bf:
                
                if (MultiByteToWideChar(cp, MB_ERR_INVALID_CHARS, lpMultiByteStr, 2, lpWideCharStr, 
                        1))
                    return 2;
                
                *_errno() = 0x2a;
                return -1;
            }
            
            if (!IsDBCSLeadByteEx(cp, TestChar))
                goto label_14000f4e3;
            
            if (n == 1)
            {
                *ps = *s;
                return -2;
            }
            
            lpWideCharStr = pwc;
            lpMultiByteStr = s;
            int32_t var_30_1 = 1;
            goto label_14000f4bf;
        }
        
        *pwc = 0;
    }
    
    return 0;
}

int64_t mbrtowc(short unsigned int* pwc, char const* s, long long unsigned int n, int* ps)
{
    short unsigned int* pwc_1 = pwc;
    short unsigned int byte_bucket = 0;
    
    if (!pwc)
        pwc_1 = &byte_bucket;
    
    int32_t mb_max = ___mb_cur_max_func();
    uint32_t cp = ___lc_codepage_func();
    int* ps_1 = &internal_mbstate;
    
    if (ps)
        ps_1 = ps;
    
    return __mbrtowc_cp(pwc_1, s, n, ps_1, cp, mb_max);
}

long long unsigned int mbsrtowcs(short unsigned int* dst, char const** src, long long unsigned int len, int* ps)
{
    int* ps_1 = ps;
    short unsigned int* pwc = dst;
    
    if (!ps)
        ps_1 = &internal_mbstate;
    
    uint32_t cp = ___lc_codepage_func();
    int32_t mb_max = ___mb_cur_max_func();
    
    if (src)
    {
        char* s = *src;
        
        if (s)
        {
            int64_t result;
            
            if (!pwc)
            {
                result = 0;
                short unsigned int byte_bucket = 0;
                
                while (true)
                {
                    int rax_4 = __mbrtowc_cp(&byte_bucket, &s[result], mb_max, ps_1, cp, mb_max);
                    
                    if (rax_4 <= 0)
                        break;
                    
                    s = *src;
                    result += rax_4;
                }
            }
            else
            {
                result = 0;
                
                if (len)
                {
                    do
                    {
                        int rax_1 = __mbrtowc_cp(pwc, s, len - result, ps_1, cp, mb_max);
                        
                        if (rax_1 <= 0)
                        {
                            if (result < len && !rax_1)
                                *src = nullptr;
                            
                            break;
                        }
                        
                        int64_t rax = rax_1;
                        pwc = &pwc[1];
                        result += rax;
                        s = &(*src)[rax];
                        *src = s;
                    } while (result < len);
                }
            }
            
            return result;
        }
    }
    
    return 0;
}

int64_t mbrlen(char const* s, long long unsigned int n, int* ps)
{
    int* ps_1 = ps;
    short unsigned int byte_bucket = 0;
    int32_t mb_max = ___mb_cur_max_func();
    uint32_t cp = ___lc_codepage_func();
    
    if (!ps_1)
        ps_1 = &s_mbstate;
    
    return __mbrtowc_cp(&byte_bucket, s, n, ps_1, cp, mb_max);
}

EXCEPTION_DISPOSITION _.text(struct _EXCEPTION_RECORD* ExceptionRecord, void* EstablisherFrame, struct _CONTEXT* ContextRecord, struct _DISPATCHER_CONTEXT* DispatcherContext)
{
    /* tailcall */
    return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, 
        DispatcherContext);
}

uint32_t ___lc_codepage_func()
{
    /* tailcall */
    return ___lc_codepage_func();
}

int32_t ___mb_cur_max_func()
{
    /* tailcall */
    return ___mb_cur_max_func();
}

uint64_t __getmainargs(int32_t* arg1, int64_t* arg2, int64_t* arg3, int32_t arg4, int32_t* arg5)
{
    /* tailcall */
    return __getmainargs(arg1, arg2, arg3, arg4, arg5);
}

FILE* __iob_func()
{
    /* tailcall */
    return __iob_func();
}

void __set_app_type(enum _crt_app_type _Type)
{
    /* tailcall */
    return __set_app_type(_Type);
}

void __setusermatherr(_UserMathErrorFunctionPointer _UserMathErrorFunction)
{
    /* tailcall */
    return __setusermatherr(_UserMathErrorFunction);
}

void _amsg_exit(int32_t rterrnum)
{
    /* tailcall */
    return _amsg_exit(rterrnum);
}

void _cexit()
{
    /* tailcall */
    return _cexit();
}

int32_t* _errno()
{
    /* tailcall */
    return _errno();
}

void _initterm(_PVFV* _First, _PVFV* _Last)
{
    /* tailcall */
    return _initterm(_First, _Last);
}

void _lock(int32_t locknum)
{
    /* tailcall */
    return _lock(locknum);
}

_onexit_t_1 _onexit(_onexit_t_1 _Func)
{
    /* tailcall */
    return _onexit(_Func);
}

void _unlock(int32_t locknum)
{
    /* tailcall */
    return _unlock(locknum);
}

void abort() __noreturn
{
    /* tailcall */
    return abort();
}

int64_t calloc(uint64_t _Count, uint64_t _Size)
{
    /* tailcall */
    return calloc(_Count, _Size);
}

void exit(int32_t _Except) __noreturn
{
    /* tailcall */
    return exit(_Except);
}

int32_t fprintf(FILE* const _Stream, char const* const _Format, ...)
{
    /* tailcall */
    return fprintf(_Stream, _Format);
}

int32_t fputc(int32_t _Character, FILE* _Stream)
{
    /* tailcall */
    return fputc(_Character, _Stream);
}

void free(void* _Block)
{
    /* tailcall */
    return free(_Block);
}

uint64_t fwrite(void const* _Buffer, uint64_t _ElementSize, uint64_t _ElementCount, FILE* _Stream)
{
    /* tailcall */
    return fwrite(_Buffer, _ElementSize, _ElementCount, _Stream);
}

int32_t getc(FILE* _Stream)
{
    /* tailcall */
    return getc(_Stream);
}

int32_t isspace(int32_t _C)
{
    /* tailcall */
    return isspace(_C);
}

int32_t isxdigit(int32_t _C)
{
    /* tailcall */
    return isxdigit(_C);
}

struct lconv* localeconv()
{
    /* tailcall */
    return localeconv();
}

int64_t malloc(uint64_t _Size)
{
    /* tailcall */
    return malloc(_Size);
}

int64_t memcpy(void* _Dst, void const* _Src, uint64_t _Size)
{
    /* tailcall */
    return memcpy(_Dst, _Src, _Size);
}

int64_t memmove(void* _Dst, void const* _Src, uint64_t _Size)
{
    /* tailcall */
    return memmove(_Dst, _Src, _Size);
}

int64_t memset(void* _Dst, int32_t _Val, uint64_t _Size)
{
    /* tailcall */
    return memset(_Dst, _Val, _Size);
}

void perror(char const* _ErrorMessage)
{
    /* tailcall */
    return perror(_ErrorMessage);
}

int64_t realloc(void* _Block, uint64_t _Size)
{
    /* tailcall */
    return realloc(_Block, _Size);
}

_crt_signal_t signal(int32_t _Signal, _crt_signal_t _Function)
{
    /* tailcall */
    return signal(_Signal, _Function);
}

char* strerror(int32_t _ErrorMessage)
{
    /* tailcall */
    return strerror(_ErrorMessage);
}

uint64_t strlen(char const* _Str)
{
    /* tailcall */
    return strlen(_Str);
}

int32_t strncmp(char const* _Str1, char const* _Str2, uint64_t _MaxCount)
{
    /* tailcall */
    return strncmp(_Str1, _Str2, _MaxCount);
}

int32_t strtol(char const* _String, char** _EndPtr, int32_t _Radix)
{
    /* tailcall */
    return strtol(_String, _EndPtr, _Radix);
}

uint32_t strtoul(char const* _String, char** _EndPtr, int32_t _Radix)
{
    /* tailcall */
    return strtoul(_String, _EndPtr, _Radix);
}

int32_t tolower(int32_t _C)
{
    /* tailcall */
    return tolower(_C);
}

int32_t ungetc(int32_t _Character, FILE* _Stream)
{
    /* tailcall */
    return ungetc(_Character, _Stream);
}

int32_t vfprintf(FILE* const _Stream, char const* const _Format, va_list _ArgList)
{
    /* tailcall */
    return vfprintf(_Stream, _Format, _ArgList);
}

uint64_t wcslen(wchar16 const* _String)
{
    /* tailcall */
    return wcslen(_String);
}

uint64_t _strtoui64(char const* _String, char** _EndPtr, int32_t _Radix)
{
    /* tailcall */
    return _strtoui64(_String, _EndPtr, _Radix);
}

int64_t _strtoi64(char const* _String, char** _EndPtr, int32_t _Radix)
{
    /* tailcall */
    return _strtoi64(_String, _EndPtr, _Radix);
}

int32_t WideCharToMultiByte(uint32_t CodePage, uint32_t dwFlags, wchar16* lpWideCharStr, int32_t cchWideChar, PSTR lpMultiByteStr, int32_t cbMultiByte, PSTR lpDefaultChar, BOOL* lpUsedDefaultChar)
{
    /* tailcall */
    return WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, 
        cbMultiByte, lpDefaultChar, lpUsedDefaultChar);
}

uint64_t VirtualQuery(void* lpAddress, MEMORY_BASIC_INFORMATION* lpBuffer, uint64_t dwLength)
{
    /* tailcall */
    return VirtualQuery(lpAddress, lpBuffer, dwLength);
}

BOOL VirtualProtect(void* lpAddress, uint64_t dwSize, enum PAGE_PROTECTION_FLAGS flNewProtect, enum PAGE_PROTECTION_FLAGS* lpflOldProtect)
{
    /* tailcall */
    return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}

int64_t TlsGetValue(uint32_t dwTlsIndex)
{
    /* tailcall */
    return TlsGetValue(dwTlsIndex);
}

void Sleep(uint32_t dwMilliseconds)
{
    /* tailcall */
    return Sleep(dwMilliseconds);
}

LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
    /* tailcall */
    return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

int32_t MultiByteToWideChar(uint32_t CodePage, enum MULTI_BYTE_TO_WIDE_CHAR_FLAGS dwFlags, uint8_t* lpMultiByteStr, int32_t cbMultiByte, wchar16* lpWideCharStr, int32_t cchWideChar)
{
    /* tailcall */
    return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, 
        cchWideChar);
}

void LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return LeaveCriticalSection(lpCriticalSection);
}

BOOL IsDBCSLeadByteEx(uint32_t CodePage, uint8_t TestChar)
{
    /* tailcall */
    return IsDBCSLeadByteEx(CodePage, TestChar);
}

void InitializeCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return InitializeCriticalSection(lpCriticalSection);
}

enum WIN32_ERROR GetLastError()
{
    /* tailcall */
    return GetLastError();
}

void EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return EnterCriticalSection(lpCriticalSection);
}

void DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return DeleteCriticalSection(lpCriticalSection);
}

int64_t main()
{
    __main();
    int32_t rdx = 0;
    int64_t var_5c8;
    __builtin_memset(&var_5c8, 0, 0xa3);
    int64_t var_518;
    __builtin_memset(&var_518, 0, 0x44);
    void _Str;
    __builtin_memset(&_Str, 0, 0x400);
    int64_t var_5a8;
    
    for (int64_t i = 0x2a; i != 0x6c; i += 1)
    {
        if (!(i & 1))
        {
            int64_t rcx_1 = rdx;
            rdx += 1;
            *(&var_5a8 + rcx_1) = *(u"One step closer... : aee1ee5262757cf67b619ff63e9672b6" + i);
        }
    }
    
    int64_t var_5b8;
    hexStringToBytes(&var_5a8, &var_5b8);
    void var_4c8;
    __builtin_memset(&var_4c8, 0, 0x98);
    int64_t var_568;
    printf("Please enter the password: ", 
        printf("\n\n", 
            printf("binary and see if you can figure out what it is!\n", 
                printf("Mr. Sam Altman. has a favorite spooky cereal.  Tear apart this\n", 
                    printf(
                        "This year, AI moguls are asking their LLMs which spooky cereal is best!\n", 
                        hexStringToBytes(
                        "393efd6a57f30a45c253336ca27fe7171c25492ac1f358f7e954d13b806b7fa25902d72c1c353d0901ca08b58cadef510d1868dedaa21459f1478ba3b6c09b898e7718", 
                        &var_568))))));
    scanf.constprop.0("%1023[^\n]", &_Str);
    trim(&_Str);
    MD5_Init(&var_4c8);
    MD5_Update(&var_4c8, &_Str, strlen(&_Str));
    MD5_Final(&var_5c8, &var_4c8);
    int64_t var_5c0;
    int64_t var_5b0;
    int64_t rdx_12 = var_5c0 ^ var_5b0;
    
    if (!((var_5c8 ^ var_5b8) | rdx_12))
    {
        printf("\n\n*********** (I THINK I MIGHT BE HALLUCINATING) ***********\n\n", 
            printf("The SPOOKIEST cereal is...", 
                printf("ChatGPT says: \n", printf("\n\n", rdx_12))));
        Discombobulate(&var_568, 0x43, &var_5c8, 0x10, &var_518);
        printf("\n\n*********** (I THINK I MIGHT BE HALLUCINATING) ***********\n\n", 
            printf("%s", &var_518));
    }
    else
        printf("ACCESS DENIED: I'm sorry, Sam, I'm AFRAID I can't DO that...\n", rdx_12);
    
    return 0;
}

int64_t register_frame_ctor()
{
    /* tailcall */
    return __gcc_register_frame();
}

