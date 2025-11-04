int64_t sub_140001000() __pure
{
    return;
}

int64_t sub_140001010()
{
    data_1400300e8 = 1;
    data_1400300e4 = 1;
    data_1400300e0 = 1;
    int32_t rcx;
    rcx = false;
    data_14003000c = rcx;
    
    if (!data_140030100)
        __set_app_type(_crt_console_app);
    else
        __set_app_type(_crt_gui_app);
    
    int32_t* rax_1 = sub_140014ba0();
    *rax_1 = data_140030130;
    int32_t* rax_2 = sub_140014bb0();
    *rax_2 = data_1400300f0;
    
    if (data_1400230a0 != 1)
        return 0;
    
    sub_14000e780(sub_14000e0f0);
    return 0;
}

uint64_t sub_140001130()
{
    data_140030004 = data_1400300d0;
    return __getmainargs(&data_140030028, &data_140030020, &data_140030018, data_1400300c0, 
        &data_140030004);
}

uint64_t sub_140001180()
{
    TEB* gsbase;
    void* StackBase = gsbase->NtTib.Self->NtTib.StackBase;
    
    while (true)
    {
        int64_t rax_1 = 0;
        
        if (0 == data_1400300b0)
            data_1400300b0 = StackBase;
        else
            rax_1 = data_1400300b0;
        
        int32_t rdi;
        
        if (rax_1)
        {
            if (StackBase != rax_1)
            {
                Sleep(0x3e8);
                continue;
            }
            
            rdi = 1;
            
            if (data_1400300b8 != 1)
                goto label_1400011e5;
            
            goto label_14000133c;
        }
        else
        {
            rdi = 0;
            
            if (data_1400300b8 != 1)
            {
            label_1400011e5:
                
                if (!data_1400300b8)
                {
                    data_1400300b8 = 1;
                    _initterm(0x1400292b0, 0x1400292c0);
                }
                else
                    data_140030008 = 1;
                
                if (data_1400300b8 == 1)
                    goto label_14000135a;
                
                goto label_140001200;
            }
            
        label_14000133c:
            _amsg_exit(0x1f);
            
            if (data_1400300b8 != 1)
            {
            label_140001200:
                
                if (rdi)
                    break;
            }
            else
            {
            label_14000135a:
                _initterm(0x140029298, 0x1400292a8);
                data_1400300b8 = 2;
                
                if (rdi)
                    break;
            }
        }
        data_1400300b0;
        data_1400300b0 = 0;
        break;
    }
    
    _TLS_Entry_0(0, 2);
    sub_14000e3e0();
    data_140030140 = SetUnhandledExceptionFilter(sub_14000e790);
    sub_140014cb0(sub_140001000);
    int32_t rbx = data_140030028;
    int64_t _Size_1 = (rbx + 1) << 3;
    void* rax_6 = malloc(_Size_1);
    int64_t* r12 = data_140030020;
    int64_t* rbp = rax_6;
    void* rdi_4;
    
    if (rbx <= 0)
        rdi_4 = rax_6;
    else
    {
        int64_t i = 0;
        
        do
        {
            uint64_t _Size = strlen(*(r12 + i)) + 1;
            int64_t rax_8 = malloc(_Size);
            *(rbp + i) = rax_8;
            int64_t rdx_1 = *(r12 + i);
            i += 8;
            memcpy(rax_8, rdx_1, _Size);
        } while (_Size_1 - 8 != i);
        
        rdi_4 = _Size_1 - 8 + rbp;
    }
    
    *rdi_4 = 0;
    data_140030020 = rbp;
    sub_14000dff0();
    data_140030028;
    *__initenv = data_140030018;
    data_140030020;
    int32_t _Except = main();
    int32_t rcx_5 = data_14003000c;
    data_140030010 = _Except;
    
    if (!rcx_5)
    {
        exit(_Except);
        /* no return */
    }
    
    if (data_140030008)
        return _Except;
    
    _cexit();
    return data_140030010;
}

uint64_t _start()
{
    data_140030100 = 1;
    return sub_140001180();
}

uint64_t sub_1400013f0()
{
    data_140030100 = 0;
    return sub_140001180();
}

uint64_t sub_140001410(_onexit_t_1 arg1)
{
    _onexit_t_1 rax = _onexit(arg1);
    return rax - rax;
}

int64_t sub_140001430()
{
    /* tailcall */
    return sub_140001410(sub_140001440);
}

int64_t sub_140001440() __pure
{
    return;
}

LRESULT sub_140001480(HWND arg1, uint32_t arg2, WPARAM arg3, LPARAM arg4)
{
    WNDPROC lpPrevWndFunc = data_140030038;
    
    if (arg2 == 0x100)
    {
        if (arg3 == 0x20 || arg3 == 0xd)
        {
            HWND hWnd = GetParent(arg1);
            
            if (hWnd)
                SendMessageA(hWnd, 0x111, GetDlgCtrlID(arg1), arg1);
            
            InvalidateRect(arg1, nullptr, 1);
            return 0;
        }
    }
    else
    {
        void var_148;
        
        if (arg2 == 0x202)
        {
            GetClientRect(arg1, &var_148);
            
            if (PtInRect(&var_148, arg4 | arg4 >> 0x10 << 0x20))
            {
                HWND hWnd_1 = GetParent(arg1);
                
                if (hWnd_1)
                    SendMessageA(hWnd_1, 0x111, GetDlgCtrlID(arg1), arg1);
            }
        }
        else if (arg2 == 0xf)
        {
            PAINTSTRUCT paint;
            HDC rax_1 = BeginPaint(arg1, &paint);
            RECT var_1a8;
            GetClientRect(arg1, &var_1a8);
            COLORREF color = 0x71cc2e;
            uint64_t rax_3 = SendMessageA(arg1, 0xf2, 0, 0) & 4;
            
            if (!data_140030030)
                color = ((0x71cc2e - 0x71cc2e) & 0xa0a28) + 0x3c28b4;
            
            HBRUSH rax_4 = CreateSolidBrush(color);
            FillRect(rax_1, &var_1a8, rax_4);
            DeleteObject(rax_4);
            HPEN rax_5 = CreatePen(PS_COSMETIC, 1, 0xffffff);
            HGDIOBJ h = SelectObject(rax_1, rax_5);
            SelectObject(rax_1, GetStockObject(HOLLOW_BRUSH));
            Rectangle(rax_1, var_1a8.left, var_1a8.top, var_1a8.right, var_1a8.bottom);
            SelectObject(rax_1, h);
            DeleteObject(rax_5);
            SetBkMode(rax_1, 1);
            SetTextColor(rax_1, 0xffffff);
            SelectObject(rax_1, data_140030060);
            GetWindowTextA(arg1, &var_148, 0x100);
            
            if (rax_3)
                OffsetRect(&var_1a8, 1, 1);
            
            DrawTextA(rax_1, &var_148, 0xffffffff, &var_1a8, 
                DT_CENTER | DT_SINGLELINE | DT_VCENTER);
            EndPaint(arg1, &paint);
            return 0;
        }
    }
    
    if (!lpPrevWndFunc)
        /* tailcall */
        return DefWindowProcA(arg1, arg2, arg3, arg4);
    
    return CallWindowProcA(lpPrevWndFunc, arg1, arg2, arg3, arg4);
}

int64_t sub_140001780(HWND arg1, uint32_t arg2, HDC arg3, LPARAM arg4)
{
    uint128_t zmm6;
    uint128_t var_98 = zmm6;
    uint128_t zmm7;
    uint128_t var_88 = zmm7;
    uint128_t zmm8;
    uint128_t var_78 = zmm8;
    uint128_t zmm9;
    uint128_t var_68 = zmm9;
    int32_t zmm10[0x4];
    int32_t var_58[0x4] = zmm10;
    int32_t zmm11[0x4];
    int32_t var_48[0x4] = zmm11;
    uint8_t var_298;
    
    if (arg2 != 0x111)
    {
        if (arg2 > 0x111)
        {
            if (arg2 == 0x133)
            {
                SetTextColor(arg3, 0xffffff);
                SetBkColor(arg3, 0x232323);
                return data_140030040;
            }
            
            if (arg2 != 0x138)
                /* tailcall */
                return DefWindowProcA(arg1, arg2, arg3, arg4);
            
            SetBkMode(arg3, 1);
            GetWindowTextA(arg4, &var_298, 0x100);
            
            if (!strstr(&var_298, "LUCIFER"))
            {
                char* rax_31;
                
                if (data_140030030)
                    rax_31 = strstr(&var_298, "citadel{");
                
                if (!data_140030030 || !rax_31)
                    SetTextColor(arg3, 0xa0a0a0);
                else
                    SetTextColor(arg3, 0x71cc2e);
            }
            else
                SetTextColor(arg3, 0x4632dc);
            
            return data_140030048;
        }
        LUCIFER
        if (arg2 == 2)
        {
            HGDIOBJ ho = data_140030078;
            
            if (ho)
                DeleteObject(ho);
            
            HGDIOBJ ho_1 = data_140030070;
            
            if (ho_1)
                DeleteObject(ho_1);
            
            HGDIOBJ ho_2 = data_140030068;
            
            if (ho_2)
                DeleteObject(ho_2);
            
            HGDIOBJ ho_3 = data_140030060;
            
            if (ho_3)
                DeleteObject(ho_3);
            
            HGDIOBJ ho_4 = data_140030058;
            
            if (ho_4)
                DeleteObject(ho_4);
            
            HGDIOBJ ho_5 = data_140030050;
            
            if (ho_5)
                DeleteObject(ho_5);
            
            HGDIOBJ ho_6 = data_140030048;
            
            if (ho_6)
                DeleteObject(ho_6);
            
            HGDIOBJ ho_7 = data_140030040;
            
            if (ho_7)
                DeleteObject(ho_7);
            
            PostQuitMessage(0);
            return 0;
        }
        
        if (arg2 == 0xf)
        {
            RECT lprc[0x1f];
            FillRect(BeginPaint(arg1, &var_298), &lprc, data_140030048);
            EndPaint(arg1, &var_298);
            return 0;
        }
        
        if (arg2 != 1)
            /* tailcall */
            return DefWindowProcA(arg1, arg2, arg3, arg4);
        
        data_140030048 = CreateSolidBrush(0x141414);
        data_140030040 = CreateSolidBrush(0x232323);
        data_140030078 = CreateFontA(0x30, 0, 0, 0, 0x2bc, 0, 0, 0, 1, 0, 0, 4, 0, "Arial");
        data_140030070 = CreateFontA(0x10, 0, 0, 0, 0x190, 0, 0, 0, 1, 0, 0, 4, 0, "Arial");
        data_140030068 = CreateFontA(0x12, 0, 0, 0, 0x190, 0, 0, 0, 1, 0, 0, 4, 0, "Arial");
        data_140030060 = CreateFontA(0xe, 0, 0, 0, 0x2bc, 0, 0, 0, 1, 0, 0, 4, 0, "Arial");
        data_140030058 = CreateFontA(0x10, 0, 0, 0, 0x190, 0, 0, 0, 1, 0, 0, 4, 0, "Consolas");
        int32_t var_418 = 0;
        int32_t hWndParent_1 = 1;
        data_140030050 = CreateFontA(0x12, 0, 0, 0, 0x2bc, 0, 0, 0, 1, 0, 0, 4, 0, "Courier New");
        var_418 = GetModuleHandleA(nullptr);
        hWndParent_1 = arg1;
        CreateWindowExA(WS_EX_LEFT, "STATIC", "LUCIFER", 0x50000001, 0x32, 0x32, 0x1f4, 0x3c, 
            hWndParent_1, nullptr, nullptr, nullptr);
        var_418 = GetModuleHandleA(nullptr);
        hWndParent_1 = arg1;
        CreateWindowExA(WS_EX_LEFT, "STATIC", "The Morning Star Awaits Your Offering", 0x50000001, 
            0x32, 0x6e, 0x1f4, 0x19, hWndParent_1, nullptr, nullptr, nullptr);
        var_418 = GetModuleHandleA(nullptr);
        hWndParent_1 = arg1;
        CreateWindowExA(WS_EX_LEFT, "STATIC", "Enter the Sacred Password:", 0x50000001, 0x32, 0xa0, 
            0x1f4, 0x19, hWndParent_1, nullptr, nullptr, nullptr);
        var_418 = GetModuleHandleA(nullptr);
        hWndParent_1 = arg1;
        HWND hWnd = CreateWindowExA(WS_EX_CLIENTEDGE, "EDIT", &data_140024071, 0x50010021, 0x82, 
            0xbe, 0x154, 0x23, hWndParent_1, 0x3e9, nullptr, nullptr);
        WPARAM wParam = data_140030058;
        data_140030090 = hWnd;
        SendMessageA(hWnd, 0x30, wParam, 1);
        hWndParent_1 = arg1;
        var_418 = GetModuleHandleA(nullptr);
        HWND hWnd_1 = CreateWindowExA(WS_EX_LEFT, "BUTTON", "SUBMIT OFFERING", 0x5001000b, 0xd2, 
            0xf0, 0xb4, 0x28, hWndParent_1, 0x3ea, nullptr, nullptr);
        WPARAM wParam_1 = data_140030060;
        data_140030088 = hWnd_1;
        SendMessageA(hWnd_1, 0x30, wParam_1, 1);
        data_140030038 = SetWindowLongPtrA(data_140030088, 0xfffffffc, sub_140001480);
    }
    else if (arg3 == 0x3ea && !(arg3 & 0xffff0000))
    {
        GetWindowTextA(data_140030090, &var_298, 0x200);
        uint64_t var_3d8;
        uint8_t* var_3e8 = &var_3d8;
        uint64_t rax_19 = strlen(&var_298);
        uint64_t var_3a8 = rax_19;
        int32_t r13_1 = rax_19;
        uint8_t* rdx_7;
        uint8_t* rax_32;
        
        if (rax_19 > 0xf)
        {
            rax_32 = sub_1400200f0(&var_3e8, &var_3a8, 0);
            uint64_t rdx_16 = var_3a8;
            var_3e8 = rax_32;
            var_3d8 = rdx_16;
        label_1400020f3:
            
            if (r13_1 >= 8)
            {
                *rax_32 = var_298;
                uint64_t rdx_21 = r13_1;
                void var_2a0;
                *(rax_32 + rdx_21 - 8) = *(&var_2a0 + rdx_21);
                void* rdx_23 = &rax_32[8] & 0xfffffffffffffff8;
                void* rax_41 = rax_32 - rdx_23;
                __builtin_memcpy(rdx_23, &var_298 - rax_41, (r13_1 + rax_41) >> 3 << 3);
            }
            else if (r13_1 & 4)
            {
                uint64_t r13_3 = r13_1;
                *rax_32 = var_298;
                void var_29c;
                *(rax_32 + r13_3 - 4) = *(&var_29c + r13_3);
            }
            else if (r13_1)
            {
                *rax_32 = var_298;
                
                if (r13_1 & 2)
                {
                    uint64_t r13_4 = r13_1;
                    void var_29a;
                    *(rax_32 + r13_4 - 2) = *(&var_29a + r13_4);
                }
            }
            
            rax_19 = var_3a8;
            rdx_7 = var_3e8;
        }
        else if (rax_19 != 1)
        {
            if (rax_19)
            {
                rax_32 = &var_3d8;
                goto label_1400020f3;
            }
            
            rdx_7 = &var_3d8;
        }
        else
        {
            var_3d8 = var_298;
            rdx_7 = &var_3d8;
        }
        rdx_7[rax_19] = 0;
        
        if (!rax_19)
            MessageBoxA(arg1, "Please enter a password first.", "Empty Password", MB_ICONASTERISK);
        else
        {
            int64_t rcx_15 = 0;
            int64_t rdx_8 = -0x3f0011edcba98765;
            
            do
            {
                uint64_t rax_20 = var_3e8[rcx_15];
                rcx_15 += 1;
                int64_t rax_24 = ((rax_20 * rcx_15 - 0x61c8864680b583eb) ^ rdx_8) * 0x100000001b3;
                rdx_8 = ROLQ(rax_24, 0xd) ^ rax_24 >> 7;
            } while (rax_19 != rcx_15);
            
            int32_t i_4 = 0xc350;
            int32_t i;
            
            do
            {
                int64_t rax_29 = (rdx_8 >> 0x1b ^ rdx_8) * -0x6b2fb644ecceee15;
                rdx_8 = rax_29 >> 0x21 ^ rax_29;
                i = i_4;
                i_4 -= 1;
            } while (i != 1);
            
            if (rdx_8 == -0x3326faf082668b85)
            {
                int128_t* rax_33 = sub_140021560(0x24);
                uint128_t* rsi_1 = rax_33;
                zmm6 = data_140023000;
                int32_t zmm3[0x4] = data_140024130;
                rax_33[1] = data_140023010;
                *rax_33 = zmm6;
                int32_t rax_34 = data_140023020;
                int128_t var_3c8;
                __builtin_memset(&var_3c8, 0, 0x20);
                int32_t zmm2[0x4] = zmm3;
                rsi_1[2] = rax_34;
                int64_t rax_35 = 0;
                zmm9 = _mm_shuffle_epi32(4, 0);
                zmm8 = _mm_shuffle_epi32(0x10, 0);
                zmm7 = _mm_shuffle_epi32(8, 0);
                zmm6 = _mm_shuffle_epi32(0xc, 0);
                int32_t zmm4_2[0x4] = _mm_shuffle_epi32(0xff00ff, 0);
                uint128_t zmm5_2 = _mm_shuffle_epi32(0x5a5a5a5a, 0);
                int32_t zmm0_1[0x4];
                int16_t zmm1[0x8];
                
                while (true)
                {
                    zmm11 = _mm_add_epi32(zmm2, zmm9);
                    zmm0_1 = _mm_unpacklo_epi16(zmm2, zmm11[0]);
                    zmm1 = _mm_unpackhi_epi16(zmm2, zmm11[0]);
                    zmm10 = _mm_add_epi32(zmm2, zmm8);
                    zmm11 = zmm0_1;
                    zmm0_1 = _mm_unpacklo_epi16(zmm0_1, zmm1[0]);
                    zmm11 = _mm_unpackhi_epi16(zmm11, zmm1[0]);
                    zmm1 = zmm2;
                    zmm2 = _mm_add_epi32(zmm2, zmm6);
                    zmm1 = _mm_add_epi32(zmm1, zmm7);
                    zmm0_1 = _mm_unpacklo_epi16(zmm0_1, zmm11[0]);
                    zmm11 = zmm1;
                    zmm1 = _mm_unpacklo_epi16(zmm1, zmm2[0]);
                    zmm11 = _mm_unpackhi_epi16(zmm11, zmm2[0]);
                    zmm2 = _mm_unpackhi_epi16(zmm1, zmm11[0]);
                    zmm0_1 = _mm_packus_epi16(zmm0_1 & zmm4_2, 
                        _mm_unpacklo_epi16(_mm_unpacklo_epi16(zmm1, zmm11[0]), zmm2[0]) & zmm4_2);
                    *(&var_3c8 + rax_35) =
                        _mm_add_epi8(_mm_add_epi8(zmm0_1, _mm_add_epi8(zmm0_1, zmm0_1)), zmm5_2)
                        ^ *(&data_140023040 + rax_35);
                    rax_35 += 0x10;
                    
                    if (rax_35 == 0x20)
                        break;
                    
                    zmm2 = zmm10;
                }
                
                uint64_t* i_1 = &var_3a8;
                zmm9 = _mm_shuffle_epi32(4, 0);
                zmm8 = _mm_shuffle_epi32(0x10, 0);
                zmm7 = _mm_shuffle_epi32(8, 0);
                zmm6 = _mm_shuffle_epi32(0xc, 0);
                zmm5_2 = _mm_shuffle_epi32(0xff00ff, 0);
                void var_2a8;
                
                do
                {
                    zmm2 = zmm3;
                    i_1 = &i_1[2];
                    zmm4_2 = _mm_add_epi32(zmm3, zmm9);
                    zmm1 = _mm_unpacklo_epi16(zmm2, zmm4_2[0]);
                    zmm0_1 = _mm_unpackhi_epi16(zmm2, zmm4_2[0]);
                    zmm3 = _mm_add_epi32(zmm3, zmm8);
                    zmm4_2 = zmm1;
                    zmm1 = _mm_unpacklo_epi16(zmm1, zmm0_1[0]);
                    zmm4_2 = _mm_unpackhi_epi16(zmm4_2, zmm0_1[0]);
                    zmm0_1 = zmm2;
                    zmm2 = _mm_add_epi32(zmm2, zmm6);
                    zmm0_1 = _mm_add_epi32(zmm0_1, zmm7);
                    zmm1 = _mm_unpacklo_epi16(zmm1, zmm4_2[0]);
                    zmm4_2 = zmm0_1;
                    zmm0_1 = _mm_unpacklo_epi16(zmm0_1, zmm2[0]);
                    zmm4_2 = _mm_unpackhi_epi16(zmm4_2, zmm2[0]);
                    zmm2 = _mm_unpackhi_epi16(zmm0_1, zmm4_2[0]);
                    *(i_1 - 0x10) = _mm_packus_epi16(zmm1 & zmm5_2, 
                        _mm_unpacklo_epi16(_mm_unpacklo_epi16(zmm0_1, zmm4_2[0]), zmm2[0])
                            & zmm5_2);
                } while (&var_2a8 != i_1);
                
                uint64_t* rdx_17 = &var_3a8;
                int32_t rcx_24 = 0;
                
                for (int32_t i_2 = 0; i_2 != 0x100; )
                {
                    int32_t i_5 = i_2;
                    uint32_t r9_1 = *rdx_17;
                    i_2 += 1;
                    rdx_17 += 1;
                    rcx_24 += *(&var_3c8 + (i_5 & 0x1f)) + r9_1;
                    uint64_t r8_6 = rcx_24;
                    *(rdx_17 - 1) = *(&var_3a8 + r8_6);
                    *(&var_3a8 + r8_6) = r9_1;
                }
                
                void* i_3 = &*var_3a8[1];
                uint128_t* rcx_25 = rsi_1;
                int32_t r8_7 = 0;
                void var_383;
                
                do
                {
                    uint32_t rax_36 = *i_3;
                    i_3 += 1;
                    r8_7 += rax_36;
                    uint64_t r9_2 = r8_7;
                    *(i_3 - 1) = *(&var_3a8 + r9_2);
                    *(&var_3a8 + r9_2) = rax_36;
                    rax_36 += *(i_3 - 1);
                    *rcx_25 ^= *(&var_3a8 + rax_36);
                    rcx_25 += 1;
                } while (i_3 != &var_383);
                
                int128_t* lpWindowName = sub_140021560(0x48);
                zmm6 = *rsi_1;
                zmm7 = rsi_1[1];
                *(lpWindowName + 0x24) = 0;
                *lpWindowName = zmm6;
                lpWindowName[1] = zmm7;
                lpWindowName[2] = rsi_1[2];
                sub_140021550(rsi_1);
                SetWindowTextA(arg1, "ACCESS GRANTED");
                HWND hWnd_3 = data_140030080;
                
                if (hWnd_3)
                    DestroyWindow(hWnd_3);
                
                int32_t hInstance;
                hInstance = GetModuleHandleA(nullptr);
                int32_t hWndParent;
                hWndParent = arg1;
                HWND hWnd_2 = CreateWindowExA(WS_EX_LEFT, "STATIC", lpWindowName, 0x50000001, 0x32, 
                    0x118, 0x1f4, 0x1e, hWndParent, 0x3eb, hInstance, nullptr);
                data_140030080 = hWnd_2;
                SendMessageA(hWnd_2, 0x30, data_140030050, 1);
                InvalidateRect(arg1, nullptr, 1);
                sub_140021550(lpWindowName);
                EnableWindow(data_140030090, 0);
                data_140030030 = 1;
            }
            else
            {
                MessageBoxA(arg1, "The offering is rejected. Try again.", "Access Denied", 
                    MB_ICONHAND);
                SetWindowTextA(data_140030090, &data_140024071);
                SetFocus(data_140030090);
            }
        }
        
        uint8_t* rcx_19 = var_3e8;
        
        if (rcx_19 != &var_3d8)
            sub_140021550(rcx_19);
    }
    return 0;
}

void sub_1400025de(void* arg1 @ rax, int64_t* arg2 @ r12) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

BOOL sub_140002620(HINSTANCE arg1, int64_t arg2, int64_t arg3, enum SHOW_WINDOW_CMD arg4)
{
    int64_t picce = 0xff00000008;
    InitCommonControlsEx(&picce);
    WNDCLASSA wndClass;
    wndClass.style = 0;
    wndClass.lpfnWndProc = 0;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = 0;
    wndClass.lpfnWndProc = sub_140001780;
    wndClass.hInstance = arg1;
    wndClass.lpszClassName = "LuciferCrackMe";
    wndClass.hIcon = 0;
    wndClass.hCursor = 0;
    wndClass.hbrBackground = 0;
    wndClass.lpszMenuName = 0;
    wndClass.hbrBackground = CreateSolidBrush(0x141414);
    wndClass.hCursor = LoadCursorA(nullptr, 0x7f00);
    wndClass.hIcon = LoadIconA(nullptr, 0x7f06);
    RegisterClassA(&wndClass);
    HWND hWnd = CreateWindowExA(WS_EX_LEFT, "LuciferCrackMe", "Lucifer v6.66", 0xca0000, 
        0x80000000, 0x80000000, 0x258, 0x190, nullptr, nullptr, arg1, nullptr);
    BOOL result = 1;
    
    if (hWnd)
    {
        ShowWindow(hWnd, arg4);
        UpdateWindow(hWnd);
        MSG msg;
        msg.hwnd = 0;
        msg.message = 0;
        msg.wParam = 0;
        msg.lParam = 0;
        msg.time = 0;
        msg.pt.x = 0;
        msg.pt.y = 0;
        
        while (true)
        {
            result = GetMessageA(&msg, nullptr, 0, 0);
            
            if (!result)
                break;
            
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }
    
    return result;
}

BOOL InitCommonControlsEx(struct INITCOMMONCONTROLSEX* picce)
{
    /* tailcall */
    return InitCommonControlsEx(picce);
}

BOOL UpdateWindow(HWND hWnd)
{
    /* tailcall */
    return UpdateWindow(hWnd);
}

BOOL TranslateMessage(MSG* lpMsg)
{
    /* tailcall */
    return TranslateMessage(lpMsg);
}

BOOL ShowWindow(HWND hWnd, enum SHOW_WINDOW_CMD nCmdShow)
{
    /* tailcall */
    return ShowWindow(hWnd, nCmdShow);
}

BOOL SetWindowTextA(HWND hWnd, PSTR lpString)
{
    /* tailcall */
    return SetWindowTextA(hWnd, lpString);
}

int64_t SetWindowLongPtrA(HWND hWnd, enum WINDOW_LONG_PTR_INDEX nIndex, int64_t dwNewLong)
{
    /* tailcall */
    return SetWindowLongPtrA(hWnd, nIndex, dwNewLong);
}

HWND SetFocus(HWND hWnd)
{
    /* tailcall */
    return SetFocus(hWnd);
}

LRESULT SendMessageA(HWND hWnd, uint32_t Msg, WPARAM wParam, LPARAM lParam)
{
    /* tailcall */
    return SendMessageA(hWnd, Msg, wParam, lParam);
}

uint16_t RegisterClassA(WNDCLASSA* lpWndClass)
{
    /* tailcall */
    return RegisterClassA(lpWndClass);
}

BOOL PtInRect(RECT* lprc, POINT pt)
{
    /* tailcall */
    return PtInRect(lprc, pt);
}

void PostQuitMessage(int32_t nExitCode)
{
    /* tailcall */
    return PostQuitMessage(nExitCode);
}

BOOL OffsetRect(RECT* lprc, int32_t dx, int32_t dy)
{
    /* tailcall */
    return OffsetRect(lprc, dx, dy);
}

enum MESSAGEBOX_RESULT MessageBoxA(HWND hWnd, PSTR lpText, PSTR lpCaption, enum MESSAGEBOX_STYLE uType)
{
    /* tailcall */
    return MessageBoxA(hWnd, lpText, lpCaption, uType);
}

HICON LoadIconA(HINSTANCE hInstance, PSTR lpIconName)
{
    /* tailcall */
    return LoadIconA(hInstance, lpIconName);
}

HCURSOR LoadCursorA(HINSTANCE hInstance, PSTR lpCursorName)
{
    /* tailcall */
    return LoadCursorA(hInstance, lpCursorName);
}

BOOL InvalidateRect(HWND hWnd, RECT* lpRect, BOOL bErase)
{
    /* tailcall */
    return InvalidateRect(hWnd, lpRect, bErase);
}

int32_t GetWindowTextA(HWND hWnd, uint8_t* lpString, int32_t nMaxCount)
{
    /* tailcall */
    return GetWindowTextA(hWnd, lpString, nMaxCount);
}

HWND GetParent(HWND hWnd)
{
    /* tailcall */
    return GetParent(hWnd);
}

BOOL GetMessageA(MSG* lpMsg, HWND hWnd, uint32_t wMsgFilterMin, uint32_t wMsgFilterMax)
{
    /* tailcall */
    return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}

int32_t GetDlgCtrlID(HWND hWnd)
{
    /* tailcall */
    return GetDlgCtrlID(hWnd);
}

BOOL GetClientRect(HWND hWnd, RECT* lpRect)
{
    /* tailcall */
    return GetClientRect(hWnd, lpRect);
}

int32_t FillRect(HDC hDC, RECT* lprc, HBRUSH hbr)
{
    /* tailcall */
    return FillRect(hDC, lprc, hbr);
}

BOOL EndPaint(HWND hWnd, PAINTSTRUCT* lpPaint)
{
    /* tailcall */
    return EndPaint(hWnd, lpPaint);
}

BOOL EnableWindow(HWND hWnd, BOOL bEnable)
{
    /* tailcall */
    return EnableWindow(hWnd, bEnable);
}

int32_t DrawTextA(HDC hdc, uint8_t* lpchText, int32_t cchText, RECT* lprc, enum DRAW_TEXT_FORMAT format)
{
    /* tailcall */
    return DrawTextA(hdc, lpchText, cchText, lprc, format);
}

LRESULT DispatchMessageA(MSG* lpMsg)
{
    /* tailcall */
    return DispatchMessageA(lpMsg);
}

BOOL DestroyWindow(HWND hWnd)
{
    /* tailcall */
    return DestroyWindow(hWnd);
}

LRESULT DefWindowProcA(HWND hWnd, uint32_t Msg, WPARAM wParam, LPARAM lParam)
{
    /* tailcall */
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

HWND CreateWindowExA(enum WINDOW_EX_STYLE dwExStyle, PSTR lpClassName, PSTR lpWindowName, enum WINDOW_STYLE dwStyle, int32_t X, int32_t Y, int32_t nWidth, int32_t nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, void* lpParam)
{
    /* tailcall */
    return CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, 
        hWndParent, hMenu, hInstance, lpParam);
}

LRESULT CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, uint32_t Msg, WPARAM wParam, LPARAM lParam)
{
    /* tailcall */
    return CallWindowProcA(lpPrevWndFunc, hWnd, Msg, wParam, lParam);
}

HDC BeginPaint(HWND hWnd, PAINTSTRUCT* lpPaint)
{
    /* tailcall */
    return BeginPaint(hWnd, lpPaint);
}

COLORREF SetTextColor(HDC hdc, COLORREF color)
{
    /* tailcall */
    return SetTextColor(hdc, color);
}

int32_t SetBkMode(HDC hdc, int32_t mode)
{
    /* tailcall */
    return SetBkMode(hdc, mode);
}

COLORREF SetBkColor(HDC hdc, COLORREF color)
{
    /* tailcall */
    return SetBkColor(hdc, color);
}

HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h)
{
    /* tailcall */
    return SelectObject(hdc, h);
}

BOOL Rectangle(HDC hdc, int32_t left, int32_t top, int32_t right, int32_t bottom)
{
    /* tailcall */
    return Rectangle(hdc, left, top, right, bottom);
}

HGDIOBJ GetStockObject(enum GET_STOCK_OBJECT_FLAGS i)
{
    /* tailcall */
    return GetStockObject(i);
}

BOOL DeleteObject(HGDIOBJ ho)
{
    /* tailcall */
    return DeleteObject(ho);
}

HBRUSH CreateSolidBrush(COLORREF color)
{
    /* tailcall */
    return CreateSolidBrush(color);
}

HPEN CreatePen(enum PEN_STYLE iStyle, int32_t cWidth, COLORREF color)
{
    /* tailcall */
    return CreatePen(iStyle, cWidth, color);
}

HFONT CreateFontA(int32_t cHeight, int32_t cWidth, int32_t cEscapement, int32_t cOrientation, int32_t cWeight, uint32_t bItalic, uint32_t bUnderline, uint32_t bStrikeOut, uint32_t iCharSet, uint32_t iOutPrecision, uint32_t iClipPrecision, uint32_t iQuality, uint32_t iPitchAndFamily, PSTR pszFaceName)
{
    /* tailcall */
    return CreateFontA(cHeight, cWidth, cEscapement, cOrientation, cWeight, bItalic, bUnderline, 
        bStrikeOut, iCharSet, iOutPrecision, iClipPrecision, iQuality, iPitchAndFamily, 
        pszFaceName);
}

int64_t __C_specific_handler()
{
    /* tailcall */
    return __C_specific_handler();
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

HMODULE GetModuleHandleA(PSTR lpModuleName)
{
    /* tailcall */
    return GetModuleHandleA(lpModuleName);
}

int32_t* sub_140002940(void* arg1, int32_t arg2, int64_t arg3, int64_t arg4)
{
    if (arg2 > 0x50)
    {
        uint64_t rax_9 = arg2 - 0x52;
        
        if (rax_9 > 0xc)
        {
        label_140002a18:
            
            if (arg3)
                goto label_1400029be;
        }
        else
            switch (rax_9)
            {
                case 0:
                case 1:
                case 8:
                {
                label_1400029be:
                    int32_t rcx_1 = *(arg1 + 0x28);
                    
                    if (rcx_1 < *(arg1 + 0x2c))
                    {
                        int32_t* result = (rcx_1 << 5) + *(arg1 + 0x20);
                        *(result + 4) = 0;
                        *(arg1 + 0x28) = rcx_1 + 1;
                        *result = arg2;
                        *(result + 0x10) = arg3;
                        *(result + 0x18) = arg4;
                        return result;
                    }
                    break;
                }
                case 2:
                case 6:
                case 7:
                case 9:
                case 0xa:
                case 0xb:
                {
                    goto label_140002a18;
                }
                case 3:
                case 4:
                {
                label_1400029b9:
                    
                    if (arg4)
                        goto label_1400029be;
                    break;
                }
                case 5:
                case 0xc:
                {
                label_1400029b4:
                    
                    if (arg3)
                        goto label_1400029b9;
                    break;
                }
            }
    }
    else if (arg2 > 0x34)
    {
        int32_t rax_6 = 1 << (arg2 - 0x35);
        
        if (rax_6 & 0x1c71107)
            goto label_140002a18;
        
        if (rax_6 & 0xa002ef8)
            goto label_1400029b4;
        
        if (arg2 == 0x4f)
            goto label_1400029be;
    }
    else if (arg2 <= 0x29)
    {
        int64_t rax_3 = 1 << arg2;
        
        if (rax_3 & 0x2f800fff600)
            goto label_140002a18;
        
        if (rax_3 & 0x3fe000000)
            goto label_1400029be;
        
        if (rax_3 & 0x40000081e)
            goto label_1400029b4;
    }
    else
    {
        uint64_t rax = arg2 - 0x2a;
        
        if (rax <= 8)
            switch (rax)
            {
                case 0:
                case 5:
                case 6:
                {
                    goto label_1400029be;
                }
                case 1:
                case 8:
                {
                    goto label_1400029b9;
                }
                case 2:
                case 4:
                {
                    goto label_1400029b4;
                }
                case 7:
                {
                    goto label_140002a18;
                }
            }
    }
    
    return 0;
}

int32_t* sub_140002a40(void* arg1, int64_t arg2, int32_t arg3)
{
    int32_t r9_1 = *(arg1 + 0x28);
    
    if (r9_1 < *(arg1 + 0x2c))
    {
        int32_t* result = (r9_1 << 5) + *(arg1 + 0x20);
        *(result + 4) = 0;
        *(arg1 + 0x28) = r9_1 + 1;
        
        if (arg2 && arg3 > 0)
        {
            *(result + 4) = 0;
            *result = 0;
            *(result + 0x10) = arg2;
            result[6] = arg3;
            return result;
        }
    }
    
    return 0;
}

uint64_t sub_140002aa0(void* arg1)
{
    char* rdx_8 = *(arg1 + 0x18);
    char rax = *rdx_8;
    int32_t rcx_1;
    int32_t r11_1;
    
    if (rax == 0x6e)
    {
        *(arg1 + 0x18) = &rdx_8[1];
        rax = rdx_8[1];
        
        if (rax - 0x30 > 9)
            rcx_1 = 0;
        else
        {
            r11_1 = 1;
        label_140002ac1:
            uint64_t rcx = 0;
            
            while (true)
            {
                int32_t rax_3 = rax - 0x30;
                
                if ((0x7fffffff - rax_3) / 0xa < rcx)
                {
                    rcx_1 = -1;
                    break;
                }
                
                rcx = rax_3 + ((rcx * 5) << 1);
                void* rax_1 = *(arg1 + 0x18);
                *(arg1 + 0x18) = rax_1 + 1;
                rax = *(rax_1 + 1);
                
                if (rax - 0x30 > 9)
                {
                    if (r11_1)
                        rcx = -(rcx);
                    
                    return rcx;
                }
            }
        }
    }
    else
    {
        if (rax - 0x30 <= 9)
        {
            r11_1 = 0;
            goto label_140002ac1;
        }
        
        rcx_1 = 0;
    }
    return rcx_1;
}

int64_t sub_140002b80(void* arg1, int32_t arg2)
{
    if (!arg2)
    {
        char* rax_3 = *(arg1 + 0x18);
        
        if (*rax_3)
        {
            *(arg1 + 0x18) = &rax_3[1];
            int32_t rax_4 = *rax_3;
            
            if (rax_4 == 0x68)
                goto label_140002bdb;
            
            if (rax_4 == 0x76)
                goto label_140002b94;
        }
    }
    else
    {
        if (arg2 == 0x68)
            goto label_140002bdb;
        
    label_140002b94:
        sub_140002aa0(arg1);
        char* rax_1 = *(arg1 + 0x18);
        
        if (*rax_1 == 0x5f)
        {
            *(arg1 + 0x18) = &rax_1[1];
        label_140002bdb:
            sub_140002aa0(arg1);
            char* rax_6 = *(arg1 + 0x18);
            
            if (*rax_6 == 0x5f)
            {
                *(arg1 + 0x18) = &rax_6[1];
                return 1;
            }
        }
    }
    
    return 0;
}

int64_t sub_140002c00(void* arg1, int64_t arg2)
{
    char* rax_3 = *(arg1 + 0x18);
    char rdx = *rax_3;
    
    if (rdx != 0x52 && rdx != 0x4f)
        return arg2;
    
    int32_t r11 = *(arg1 + 0x48);
    int32_t r10 = 0x20;
    int32_t r9 = r11 + 3;
    
    if (rdx == 0x52)
    {
        r9 = r11 + 2;
        r10 = 0x1f;
    }
    
    *(arg1 + 0x48) = r9;
    *(arg1 + 0x18) = &rax_3[1];
    /* tailcall */
    return sub_140002940(arg1, r10, arg2, 0);
}

int64_t sub_140002c60(void* arg1)
{
    char* rax = *(arg1 + 0x18);
    
    if (*rax == 0x5f)
    {
        *(arg1 + 0x18) = &rax[1];
        
        if (rax[1] == 0x5f)
        {
            *(arg1 + 0x18) = &rax[2];
            int32_t rax_4 = sub_140002aa0(arg1);
            
            if (rax_4 < 0)
                return 0;
            
            if (rax_4 > 9)
            {
                char* rax_5 = *(arg1 + 0x18);
                
                if (*rax_5 != 0x5f)
                    return 0;
                
                *(arg1 + 0x18) = &rax_5[1];
            }
        }
        else if (sub_140002aa0(arg1) < 0)
            return 0;
    }
    
    return 1;
}

void sub_140002cd0(void* arg1, int32_t* arg2)
{
    int32_t* rbx = arg2;
    
    if (!arg2)
        return;
    
    while (true)
    {
        uint64_t rax = rbx[2];
        
        if (rax > 1)
            break;
        
        int32_t rdx = *(arg1 + 0x134);
        
        if (rdx > 0x400)
            break;
        
        int32_t rcx = *rbx;
        rbx[2] = rax + 1;
        int32_t* rax_1;
        
        if (rcx > 0x34)
        {
            if (rcx - 0x35 > 0x29)
                break;
            
            rax = 1 << (rcx - 0x35);
            
            if (!(rax & 0x2006fc13fff))
            {
                if (!(rax & 0x410060000) && !(rax & 0x180000))
                    break;
                
                rbx = *(rbx + 0x10);
                goto label_140002d94;
            }
            
            rax_1 = *(rbx + 0x10);
        }
        else if (rcx > 8)
        {
            rax = 1 << rcx;
            
            if (rax & 0x7decffefffe00)
                rax_1 = *(rbx + 0x10);
            else
            {
                if (!(rax & 0x3000000000))
                {
                    if (rcx != 0x34)
                        break;
                    
                    goto label_140002d90;
                }
                
                rax_1 = *(rbx + 0x10);
                
                if (*rax_1 == 5)
                    *(arg1 + 0x15c) += 1;
            }
        }
        else if (rcx == 7 || rcx == 8)
        {
        label_140002d90:
            rbx = *(rbx + 0x18);
        label_140002d94:
            
            if (!rbx)
                break;
            
            continue;
        }
        else
        {
            if (rcx > 3)
            {
                if (rcx != 4)
                    break;
                
                *(arg1 + 0x16c) += 1;
            }
            else if (!rcx)
                break;
            
            rax_1 = *(rbx + 0x10);
        }
        
        *(arg1 + 0x134) = rdx + 1;
        sub_140002cd0(arg1, rax_1);
        sub_140002cd0(arg1, *(rbx + 0x18));
        *(arg1 + 0x134) -= 1;
        break;
    }
}

int64_t sub_140002e20(int32_t* arg1)
{
    int32_t result = 0;
    
    if (arg1)
    {
        while (*arg1 == 0x30)
        {
            if (!*(arg1 + 0x10))
                break;
            
            arg1 = *(arg1 + 0x18);
            result += 1;
            
            if (!arg1)
                break;
        }
    }
    
    return result;
}

int64_t sub_140002e50(int32_t* arg1, int32_t arg2)
{
    if (arg1)
    {
        while (*arg1 == 0x30)
        {
            if (!arg2)
                return *(arg1 + 0x10);
            
            arg1 = *(arg1 + 0x18);
            arg2 -= 1;
            
            if (!arg1)
                break;
        }
    }
    
    return 0;
}

uint64_t sub_140002e90(int64_t arg1, uint64_t arg2, int64_t* arg3)
{
    uint64_t _Size = arg3[2];
    uint64_t result = arg2 + arg3[1] + 1;
    
    if (_Size >= result)
        goto label_140002eb3;
    
    if (!arg3[3])
    {
        if (!_Size)
        {
            _Size = 2;
            
            if (result > 2)
                goto label_140002f06;
        }
        else
        {
        label_140002f06:
            
            do
                _Size *= 2;
             while (_Size < result);
        }
        
        int64_t rax_3 = realloc(*arg3, _Size);
        
        if (!rax_3)
        {
            result = free(*arg3);
            arg3[3] = 1;
            __builtin_memset(arg3, 0, 0x18);
        }
        else
        {
            *arg3 = rax_3;
            arg3[2] = _Size;
        label_140002eb3:
            result = arg3[3];
            
            if (!result)
            {
                memcpy(arg3[1] + *arg3, arg1, arg2);
                result = *arg3 + arg2 + arg3[1];
                *result = 0;
                arg3[1] += arg2;
            }
        }
    }
    
    return result;
}

int64_t sub_140002f60(char* arg1, int64_t arg2, int64_t arg3)
{
    int64_t arg_18 = arg3;
    int64_t r9;
    int64_t arg_20 = r9;
    int64_t* var_10 = &arg_18;
    return sub_14000fcb0(arg1, "%d", &arg_18);
}

uint64_t sub_140002f90(void* arg1)
{
    char* rdx = **(arg1 + 0x10);
    
    if (*rdx == 0x64)
    {
        uint64_t rdx_2 = rdx[1] - 0x58;
        
        if (rdx_2 <= 0x20)
            return TEST_BITQ(0x100020001, rdx_2);
    }
    
    return 0;
}

uint64_t sub_140002fd0(char* arg1)
{
    uint32_t rdx_2 = *arg1;
    uint64_t rax = rdx_2 - 0x4b;
    
    if (rax <= 0x27)
    {
        rax = !TEST_BITQ(-0x8000000802, rax);
        return rax;
    }
    
    if (rdx_2 == 0x44)
    {
        uint64_t rdx_1 = arg1[1] - 0x4f;
        
        if (rdx_1 <= 0x29)
            return TEST_BITQ(0x30100000001, rdx_1);
    }
    
    return 0;
}

int64_t sub_140003030(char* arg1, char arg2, int512_t arg3 @ zmm0)
{
    int64_t result = *(arg1 + 0x100);
    int64_t rdx;
    
    if (result == 0xff)
    {
        arg1[0xff] = 0;
        (*(arg1 + 0x110))(arg3, 0xff, *(arg1 + 0x118));
        *(arg1 + 0x140) += 1;
        rdx = 1;
        result = 0;
    }
    else
        rdx = result + 1;
    
    *(arg1 + 0x100) = rdx;
    arg1[result] = arg2;
    arg1[0x108] = arg2;
    return result;
}

int32_t* sub_1400030a0(void* arg1, void* arg2)
{
    void* rax_2 = *(arg1 + 0x120);
    
    if (!rax_2)
    {
        *(arg1 + 0x130) = 1;
        return nullptr;
    }
    
    int32_t rdx = *(arg2 + 0x10);
    int32_t* result = *(*(rax_2 + 8) + 0x18);
    
    if (rdx < 0)
        return result;
    
    if (result)
    {
        while (*result == 0x30)
        {
            if (!rdx)
                return *(result + 0x10);
            
            result = *(result + 0x18);
            rdx -= 1;
            
            if (!result)
                break;
        }
    }
    
    return nullptr;
}

uint64_t sub_140003100(char* arg1, char* arg2)
{
    char* rbx = arg2;
    uint64_t result = strlen(arg2);
    
    if (result)
    {
        int64_t rdx = *(arg1 + 0x100);
        void* rbp_1 = &rbx[result];
        
        do
        {
            char rdi_1 = *rbx;
            int64_t rcx_1;
            
            if (rdx != 0xff)
                rcx_1 = rdx;
            else
            {
                rbx = &rbx[1];
                arg1[0xff] = 0;
                result = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_1;
                arg1[0x108] = rdi_1;
                
                if (rbp_1 == rbx)
                    break;
                
                rdi_1 = *rbx;
                rcx_1 = 1;
            }
            
            rdx = rcx_1 + 1;
            rbx = &rbx[1];
            *(arg1 + 0x100) = rdx;
            arg1[rcx_1] = rdi_1;
            arg1[0x108] = rdi_1;
        } while (rbx != rbp_1);
    }
    
    return result;
}

int32_t* sub_1400031d0(void* arg1, int32_t* arg2)
{
    int32_t* rbx = arg2;
    
    if (arg2)
    {
        while (true)
        {
            uint64_t rax_1 = *rbx;
            
            if (rax_1 > 0x18)
            {
                uint64_t rax_4 = rax_1 - 0x28;
                
                if (rax_4 <= 0x37)
                {
                    if (TEST_BITQ(0x80006718000801, rax_4))
                        break;
                    
                    if (rax_4 != 0xc)
                        goto label_140003247;
                    
                    goto label_14000321d;
                }
                
            label_140003247:
                int64_t rax_5 = sub_1400031d0(arg1, *(rbx + 0x10));
                
                if (rax_5)
                    return rax_5;
                
                rbx = *(rbx + 0x18);
                
                if (!rbx)
                    break;
            }
            else
                switch (rax_1)
                {
                    case 0:
                    case 6:
                    case 0x18:
                    {
                        break;
                        break;
                    }
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 9:
                    case 0xa:
                    case 0xb:
                    case 0xc:
                    case 0xd:
                    case 0xe:
                    case 0xf:
                    case 0x10:
                    case 0x11:
                    case 0x12:
                    case 0x13:
                    case 0x14:
                    case 0x15:
                    case 0x16:
                    case 0x17:
                    {
                        goto label_140003247;
                    }
                    case 5:
                    {
                        void* rax_6 = *(arg1 + 0x120);
                        
                        if (!rax_6)
                            *(arg1 + 0x130) = 1;
                        else
                        {
                            int32_t rdx_1 = rbx[4];
                            int32_t* rax_8 = *(*(rax_6 + 8) + 0x18);
                            
                            if (rdx_1 < 0)
                            {
                            label_1400032a4:
                                
                                if (rax_8 && *rax_8 == 0x30)
                                    return rax_8;
                            }
                            else if (rax_8)
                            {
                                while (true)
                                {
                                    if (*rax_8 != 0x30)
                                        return 0;
                                    
                                    if (!rdx_1)
                                        break;
                                    
                                    rax_8 = *(rax_8 + 0x18);
                                    rdx_1 -= 1;
                                    
                                    if (!rax_8)
                                        return 0;
                                }
                                
                                rax_8 = *(rax_8 + 0x10);
                                goto label_1400032a4;
                            }
                        }
                        
                        break;
                        break;
                    }
                    case 7:
                    case 8:
                    {
                    label_14000321d:
                        rbx = *(rbx + 0x18);
                        
                        if (!rbx)
                            break;
                        
                        continue;
                    }
                }
        }
    }
    
    return 0;
}

int32_t* sub_1400032d0(void* arg1)
{
    void* rax = *(arg1 + 0x18);
    
    if (*rax == 0x54)
    {
        void* rdx_1 = rax + 1;
        *(arg1 + 0x18) = rdx_1;
        char rax_1 = *(rax + 1);
        int32_t rcx;
        
        if (rax_1 == 0x5f)
        {
            rcx = 0;
        label_14000330e:
            *(arg1 + 0x18) = rdx_1 + 1;
            int32_t rdx_3 = *(arg1 + 0x28);
            
            if (rdx_3 < *(arg1 + 0x2c))
            {
                int32_t* result = (rdx_3 << 5) + *(arg1 + 0x20);
                *(result + 4) = 0;
                *(arg1 + 0x28) = rdx_3 + 1;
                *result = 5;
                result[4] = rcx;
                return result;
            }
        }
        else if (rax_1 != 0x6e)
        {
            int32_t rax_2 = sub_140002aa0(arg1);
            rcx = rax_2 + 1;
            
            if (rax_2 + 1 >= 0)
            {
                rdx_1 = *(arg1 + 0x18);
                
                if (*rdx_1 == 0x5f)
                    goto label_14000330e;
            }
        }
    }
    
    return 0;
}

uint64_t sub_140003360(char* arg1, int32_t arg2)
{
    void _Str;
    void* rbx = &_Str;
    sub_140002f60(&_Str, &data_140024478, arg2);
    uint64_t result = strlen(&_Str);
    
    if (result)
    {
        int64_t rdx = *(arg1 + 0x100);
        void* rbp_1 = &_Str + result;
        
        do
        {
            char rdi_1 = *rbx;
            int64_t rcx_2;
            
            if (rdx != 0xff)
                rcx_2 = rdx;
            else
            {
                rbx += 1;
                arg1[0xff] = 0;
                result = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_1;
                arg1[0x108] = rdi_1;
                
                if (rbp_1 == rbx)
                    break;
                
                rdi_1 = *rbx;
                rcx_2 = 1;
            }
            
            rdx = rcx_2 + 1;
            rbx += 1;
            *(arg1 + 0x100) = rdx;
            arg1[rcx_2] = rdi_1;
            arg1[0x108] = rdi_1;
        } while (rbx != rbp_1);
    }
    
    return result;
}

uint64_t sub_140003450(char* arg1, int32_t arg2, int32_t arg3)
{
    void* const rsi_2;
    void* const r12_1;
    
    if (arg2 == 0x5b)
    {
        r12_1 = 2;
        rsi_2 = &data_1400244e7;
    label_140003555:
        int64_t rax_1 = *(arg1 + 0x100);
        void* r12_2 = r12_1 + rsi_2;
        
        do
        {
            char rdi_2 = *rsi_2;
            int64_t rdx_1;
            
            if (rax_1 != 0xff)
                rdx_1 = rax_1;
            else
            {
                rsi_2 += 1;
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_2;
                arg1[0x108] = rdi_2;
                
                if (rsi_2 == r12_2)
                    break;
                
                rdi_2 = *rsi_2;
                rdx_1 = 1;
            }
            
            rax_1 = rdx_1 + 1;
            rsi_2 += 1;
            *(arg1 + 0x100) = rax_1;
            arg1[rdx_1] = rdi_2;
            arg1[0x108] = rdi_2;
        } while (rsi_2 != r12_2);
    }
    else
    {
        if (arg2 == 0x5c)
        {
            r12_1 = 3;
            rsi_2 = &data_1400244e0;
            goto label_140003555;
        }
        
        if (arg2 == 0x5a)
        {
            r12_1 = 2;
            rsi_2 = &data_1400244e4;
            goto label_140003555;
        }
        
        *(arg1 + 0x130) = 1;
    }
    void _Str;
    void* rsi_1 = &_Str;
    sub_140002f60(&_Str, &data_140024478, arg3);
    uint64_t result = strlen(&_Str);
    
    if (result)
    {
        int64_t rdx = *(arg1 + 0x100);
        void* rbp_1 = &_Str + result;
        
        do
        {
            char rdi_1 = *rsi_1;
            int64_t rcx_2;
            
            if (rdx != 0xff)
                rcx_2 = rdx;
            else
            {
                rsi_1 += 1;
                arg1[0xff] = 0;
                result = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_1;
                arg1[0x108] = rdi_1;
                
                if (rbp_1 == rsi_1)
                    break;
                
                rdi_1 = *rsi_1;
                rcx_2 = 1;
            }
            
            rdx = rcx_2 + 1;
            rsi_1 += 1;
            *(arg1 + 0x100) = rdx;
            arg1[rcx_2] = rdi_1;
            arg1[0x108] = rdi_1;
        } while (rbp_1 != rsi_1);
    }
    
    return result;
}

int32_t* sub_140003640(void* arg1)
{
    int32_t rax = sub_140002aa0(arg1);
    int32_t* result = nullptr;
    
    if (rax > 0)
    {
        int64_t* rdx_1 = *(arg1 + 0x18);
        int64_t rax_1 = rax;
        
        if (*(arg1 + 8) - rdx_1 < rax_1)
            result = nullptr;
        else
        {
            char* rax_2 = rax_1 + rdx_1;
            *(arg1 + 0x18) = rax_2;
            
            if (*(arg1 + 0x10) & 4 && *rax_2 == 0x24)
            {
                *(arg1 + 0x18) = &rax_2[1];
                
                if (rax > 9 && *rdx_1 == 0x5f4c41424f4c475f)
                    goto label_140003699;
                
                result = sub_140002a40(arg1, rdx_1, rax);
            }
            else if (rax <= 9 || *rdx_1 != 0x5f4c41424f4c475f)
                result = sub_140002a40(arg1, rdx_1, rax);
            else
            {
            label_140003699:
                uint64_t rax_4 = rdx_1[1] - 0x24;
                
                if (rax_4 > 0x3b || !TEST_BITQ(0x800000000000401, rax_4) || *(rdx_1 + 9) != 0x4e)
                    result = sub_140002a40(arg1, rdx_1, rax);
                else
                {
                    int32_t rdx_2 = *(arg1 + 0x28);
                    *(arg1 + 0x48) = *(arg1 + 0x48) + 0x16 - rax;
                    
                    if (rdx_2 >= *(arg1 + 0x2c))
                        result = nullptr;
                    else
                    {
                        *(arg1 + 0x28) = rdx_2 + 1;
                        result = (rdx_2 << 5) + *(arg1 + 0x20);
                        *(result + 4) = 0;
                        *result = 0;
                        *(result + 0x10) = "(anonymous namespace)";
                        result[6] = 0x15;
                    }
                }
            }
        }
        
        *(arg1 + 0x40) = result;
    }
    
    return result;
}

int32_t* sub_140003740(void* arg1, int32_t arg2)
{
    char* rcx = *(arg1 + 0x18);
    
    if (*rcx == 0x53)
    {
        *(arg1 + 0x18) = &rcx[1];
        int32_t rax_2 = rcx[1];
        
        if (!rax_2)
        {
        label_1400037e3:
            int32_t rcx_6 = *(arg1 + 0x10) & 8;
            
            if (rcx_6 || !(arg2 & 1))
                rcx_6 = rcx_6 >> 3 & 1;
            else
                rcx_6 = **(arg1 + 0x18) - 0x43 <= 1;
            
            for (void* const i = &data_140024f40; i != &data_1400250c8; i += 0x38)
            {
                if (*i == rax_2)
                {
                    int64_t r10_1 = *(i + 0x28);
                    int32_t rax_8 = *(arg1 + 0x28);
                    int32_t r9_1 = *(arg1 + 0x2c);
                    
                    if (r10_1)
                    {
                        int32_t r11_1 = *(i + 0x30);
                        int32_t* r8_3;
                        
                        if (rax_8 >= r9_1)
                            r8_3 = nullptr;
                        else
                        {
                            int64_t r8_1 = rax_8;
                            rax_8 += 1;
                            r8_3 = (r8_1 << 5) + *(arg1 + 0x20);
                            *(r8_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_8;
                            *r8_3 = 0x18;
                            *(r8_3 + 0x10) = r10_1;
                            r8_3[6] = r11_1;
                        }
                        
                        *(arg1 + 0x40) = r8_3;
                    }
                    
                    int64_t rcx_11;
                    int32_t rdx_6;
                    
                    if (rcx_6)
                    {
                        rcx_11 = *(i + 0x18);
                        rdx_6 = *(i + 0x20);
                    }
                    else
                    {
                        rcx_11 = *(i + 8);
                        rdx_6 = *(i + 0x10);
                    }
                    
                    *(arg1 + 0x48) += rdx_6;
                    int32_t* result;
                    
                    if (rax_8 >= r9_1)
                        result = nullptr;
                    else
                    {
                        result = (rax_8 << 5) + *(arg1 + 0x20);
                        *(result + 4) = 0;
                        *(arg1 + 0x28) = rax_8 + 1;
                        *result = 0x18;
                        *(result + 0x10) = rcx_11;
                        result[6] = rdx_6;
                    }
                    
                    char* rax_13 = *(arg1 + 0x18);
                    
                    if (*rax_13 != 0x42)
                        return result;
                    
                    int64_t rdi_1 = *(arg1 + 0x40);
                    
                    do
                    {
                        *(arg1 + 0x18) = &rax_13[1];
                        result = sub_140002940(arg1, 0x4e, result, sub_140003640(arg1));
                        rax_13 = *(arg1 + 0x18);
                    } while (*rax_13 == 0x42);
                    
                    *(arg1 + 0x40) = rdi_1;
                    
                    if (result)
                    {
                        int32_t rax_14 = *(arg1 + 0x38);
                        
                        if (rax_14 < *(arg1 + 0x3c))
                        {
                            *(*(arg1 + 0x30) + (rax_14 << 3)) = result;
                            *(arg1 + 0x38) = rax_14 + 1;
                            return result;
                        }
                    }
                    
                    break;
                }
            }
        }
        else
        {
            *(arg1 + 0x18) = &rcx[2];
            rax_2 = rcx[1];
            uint64_t rcx_1 = rax_2 - 0x30;
            
            if (rcx_1 > 0x2f || !TEST_BITQ(0x87fffffe03ff, rcx_1))
                goto label_1400037e3;
            
            uint64_t rdx = 0;
            uint64_t rcx_10;
            
            if (rax_2 != 0x5f)
            {
                int32_t rcx_4;
                
                while (true)
                {
                    if (rax_2 - 0x30 > 9)
                    {
                        if (rax_2 - 0x41 > 0x19)
                            return nullptr;
                        
                        rcx_4 = rax_2 + ((rdx * 9) << 2) - 0x37;
                    }
                    else
                        rcx_4 = rax_2 + ((rdx * 9) << 2) - 0x30;
                    
                    if (rcx_4 < rdx)
                        return nullptr;
                    
                    char* rax_4 = *(arg1 + 0x18);
                    
                    if (!*rax_4)
                        return nullptr;
                    
                    *(arg1 + 0x18) = &rax_4[1];
                    rax_2 = *rax_4;
                    
                    if (rax_2 == 0x5f)
                        break;
                    
                    rdx = rcx_4;
                }
                
                rcx_10 = rcx_4 + 1;
            }
            else
                rcx_10 = 0;
            
            if (rcx_10 < *(arg1 + 0x38))
                return *(*(arg1 + 0x30) + (rcx_10 << 3));
        }
    }
    
    return nullptr;
}

int64_t sub_140003990(void* arg1, int32_t** arg2)
{
    char* rax = *(arg1 + 0x18);
    
    if (*rax == 0x57)
    {
        do
        {
            int32_t rdi_1 = 0x55;
            *(arg1 + 0x18) = &rax[1];
            
            if (rax[1] == 0x50)
            {
                rdi_1 = 0x56;
                *(arg1 + 0x18) = &rax[2];
            }
            
            int32_t* rax_2 = sub_140003640(arg1);
            int32_t* rax_3 = sub_140002940(arg1, rdi_1, *arg2, rax_2);
            *arg2 = rax_3;
            int32_t rdx_3;
            
            if (rax_3)
                rdx_3 = *(arg1 + 0x38);
            
            if (!rax_3 || rdx_3 >= *(arg1 + 0x3c))
                return 0;
            
            *(*(arg1 + 0x30) + (rdx_3 << 3)) = rax_3;
            rax = *(arg1 + 0x18);
            *(arg1 + 0x38) = rdx_3 + 1;
        } while (*rax == 0x57);
    }
    
    return 1;
}

int32_t* sub_140003a30(void* arg1)
{
    int64_t r12;
    int64_t var_10 = r12;
    int64_t rbp;
    int64_t var_18 = rbp;
    int64_t rdi;
    int64_t var_20 = rdi;
    char* r8 = *(arg1 + 0x18);
    int32_t* _Str;
    
    if (sub_140002fd0(r8))
    {
        int32_t** rax_6 = sub_140005d80(arg1, &_Str, 0, rbp, rdi, r12);
        
        if (rax_6)
        {
            int32_t* rax_8;
            
            if (**(arg1 + 0x18) == 0x46)
                rax_8 = sub_1400046b0(arg1);
            else
                rax_8 = sub_140003a30(arg1);
            
            *rax_6 = rax_8;
            
            if (rax_8)
            {
                if (*rax_8 - 0x1f <= 1)
                {
                    int32_t* rdx_3 = *(rax_8 + 0x10);
                    *(rax_8 + 0x10) = _Str;
                    _Str = *rax_6;
                    *rax_6 = rdx_3;
                }
                
                int32_t* _Str_17 = _Str;
                
                if (_Str_17)
                {
                    int32_t rax_10 = *(arg1 + 0x38);
                    
                    if (rax_10 < *(arg1 + 0x3c))
                    {
                        *(*(arg1 + 0x30) + (rax_10 << 3)) = _Str_17;
                        *(arg1 + 0x38) = rax_10 + 1;
                        return _Str_17;
                    }
                }
            }
        }
    }
    else
    {
        int32_t rax_1 = *r8;
        int32_t* _Str_19;
        int32_t* rsi_3;
        
        if (rax_1 > 0x54)
        {
            if (rax_1 - 0x55 > 0x25)
                /* tailcall */
                return sub_140006690(arg1, 1);
            
            int64_t rdx_6 = 1 << (rax_1 - 0x55);
            
            if (rdx_6 & 0x3ec7bff000)
            {
                int32_t rdx_17 = *(arg1 + 0x28);
                
                if (rdx_17 >= *(arg1 + 0x2c))
                {
                    *0x10;
                    trap(6);
                }
                
                rsi_3 = *(arg1 + 0x20) + (rdx_17 << 5);
                *(rsi_3 + 4) = 0;
                *(arg1 + 0x28) = rdx_17 + 1;
                *(rsi_3 + 0x10) = &(&data_140025b00)[(rax_1 - 0x61) * 4];
                int32_t rax_89 = *(((rax_1 - 0x61) << 5) + 0x140025b08);
                *rsi_3 = 0x28;
                *(arg1 + 0x48) += rax_89;
                *(arg1 + 0x18) = &r8[1];
                return rsi_3;
            }
            
            if (!(rdx_6 & 1))
            {
                if (rax_1 != 0x75)
                    /* tailcall */
                    return sub_140006690(arg1, 1);
                
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_2 = sub_140002940(arg1, 0x29, sub_140003640(arg1), 0);
                _Str = _Str_2;
                _Str_19 = _Str_2;
                goto label_140003c00;
            }
            
            *(arg1 + 0x18) = &r8[1];
            int32_t* _Str_15 = sub_140003640(arg1);
            _Str = _Str_15;
            int32_t* _Str_20 = _Str_15;
            char* rax_83 = *(arg1 + 0x18);
            
            if (*rax_83 == 0x49)
            {
                *(arg1 + 0x18) = &rax_83[1];
                _Str_20 = sub_140002940(arg1, 4, _Str_20, sub_140005310(arg1));
            }
            
            int32_t* _Str_16 = sub_140002940(arg1, 0x22, sub_140003a30(arg1), _Str_20);
            _Str = _Str_16;
            _Str_19 = _Str_16;
            goto label_140003c00;
        }
        
        if (rax_1 <= 0x40 || rax_1 - 0x41 > 0x13)
            /* tailcall */
            return sub_140006690(arg1, 1);
        
        switch (rax_1)
        {
            case 0x41:
            {
                void* rdx_12 = &r8[1];
                *(arg1 + 0x18) = rdx_12;
                char rax_37 = r8[1];
                int32_t* rsi_4;
                
                if (rax_37 == 0x5f)
                {
                    rsi_4 = nullptr;
                label_140003eca:
                    *(arg1 + 0x18) = rdx_12 + 1;
                    int32_t* _Str_11 =
                        sub_140002940(arg1, 0x2b, rsi_4, sub_140003a30(arg1, rdx_12 + 1));
                    _Str = _Str_11;
                    _Str_19 = _Str_11;
                    goto label_140003c00;
                }
                
                char rax_44;
                void* r10_2;
                
                if (rax_37 - 0x30 > 9)
                {
                    int32_t rdi_9 = *(arg1 + 0x4c);
                    *(arg1 + 0x4c) = 1;
                    int32_t* rax_93 = sub_1400055b0(arg1);
                    *(arg1 + 0x4c) = rdi_9;
                    rsi_4 = rax_93;
                    
                    if (rax_93)
                    {
                        r10_2 = *(arg1 + 0x18);
                        rax_44 = *r10_2;
                    label_140003eb8:
                        rdx_12 = r10_2;
                        
                        if (rax_44 == 0x5f)
                            goto label_140003eca;
                    }
                }
                else
                {
                    r10_2 = rdx_12;
                    void* r11_2;
                    
                    do
                    {
                        r11_2 = r10_2;
                        r10_2 += 1;
                        *(arg1 + 0x18) = r10_2;
                    } while (*r10_2 - 0x30 <= 9);
                    
                    int32_t* rax_43 = sub_140002a40(arg1, rdx_12, r11_2 - r8);
                    rsi_4 = rax_43;
                    
                    if (rax_43)
                    {
                        rax_44 = *(r11_2 + 1);
                        goto label_140003eb8;
                    }
                }
                break;
            }
            case 0x42:
            case 0x45:
            case 0x48:
            case 0x49:
            case 0x4a:
            case 0x4b:
            case 0x4c:
            case 0x4e:
            case 0x51:
            case 0x53:
            {
                /* tailcall */
                return sub_140006690(arg1, 1);
            }
            case 0x43:
            {
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_3 = sub_140002940(arg1, 0x26, 
                    sub_140003a30(arg1, &jump_table_140024514, &r8[1]), 0);
                _Str = _Str_3;
                _Str_19 = _Str_3;
            label_140003c00:
                
                if (_Str_19)
                {
                label_140003c09:
                    int32_t rax_17 = *(arg1 + 0x38);
                    
                    if (rax_17 < *(arg1 + 0x3c))
                    {
                        *(*(arg1 + 0x30) + (rax_17 << 3)) = _Str_19;
                        int32_t* _Str_18 = _Str;
                        *(arg1 + 0x38) = rax_17 + 1;
                        return _Str_18;
                    }
                }
                break;
            }
            case 0x44:
            {
                *(arg1 + 0x18) = &r8[1];
                
                if (r8[1])
                {
                    *(arg1 + 0x18) = &r8[2];
                    
                    switch (r8[1] - 0x46)
                    {
                        case 0:
                        {
                            int32_t rax_48;
                            int64_t rcx_35;
                            rax_48 = sub_140002aa0(arg1);
                            char* rdx_14 = *(arg1 + 0x18);
                            uint64_t r8_20 = rax_48;
                            char rdi_8 = *rdx_14;
                            
                            if (rdi_8 != 0x62)
                            {
                                if (rdi_8 == 0x78)
                                    goto label_140003f73;
                                
                                if (rdi_8 == 0x5f)
                                {
                                    rdi_8 = 0;
                                label_140003f73:
                                    int32_t rax_49 = *(arg1 + 0x28);
                                    
                                    if (rax_49 >= *(arg1 + 0x2c))
                                        /* tailcall */
                                        return sub_140021b40(rcx_35, &rdx_14[1], r8_20, arg1);
                                    
                                    rsi_3 = *(arg1 + 0x20) + (rax_49 << 5);
                                    *(rsi_3 + 4) = 0;
                                    *(arg1 + 0x28) = rax_49 + 1;
                                    rsi_3[6] = r8_20;
                                    *rsi_3 = 0x5f;
                                    *(rsi_3 + 0x10) = &data_140025f40;
                                    *(rsi_3 + 0x1a) = rdi_8;
                                    *(arg1 + 0x18) = &rdx_14[1];
                                    sub_140002f60(&_Str, &data_140024478, r8_20);
                                    int32_t rax_51 = strlen(&_Str);
                                    *(arg1 + 0x48) =
                                        *(arg1 + 0x48) + *(*(rsi_3 + 0x10) + 8) + 1 + rax_51;
                                    return rsi_3;
                                }
                            }
                            else if (rax_48 == 0x10)
                            {
                                int32_t rax_95 = *(arg1 + 0x28);
                                *(arg1 + 0x18) = &rdx_14[1];
                                
                                if (rax_95 >= *(arg1 + 0x2c))
                                {
                                    *0x10;
                                    trap(6);
                                }
                                
                                rsi_3 = *(arg1 + 0x20) + (rax_95 << 5);
                                *(rsi_3 + 4) = 0;
                                *(arg1 + 0x28) = rax_95 + 1;
                                *(rsi_3 + 0x10) = &data_140025f60;
                                int32_t rax_97 = *(arg1 + 0x48);
                                *rsi_3 = 0x28;
                                *(arg1 + 0x48) = rax_97 + 0xf;
                                return rsi_3;
                            }
                            break;
                        }
                        case 0xe:
                        case 0x2e:
                        {
                            int32_t rsi_2 = *(arg1 + 0x4c);
                            *(arg1 + 0x4c) = 1;
                            int32_t* rax_13 = sub_1400055b0(arg1);
                            *(arg1 + 0x4c) = rsi_2;
                            int32_t* _Str_1 = sub_140002940(arg1, 0x45, rax_13, 0);
                            _Str = _Str_1;
                            _Str_19 = _Str_1;
                            
                            if (_Str_1)
                            {
                                char* rax_14 = *(arg1 + 0x18);
                                
                                if (*rax_14)
                                {
                                    *(arg1 + 0x18) = &rax_14[1];
                                    
                                    if (*rax_14 == 0x45)
                                        goto label_140003c09;
                                }
                            }
                            break;
                        }
                        case 0x1b:
                        {
                            int32_t rax_76 = *(arg1 + 0x28);
                            
                            if (rax_76 < *(arg1 + 0x2c))
                            {
                                void* rsi_17 = *(arg1 + 0x20);
                                *(arg1 + 0x28) = rax_76 + 1;
                                rsi_3 = rsi_17 + (rax_76 << 5);
                                *(rsi_3 + 4) = 0;
                                *rsi_3 = 0;
                                *(rsi_3 + 0x10) = "auto";
                                rsi_3[6] = 4;
                                return rsi_3;
                            }
                            break;
                        }
                        case 0x1d:
                        {
                            int32_t rax_56 = *(arg1 + 0x28);
                            
                            if (rax_56 < *(arg1 + 0x2c))
                            {
                                void* rsi_7 = *(arg1 + 0x20);
                                *(arg1 + 0x28) = rax_56 + 1;
                                rsi_3 = rsi_7 + (rax_56 << 5);
                                *(rsi_3 + 4) = 0;
                                *rsi_3 = 0;
                                *(rsi_3 + 0x10) = "decltype(auto)";
                                rsi_3[6] = 0xe;
                                return rsi_3;
                            }
                            break;
                        }
                        case 0x1e:
                        {
                            int32_t rax_74 = *(arg1 + 0x28);
                            
                            if (rax_74 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_74 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_74 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025e60;
                            *(arg1 + 0x48) += 9;
                            return rsi_3;
                            break;
                        }
                        case 0x1f:
                        {
                            int32_t rax_72 = *(arg1 + 0x28);
                            
                            if (rax_72 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_72 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_72 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025e80;
                            *(arg1 + 0x48) += 0xa;
                            return rsi_3;
                            break;
                        }
                        case 0x20:
                        {
                            int32_t rax_70 = *(arg1 + 0x28);
                            
                            if (rax_70 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_70 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_70 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025e40;
                            *(arg1 + 0x48) += 9;
                            return rsi_3;
                            break;
                        }
                        case 0x22:
                        {
                            int32_t rax_68 = *(arg1 + 0x28);
                            
                            if (rax_68 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_68 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_68 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025ea0;
                            *(arg1 + 0x48) += 4;
                            return rsi_3;
                            break;
                        }
                        case 0x23:
                        {
                            int32_t rax_80 = *(arg1 + 0x28);
                            
                            if (rax_80 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_80 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_80 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025f00;
                            *(arg1 + 0x48) += 8;
                            return rsi_3;
                            break;
                        }
                        case 0x28:
                        {
                            int32_t rax_78 = *(arg1 + 0x28);
                            
                            if (rax_78 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_78 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_78 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025f20;
                            *(arg1 + 0x48) += 0x11;
                            return rsi_3;
                            break;
                        }
                        case 0x2a:
                        {
                            int32_t* _Str_14 = sub_140002940(arg1, 0x4d, 
                                sub_140003a30(arg1, &jump_table_140024564), 0);
                            _Str = _Str_14;
                            _Str_19 = _Str_14;
                            goto label_140003c00;
                        }
                        case 0x2d:
                        {
                            int32_t rax_66 = *(arg1 + 0x28);
                            
                            if (rax_66 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_66 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_66 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025ee0;
                            *(arg1 + 0x48) += 8;
                            return rsi_3;
                            break;
                        }
                        case 0x2f:
                        {
                            int32_t rax_64 = *(arg1 + 0x28);
                            
                            if (rax_64 >= *(arg1 + 0x2c))
                            {
                                *0x10;
                                trap(6);
                            }
                            
                            rsi_3 = *(arg1 + 0x20) + (rax_64 << 5);
                            *(rsi_3 + 4) = 0;
                            *(arg1 + 0x28) = rax_64 + 1;
                            *rsi_3 = 0x28;
                            *(rsi_3 + 0x10) = &data_140025ec0;
                            *(arg1 + 0x48) += 7;
                            return rsi_3;
                            break;
                        }
                        case 0x30:
                        {
                            int32_t* rsi_10;
                            
                            if (r8[2] == 0x5f)
                            {
                                int32_t rdi_10 = *(arg1 + 0x4c);
                                *(arg1 + 0x4c) = 1;
                                *(arg1 + 0x18) = &r8[3];
                                int32_t* rax_98 = sub_1400055b0(arg1);
                                *(arg1 + 0x4c) = rdi_10;
                                rsi_10 = rax_98;
                                
                                if (rax_98)
                                    goto label_14000407b;
                            }
                            else
                            {
                                int32_t rax_58 = *(arg1 + 0x28);
                                
                                if (rax_58 < *(arg1 + 0x2c))
                                {
                                    rsi_10 = (rax_58 << 5) + *(arg1 + 0x20);
                                    *(rsi_10 + 4) = 0;
                                    *(arg1 + 0x28) = rax_58 + 1;
                                    *rsi_10 = 0x44;
                                    rsi_10[4] = sub_140002aa0(arg1);
                                label_14000407b:
                                    char* rax_61 = *(arg1 + 0x18);
                                    
                                    if (*rax_61 == 0x5f)
                                    {
                                        *(arg1 + 0x18) = &rax_61[1];
                                        int32_t* _Str_13 =
                                            sub_140002940(arg1, 0x2e, rsi_10, sub_140003a30(arg1));
                                        _Str = _Str_13;
                                        _Str_19 = _Str_13;
                                        goto label_140003c00;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            }
            case 0x46:
            {
                int32_t* _Str_4 = sub_1400046b0(arg1);
                _Str = _Str_4;
                _Str_19 = _Str_4;
                goto label_140003c00;
            }
            case 0x47:
            {
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_5 = sub_140002940(arg1, 0x27, 
                    sub_140003a30(arg1, &jump_table_140024514, &r8[1]), 0);
                _Str = _Str_5;
                _Str_19 = _Str_5;
                goto label_140003c00;
            }
            case 0x4d:
            {
                *(arg1 + 0x18) = &r8[1];
                int64_t rax_46 = sub_140003a30(arg1, &jump_table_140024514, &r8[1]);
                
                if (rax_46)
                {
                    int64_t rax_47 = sub_140003a30(arg1);
                    
                    if (rax_47)
                    {
                        int32_t* _Str_12 = sub_140002940(arg1, 0x2c, rax_46, rax_47);
                        _Str = _Str_12;
                        _Str_19 = _Str_12;
                        goto label_140003c00;
                    }
                }
                break;
            }
            case 0x4f:
            {
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_6 = sub_140002940(arg1, 0x25, 
                    sub_140003a30(arg1, &jump_table_140024514, &r8[1]), 0);
                _Str = _Str_6;
                _Str_19 = _Str_6;
                goto label_140003c00;
            }
            case 0x50:
            {
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_7 = sub_140002940(arg1, 0x23, 
                    sub_140003a30(arg1, &jump_table_140024514, &r8[1]), 0);
                _Str = _Str_7;
                _Str_19 = _Str_7;
                goto label_140003c00;
            }
            case 0x52:
            {
                *(arg1 + 0x18) = &r8[1];
                int32_t* _Str_8 = sub_140002940(arg1, 0x24, 
                    sub_140003a30(arg1, &jump_table_140024514, &r8[1]), 0);
                _Str = _Str_8;
                _Str_19 = _Str_8;
                goto label_140003c00;
            }
            case 0x54:
            {
                int32_t* _Str_9 = sub_1400032d0(arg1);
                char* rdi_6 = *(arg1 + 0x18);
                _Str = _Str_9;
                _Str_19 = _Str_9;
                
                if (*rdi_6 != 0x49)
                    goto label_140003c00;
                
                int32_t* rax_36;
                int32_t* r9_3;
                
                if (*(arg1 + 0x50))
                {
                    int32_t r13_1 = *(arg1 + 0x28);
                    int32_t r12_5 = *(arg1 + 0x38);
                    *(arg1 + 0x18) = &rdi_6[1];
                    int32_t rbp_5 = *(arg1 + 0x48);
                    rax_36 = sub_140005310(arg1);
                    
                    if (**(arg1 + 0x18) != 0x49)
                    {
                        *(arg1 + 0x18) = rdi_6;
                        *(arg1 + 0x28) = r13_1;
                        *(arg1 + 0x38) = r12_5;
                        *(arg1 + 0x48) = rbp_5;
                        goto label_140003c00;
                    }
                    
                    if (_Str_19)
                    {
                        int32_t rdx_20 = *(arg1 + 0x38);
                        
                        if (rdx_20 < *(arg1 + 0x3c))
                        {
                            *(*(arg1 + 0x30) + (rdx_20 << 3)) = _Str_19;
                            *(arg1 + 0x38) = rdx_20 + 1;
                        label_140003e1e:
                            r9_3 = rax_36;
                        label_140003e2c:
                            int32_t* _Str_10 = sub_140002940(arg1, 4, _Str_19, r9_3);
                            _Str = _Str_10;
                            _Str_19 = _Str_10;
                            goto label_140003c00;
                        }
                    }
                }
                else if (_Str_9)
                {
                    int32_t rax_33 = *(arg1 + 0x38);
                    
                    if (rax_33 < *(arg1 + 0x3c))
                    {
                        r9_3 = nullptr;
                        *(*(arg1 + 0x30) + (rax_33 << 3)) = _Str_19;
                        *(arg1 + 0x38) = rax_33 + 1;
                        
                        if (*rdi_6 - 0x49 > 1)
                            goto label_140003e2c;
                        
                        *(arg1 + 0x18) = &rdi_6[1];
                        rax_36 = sub_140005310(arg1);
                        goto label_140003e1e;
                    }
                }
                break;
            }
        }
    }
    return nullptr;
}

void* sub_140004530(void* arg1)
{
    void* result_1;
    int64_t* rsi = &result_1;
    result_1 = nullptr;
    char* rax = *(arg1 + 0x18);
    
    for (char i = *rax; i; i = *rax)
    {
        if (i - 0x2e <= 0x24)
        {
            int64_t rdx_1 = 1 << (i - 0x2e);
            
            if (rdx_1 & 0x800800001)
                break;
            
            if (rdx_1 & 0x1200000000 && rax[1] == 0x45)
                break;
        }
        
        int32_t* rax_1 = sub_140003a30(arg1);
        
        if (!rax_1)
            return 0;
        
        int32_t* rax_2 = sub_140002940(arg1, 0x2f, rax_1, 0);
        *rsi = rax_2;
        
        if (!rax_2)
            return 0;
        
        rsi = &rax_2[6];
        rax = *(arg1 + 0x18);
    }
    
    void* result = result_1;
    
    if (!result)
        return 0;
    
    if (!*(result + 0x18))
    {
        int32_t* rdx_2 = *(result + 0x10);
        
        if (*rdx_2 == 0x28)
        {
            void* rdx_3 = *(rdx_2 + 0x10);
            
            if (*(rdx_3 + 0x1c) == 9)
            {
                *(arg1 + 0x48) -= *(rdx_3 + 8);
                *(result + 0x10) = 0;
            }
        }
    }
    
    return result;
}

int64_t sub_140004630(void* arg1, int32_t arg2)
{
    int64_t rax = *(arg1 + 0x18);
    
    if (*rax == 0x4a)
    {
        *(arg1 + 0x18) = rax + 1;
    label_140004649:
        int32_t* rax_1 = sub_140003a30(arg1);
        
        if (rax_1)
        {
            void* rax_2 = sub_140004530(arg1);
            
            if (rax_2)
                /* tailcall */
                return sub_140002940(arg1, 0x2a, rax_1, rax_2);
        }
    }
    else
    {
        if (arg2)
            goto label_140004649;
        
        void* rax_4 = sub_140004530(arg1);
        
        if (rax_4)
            /* tailcall */
            return sub_140002940(arg1, 0x2a, nullptr, rax_4);
    }
    
    return 0;
}

int64_t sub_1400046b0(void* arg1)
{
    char* rdx_1;
    
    if (*(arg1 + 0x12) & 4)
    {
        rdx_1 = *(arg1 + 0x18);
        
        if (*rdx_1 == 0x46)
        {
        label_140004704:
            *(arg1 + 0x18) = &rdx_1[1];
            
            if (rdx_1[1] == 0x59)
                *(arg1 + 0x18) = &rdx_1[2];
            
            int64_t result = sub_140002c00(arg1, sub_140004630(arg1, 1));
            char* rdx_4 = *(arg1 + 0x18);
            
            if (*rdx_4 == 0x45)
                *(arg1 + 0x18) = &rdx_4[1];
            else
                result = 0;
            
            if (*(arg1 + 0x12) & 4)
                return result;
            
            *(arg1 + 0x58) -= 1;
            return result;
        }
    }
    else
    {
        int32_t rcx = *(arg1 + 0x58);
        
        if (rcx <= 0x800)
        {
            rdx_1 = *(arg1 + 0x18);
            *(arg1 + 0x58) = rcx + 1;
            
            if (*rdx_1 == 0x46)
                goto label_140004704;
            
            *(arg1 + 0x58) = rcx;
        }
    }
    return 0;
}

int64_t sub_140004760(void* arg1, int32_t* arg2)
{
    void* rax = *(arg1 + 0x18);
    
    if (*rax == 0x54)
    {
        char rdx = *(rax + 1);
        
        if (rdx == 0x74)
        {
            *(arg1 + 0x18) = rax + 2;
            int32_t* rax_9 = sub_140004850(arg1, arg2);
            
            if (!rax_9)
                *arg2 = 1;
            else
            {
                char* rax_10 = *(arg1 + 0x18);
                
                if (*rax_10 == 0x45)
                {
                    *(arg1 + 0x18) = &rax_10[1];
                    /* tailcall */
                    return sub_140002940(arg1, 0x5c, rax_9, 0);
                }
                
                *arg2 = 1;
            }
        }
        else
        {
            if (rdx == 0x79)
            {
                *(arg1 + 0x18) = rax + 2;
                /* tailcall */
                return sub_140002940(arg1, 0x5a, nullptr, 0);
            }
            
            if (rdx == 0x6e)
            {
                *(arg1 + 0x18) = rax + 2;
                int32_t* rax_7 = sub_140003a30(arg1);
                
                if (rax_7)
                    /* tailcall */
                    return sub_140002940(arg1, 0x5b, rax_7, 0);
                
                *arg2 = 1;
            }
            else if (rdx == 0x70)
            {
                *(arg1 + 0x18) = rax + 2;
                int32_t* rax_2 = sub_140004760(arg1, arg2);
                
                if (rax_2)
                    /* tailcall */
                    return sub_140002940(arg1, 0x5d, rax_2, 0);
                
                *arg2 = 1;
            }
        }
    }
    
    return 0;
}

int64_t sub_140004850(void* arg1, int32_t* arg2)
{
    int64_t var_20 = 0;
    int64_t* rbx = &var_20;
    
    while (true)
    {
        void* rax_1 = sub_140004760(arg1, arg2);
        
        if (!rax_1)
            break;
        
        *rbx = rax_1;
        rbx = rax_1 + 0x18;
    }
    
    int64_t r8 = var_20;
    
    if (!r8)
        return 0;
    
    /* tailcall */
    return sub_140002940(arg1, 0x59, r8, 0);
}

int32_t* sub_1400048c0(void* arg1)
{
    char* rax = *(arg1 + 0x18);
    char r10 = *rax;
    char rsi;
    
    if (!r10)
    {
        rsi = 0;
    label_140004910:
        int32_t r8_1 = 0x49;
        int32_t rdx_3 = 0;
        
        do
        {
            int32_t rcx_1 = r8_1 - rdx_3;
            int32_t rax_6 = (((rcx_1 >> 0x1f) + rcx_1) >> 1) + rdx_3;
            int64_t rcx_2 = rax_6;
            char* rcx_4 = (&data_1400252c0)[rcx_2 * 3];
            char temp0_1 = *rcx_4;
            bool cond:0_1 = temp0_1 > r10;
            
            if (temp0_1 == r10)
            {
                char temp1_1 = rcx_4[1];
                cond:0_1 = temp1_1 > rsi;
                
                if (temp1_1 == rsi)
                {
                    int32_t rdx_4 = *(arg1 + 0x28);
                    
                    if (rdx_4 >= *(arg1 + 0x2c))
                        break;
                    
                    int32_t* rax_10 = (rdx_4 << 5) + *(arg1 + 0x20);
                    *(rax_10 + 4) = 0;
                    *(arg1 + 0x28) = rdx_4 + 1;
                    *rax_10 = 0x33;
                    *(rax_10 + 0x10) = &(&data_1400252c0)[rcx_2 * 3];
                    return rax_10;
                }
            }
            
            if (cond:0_1)
                r8_1 = rax_6;
            else
                rdx_3 = rax_6 + 1;
        } while (rdx_3 != r8_1);
    }
    else
    {
        *(arg1 + 0x18) = &rax[1];
        rsi = rax[1];
        r10 = *rax;
        
        if (!rsi)
            goto label_140004910;
        
        *(arg1 + 0x18) = &rax[2];
        rsi = rax[1];
        
        if (r10 != 0x76)
        {
            if (r10 != 0x63 || rsi != 0x76)
                goto label_140004910;
            
            int32_t rsi_1 = *(arg1 + 0x50);
            int32_t rax_14;
            rax_14 = !*(arg1 + 0x4c);
            *(arg1 + 0x50) = rax_14;
            int32_t* rax_15 = sub_140003a30(arg1);
            int32_t* rax_16;
            
            if (!*(arg1 + 0x50))
                rax_16 = sub_140002940(arg1, 0x35, rax_15, 0);
            else
                rax_16 = sub_140002940(arg1, 0x36, rax_15, 0);
            
            *(arg1 + 0x50) = rsi_1;
            return rax_16;
        }
        
        if (rsi - 0x30 > 9)
            goto label_140004910;
        
        int32_t* rax_11 = sub_140003640(arg1);
        int32_t rdx_6 = *(arg1 + 0x28);
        
        if (rdx_6 < *(arg1 + 0x2c))
        {
            int32_t* rax_7 = (rdx_6 << 5) + *(arg1 + 0x20);
            *(rax_7 + 4) = 0;
            *(arg1 + 0x28) = rdx_6 + 1;
            
            if (rax_11)
            {
                *(rax_7 + 4) = 0;
                *rax_7 = 0x34;
                rax_7[4] = rsi - 0x30;
                *(rax_7 + 0x18) = rax_11;
                return rax_7;
            }
        }
    }
    return nullptr;
}

int32_t* sub_140004a60(void* arg1, int64_t arg2, int32_t* arg3, int32_t* arg4 @ rsi)
{
    int32_t* var_28 = arg4;
    int32_t* arg_18 = arg3;
    int32_t rax = sub_140003990(arg1, &arg_18);
    int32_t rdi = rax;
    
    if (rax)
    {
        char* rdx_1 = *(arg1 + 0x18);
        char rax_1 = *rdx_1;
        
        if (rax_1 != 0x46)
        {
            rdi = 0;
            
            if (rax_1 - 0x30 <= 9)
                goto label_140004c50;
            
            goto label_140004ab1;
        }
        
        *(arg1 + 0x18) = &rdx_1[1];
        rax_1 = rdx_1[1];
        int32_t* r9_2;
        
        if (rax_1 - 0x30 <= 9)
        {
        label_140004c50:
            arg4 = sub_140003640(arg1);
        label_140004c53:
            r9_2 = arg_18;
            
            if (!r9_2)
                goto label_140004c73;
            
            goto label_140004c70;
        }
        
    label_140004ab1:
        
        if (rax_1 - 0x61 <= 0x19)
        {
            int32_t r12_1 = *(arg1 + 0x4c);
            
            if (rax_1 == 0x6f)
            {
                void* rax_22 = *(arg1 + 0x18);
                
                if (*(rax_22 + 1) == 0x6e)
                {
                    *(arg1 + 0x4c) = 0;
                    *(arg1 + 0x18) = rax_22 + 2;
                }
            }
            
            int32_t* rax_2 = sub_1400048c0(arg1);
            *(arg1 + 0x4c) = r12_1;
            arg4 = rax_2;
            
            if (!rax_2)
            {
            label_140004d90:
                arg4 = nullptr;
                goto label_140004c53;
            }
            
            if (*rax_2 == 0x33)
            {
                int64_t* rax_3 = *(rax_2 + 0x10);
                char* rax_4 = *rax_3;
                *(arg1 + 0x48) = *(arg1 + 0x48) + rax_3[2] + 7;
                
                if (*rax_4 == 0x6c && rax_4[1] == 0x69 && !rax_4[2])
                    arg4 = sub_140002940(arg1, 0x38, arg4, sub_140003640(arg1));
            }
            
            goto label_140004c53;
        }
        
        char* rax_24;
        
        if (rax_1 == 0x44)
        {
            rax_24 = *(arg1 + 0x18);
            
            if (rax_24[1] != 0x43)
                goto label_140004d46;
            
            int32_t* r12_5 = nullptr;
            *(arg1 + 0x18) = &rax_24[2];
            char* rax_45;
            
            do
            {
                int32_t* r11_1 = r12_5;
                int32_t* rax_47 = sub_140002940(arg1, 0x54, sub_140003640(arg1), 0);
                r12_5 = rax_47;
                
                if (r11_1)
                    *(r11_1 + 0x18) = rax_47;
                else
                    arg4 = rax_47;
                
                if (!r12_5)
                    goto label_140004d90;
                
                rax_45 = *(arg1 + 0x18);
            } while (*rax_45 != 0x45);
            
            *(arg1 + 0x18) = &rax_45[1];
            goto label_140004c53;
        }
        
        if (rax_1 - 0x43 <= 1)
        {
            rax_24 = *(arg1 + 0x18);
        label_140004d46:
            int32_t* rdx_15 = *(arg1 + 0x40);
            
            if (rdx_15)
            {
                int32_t rcx_12 = *rdx_15;
                
                if (!rcx_12 || rcx_12 == 0x18)
                    *(arg1 + 0x48) += rdx_15[6];
            }
            
            char rcx_14 = *rax_24;
            
            if (rcx_14 == 0x43)
            {
                int32_t rcx_21 = rax_24[1];
                int32_t r12_3;
                
                if (rcx_21 != 0x49)
                {
                    if (rcx_21 - 0x31 > 4)
                        goto label_140004d90;
                    
                    r12_3 = rcx_21 - 0x30;
                    *(arg1 + 0x18) = &rax_24[2];
                    goto label_140004e13;
                }
                
                *(arg1 + 0x18) = &rax_24[1];
                int32_t rdx_21 = rax_24[2];
                
                if (rdx_21 - 0x31 > 4)
                    goto label_140004d90;
                
                r12_3 = rdx_21 - 0x30;
                *(arg1 + 0x18) = &rax_24[3];
                sub_140003a30(arg1);
                rdx_15 = *(arg1 + 0x40);
            label_140004e13:
                int32_t rax_30 = *(arg1 + 0x28);
                
                if (rax_30 >= *(arg1 + 0x2c))
                    goto label_140004d90;
                
                arg4 = (rax_30 << 5) + *(arg1 + 0x20);
                *(arg4 + 4) = 0;
                *(arg1 + 0x28) = rax_30 + 1;
                
                if (!rdx_15)
                    goto label_140004d90;
                
                *(arg4 + 4) = 0;
                *arg4 = 7;
                arg4[4] = r12_3;
                *(arg4 + 0x18) = rdx_15;
                goto label_140004c53;
            }
            
            if (rcx_14 != 0x44)
                goto label_140004d90;
            
            char rcx_15 = rax_24[1] - 0x30;
            
            if (rcx_15 > 5)
                goto label_140004d90;
            
            int32_t rcx_22;
            
            switch (rcx_15)
            {
                case 0:
                {
                    rcx_22 = 1;
                    goto label_140004e65;
                }
                case 1:
                {
                    rcx_22 = 2;
                label_140004e65:
                    *(arg1 + 0x18) = &rax_24[2];
                    int32_t rax_33 = *(arg1 + 0x28);
                    
                    if (rax_33 >= *(arg1 + 0x2c))
                        goto label_140004d90;
                    
                    arg4 = (rax_33 << 5) + *(arg1 + 0x20);
                    *(arg4 + 4) = 0;
                    *(arg1 + 0x28) = rax_33 + 1;
                    
                    if (!rdx_15)
                        goto label_140004d90;
                    
                    *(arg4 + 4) = 0;
                    *arg4 = 8;
                    arg4[4] = rcx_22;
                    *(arg4 + 0x18) = rdx_15;
                    goto label_140004c53;
                }
                case 2:
                {
                    rcx_22 = 3;
                    goto label_140004e65;
                }
                case 3:
                {
                    goto label_140004d90;
                }
                case 4:
                {
                    rcx_22 = 4;
                    goto label_140004e65;
                }
                case 5:
                {
                    rcx_22 = 5;
                    goto label_140004e65;
                }
            }
        }
        else if (rax_1 == 0x4c)
        {
            *(arg1 + 0x18) += 1;
            int32_t* rax_19 = sub_140003640(arg1);
            arg4 = rax_19;
            
            if (rax_19 && sub_140002c60(arg1))
                goto label_140004c53;
        }
        else if (rax_1 == 0x55)
        {
            char* rax_7 = *(arg1 + 0x18);
            char rdx_7 = rax_7[1];
            
            if (rdx_7 == 0x6c)
            {
                if (*rax_7 != 0x55)
                    goto label_140004d90;
                
                *(arg1 + 0x18) = &rax_7[1];
                
                if (rax_7[1] != 0x6c)
                    goto label_140004d90;
                
                int32_t var_3c = 0;
                *(arg1 + 0x18) = &rax_7[2];
                void* rax_36 = sub_140004850(arg1, &var_3c);
                int32_t r13_1 = var_3c;
                void* r12_4 = rax_36;
                
                if (r13_1)
                    goto label_140004d90;
                
                void* rax_37 = sub_140004530(arg1);
                
                if (!rax_37)
                    goto label_140004d90;
                
                if (!r12_4)
                    r12_4 = rax_37;
                else
                    *(r12_4 + 0x18) = rax_37;
                
                char* rdx_18 = *(arg1 + 0x18);
                
                if (*rdx_18 != 0x45)
                    goto label_140004d90;
                
                void* rax_38 = &rdx_18[1];
                *(arg1 + 0x18) = rax_38;
                char rdx_19 = rdx_18[1];
                
                if (rdx_19 == 0x5f)
                {
                label_140004f84:
                    *(arg1 + 0x18) = rax_38 + 1;
                    int32_t rax_42 = *(arg1 + 0x28);
                    
                    if (rax_42 >= *(arg1 + 0x2c))
                        goto label_140004d90;
                    
                    arg4 = (rax_42 << 5) + *(arg1 + 0x20);
                    *(arg4 + 4) = 0;
                    *(arg1 + 0x28) = rax_42 + 1;
                    *arg4 = 0x48;
                    *(arg4 + 0x10) = r12_4;
                    arg4[6] = r13_1;
                    goto label_140004c53;
                }
                
                if (rdx_19 == 0x6e)
                    goto label_140004d90;
                
                int32_t rax_39 = sub_140002aa0(arg1);
                r13_1 = rax_39 + 1;
                
                if (rax_39 + 1 < 0)
                    goto label_140004d90;
                
                rax_38 = *(arg1 + 0x18);
                
                if (*rax_38 != 0x5f)
                    goto label_140004d90;
                
                goto label_140004f84;
            }
            
            if (rdx_7 == 0x74)
            {
                if (*rax_7 != 0x55)
                    goto label_140004d90;
                
                arg4 = arg_18;
                *(arg1 + 0x18) = &rax_7[1];
                
                if (rax_7[1] != 0x74)
                    goto label_140004d90;
                
                void* rdx_9 = &rax_7[2];
                *(arg1 + 0x18) = rdx_9;
                char rax_8 = rax_7[2];
                int32_t rax_10;
                
                if (rax_8 == 0x5f)
                {
                    rax_10 = 0;
                label_140004bdf:
                    *(arg1 + 0x18) = rdx_9 + 1;
                    int32_t rdx_11 = *(arg1 + 0x28);
                    
                    if (rdx_11 >= *(arg1 + 0x2c))
                        goto label_140004d90;
                    
                    arg4 = (rdx_11 << 5) + *(arg1 + 0x20);
                    *(arg4 + 4) = 0;
                    *(arg1 + 0x28) = rdx_11 + 1;
                    arg4[4] = rax_10;
                    int32_t rax_11 = *(arg1 + 0x38);
                    *arg4 = 0x4a;
                    
                    if (rax_11 >= *(arg1 + 0x3c))
                        goto label_140004d90;
                    
                    *(*(arg1 + 0x30) + (rax_11 << 3)) = arg4;
                    *(arg1 + 0x38) = rax_11 + 1;
                    goto label_140004c53;
                }
                
                if (rax_8 != 0x6e)
                {
                    int32_t rax_9 = sub_140002aa0(arg1);
                    rax_10 = rax_9 + 1;
                    
                    if (rax_9 + 1 < 0)
                        goto label_140004d90;
                    
                    rdx_9 = *(arg1 + 0x18);
                    
                    if (*rdx_9 != 0x5f)
                        goto label_140004d90;
                    
                    goto label_140004bdf;
                }
                
                if (arg4)
                {
                    r9_2 = arg4;
                    arg4 = nullptr;
                label_140004c70:
                    arg4 = sub_140002940(arg1, 0x57, arg4, r9_2);
                label_140004c73:
                    char* rax_28 = *(arg1 + 0x18);
                    
                    if (*rax_28 == 0x42)
                    {
                        int64_t r12_2 = *(arg1 + 0x40);
                        
                        do
                        {
                            *(arg1 + 0x18) = &rax_28[1];
                            arg4 = sub_140002940(arg1, 0x4e, arg4, sub_140003640(arg1));
                            rax_28 = *(arg1 + 0x18);
                        } while (*rax_28 == 0x42);
                        
                        *(arg1 + 0x40) = r12_2;
                    }
                }
                
                if (rdi)
                    arg4 = sub_140002940(arg1, 0x51, arg4, 0);
                
                if (!arg2)
                    return arg4;
                
                return sub_140002940(arg1, 1, arg2, arg4);
            }
        }
    }
    
    return 0;
}

int32_t* sub_140005090(void* arg1)
{
    void* rdx = *(arg1 + 0x18);
    
    if (*rdx == 0x4c)
    {
        void* rax_1 = rdx + 1;
        *(arg1 + 0x18) = rax_1;
        char rcx = *(rdx + 1);
        char rdx_3;
        int32_t* rsi_2;
        
        if (rcx == 0x5f)
        {
        label_140005220:
            rax_1 = rdx + 2;
            rsi_2 = nullptr;
            *(arg1 + 0x18) = rax_1;
            rdx_3 = *(rdx + 2);
            
            if (rdx_3 == 0x5a)
            {
            label_14000513d:
                *(arg1 + 0x18) = rax_1 + 1;
                char rax_4 = *(rax_1 + 1);
                
                if (rax_4 == 0x47 || rax_4 == 0x54)
                {
                    rsi_2 = sub_140006060(arg1);
                    rax_1 = *(arg1 + 0x18);
                    rdx_3 = *rax_1;
                }
                else
                {
                    rsi_2 = sub_140006b30(arg1, 0);
                    rax_1 = *(arg1 + 0x18);
                    rdx_3 = *rax_1;
                }
                
                goto label_140005169;
            }
            
        label_140005169:
            
            if (rdx_3 == 0x45)
            {
                *(arg1 + 0x18) = rax_1 + 1;
                return rsi_2;
            }
        }
        else
        {
            if (rcx == 0x5a)
            {
                if (rcx == 0x5f)
                    goto label_140005220;
                
                goto label_14000513d;
            }
            
            int32_t* rax_2 = sub_140003a30(arg1);
            
            if (rax_2)
            {
                char* rdi_1 = *(arg1 + 0x18);
                char i;
                int32_t r10_1;
                
                if (*rax_2 == 0x28)
                {
                    int64_t* rax_8 = *(rax_2 + 0x10);
                    
                    if (*(rax_8 + 0x1c))
                        *(arg1 + 0x48) -= rax_8[1];
                    
                    int32_t rax_9 = strcmp(*rax_8, "decltype(nullptr)");
                    i = *rdi_1;
                    
                    if (rax_9)
                        goto label_1400050dd;
                    
                    if (i == 0x45)
                    {
                        *(arg1 + 0x18) = &rdi_1[1];
                        return rax_2;
                    }
                    
                    r10_1 = 0x3e;
                    
                    if (i != 0x6e)
                        goto label_1400050f5;
                    
                    goto label_1400051d4;
                }
                
                i = *rdi_1;
            label_1400050dd:
                r10_1 = 0x3e;
                
                if (i == 0x6e)
                {
                label_1400051d4:
                    r10_1 = 0x3f;
                    *(arg1 + 0x18) = &rdi_1[1];
                    i = rdi_1[1];
                    rdi_1 = &rdi_1[1];
                }
                
                int32_t r8_2;
                
                if (i == 0x45)
                    r8_2 = 0;
                else
                {
                label_1400050f5:
                    void* rdx_1 = &rdi_1[1];
                    int32_t r8_1;
                    
                    do
                    {
                        if (!i)
                            return nullptr;
                        
                        *(arg1 + 0x18) = rdx_1;
                        r8_1 = rdx_1;
                        i = *rdx_1;
                        rdx_1 += 1;
                    } while (i != 0x45);
                    
                    r8_2 = r8_1 - rdi_1;
                }
                
                rsi_2 = sub_140002940(arg1, r10_1, rax_2, sub_140002a40(arg1, rdi_1, r8_2));
                rax_1 = *(arg1 + 0x18);
                rdx_3 = *rax_1;
                goto label_140005169;
            }
        }
    }
    
    return nullptr;
}

int32_t* sub_140005270(void* arg1)
{
    char* rax = *(arg1 + 0x18);
    char rdx = *rax;
    
    if (rdx == 0x4c)
        /* tailcall */
        return sub_140005090(arg1);
    
    if (rdx > 0x4c)
    {
        if (rdx == 0x58)
        {
            int32_t rsi = *(arg1 + 0x4c);
            *(arg1 + 0x4c) = 1;
            *(arg1 + 0x18) = &rax[1];
            int32_t* result = sub_1400055b0(arg1);
            char* rdx_3 = *(arg1 + 0x18);
            *(arg1 + 0x4c) = rsi;
            
            if (*rdx_3 != 0x45)
                return nullptr;
            
            *(arg1 + 0x18) = &rdx_3[1];
            return result;
        }
    }
    else if (rdx - 0x49 <= 1)
    {
        *(arg1 + 0x18) = &rax[1];
        /* tailcall */
        return sub_140005310(arg1);
    }
    
    /* tailcall */
    return sub_140003a30(arg1);
}

int32_t* sub_140005310(void* arg1)
{
    int64_t rax = *(arg1 + 0x18);
    int64_t rdi = *(arg1 + 0x40);
    
    if (*rax == 0x45)
    {
        *(arg1 + 0x18) = rax + 1;
        /* tailcall */
        return sub_140002940(arg1, 0x30, 0, 0);
    }
    
    int32_t* result_1 = nullptr;
    int64_t* rsi = &result_1;
    
    while (true)
    {
        int32_t* rax_3 = sub_140005270(arg1);
        
        if (!rax_3)
            break;
        
        int32_t* rax_1 = sub_140002940(arg1, 0x30, rax_3, 0);
        *rsi = rax_1;
        
        if (!rax_1)
            break;
        
        char* rdx_1 = *(arg1 + 0x18);
        rsi = &rax_1[6];
        char rax_2 = *rdx_1;
        
        if (rax_2 != 0x45 && rax_2 != 0x51)
            continue;
        
        int32_t* result = result_1;
        char rax_9;
        
        if (rax_2 == 0x51)
        {
            int32_t rbp_1 = *(arg1 + 0x4c);
            *(arg1 + 0x4c) = 1;
            *(arg1 + 0x18) = &rdx_1[1];
            int32_t* rax_8 = sub_1400055b0(arg1);
            *(arg1 + 0x4c) = rbp_1;
            
            if (!rax_8)
            {
                rdx_1 = *(arg1 + 0x18);
                result = nullptr;
                rax_9 = *rdx_1;
            }
            else
            {
                int32_t* result_2 = sub_140002940(arg1, 0x5e, result, rax_8);
                rdx_1 = *(arg1 + 0x18);
                result = result_2;
                rax_9 = *rdx_1;
            }
        }
        
        if (rax_2 == 0x51 && rax_9 != 0x45)
            break;
        
        *(arg1 + 0x40) = rdi;
        *(arg1 + 0x18) = &rdx_1[1];
        return result;
    }
    
    return 0;
}

int32_t* sub_140005430(void* arg1, int32_t arg2)
{
    int32_t* result = nullptr;
label_14000543e:
    char* rcx = *(arg1 + 0x18);
    char rdx = *rcx;
    
    if (rdx != 0x44)
    {
        if (rdx != 0x49)
            goto label_140005457;
        
        if (result)
        {
        label_1400054a3:
            *(arg1 + 0x18) = &rcx[1];
            int32_t* rax_2 = sub_140005310(arg1);
            
            if (rax_2)
            {
                result = sub_140002940(arg1, 4, result, rax_2);
                goto label_140005470;
            }
        }
        
        return nullptr;
    }
    
    while (true)
    {
        int32_t* result_1;
        
        if ((rcx[1] & 0xdf) == 0x54)
        {
            if (result)
                return nullptr;
            
            result = sub_140003a30(arg1);
        label_140005470:
            
            if (!result)
                return nullptr;
            
            rcx = *(arg1 + 0x18);
            
            if (*rcx == 0x45)
                return result;
            
            if (arg2)
            {
                int32_t rax_9 = *(arg1 + 0x38);
                
                if (rax_9 >= *(arg1 + 0x3c))
                    return nullptr;
                
                *(*(arg1 + 0x30) + (rax_9 << 3)) = result;
                *(arg1 + 0x38) = rax_9 + 1;
            }
            
            rdx = *rcx;
            
            if (rdx == 0x44)
                continue;
            else
            {
            label_14000549a:
                
                if (rdx == 0x49)
                    break;
                
            label_140005457:
                
                if (rdx == 0x54)
                {
                    if (result)
                        return nullptr;
                    
                    result = sub_1400032d0(arg1);
                    goto label_140005470;
                }
                
                if (rdx == 0x4d)
                {
                    *(arg1 + 0x18) = &rcx[1];
                    goto label_14000543e;
                }
                
                if (rdx == 0x53)
                {
                    int32_t* result_2 = sub_140003740(arg1, 1);
                    result_1 = result_2;
                    
                    if (!result_2)
                        return nullptr;
                    
                    if (*result_2 - 0x55 <= 1)
                    {
                    label_14000558e:
                        result = sub_140004a60(arg1, result, result_1, result);
                        goto label_140005470;
                    }
                    
                    if (result)
                        return nullptr;
                    
                    rcx = *(arg1 + 0x18);
                    result = result_1;
                    rdx = *rcx;
                    
                    if (rdx != 0x44)
                        goto label_14000549a;
                    
                    continue;
                }
            }
        }
        
        result_1 = nullptr;
        goto label_14000558e;
    }
    
    goto label_1400054a3;
}

int32_t* sub_1400055b0(void* arg1)
{
    int32_t* rsi;
    int32_t* var_18 = rsi;
    char* rdx = *(arg1 + 0x18);
    char rax = *rdx;
    
    if (rax == 0x4c)
        /* tailcall */
        return sub_140005090(arg1);
    
    if (rax == 0x54)
        /* tailcall */
        return sub_1400032d0(arg1);
    
    char* rax_1;
    int32_t* result;
    
    if (rax == 0x73)
    {
        char rax_3 = rdx[1];
        
        if (rax_3 == 0x72)
        {
            *(arg1 + 0x18) = &rdx[2];
            int32_t* rdx_8;
            
            if (!*(arg1 + 0x54))
                rdx_8 = sub_140003a30(arg1);
            else
            {
                uint32_t rax_20 = rdx[2];
                
                if (rax_20 > 0x39)
                {
                    uint64_t rax_21 = rax_20 - 0x43;
                    
                    if (rax_21 <= 0x37 && TEST_BITQ(0xffffffc0040201, rax_21))
                        goto label_14000581e;
                    
                    rdx_8 = sub_140003a30(arg1);
                }
                else if (rax_20 > 0x2f)
                {
                label_14000581e:
                    *(arg1 + 0x54) = 0xffffffff;
                    rdx_8 = sub_140005430(arg1, 0);
                    char* rax_23 = *(arg1 + 0x18);
                    
                    if (*rax_23 == 0x45)
                        *(arg1 + 0x18) = &rax_23[1];
                }
                else
                    rdx_8 = sub_140003a30(arg1);
            }
            
            result = sub_140004a60(arg1, rdx_8, nullptr, rsi);
            rax_1 = *(arg1 + 0x18);
            
            if (*rax_1 != 0x49)
                return result;
            
        label_140005877:
            *(arg1 + 0x18) = &rax_1[1];
            /* tailcall */
            return sub_140002940(arg1, 4, result, sub_140005310(arg1));
        }
        
        if (rax_3 == 0x70)
        {
            *(arg1 + 0x18) = &rdx[2];
            /* tailcall */
            return sub_140002940(arg1, 0x4d, sub_1400055b0(), nullptr);
        }
        
    label_140005647:
        int32_t* rax_4 = sub_1400048c0(arg1);
        
        if (rax_4)
        {
            int32_t rax_5 = *rax_4;
            int32_t* r9_1;
            
            if (rax_5 == 0x33)
            {
                int64_t* rdx_7 = *(rax_4 + 0x10);
                char* rdi_1 = *rdx_7;
                *(arg1 + 0x48) += rdx_7[2] - 2;
                uint32_t rax_16 = *rdi_1;
                
                if (rax_16 == 0x73 && rdi_1[1] == 0x74 && !rdi_1[2])
                    /* tailcall */
                    return sub_140002940(arg1, 0x38, rax_4, sub_140003a30(arg1));
                
                int32_t rbp_1 = *(rdx_7 + 0x14);
                
                if (rbp_1 == 2)
                {
                    char rdx_13 = *rdi_1;
                    int32_t* rbp_2;
                    
                    if (rdi_1[1] == 0x63 && (rdx_13 - 0x72 <= 1 || rdx_13 - 0x63 <= 1))
                        rbp_2 = sub_140003a30(arg1);
                    else if (rdx_13 == 0x66)
                        rbp_2 = sub_1400048c0(arg1);
                    else if (rax_16 != 0x64 || rdi_1[1] != 0x69 || rdi_1[2])
                        rbp_2 = sub_1400055b0(arg1);
                    else
                        rbp_2 = sub_140004a60(arg1, 0, nullptr, rax_4);
                    
                    uint32_t rax_37 = *rdi_1;
                    int32_t* rdi_2;
                    
                    if (rax_37 == 0x63 && rdi_1[1] == 0x6c && !rdi_1[2])
                        rdi_2 = sub_140005fb0(arg1, 0x45);
                    else if (rax_37 == 0x64 && rdi_1[1] == 0x74)
                    {
                        if (!rdi_1[2] || (rax_37 == 0x70 && rdi_1[1] == 0x74 && !rdi_1[2]))
                            goto label_140005c5d;
                        
                        rdi_2 = sub_1400055b0(arg1);
                    }
                    else if (rax_37 != 0x70 || rdi_1[1] != 0x74 || rdi_1[2])
                        rdi_2 = sub_1400055b0(arg1);
                    else
                    {
                    label_140005c5d:
                        char* rax_57 = *(arg1 + 0x18);
                        char rdx_18 = *rax_57;
                        
                        if (rdx_18 != 0x67)
                        {
                            if (rdx_18 != 0x73 || rax_57[1] != 0x72)
                                goto label_140005c89;
                            
                            rdi_2 = sub_1400055b0(arg1);
                        }
                        else if (rax_57[1] != 0x73)
                        {
                        label_140005c89:
                            rdi_2 = sub_140004a60(arg1, 0, nullptr, rax_4);
                            char* rax_59 = *(arg1 + 0x18);
                            
                            if (*rax_59 == 0x49)
                            {
                                *(arg1 + 0x18) = &rax_59[1];
                                rdi_2 = sub_140002940(arg1, 4, rdi_2, sub_140005310(arg1));
                            }
                        }
                        else
                            rdi_2 = sub_1400055b0(arg1);
                    }
                    
                    /* tailcall */
                    return sub_140002940(arg1, 0x39, rax_4, 
                        sub_140002940(arg1, 0x3a, rbp_2, rdi_2));
                }
                
                if (!rbp_1)
                    goto label_14000599d;
                
                if (rbp_1 == 1)
                {
                    uint64_t rdx_9 = *rdi_1;
                    
                    if (rdx_9 == 0x6d)
                    {
                        if (rdi_1[1] == rdx_9)
                            goto label_140005a89;
                        
                        rbp_1 = 0;
                    }
                    else if (rdx_9 == 0x70 && rdi_1[1] == rdx_9)
                    {
                    label_140005a89:
                        rdx_9 = *(arg1 + 0x18);
                        
                        if (*rdx_9 == 0x5f)
                        {
                            rdx_9 += 1;
                            *(arg1 + 0x18) = rdx_9;
                            rax_16 = *rdi_1;
                            rbp_1 = 0;
                        }
                    }
                    else
                        rbp_1 = 0;
                    
                    if (rax_16 != 0x73 || rdi_1[1] != 0x50 || rdi_1[2])
                        r9_1 = sub_1400055b0(arg1, rdx_9);
                    else
                        r9_1 = sub_140005310(arg1);
                    
                    if (rbp_1)
                        r9_1 = sub_140002940(arg1, 0x3a, r9_1, r9_1);
                    
                    goto label_14000568d;
                }
                
                if (rbp_1 == 3)
                {
                    if (rax_16 == 0x71 && rdi_1[1] == 0x75)
                    {
                        if (rdi_1[2] && (rax_16 != 0x64 || rdi_1[1] != 0x58 || rdi_1[2]))
                            goto label_140005bbd;
                        
                        goto label_140005b2d;
                    }
                    
                    int32_t* rax_45;
                    int32_t* rbp_3;
                    int32_t* rdi_3;
                    int64_t r9_5;
                    
                    if (rax_16 != 0x64 || rdi_1[1] != 0x58 || rdi_1[2])
                    {
                    label_140005bbd:
                        char rax_51 = *rdi_1;
                        
                        if (rax_51 == 0x66)
                        {
                            rax_45 = sub_1400048c0(arg1);
                            goto label_140005b35;
                        }
                        
                        if (rax_51 == 0x6e)
                        {
                            char rax_52 = rdi_1[1];
                            
                            if (rax_52 == 0x77 || rax_52 == 0x61)
                            {
                                rdi_3 = sub_140005fb0(arg1, 0x5f);
                                rbp_3 = sub_140003a30(arg1);
                                char* rax_55 = *(arg1 + 0x18);
                                char rdx_17 = *rax_55;
                                
                                if (rdx_17 == 0x45)
                                {
                                    r9_5 = 0;
                                    *(arg1 + 0x18) = &rax_55[1];
                                label_140005b77:
                                    /* tailcall */
                                    return sub_140002940(arg1, 0x3b, rax_4, 
                                        sub_140002940(arg1, 0x3c, rdi_3, 
                                            sub_140002940(arg1, 0x3d, rbp_3, r9_5)));
                                }
                                
                                if (rdx_17 == 0x70)
                                {
                                    if (rax_55[1] == 0x69)
                                    {
                                        *(arg1 + 0x18) = &rax_55[2];
                                        r9_5 = sub_140005fb0(arg1, 0x45);
                                        goto label_140005b77;
                                    }
                                }
                                else if (rdx_17 == 0x69 && rax_55[1] == 0x6c)
                                {
                                    r9_5 = sub_1400055b0(arg1);
                                    goto label_140005b77;
                                }
                            }
                        }
                    }
                    else
                    {
                    label_140005b2d:
                        rax_45 = sub_1400055b0(arg1);
                    label_140005b35:
                        rdi_3 = rax_45;
                        rbp_3 = sub_1400055b0(arg1);
                        int64_t rax_47 = sub_1400055b0(arg1);
                        r9_5 = rax_47;
                        
                        if (rax_47)
                            goto label_140005b77;
                    }
                }
            }
            else if (rax_5 == 0x34)
            {
                int32_t rax_35 = rax_4[4];
                
                if (rax_35 == 1)
                {
                label_14000568a:
                    r9_1 = sub_1400055b0(arg1);
                label_14000568d:
                    /* tailcall */
                    return sub_140002940(arg1, 0x38, rax_4, r9_1);
                }
                
                if (rax_35 != 3 && !rax_35)
                {
                label_14000599d:
                    /* tailcall */
                    return sub_140002940(arg1, 0x37, rax_4, nullptr);
                }
            }
            else if (rax_5 == 0x35)
            {
                char* rax_6 = *(arg1 + 0x18);
                
                if (*rax_6 != 0x5f)
                    goto label_14000568a;
                
                *(arg1 + 0x18) = &rax_6[1];
                r9_1 = sub_140005fb0(arg1, 0x45);
                goto label_14000568d;
            }
        }
    }
    else if (rax == 0x66)
    {
        if (rdx[1] != 0x70)
            goto label_140005647;
        
        *(arg1 + 0x18) = &rdx[2];
        char rax_9 = rdx[2];
        int32_t rdx_5;
        
        if (rax_9 == 0x54)
        {
            *(arg1 + 0x18) = &rdx[3];
            rdx_5 = 0;
        label_1400056fe:
            int32_t rax_11 = *(arg1 + 0x28);
            
            if (rax_11 < *(arg1 + 0x2c))
            {
                result = (rax_11 << 5) + *(arg1 + 0x20);
                *(result + 4) = 0;
                *(arg1 + 0x28) = rax_11 + 1;
                *result = 6;
                result[4] = rdx_5;
                return result;
            }
        }
        else
        {
            if (rax_9 == 0x5f)
            {
                *(arg1 + 0x18) = &rdx[3];
                rdx_5 = 1;
                goto label_1400056fe;
            }
            
            if (rax_9 != 0x6e)
            {
                int32_t rax_10 = sub_140002aa0(arg1);
                
                if (rax_10 + 1 >= 0)
                {
                    char* rdx_3 = *(arg1 + 0x18);
                    
                    if (*rdx_3 == 0x5f)
                    {
                        *(arg1 + 0x18) = &rdx_3[1];
                        
                        if (rax_10 != 0x7ffffffe)
                        {
                            rdx_5 = rax_10 + 2;
                            goto label_1400056fe;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (rax - 0x30 <= 9)
            goto label_140005604;
        
        if (rax != 0x6f)
        {
            if (rax != 0x69 && rax != 0x74)
            {
                if (rax != 0x75)
                    goto label_140005647;
                
                *(arg1 + 0x18) = &rdx[1];
                /* tailcall */
                return sub_140002940(arg1, 0x40, sub_140003640(arg1), sub_140005310(arg1));
            }
            
            if (rdx[1] != 0x6c)
                goto label_140005647;
            
            void* rdx_6 = &rdx[2];
            int32_t* rsi_5 = nullptr;
            *(arg1 + 0x18) = rdx_6;
            
            if (rax == 0x74)
            {
                int32_t* rax_50 = sub_140003a30(arg1);
                rdx_6 = *(arg1 + 0x18);
                rsi_5 = rax_50;
            }
            
            if (*rdx_6 && *(rdx_6 + 1))
                /* tailcall */
                return sub_140002940(arg1, 0x32, rsi_5, sub_140005fb0(arg1, 0x45));
        }
        else
        {
            if (rdx[1] != 0x6e)
                goto label_140005647;
            
            *(arg1 + 0x18) = &rdx[2];
        label_140005604:
            int32_t* result_1 = sub_140004a60(arg1, 0, nullptr, rsi);
            result = result_1;
            
            if (result_1)
            {
                rax_1 = *(arg1 + 0x18);
                
                if (*rax_1 == 0x49)
                    goto label_140005877;
                
                return result;
            }
        }
    }
    return nullptr;
}

void* sub_140005d80(void* arg1, void* arg2, int32_t arg3, int64_t arg4 @ rbp, int64_t arg5 @ rdi, int64_t arg6 @ r12)
{
    int64_t var_20 = arg6;
    int64_t var_28 = arg4;
    int64_t var_30 = arg5;
    char* rcx = *(arg1 + 0x18);
    void* i = arg2;
    void* result = arg2;
    char rax_1 = arg3 & 1;
    char r8 = *rcx;
    
    while (sub_140002fd0(rcx))
    {
        *(arg1 + 0x18) = &rcx[1];
        int32_t rdx_2;
        int32_t* r9_1;
        
        if (r8 == 0x72)
        {
            *(arg1 + 0x48) += 9;
            rdx_2 = ((arg5 - arg5) & 0xfffffffd) + 0x1c;
            r9_1 = nullptr;
        }
        else if (r8 == 0x56)
        {
            *(arg1 + 0x48) += 9;
            rdx_2 = ((arg4 - arg4) & 0xfffffffd) + 0x1d;
            r9_1 = nullptr;
        }
        else if (r8 == 0x4b)
        {
            *(arg1 + 0x48) += 6;
            rdx_2 = ((arg6 - arg6) & 0xfffffffd) + 0x1e;
            r9_1 = nullptr;
        }
        else
        {
            if (!rcx[1])
                return nullptr;
            
            *(arg1 + 0x18) = &rcx[2];
            char rax_3 = rcx[1];
            
            if (rax_3 == 0x78)
            {
                *(arg1 + 0x48) += 0x11;
                r9_1 = nullptr;
                rdx_2 = 0x4f;
            }
            else if ((rax_3 & 0xdf) != 0x4f)
            {
                if (rax_3 != 0x77)
                    return nullptr;
                
                *(arg1 + 0x48) += 6;
                int32_t* rax_12 = sub_140004530(arg1);
                r9_1 = rax_12;
                
                if (!rax_12)
                    return nullptr;
                
                char* rax_13 = *(arg1 + 0x18);
                
                if (*rax_13 != 0x45)
                    return nullptr;
                
                rdx_2 = 0x53;
                *(arg1 + 0x18) = &rax_13[1];
            }
            else
            {
                *(arg1 + 0x48) += 9;
                r9_1 = nullptr;
                rdx_2 = 0x52;
                
                if (rax_3 == 0x4f)
                {
                    int32_t r15_1 = *(arg1 + 0x4c);
                    *(arg1 + 0x4c) = 1;
                    int32_t* rax_7 = sub_1400055b0(arg1);
                    *(arg1 + 0x4c) = r15_1;
                    r9_1 = rax_7;
                    
                    if (!rax_7)
                        return nullptr;
                    
                    char* rax_9 = *(arg1 + 0x18);
                    
                    if (*rax_9 != 0x45)
                        return nullptr;
                    
                    rdx_2 = 0x52;
                    *(arg1 + 0x18) = &rax_9[1];
                }
            }
        }
        
        int32_t* rax_4 = sub_140002940(arg1, rdx_2, 0, r9_1);
        *result = rax_4;
        
        if (!rax_4)
            return nullptr;
        
        rcx = *(arg1 + 0x18);
        result = &rax_4[4];
        r8 = *rcx;
    }
    
    int32_t* rsi;
    
    if (!(arg3 & 1) && r8 == 0x46)
    {
        for (; result != i; i = &rsi[4])
        {
            rsi = *i;
            int32_t rax_11 = *rsi;
            
            if (rax_11 == 0x1a)
                *rsi = 0x1d;
            else if (rax_11 == 0x1b)
                *rsi = 0x1e;
            else if (rax_11 == 0x19)
                *rsi = 0x1c;
        }
    }
    return result;
}

int64_t sub_140005fb0(void* arg1, char arg2)
{
    char* rax = *(arg1 + 0x18);
    int64_t result = 0;
    int64_t* rsi = &result;
    
    if (*rax == arg2)
    {
        *(arg1 + 0x18) = &rax[1];
        /* tailcall */
        return sub_140002940(arg1, 0x2f, 0, 0);
    }
    
    char* rax_2;
    
    do
    {
        int32_t rdi_1 = *(arg1 + 0x4c);
        *(arg1 + 0x4c) = 1;
        int32_t* rax_3 = sub_1400055b0(arg1);
        *(arg1 + 0x4c) = rdi_1;
        int32_t* rax_1;
        
        if (rax_3)
        {
            rax_1 = sub_140002940(arg1, 0x2f, rax_3, 0);
            *rsi = rax_1;
        }
        
        if (!rax_3 || !rax_1)
            return 0;
        
        rsi = &rax_1[6];
        rax_2 = *(arg1 + 0x18);
    } while (*rax_2 != arg2);
    
    *(arg1 + 0x18) = &rax_2[1];
    return result;
}

int64_t sub_140006060(void* arg1)
{
    int32_t rcx = *(arg1 + 0x48);
    *(arg1 + 0x48) = rcx + 0x14;
    char* rax_1 = *(arg1 + 0x18);
    char rdx = *rax_1;
    int32_t* r8_1;
    
    if (rdx == 0x54)
    {
        *(arg1 + 0x18) = &rax_1[1];
        
        if (!rax_1[1])
            return 0;
        
        *(arg1 + 0x18) = &rax_1[2];
        char rax_3 = rax_1[1] - 0x41;
        
        if (rax_3 > 0x35)
            return 0;
        
        switch (rax_3)
        {
            case 0:
            {
                /* tailcall */
                return sub_140002940(arg1, 0x31, sub_140005270(arg1), nullptr);
            }
            case 1:
            case 3:
            case 4:
            case 6:
            case 0xa:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x10:
            case 0x11:
            case 0x14:
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1a:
            case 0x1b:
            case 0x1c:
            case 0x1d:
            case 0x1e:
            case 0x1f:
            case 0x20:
            case 0x21:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
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
            {
                return 0;
                break;
            }
            case 2:
            {
                int32_t* rax_50 = sub_140003a30(arg1);
                
                if (sub_140002aa0(arg1) < 0)
                    return 0;
                
                char* rax_52 = *(arg1 + 0x18);
                
                if (*rax_52 != 0x5f)
                    return 0;
                
                *(arg1 + 0x18) = &rax_52[1];
                int32_t* rax_54 = sub_140003a30(arg1);
                *(arg1 + 0x48) += 5;
                /* tailcall */
                return sub_140002940(arg1, 0xb, rax_54, rax_50);
            }
            case 5:
            {
                /* tailcall */
                return sub_140002940(arg1, 0xe, sub_140003a30(arg1), nullptr);
            }
            case 7:
            {
                /* tailcall */
                return sub_140002940(arg1, 0x14, sub_140006690(arg1, 0), nullptr);
            }
            case 8:
            {
                /* tailcall */
                return sub_140002940(arg1, 0xc, sub_140003a30(arg1), nullptr);
            }
            case 9:
            {
                /* tailcall */
                return sub_140002940(arg1, 0x12, sub_140003a30(arg1), nullptr);
            }
            case 0x12:
            {
                /* tailcall */
                return sub_140002940(arg1, 0xd, sub_140003a30(arg1), nullptr);
            }
            case 0x13:
            {
                *(arg1 + 0x48) = rcx + 0xa;
                /* tailcall */
                return sub_140002940(arg1, 0xa, sub_140003a30(arg1), nullptr);
            }
            case 0x15:
            {
                *(arg1 + 0x48) = rcx + 0xf;
                /* tailcall */
                return sub_140002940(arg1, 9, sub_140003a30(arg1), nullptr);
            }
            case 0x16:
            {
                /* tailcall */
                return sub_140002940(arg1, 0x15, sub_140006690(arg1, 0), nullptr);
            }
            case 0x22:
            {
                if (!sub_140002b80(arg1, 0))
                    return 0;
                
                if (!sub_140002b80(arg1, 0))
                    return 0;
                
                char rax_44 = **(arg1 + 0x18);
                
                if (rax_44 == 0x47 || rax_44 == 0x54)
                    r8_1 = sub_140006060(arg1);
                else
                    r8_1 = sub_140006b30(arg1, 0);
                
                /* tailcall */
                return sub_140002940(arg1, 0x11, r8_1, nullptr);
            }
            case 0x27:
            {
                if (!sub_140002b80(arg1, 0x68))
                    return 0;
                
                char rax_36 = **(arg1 + 0x18);
                
                if (rax_36 == 0x47 || rax_36 == 0x54)
                    r8_1 = sub_140006060(arg1);
                else
                    r8_1 = sub_140006b30(arg1, 0);
                
                /* tailcall */
                return sub_140002940(arg1, 0xf, r8_1, nullptr);
            }
            case 0x35:
            {
                if (!sub_140002b80(arg1, 0x76))
                    return 0;
                
                char rax_32 = **(arg1 + 0x18);
                
                if (rax_32 == 0x47 || rax_32 == 0x54)
                    r8_1 = sub_140006060(arg1);
                else
                    r8_1 = sub_140006b30(arg1, 0);
                
                /* tailcall */
                return sub_140002940(arg1, 0x10, r8_1, nullptr);
            }
        }
        
        return;
    }
    
    if (rdx != 0x47)
        return 0;
    
    *(arg1 + 0x18) = &rax_1[1];
    
    if (!rax_1[1])
        return 0;
    
    *(arg1 + 0x18) = &rax_1[2];
    char rdx_3 = rax_1[1];
    
    if (rdx_3 > 0x56)
    {
        if (rdx_3 != 0x72)
            return 0;
        
        int32_t rax_19 = sub_140002aa0(arg1);
        
        if (rax_19 <= 1)
            return 0;
        
        char* rdx_13 = *(arg1 + 0x18);
        
        if (!*rdx_13)
            return 0;
        
        void* r11_1 = &rdx_13[1];
        *(arg1 + 0x18) = r11_1;
        
        if (*rdx_13 != 0x5f)
            return 0;
        
        int32_t rsi_4 = rax_19 - 1;
        int32_t* rdi_2 = nullptr;
        
        while (true)
        {
            char rax_20 = *r11_1;
            
            if (!rax_20)
                return 0;
            
            int64_t r10_2 = 0;
            int32_t* r9_4;
            
            if (rax_20 != 0x24)
            {
                int32_t r8_3;
                
                while (true)
                {
                    char rax_25 = *(r11_1 + r10_2);
                    
                    if (!rax_25 || rax_25 == 0x24)
                    {
                        r8_3 = r10_2;
                        break;
                    }
                    
                    if (r10_2 + 1 != rsi_4)
                    {
                        r10_2 += 1;
                        continue;
                    }
                    
                    r8_3 = r10_2 + 1;
                    r10_2 = r8_3;
                    break;
                }
                
                rsi_4 -= r8_3;
                int32_t* rax_27 = sub_140002a40(arg1, r11_1, r8_3);
                r9_4 = rax_27;
                r11_1 = *(arg1 + 0x18) + r10_2;
                *(arg1 + 0x18) = r11_1;
                
                if (!rax_27)
                    return 0;
            }
            else
            {
                char rax_21 = *(r11_1 + 1);
                int32_t rdx_15;
                
                if (rax_21 == 0x53)
                    rdx_15 = 0x2f;
                else if (rax_21 == 0x5f)
                    rdx_15 = 0x2e;
                else
                {
                    if (rax_21 != 0x24)
                        return 0;
                    
                    rdx_15 = 0x24;
                }
                
                int32_t rax_22 = *(arg1 + 0x28);
                r11_1 = *(arg1 + 0x18) + 2;
                
                if (rax_22 >= *(arg1 + 0x2c))
                {
                    *(arg1 + 0x18) = r11_1;
                    return 0;
                }
                
                rsi_4 -= 2;
                r9_4 = (rax_22 << 5) + *(arg1 + 0x20);
                *(r9_4 + 4) = 0;
                *(arg1 + 0x28) = rax_22 + 1;
                *r9_4 = 0x43;
                r9_4[4] = rdx_15;
                *(arg1 + 0x18) = r11_1;
            }
            
            if (!rdi_2)
                rdi_2 = r9_4;
            else
            {
                int32_t* rax_24 = sub_140002940(arg1, 0x42, rdi_2, r9_4);
                rdi_2 = rax_24;
                
                if (!rax_24)
                    return 0;
            }
            
            if (rsi_4 <= 0)
                break;
        }
        
        /* tailcall */
        return sub_140002940(arg1, 0x41, rdi_2, nullptr);
    }
    
    if (rdx_3 <= 0x40 || rdx_3 - 0x41 > 0x15)
        return 0;
    
    switch (rdx_3)
    {
        case 0x41:
        {
            char rax_17 = rax_1[2];
            
            if (rax_17 == 0x47 || rax_17 == 0x54)
                r8_1 = sub_140006060(arg1);
            else
                r8_1 = sub_140006b30(arg1, 0);
            
            /* tailcall */
            return sub_140002940(arg1, 0x17, r8_1, nullptr);
        }
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
        case 0x50:
        case 0x51:
        case 0x53:
        case 0x55:
        {
            return 0;
            break;
        }
        case 0x49:
        {
            int32_t* var_20 = nullptr;
            
            if (!sub_140003990(arg1, &var_20))
                return 0;
            
            r8_1 = var_20;
            
            if (!r8_1)
                return 0;
            
            /* tailcall */
            return sub_140002940(arg1, 0x58, r8_1, nullptr);
        }
        case 0x52:
        {
            int32_t* rax_12 = sub_140006690(arg1, 0);
            int32_t rax_13 = *(arg1 + 0x28);
            int32_t* rsi_3;
            
            if (rax_13 >= *(arg1 + 0x2c))
                rsi_3 = nullptr;
            else
            {
                rsi_3 = (rax_13 << 5) + *(arg1 + 0x20);
                *(rsi_3 + 4) = 0;
                *(arg1 + 0x28) = rax_13 + 1;
                *rsi_3 = 0x44;
                rsi_3[4] = sub_140002aa0(arg1);
            }
            
            /* tailcall */
            return sub_140002940(arg1, 0x16, rax_12, rsi_3);
        }
        case 0x54:
        {
            int32_t rdx_10;
            int32_t* r9_1;
            
            if (!rax_1[2])
            {
            label_1400063ba:
                r8_1 = sub_140006b30(arg1, 0);
                r9_1 = nullptr;
                rdx_10 = 0x4b;
            }
            else
            {
                *(arg1 + 0x18) = &rax_1[3];
                char rax_10 = rax_1[3];
                
                if (rax_1[2] == 0x6e)
                {
                    if (rax_10 == 0x47 || rax_10 == 0x54)
                        r8_1 = sub_140006060(arg1);
                    else
                        r8_1 = sub_140006b30(arg1, 0);
                    
                    r9_1 = nullptr;
                    rdx_10 = 0x4c;
                }
                else
                {
                    if (rax_10 != 0x47 && rax_10 != 0x54)
                        goto label_1400063ba;
                    
                    r8_1 = sub_140006060(arg1);
                    r9_1 = nullptr;
                    rdx_10 = 0x4b;
                }
            }
            
            /* tailcall */
            return sub_140002940(arg1, rdx_10, r8_1, r9_1);
        }
        case 0x56:
        {
            /* tailcall */
            return sub_140002940(arg1, 0x13, sub_140006690(arg1, 0), nullptr);
        }
    }
}

int32_t* sub_140006690(void* arg1, int32_t arg2)
{
    int64_t r12;
    int64_t var_8 = r12;
    int64_t rbp;
    int64_t var_10 = rbp;
    int64_t rdi;
    int64_t var_18 = rdi;
    uint64_t rsi = arg2;
    char* rdx = *(arg1 + 0x18);
    char rax = *rdx;
    int32_t* result;
    
    if (rax == 0x55)
    {
        result = sub_140004a60(arg1, 0, nullptr, rsi);
    label_1400067d8:
        
        if (!rsi)
            return result;
        
        if (result)
        {
            int32_t rax_11 = *(arg1 + 0x38);
            
            if (rax_11 < *(arg1 + 0x3c))
            {
                *(*(arg1 + 0x30) + (rax_11 << 3)) = result;
                *(arg1 + 0x38) = rax_11 + 1;
                return result;
            }
        }
    }
    else
    {
        char* rdx_1;
        int32_t* rdi_1;
        
        if (rax > 0x55)
        {
            if (rax != 0x5a)
            {
            label_1400067b8:
                result = nullptr;
                rdi_1 = nullptr;
            label_1400067c3:
                int32_t* result_3 = sub_140004a60(arg1, rdi_1, result, rsi);
                rdx_1 = *(arg1 + 0x18);
                result = result_3;
                
                if (*rdx_1 != 0x49)
                    goto label_1400067d8;
                
                if (result_3)
                {
                    int32_t rax_21 = *(arg1 + 0x38);
                    
                    if (rax_21 < *(arg1 + 0x3c))
                    {
                        *(*(arg1 + 0x30) + (rax_21 << 3)) = result;
                        int32_t* r9_3 = nullptr;
                        *(arg1 + 0x38) = rax_21 + 1;
                        
                        if (*rdx_1 - 0x49 > 1)
                            goto label_140006905;
                        
                    label_1400068e7:
                        *(arg1 + 0x18) = &rdx_1[1];
                        r9_3 = sub_140005310(arg1);
                    label_140006905:
                        result = sub_140002940(arg1, 4, result, r9_3);
                        goto label_1400067d8;
                    }
                }
            }
            else
            {
                *(arg1 + 0x18) = &rdx[1];
                char rax_4 = rdx[1];
                int32_t* rdi_2;
                
                if (rax_4 == 0x47 || rax_4 == 0x54)
                    rdi_2 = sub_140006060(arg1);
                else
                    rdi_2 = sub_140006b30(arg1, 0);
                
                if (rdi_2)
                {
                    char* rax_6 = *(arg1 + 0x18);
                    
                    if (*rax_6 == 0x45)
                    {
                        *(arg1 + 0x18) = &rax_6[1];
                        char rdx_3 = rax_6[1];
                        int32_t* r9_1;
                        
                        if (rdx_3 == 0x73)
                        {
                            *(arg1 + 0x18) = &rax_6[2];
                            
                            if (sub_140002c60(arg1))
                            {
                                int32_t rax_44 = *(arg1 + 0x28);
                                
                                if (rax_44 >= *(arg1 + 0x2c))
                                {
                                label_140006aa0:
                                    r9_1 = nullptr;
                                    goto label_140006799;
                                }
                                
                                *(arg1 + 0x28) = rax_44 + 1;
                                r9_1 = (rax_44 << 5) + *(arg1 + 0x20);
                                *(r9_1 + 4) = 0;
                                *r9_1 = 0;
                                *(r9_1 + 0x10) = "string literal";
                                r9_1[6] = 0xe;
                            label_140006799:
                                
                                if (*rdi_2 == 3)
                                {
                                    int32_t* rax_41 = *(rdi_2 + 0x18);
                                    
                                    if (*rax_41 == 0x2a)
                                        *(rax_41 + 0x10) = 0;
                                }
                                
                                result = sub_140002940(arg1, 2, rdi_2, r9_1);
                                goto label_1400067d8;
                            }
                        }
                        else if (rdx_3 == 0x64)
                        {
                            void* rdx_8 = &rax_6[2];
                            *(arg1 + 0x18) = rdx_8;
                            char rax_32 = rax_6[2];
                            int32_t rbp_3;
                            
                            if (rax_32 == 0x5f)
                            {
                                rbp_3 = 0;
                            label_1400069f3:
                                *(arg1 + 0x18) = rdx_8 + 1;
                                int32_t* rax_35 = sub_140006690(arg1, 0);
                                int32_t rax_46;
                                
                                if (rax_35 && (*rax_35 & 0xfffffffd) != 0x48)
                                    rax_46 = sub_140002c60(arg1);
                                
                                if (!rax_35 || (*rax_35 & 0xfffffffd) == 0x48 || rax_46)
                                {
                                    int32_t rax_38 = *(arg1 + 0x28);
                                    
                                    if (rax_38 >= *(arg1 + 0x2c))
                                        goto label_140006aa0;
                                    
                                    r9_1 = (rax_38 << 5) + *(arg1 + 0x20);
                                    *(r9_1 + 4) = 0;
                                    *(arg1 + 0x28) = rax_38 + 1;
                                    *r9_1 = 0x49;
                                    r9_1[6] = rbp_3;
                                    *(r9_1 + 0x10) = rax_35;
                                    goto label_140006799;
                                }
                            }
                            else if (rax_32 != 0x6e)
                            {
                                int32_t rax_33 = sub_140002aa0(arg1);
                                rbp_3 = rax_33 + 1;
                                
                                if (rax_33 + 1 >= 0)
                                {
                                    rdx_8 = *(arg1 + 0x18);
                                    
                                    if (*rdx_8 == 0x5f)
                                        goto label_1400069f3;
                                }
                            }
                        }
                        else
                        {
                            int32_t* rax_7 = sub_140006690(arg1, 0);
                            r9_1 = rax_7;
                            
                            if (!rax_7)
                                goto label_140006aa0;
                            
                            if ((*rax_7 & 0xfffffffd) == 0x48)
                                goto label_140006799;
                            
                            if (sub_140002c60(arg1))
                                goto label_140006799;
                        }
                    }
                }
            }
        }
        else if (rax == 0x4e)
        {
            *(arg1 + 0x18) = &rdx[1];
            int32_t* result_1;
            int32_t** rbp_2;
            int32_t* result_5;
            
            if (rdx[1] == 0x48)
            {
                *(arg1 + 0x48) += 5;
                *(arg1 + 0x18) = &rdx[2];
                rbp_2 = &result_1;
                result_5 = sub_140002940(arg1, 0x21, 0, 0);
            label_140006863:
                int32_t* rax_18 = sub_140005430(arg1, 1);
                *rbp_2 = rax_18;
                
                if (rax_18)
                {
                    if (result_5)
                    {
                        int32_t* result_4 = result_1;
                        result_1 = result_5;
                        *(result_5 + 0x10) = result_4;
                    }
                    
                    char* rax_19 = *(arg1 + 0x18);
                    
                    if (*rax_19 == 0x45)
                    {
                        result = result_1;
                        *(arg1 + 0x18) = &rax_19[1];
                        goto label_1400067d8;
                    }
                }
            }
            else
            {
                int32_t** rax_16 = sub_140005d80(arg1, &result_1, 1, rbp, rdi, r12);
                rbp_2 = rax_16;
                
                if (rax_16)
                {
                    result_5 = sub_140002c00(arg1, 0);
                    goto label_140006863;
                }
            }
        }
        else
        {
            if (rax != 0x53)
                goto label_1400067b8;
            
            rdi_1 = nullptr;
            
            if (rdx[1] == 0x74)
            {
                *(arg1 + 0x18) = &rdx[2];
                int32_t rax_30 = *(arg1 + 0x28);
                
                if (rax_30 < *(arg1 + 0x2c))
                {
                    *(arg1 + 0x28) = rax_30 + 1;
                    rdi_1 = (rax_30 << 5) + *(arg1 + 0x20);
                    *(rdi_1 + 4) = 0;
                    *rdi_1 = 0;
                    *(rdi_1 + 0x10) = &data_140024793;
                    rdi_1[6] = 3;
                }
                
                *(arg1 + 0x48) += 3;
            }
            
            if (rdx[1] == 0x74 && rdx[2] != 0x53)
            {
                result = nullptr;
                goto label_1400067c3;
            }
            
            int32_t* result_2 = sub_140003740(arg1, 0);
            result = result_2;
            
            if (result_2)
            {
                if (*result_2 - 0x55 <= 1)
                    goto label_1400067c3;
                
                if (!rdi_1)
                {
                    rdx_1 = *(arg1 + 0x18);
                    
                    if (*rdx_1 != 0x49)
                        return result;
                    
                    goto label_1400068e7;
                }
            }
        }
    }
    return nullptr;
}

int32_t* sub_140006b30(void* arg1, int32_t arg2)
{
    int32_t* result_1 = sub_140006690(arg1, 0);
    int32_t* result = result_1;
    
    if (result_1)
    {
        if (!arg2 || *(arg1 + 0x10) & 1)
        {
            char rax_5 = **(arg1 + 0x18);
            
            if (!rax_5 || rax_5 == 0x45)
                return result;
            
            int32_t* result_2 = result;
            int32_t rdx_2;
            
            while (true)
            {
                int32_t rax_6 = *result_2;
                
                if (rax_6 == 4)
                {
                    int32_t* rdx_3 = *(result_2 + 0x10);
                    
                    if (!rdx_3)
                    {
                    label_140006c90:
                        rdx_2 = 1;
                        break;
                    }
                    
                    while (true)
                    {
                        int32_t rax_11 = *rdx_3;
                        
                        if (rax_11 > 8)
                        {
                            rdx_2 = rax_11 != 0x36;
                            goto label_140006c15;
                        }
                        
                        if (rax_11 > 6)
                            break;
                        
                        if (rax_11 - 1 > 1)
                            goto label_140006c90;
                        
                        rdx_3 = *(rdx_3 + 0x18);
                        
                        if (!rdx_3)
                            goto label_140006c90;
                    }
                }
                else if (rax_6 > 4)
                {
                    uint64_t rax_7 = rax_6 - 0x1c;
                    
                    if (rax_7 <= 0x37 && TEST_BITQ(0xc800000000003f, rax_7))
                    {
                        result_2 = *(result_2 + 0x10);
                        goto label_140006c07;
                    }
                }
                else if (rax_6 == 2)
                {
                    result_2 = *(result_2 + 0x18);
                label_140006c07:
                    
                    if (result_2)
                        continue;
                }
                
                rdx_2 = 0;
                break;
            }
            
        label_140006c15:
            int32_t* rax_8 = sub_140004630(arg1, rdx_2);
            int32_t* rbp_1 = rax_8;
            
            if (rax_8)
            {
                if (!arg2 && *result == 2 && *rax_8 == 0x2a)
                    *(rax_8 + 0x10) = 0;
                
                char* rax_9 = *(arg1 + 0x18);
                
                if (*rax_9 == 0x51)
                {
                    int32_t rdi_1 = *(arg1 + 0x4c);
                    *(arg1 + 0x4c) = 1;
                    *(arg1 + 0x18) = &rax_9[1];
                    int32_t* rax_14 = sub_1400055b0(arg1);
                    *(arg1 + 0x4c) = rdi_1;
                    
                    if (!rax_14)
                        rbp_1 = nullptr;
                    else
                        rbp_1 = sub_140002940(arg1, 0x5e, rbp_1, rax_14);
                }
                
                /* tailcall */
                return sub_140002940(arg1, 3, result, rbp_1);
            }
        }
        else
        {
            int32_t rdx = *result;
            uint64_t rax = rdx - 0x1c;
            
            while (rax <= 0x37)
            {
                if (!TEST_BITQ(0xc800000000003f, rax))
                    return result;
                
                result = *(result + 0x10);
                rdx = *result;
                rax = rdx - 0x1c;
            }
            
            if (rdx != 2)
                return result;
            
            int32_t* rdx_1 = *(result + 0x18);
            
            if (rdx_1)
            {
                while (true)
                {
                    uint64_t rax_2 = *rdx_1 - 0x1c;
                    
                    if (rax_2 > 0x37)
                        return result;
                    
                    if (!TEST_BITQ(0xc800000000003f, rax_2))
                        return result;
                    
                    rdx_1 = *(rdx_1 + 0x10);
                    *(result + 0x18) = rdx_1;
                    
                    if (!rdx_1)
                        return nullptr;
                }
            }
        }
    }
    
    return nullptr;
}

void sub_140006d10(char* arg1, int64_t arg2, int32_t* arg3, int64_t arg4 @ rdi, int512_t arg5 @ zmm0)
{
    int64_t var_30 = arg4;
    int32_t* rsi = arg3;
    
    if (!arg3)
        goto label_140006df0;
    
    int32_t rbp_1 = *(arg1 + 0x130);
    
    if (rbp_1)
        return;
    
    int32_t r9_1 = *arg3;
    
    if (r9_1 > 0x5f)
        goto label_140006df0;
    
    int64_t var_d8;
    int128_t _Str;
    int32_t var_b8;
    void* rax;
    void* rdx_81;
    int32_t* rsi_2;
    char rsi_5;
    int32_t* r8_4;
    int32_t* r8_24;
    int512_t zmm0_2;
    
    switch (r9_1)
    {
        case 0:
        {
            int64_t rbp_37 = arg3[6];
            char* rsi_7 = *(arg3 + 0x10);
            
            if (rbp_37)
            {
                rax = *(arg1 + 0x100);
                void* rbp_38 = &rsi_7[rbp_37];
                
                do
                {
                    char rdi_26 = *rsi_7;
                    void* rdx_66;
                    
                    if (rax != 0xff)
                        rdx_66 = rax;
                    else
                    {
                        rsi_7 = &rsi_7[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_26;
                        arg1[0x108] = rdi_26;
                        
                        if (rsi_7 == rbp_38)
                            break;
                        
                        rdi_26 = *rsi_7;
                        rdx_66 = 1;
                    }
                    
                    rax = rdx_66 + 1;
                    rsi_7 = &rsi_7[1];
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_66) = rdi_26;
                    arg1[0x108] = rdi_26;
                } while (rbp_38 != rsi_7);
            }
            
            return;
            break;
        }
        case 1:
        case 2:
        {
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            sub_140003100(arg1, "::");
            int32_t* rbp_3 = *(rsi + 0x18);
            
            if (*rbp_3 == 0x49)
            {
                int128_t* rsi_16 = &_Str;
                sub_140003100(arg1, "{default arg#");
                sub_140002f60(&_Str, &data_140024478, rbp_3[6] + 1);
                uint64_t rax_115 = strlen(&_Str);
                
                if (rax_115)
                {
                    int64_t rax_116 = *(arg1 + 0x100);
                    void* r12_13 = rax_115 + &_Str;
                    
                    do
                    {
                        char rdi_39 = *rsi_16;
                        int64_t rdx_105;
                        
                        if (rax_116 != 0xff)
                            rdx_105 = rax_116;
                        else
                        {
                            rsi_16 += 1;
                            arg1[0xff] = 0;
                            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                            *(arg1 + 0x140) += 1;
                            *(arg1 + 0x100) = 1;
                            *arg1 = rdi_39;
                            arg1[0x108] = rdi_39;
                            
                            if (r12_13 == rsi_16)
                                break;
                            
                            rdi_39 = *rsi_16;
                            rdx_105 = 1;
                        }
                        
                        rax_116 = rdx_105 + 1;
                        rsi_16 += 1;
                        *(arg1 + 0x100) = rax_116;
                        arg1[rdx_105] = rdi_39;
                        arg1[0x108] = rdi_39;
                    } while (rsi_16 != r12_13);
                }
                
                sub_140003100(arg1, "}::");
                rbp_3 = *(rbp_3 + 0x10);
            }
            
            /* tailcall */
            return sub_14000b540(arg1, 0x11, rbp_3);
        }
        case 3:
        {
            int32_t* r12_1 = *(arg3 + 0x10);
            int64_t rdi = *(arg1 + 0x128);
            *(arg1 + 0x128) = 0;
            
            if (r12_1)
            {
                int64_t r9_2 = *(arg1 + 0x120);
                void* rdx = nullptr;
                uint64_t r8 = 0;
                rax = &_Str;
                
                while (true)
                {
                    *rax = rdx;
                    void* r11_1 = rax;
                    int32_t r13_1 = r8 + 1;
                    *(rax + 0x10) = 0;
                    int32_t rdx_1 = *r12_1;
                    *(rax + 8) = r12_1;
                    uint64_t rcx = rdx_1 - 0x1c;
                    *(rax + 0x18) = r9_2;
                    
                    if (rcx <= 0x37 && TEST_BITQ(0xc800000000003f, rcx))
                    {
                        r12_1 = *(r12_1 + 0x10);
                        
                        if (!r12_1)
                        {
                            *(arg1 + 0x128) = rax;
                            goto label_140006df0;
                        }
                        
                        rax += 0x20;
                        
                        if (r13_1 == 4)
                        {
                            *(arg1 + 0x128) = r11_1;
                            goto label_140006df0;
                        }
                        
                        rdx = r11_1;
                        r8 = r13_1;
                        continue;
                    }
                    
                    *(arg1 + 0x128) = rax;
                    
                    if (rdx_1 == 2)
                    {
                        r12_1 = *(r12_1 + 0x18);
                        
                        if (*r12_1 == 0x49)
                        {
                            r12_1 = *(r12_1 + 0x10);
                            
                            if (!r12_1)
                                break;
                        }
                        
                        int32_t rcx_162 = r13_1;
                        rax = &(&_Str)[r8 * 2];
                        
                        while (true)
                        {
                            rdx_1 = *r12_1;
                            uint64_t r14_3 = rdx_1 - 0x1c;
                            
                            if (r14_3 > 0x37 || !TEST_BITQ(0xc800000000003f, r14_3))
                            {
                                r13_1 = rcx_162;
                                break;
                            }
                            
                            if (rcx_162 == 4)
                                goto label_140006df0;
                            
                            uint64_t rdx_106 = r13_1;
                            uint128_t zmm5 = *rax;
                            uint128_t* r14_5 = rax - (r8 << 5);
                            arg5 = r9_2;
                            arg5 = _mm_unpacklo_epi64(arg5, rax);
                            rcx_162 += 1;
                            r14_5[rdx_106 * 2] = zmm5;
                            uint128_t zmm3 = *(rax + 0x10);
                            void* rdx_109 = ((rdx_106 - r8) << 5) + rax;
                            rax += 0x20;
                            *(arg1 + 0x128) = rdx_109;
                            r14_5[rdx_106 * 2 + 1] = zmm3;
                            *(rax - 0x18) = r12_1;
                            *(rax - 0x10) = 0;
                            *(rax - 8) = arg5;
                            r12_1 = *(r12_1 + 0x10);
                            
                            if (!r12_1)
                                goto label_140006df0;
                            
                            continue;
                        }
                    }
                    
                    if (rdx_1 == 4)
                    {
                        arg5 = r9_2;
                        arg5 = _mm_unpacklo_epi64(arg5, r12_1);
                        *(arg1 + 0x120) = &var_d8;
                        var_d8 = arg5;
                        int32_t* rax_117 = *(r12_1 + 0x18);
                        
                        if (*rax_117 == 0x5e)
                        {
                            *(r12_1 + 0x18) = *(rax_117 + 0x10);
                            *(rax_117 + 0x10) = *(rsi + 0x18);
                            *(rsi + 0x18) = rax_117;
                        }
                    }
                    
                    sub_14000b540(arg1, 0x11, *(rsi + 0x18));
                    
                    if (*r12_1 == 4)
                        *(arg1 + 0x120) = var_d8;
                    
                    void* i = &(&_Str)[(r13_1 - 1) * 2];
                    
                    if (!*(i + 0x10))
                        goto label_14000a339;
                    
                    while (&_Str != i)
                    {
                        i -= 0x20;
                        
                        if (!*(i + 0x10))
                        {
                        label_14000a339:
                            int64_t rax_96 = *(arg1 + 0x100);
                            int64_t rdx_91;
                            
                            if (rax_96 == 0xff)
                            {
                                arg1[0xff] = 0;
                                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                                *(arg1 + 0x140) += 1;
                                rdx_91 = 1;
                                rax_96 = 0;
                            }
                            else
                                rdx_91 = rax_96 + 1;
                            
                            *(arg1 + 0x100) = rdx_91;
                            int32_t* r8_115 = *(i + 8);
                            arg1[rax_96] = 0x20;
                            arg1[0x108] = 0x20;
                            sub_14000b5e0(arg1, 0x11, r8_115);
                        }
                    }
                    
                    *(arg1 + 0x128) = rdi;
                    return;
                }
            }
            
            goto label_140006df0;
        }
        case 4:
        {
            int64_t rdi_23 = *(arg1 + 0x170);
            int64_t rbp_32 = *(arg1 + 0x128);
            *(arg1 + 0x170) = arg3;
            *(arg1 + 0x128) = 0;
            int512_t zmm0_8 = sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            
            if (arg1[0x108] == 0x3c)
                sub_140003030(arg1, 0x20, zmm0_8);
            
            int64_t rax_64 = *(arg1 + 0x100);
            int64_t rdx_57;
            
            if (rax_64 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_57 = 1;
                rax_64 = 0;
            }
            else
                rdx_57 = rax_64 + 1;
            
            *(arg1 + 0x100) = rdx_57;
            arg1[rax_64] = 0x3c;
            arg1[0x108] = 0x3c;
            int512_t zmm0_9 = sub_14000b540(arg1, 0x11, *(rsi + 0x18));
            
            if (arg1[0x108] == 0x3e)
                sub_140003030(arg1, 0x20, zmm0_9);
            
            rax = *(arg1 + 0x100);
            void* rdx_58;
            
            if (rax == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_58 = 1;
                rax = nullptr;
            }
            else
                rdx_58 = rax + 1;
            
            *(arg1 + 0x100) = rdx_58;
            *(arg1 + rax) = 0x3e;
            arg1[0x108] = 0x3e;
            *(arg1 + 0x128) = rbp_32;
            *(arg1 + 0x170) = rdi_23;
            return;
            break;
        }
        case 5:
        {
            int32_t i_47 = arg3[4];
            int32_t rax_34 = *(arg1 + 0x138);
            
            if (rax_34 > i_47 + 1)
            {
                rax = *(*(*(arg1 + 0x120) + 8) + 0x10);
                
                if (!i_47)
                {
                label_14000a881:
                    
                    if (rax)
                    {
                        int32_t rdx_102 = *rax;
                        
                        if (rdx_102 != 0x5d)
                            /* tailcall */
                            return sub_140003450(arg1, rdx_102, i_47);
                        
                        rax = *(rax + 0x10);
                        
                        if (rax)
                            /* tailcall */
                            return sub_140003450(arg1, *rax, i_47);
                    }
                }
                else if (rax)
                {
                    int32_t i_1 = i_47;
                    
                    do
                    {
                        rax = *(rax + 0x18);
                        i_1 -= 1;
                        
                        if (!rax)
                            goto label_140006df0;
                    } while (i_1);
                    
                    goto label_14000a881;
                }
                
                goto label_140006df0;
            }
            
            if (!rax_34)
            {
                rax = sub_1400030a0(arg1, rsi);
                int32_t* r8_128 = rax;
                
                if (!rax)
                    goto label_140006df0;
                
                if (*rax == 0x30)
                {
                    int32_t rdx_101 = *(arg1 + 0x13c);
                    
                    if (rdx_101 >= 0)
                    {
                        rax = sub_140002e50(rax, rdx_101);
                        r8_128 = rax;
                        
                        if (!rax)
                            goto label_140006df0;
                    }
                }
                
                int64_t* rsi_14 = *(arg1 + 0x120);
                *(arg1 + 0x120) = *rsi_14;
                sub_14000b540(arg1, 0x11, r8_128);
                *(arg1 + 0x120) = rsi_14;
                return;
            }
            
            char const* const i_2 = "auto:";
            int64_t rax_99 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_59 = *i_2;
                int64_t rdx_93;
                
                if (rax_99 != 0xff)
                    rdx_93 = rax_99;
                else
                {
                    i_2 = &i_2[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_59;
                    arg1[0x108] = rbp_59;
                    
                    if (&data_1400247b5[5] == i_2)
                        break;
                    
                    rbp_59 = *i_2;
                    rdx_93 = 1;
                }
                
                rax_99 = rdx_93 + 1;
                i_2 = &i_2[1];
                *(arg1 + 0x100) = rax_99;
                arg1[rdx_93] = rbp_59;
                arg1[0x108] = rbp_59;
            } while (i_2 != &data_1400247b5[5]);
            
            int128_t* rsi_15 = &_Str;
            sub_140002f60(&_Str, &data_140024478, rsi[4] + 1);
            rax = strlen(&_Str);
            void* rbp_61 = rax;
            
            if (rax)
            {
                rax = *(arg1 + 0x100);
                int64_t rbp_62 = rbp_61 + &_Str;
                
                do
                {
                    char rdi_38 = *rsi_15;
                    void* rdx_104;
                    
                    if (rax != 0xff)
                        rdx_104 = rax;
                    else
                    {
                        rsi_15 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_38;
                        arg1[0x108] = rdi_38;
                        
                        if (rbp_62 == rsi_15)
                            break;
                        
                        rdi_38 = *rsi_15;
                        rdx_104 = 1;
                    }
                    
                    rax = rdx_104 + 1;
                    rsi_15 += 1;
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_104) = rdi_38;
                    arg1[0x108] = rdi_38;
                } while (rbp_62 != rsi_15);
            }
            
            return;
            break;
        }
        case 6:
        {
            int32_t rdi_15 = arg3[4];
            
            if (!rdi_15)
                /* tailcall */
                return sub_140003100(arg1, "this");
            
            int128_t* rsi_13 = &_Str;
            sub_140003100(arg1, "{parm#");
            sub_140002f60(&_Str, &data_140024478, rdi_15);
            uint64_t rax_97 = strlen(&_Str);
            void* rdx_92 = *(arg1 + 0x100);
            
            if (rax_97)
            {
                void* rbp_58 = rax_97 + &_Str;
                
                do
                {
                    char rdi_35 = *rsi_13;
                    void* rax_98;
                    
                    if (rdx_92 != 0xff)
                        rax_98 = rdx_92;
                    else
                    {
                        rsi_13 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_35;
                        arg1[0x108] = rdi_35;
                        
                        if (rbp_58 == rsi_13)
                        {
                            rdx_92 = 1;
                            goto label_14000a589;
                        }
                        
                        rdi_35 = *rsi_13;
                        rax_98 = 1;
                    }
                    
                    rdx_92 = rax_98 + 1;
                    rsi_13 += 1;
                    *(arg1 + 0x100) = rdx_92;
                    *(arg1 + rax_98) = rdi_35;
                    arg1[0x108] = rdi_35;
                } while (rbp_58 != rsi_13);
            }
            
            if (rdx_92 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, rdx_92, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_92 = nullptr;
            }
            
        label_14000a589:
            *(arg1 + 0x100) = rdx_92 + 1;
            *(arg1 + rdx_92) = 0x7d;
            arg1[0x108] = 0x7d;
            return;
            break;
        }
        case 7:
        {
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 8:
        {
            int64_t rax_15 = *(arg1 + 0x100);
            int64_t rdx_13;
            
            if (rax_15 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_13 = 1;
                rax_15 = 0;
            }
            else
                rdx_13 = rax_15 + 1;
            
            *(arg1 + 0x100) = rdx_13;
            arg1[rax_15] = 0x7e;
            arg1[0x108] = 0x7e;
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 9:
        {
            char const* const i_3 = "vtable for ";
            int64_t rax_56 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_24 = *i_3;
                int64_t rdx_48;
                
                if (rax_56 != 0xff)
                    rdx_48 = rax_56;
                else
                {
                    i_3 = &i_3[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_24;
                    arg1[0x108] = rbp_24;
                    
                    if (&data_1400247f7[0xb] == i_3)
                        break;
                    
                    rbp_24 = *i_3;
                    rdx_48 = 1;
                }
                
                rax_56 = rdx_48 + 1;
                i_3 = &i_3[1];
                *(arg1 + 0x100) = rax_56;
                arg1[rdx_48] = rbp_24;
                arg1[0x108] = rbp_24;
            } while (i_3 != &data_1400247f7[0xb]);
            
            goto label_140006e10;
        }
        case 0xa:
        {
            char const* const i_4 = "VTT for ";
            int64_t rax_55 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_23 = *i_4;
                int64_t rdx_47;
                
                if (rax_55 != 0xff)
                    rdx_47 = rax_55;
                else
                {
                    i_4 = &i_4[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_23;
                    arg1[0x108] = rbp_23;
                    
                    if (&data_140024803[8] == i_4)
                        break;
                    
                    rbp_23 = *i_4;
                    rdx_47 = 1;
                }
                
                rax_55 = rdx_47 + 1;
                i_4 = &i_4[1];
                *(arg1 + 0x100) = rax_55;
                arg1[rdx_47] = rbp_23;
                arg1[0x108] = rbp_23;
            } while (i_4 != &data_140024803[8]);
            
            goto label_140006e10;
        }
        case 0xb:
        {
            char const* const i_5 = "construction vtable for ";
            int64_t rax_79 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_48 = *i_5;
                int64_t rdx_77;
                
                if (rax_79 != 0xff)
                    rdx_77 = rax_79;
                else
                {
                    i_5 = &i_5[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_48;
                    arg1[0x108] = rbp_48;
                    
                    if (&data_14002480c[0x18] == i_5)
                        break;
                    
                    rbp_48 = *i_5;
                    rdx_77 = 1;
                }
                
                rax_79 = rdx_77 + 1;
                i_5 = &i_5[1];
                *(arg1 + 0x100) = rax_79;
                arg1[rdx_77] = rbp_48;
                arg1[0x108] = rbp_48;
            } while (&data_14002480c[0x18] != i_5);
            
            char const* const i_6 = "-in-";
            sub_14000b540(arg1, 0x11, *(rsi + 0x10));
            int64_t rax_82 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_49 = *i_6;
                int64_t rdx_80;
                
                if (rax_82 != 0xff)
                    rdx_80 = rax_82;
                else
                {
                    i_6 = &i_6[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_49;
                    arg1[0x108] = rbp_49;
                    
                    if (&data_140024825[4] == i_6)
                        break;
                    
                    rbp_49 = *i_6;
                    rdx_80 = 1;
                }
                
                rax_82 = rdx_80 + 1;
                i_6 = &i_6[1];
                *(arg1 + 0x100) = rax_82;
                arg1[rdx_80] = rbp_49;
                arg1[0x108] = rbp_49;
            } while (&data_140024825[4] != i_6);
            
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0xc:
        {
            char const* const i_7 = "typeinfo for ";
            int64_t rax_78 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_47 = *i_7;
                int64_t rdx_76;
                
                if (rax_78 != 0xff)
                    rdx_76 = rax_78;
                else
                {
                    i_7 = &i_7[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_47;
                    arg1[0x108] = rbp_47;
                    
                    if (&data_14002482a[0xd] == i_7)
                        break;
                    
                    rbp_47 = *i_7;
                    rdx_76 = 1;
                }
                
                rax_78 = rdx_76 + 1;
                i_7 = &i_7[1];
                *(arg1 + 0x100) = rax_78;
                arg1[rdx_76] = rbp_47;
                arg1[0x108] = rbp_47;
            } while (&data_14002482a[0xd] != i_7);
            
            goto label_140006e10;
        }
        case 0xd:
        {
            char const* const i_8 = "typeinfo name for ";
            int64_t rax_27 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_11 = *i_8;
                int64_t rdx_29;
                
                if (rax_27 != 0xff)
                    rdx_29 = rax_27;
                else
                {
                    i_8 = &i_8[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_11;
                    arg1[0x108] = rbp_11;
                    
                    if (&data_140024838[0x12] == i_8)
                        break;
                    
                    rbp_11 = *i_8;
                    rdx_29 = 1;
                }
                
                rax_27 = rdx_29 + 1;
                i_8 = &i_8[1];
                *(arg1 + 0x100) = rax_27;
                arg1[rdx_29] = rbp_11;
                arg1[0x108] = rbp_11;
            } while (&data_140024838[0x12] != i_8);
            
            goto label_140006e10;
        }
        case 0xe:
        {
            char const* const i_9 = "typeinfo fn for ";
            int64_t rax_26 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_10 = *i_9;
                int64_t rdx_28;
                
                if (rax_26 != 0xff)
                    rdx_28 = rax_26;
                else
                {
                    i_9 = &i_9[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_10;
                    arg1[0x108] = rbp_10;
                    
                    if (i_9 == &data_14002484b[0x10])
                        break;
                    
                    rbp_10 = *i_9;
                    rdx_28 = 1;
                }
                
                rax_26 = rdx_28 + 1;
                i_9 = &i_9[1];
                *(arg1 + 0x100) = rax_26;
                arg1[rdx_28] = rbp_10;
                arg1[0x108] = rbp_10;
            } while (&data_14002484b[0x10] != i_9);
            
            goto label_140006e10;
        }
        case 0xf:
        {
            char const* const i_10 = "non-virtual thunk to ";
            int64_t rax_74 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_43 = *i_10;
                int64_t rdx_71;
                
                if (rax_74 != 0xff)
                    rdx_71 = rax_74;
                else
                {
                    i_10 = &i_10[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_43;
                    arg1[0x108] = rbp_43;
                    
                    if (i_10 == &data_14002485c[0x15])
                        break;
                    
                    rbp_43 = *i_10;
                    rdx_71 = 1;
                }
                
                rax_74 = rdx_71 + 1;
                i_10 = &i_10[1];
                *(arg1 + 0x100) = rax_74;
                arg1[rdx_71] = rbp_43;
                arg1[0x108] = rbp_43;
            } while (&data_14002485c[0x15] != i_10);
            
            goto label_140006e10;
        }
        case 0x10:
        {
            char const* const i_11 = "virtual thunk to ";
            int64_t rax_73 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_42 = *i_11;
                int64_t rdx_70;
                
                if (rax_73 != 0xff)
                    rdx_70 = rax_73;
                else
                {
                    i_11 = &i_11[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_42;
                    arg1[0x108] = rbp_42;
                    
                    if (i_11 == &data_140024872[0x11])
                        break;
                    
                    rbp_42 = *i_11;
                    rdx_70 = 1;
                }
                
                rax_73 = rdx_70 + 1;
                i_11 = &i_11[1];
                *(arg1 + 0x100) = rax_73;
                arg1[rdx_70] = rbp_42;
                arg1[0x108] = rbp_42;
            } while (&data_140024872[0x11] != i_11);
            
            goto label_140006e10;
        }
        case 0x11:
        {
            char const* const i_12 = "covariant return thunk to ";
            int64_t rax_72 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_41 = *i_12;
                int64_t rdx_69;
                
                if (rax_72 != 0xff)
                    rdx_69 = rax_72;
                else
                {
                    i_12 = &i_12[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_41;
                    arg1[0x108] = rbp_41;
                    
                    if (i_12 == &data_140024884[0x1a])
                        break;
                    
                    rbp_41 = *i_12;
                    rdx_69 = 1;
                }
                
                rax_72 = rdx_69 + 1;
                i_12 = &i_12[1];
                *(arg1 + 0x100) = rax_72;
                arg1[rdx_69] = rbp_41;
                arg1[0x108] = rbp_41;
            } while (&data_140024884[0x1a] != i_12);
            
            goto label_140006e10;
        }
        case 0x12:
        {
            char const* const i_13 = "java Class for ";
            int64_t rax_71 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_40 = *i_13;
                int64_t rdx_68;
                
                if (rax_71 != 0xff)
                    rdx_68 = rax_71;
                else
                {
                    i_13 = &i_13[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_40;
                    arg1[0x108] = rbp_40;
                    
                    if (i_13 == &data_14002489f[0xf])
                        break;
                    
                    rbp_40 = *i_13;
                    rdx_68 = 1;
                }
                
                rax_71 = rdx_68 + 1;
                i_13 = &i_13[1];
                *(arg1 + 0x100) = rax_71;
                arg1[rdx_68] = rbp_40;
                arg1[0x108] = rbp_40;
            } while (&data_14002489f[0xf] != i_13);
            
            goto label_140006e10;
        }
        case 0x13:
        {
            char const* const i_14 = "guard variable for ";
            int64_t rax_76 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_45 = *i_14;
                int64_t rdx_73;
                
                if (rax_76 != 0xff)
                    rdx_73 = rax_76;
                else
                {
                    i_14 = &i_14[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_45;
                    arg1[0x108] = rbp_45;
                    
                    if (i_14 == &data_1400248af[0x13])
                        break;
                    
                    rbp_45 = *i_14;
                    rdx_73 = 1;
                }
                
                rax_76 = rdx_73 + 1;
                i_14 = &i_14[1];
                *(arg1 + 0x100) = rax_76;
                arg1[rdx_73] = rbp_45;
                arg1[0x108] = rbp_45;
            } while (&data_1400248af[0x13] != i_14);
            
            goto label_140006e10;
        }
        case 0x14:
        {
            char const* const i_15 = "TLS init function for ";
            int64_t rax_75 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_44 = *i_15;
                int64_t rdx_72;
                
                if (rax_75 != 0xff)
                    rdx_72 = rax_75;
                else
                {
                    i_15 = &i_15[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_44;
                    arg1[0x108] = rbp_44;
                    
                    if (i_15 == &data_1400248c3[0x16])
                        break;
                    
                    rbp_44 = *i_15;
                    rdx_72 = 1;
                }
                
                rax_75 = rdx_72 + 1;
                i_15 = &i_15[1];
                *(arg1 + 0x100) = rax_75;
                arg1[rdx_72] = rbp_44;
                arg1[0x108] = rbp_44;
            } while (&data_1400248c3[0x16] != i_15);
            
            goto label_140006e10;
        }
        case 0x15:
        {
            char const* const i_16 = "TLS wrapper function for ";
            int64_t rax_37 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_16 = *i_16;
                int64_t rdx_38;
                
                if (rax_37 != 0xff)
                    rdx_38 = rax_37;
                else
                {
                    i_16 = &i_16[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_16;
                    arg1[0x108] = rbp_16;
                    
                    if (i_16 == &data_1400248da[0x19])
                        break;
                    
                    rbp_16 = *i_16;
                    rdx_38 = 1;
                }
                
                rax_37 = rdx_38 + 1;
                i_16 = &i_16[1];
                *(arg1 + 0x100) = rax_37;
                arg1[rdx_38] = rbp_16;
                arg1[0x108] = rbp_16;
            } while (&data_1400248da[0x19] != i_16);
            
            goto label_140006e10;
        }
        case 0x16:
        {
            char const* const i_17 = "reference temporary #";
            int64_t rax_32 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_15 = *i_17;
                int64_t rdx_34;
                
                if (rax_32 != 0xff)
                    rdx_34 = rax_32;
                else
                {
                    i_17 = &i_17[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_15;
                    arg1[0x108] = rbp_15;
                    
                    if (i_17 == &data_1400248f4[0x15])
                        break;
                    
                    rbp_15 = *i_17;
                    rdx_34 = 1;
                }
                
                rax_32 = rdx_34 + 1;
                i_17 = &i_17[1];
                *(arg1 + 0x100) = rax_32;
                arg1[rdx_34] = rbp_15;
                arg1[0x108] = rbp_15;
            } while (&data_1400248f4[0x15] != i_17);
            
            char const* const i_18 = " for ";
            sub_14000b540(arg1, 0x11, *(rsi + 0x18));
            int64_t rax_89 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_53 = *i_18;
                int64_t rdx_86;
                
                if (rax_89 != 0xff)
                    rdx_86 = rax_89;
                else
                {
                    i_18 = &i_18[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_53;
                    arg1[0x108] = rbp_53;
                    
                    if (i_18 == &data_14002490a[5])
                        break;
                    
                    rbp_53 = *i_18;
                    rdx_86 = 1;
                }
                
                rax_89 = rdx_86 + 1;
                i_18 = &i_18[1];
                *(arg1 + 0x100) = rax_89;
                arg1[rdx_86] = rbp_53;
                arg1[0x108] = rbp_53;
            } while (&data_14002490a[5] != i_18);
            
            goto label_140006e10;
        }
        case 0x17:
        {
            char const* const i_19 = "hidden alias for ";
            int64_t rax_31 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_14 = *i_19;
                int64_t rdx_33;
                
                if (rax_31 != 0xff)
                    rdx_33 = rax_31;
                else
                {
                    i_19 = &i_19[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_14;
                    arg1[0x108] = rbp_14;
                    
                    if (&data_140024910[0x11] == i_19)
                        break;
                    
                    rbp_14 = *i_19;
                    rdx_33 = 1;
                }
                
                rax_31 = rdx_33 + 1;
                i_19 = &i_19[1];
                *(arg1 + 0x100) = rax_31;
                arg1[rdx_33] = rbp_14;
                arg1[0x108] = rbp_14;
            } while (&data_140024910[0x11] != i_19);
            
            goto label_140006e10;
        }
        case 0x18:
        {
            int64_t rbp_12 = arg3[6];
            char* rsi_3 = *(arg3 + 0x10);
            
            if (rbp_12)
            {
                rax = *(arg1 + 0x100);
                void* rbp_13 = &rsi_3[rbp_12];
                
                do
                {
                    char rdi_14 = *rsi_3;
                    void* rdx_32;
                    
                    if (rax != 0xff)
                        rdx_32 = rax;
                    else
                    {
                        rsi_3 = &rsi_3[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_14;
                        arg1[0x108] = rdi_14;
                        
                        if (rbp_13 == rsi_3)
                            break;
                        
                        rdi_14 = *rsi_3;
                        rdx_32 = 1;
                    }
                    
                    rax = rdx_32 + 1;
                    rsi_3 = &rsi_3[1];
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_32) = rdi_14;
                    arg1[0x108] = rdi_14;
                } while (rbp_13 != rsi_3);
            }
            
            return;
            break;
        }
        case 0x19:
        case 0x1a:
        case 0x1b:
        {
            void** r8_5 = *(arg1 + 0x128);
            void** rax_6 = r8_5;
            
            if (!r8_5)
            {
                *_Str[8] = rsi;
                *(arg1 + 0x128) = &_Str;
                int64_t rax_134 = *(arg1 + 0x120);
                _Str = 0;
                r8_4 = *(rsi + 0x10);
                var_b8 = 0;
                int64_t var_b0_10 = rax_134;
                goto label_140006ec2;
            }
            
            while (true)
            {
                if (rax_6[2])
                {
                label_140006f2e:
                    rax_6 = *rax_6;
                    
                    if (rax_6)
                        continue;
                }
                else
                {
                    int32_t rdx_5 = *rax_6[1];
                    
                    if (rdx_5 - 0x19 <= 2)
                    {
                        if (r9_1 == rdx_5)
                            goto label_140006e10;
                        
                        goto label_140006f2e;
                    }
                }
                
                _Str = r8_5;
                *(arg1 + 0x128) = &_Str;
                var_b8 = 0;
                *_Str[8] = rsi;
                int64_t var_b0_2 = *(arg1 + 0x120);
                break;
            }
            
            goto label_140006f5e;
        }
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x26:
        case 0x27:
        case 0x4f:
        case 0x52:
        case 0x53:
        {
            arg5 = *(arg1 + 0x128);
            var_b8 = 0;
            *(arg1 + 0x128) = &_Str;
            int64_t rax_5 = *(arg1 + 0x120);
            arg5 = _mm_unpacklo_epi64(arg5, arg3);
            r8_4 = *(arg3 + 0x10);
            int64_t var_b0_1 = rax_5;
            _Str = arg5;
        label_140006ec2:
            sub_14000b540(arg1, 0x11, r8_4);
            
            if (!var_b8)
                sub_14000b5e0(arg1, 0x11, rsi);
            
            *(arg1 + 0x128) = _Str;
            
            if (rbp_1)
                *(arg1 + 0x120) = arg4;
            
            return;
            break;
        }
        case 0x24:
        case 0x25:
        {
            r8_4 = *(arg3 + 0x10);
            int32_t r10_4 = *(arg1 + 0x138);
            rax = *r8_4;
            int32_t* rcx_13 = r8_4;
            int64_t r10_5;
            
            if (!r10_4)
            {
                rbp_1 = 0;
                
                if (rax == 5)
                {
                    int32_t rcx_165 = *(arg1 + 0x158);
                    
                    if (rcx_165 > 0)
                    {
                        int64_t* i_20 = *(arg1 + 0x150);
                        
                        do
                        {
                            if (r8_4 == *i_20)
                            {
                                int64_t* r11_11 = *(arg1 + 0x148);
                                int64_t* rax_120 = r11_11;
                                
                                if (!r11_11)
                                {
                                label_14000b211:
                                    arg4 = *(arg1 + 0x120);
                                    *(arg1 + 0x120) = i_20[1];
                                    rax = sub_1400030a0(arg1, r8_4);
                                    rcx_13 = rax;
                                    
                                    if (!rax)
                                        goto label_14000b4d1;
                                    
                                    r10_4 = 1;
                                    goto label_14000af46;
                                }
                                
                                while (true)
                                {
                                    int64_t rcx_166 = *rax_120;
                                    
                                    if (rcx_166 == r8_4)
                                        break;
                                    
                                    if (r11_11 != rax_120 && rcx_166 == rsi)
                                        break;
                                    
                                    rax_120 = rax_120[1];
                                    
                                    if (!rax_120)
                                        goto label_14000b211;
                                }
                                
                                goto label_14000af35;
                            }
                            
                            i_20 = &i_20[2];
                        } while (&i_20[rcx_165 * 2] != i_20);
                    }
                    
                    if (rcx_165 >= *(arg1 + 0x15c))
                        goto label_140006df0;
                    
                    void** i_21 = *(arg1 + 0x120);
                    void* rax_137 = (rcx_165 << 4) + *(arg1 + 0x150);
                    *(arg1 + 0x158) = rcx_165 + 1;
                    rax = rax_137 + 8;
                    *(rax - 8) = r8_4;
                    
                    if (i_21)
                    {
                        int64_t rdx_124 = *(arg1 + 0x168);
                        int32_t r12_14 = *(arg1 + 0x16c);
                        int32_t rcx_193 = rdx_124;
                        int64_t rdx_125 = rdx_124 << 4;
                        
                        do
                        {
                            if (r12_14 <= rcx_193)
                                goto label_140006df0;
                            
                            void* rbp_63 = *(arg1 + 0x160);
                            int64_t r13_3 = i_21[1];
                            rcx_193 += 1;
                            *(arg1 + 0x168) = rcx_193;
                            void* rbp_64 = rbp_63 + rdx_125;
                            rdx_125 += 0x10;
                            *(rbp_64 + 8) = r13_3;
                            *rax = rbp_64;
                            i_21 = *i_21;
                            rax = rbp_64;
                        } while (i_21);
                    }
                    
                    *rax = 0;
                label_14000af35:
                    rax = sub_1400030a0(arg1, r8_4);
                    rcx_13 = rax;
                    
                    if (!rax)
                        goto label_140006df0;
                    
                label_14000af46:
                    rax = *rcx_13;
                    rbp_1 = r10_4;
                    
                    if (rax == 0x30)
                    {
                        int32_t rdx_113 = *(arg1 + 0x13c);
                        
                        if (rdx_113 < 0)
                        {
                            arg5 = *(arg1 + 0x128);
                            r10_5 = *(arg1 + 0x120);
                            
                            if (r9_1 != 0x30)
                            {
                                arg5 = _mm_unpacklo_epi64(arg5, rsi);
                                goto label_140007215;
                            }
                            
                            rsi = rcx_13;
                            arg5 = _mm_unpacklo_epi64(arg5, rcx_13);
                            goto label_14000a9c4;
                        }
                        
                        rax = sub_140002e50(rcx_13, rdx_113);
                        rcx_13 = rax;
                        
                        if (!rax)
                        {
                            if (!r10_4)
                                goto label_140006df0;
                            
                        label_14000b4d1:
                            *(arg1 + 0x120) = arg4;
                        label_140006df0:
                            *(arg1 + 0x130) = 1;
                            return;
                        }
                        
                        rax = *rax;
                    }
                }
            }
            
            if (rax == 0x24)
            {
                int64_t rax_106 = *(arg1 + 0x120);
                rsi = rcx_13;
                arg5 = *(arg1 + 0x128);
                var_b8 = 0;
                *(arg1 + 0x128) = &_Str;
                arg5 = _mm_unpacklo_epi64(arg5, rcx_13);
                int64_t var_b0_8 = rax_106;
                _Str = arg5;
                r8_4 = *(rcx_13 + 0x10);
                goto label_140006ec2;
            }
            
            int64_t rdx_12 = *(arg1 + 0x128);
            r10_5 = *(arg1 + 0x120);
            
            if (r9_1 == rax)
            {
                arg5 = rdx_12;
                rsi = rcx_13;
                arg5 = _mm_unpacklo_epi64(arg5, rcx_13);
            label_14000a9c4:
                _Str = arg5;
                r8_4 = *(rcx_13 + 0x10);
                *(arg1 + 0x128) = &_Str;
                var_b8 = 0;
                int64_t var_b0_9 = r10_5;
                goto label_140006ec2;
            }
            
            if (rax != 0x25)
            {
                arg5 = rdx_12;
                arg5 = _mm_unpacklo_epi64(arg5, rsi);
            label_140007215:
                var_b8 = 0;
                *(arg1 + 0x128) = &_Str;
                int64_t var_b0_4 = r10_5;
                _Str = arg5;
                goto label_140006ec2;
            }
            
            r8_4 = *(rcx_13 + 0x10);
            _Str = rdx_12;
            *(arg1 + 0x128) = &_Str;
            *_Str[8] = rsi;
            var_b8 = 0;
            int64_t var_b0_7 = r10_5;
            
            if (r8_4)
                goto label_140006ec2;
            
        label_140006f5e:
            r8_4 = *(rsi + 0x10);
            goto label_140006ec2;
        }
        case 0x28:
        {
            rax = *(arg3 + 0x10);
            int64_t rbp_29 = *(rax + 8);
            char* rsi_6 = *rax;
            
            if (rbp_29)
            {
                rax = *(arg1 + 0x100);
                void* rbp_30 = &rsi_6[rbp_29];
                
                do
                {
                    char rdi_22 = *rsi_6;
                    void* rdx_55;
                    
                    if (rax != 0xff)
                        rdx_55 = rax;
                    else
                    {
                        rsi_6 = &rsi_6[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_22;
                        arg1[0x108] = rdi_22;
                        
                        if (rbp_30 == rsi_6)
                            break;
                        
                        rdi_22 = *rsi_6;
                        rdx_55 = 1;
                    }
                    
                    rax = rdx_55 + 1;
                    rsi_6 = &rsi_6[1];
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_55) = rdi_22;
                    arg1[0x108] = rdi_22;
                } while (rbp_30 != rsi_6);
            }
            
            return;
            break;
        }
        case 0x29:
        case 0x5b:
        {
        label_140006e10:
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x10));
        }
        case 0x2a:
        {
            int32_t* r8_90 = *(arg3 + 0x10);
            
            if (!r8_90)
                /* tailcall */
                return sub_14000c200(arg1, 0x11, rsi, *(arg1 + 0x128));
            
            arg5 = *(arg1 + 0x128);
            *(arg1 + 0x128) = &_Str;
            int64_t rax_80 = *(arg1 + 0x120);
            arg5 = _mm_unpacklo_epi64(arg5, rsi);
            var_b8 = 0;
            int64_t var_b0_6 = rax_80;
            _Str = arg5;
            int512_t zmm0_10 = sub_14000b540(arg1, 0x11, r8_90);
            int32_t r14_2 = var_b8;
            *(arg1 + 0x128) = _Str;
            
            if (r14_2)
                return;
            
            sub_140003030(arg1, 0x20, zmm0_10);
            /* tailcall */
            return sub_14000c200(arg1, 0x11, rsi, *(arg1 + 0x128));
        }
        case 0x2b:
        {
            void* r12_3 = *(arg1 + 0x128);
            int64_t rax_22 = *(arg1 + 0x120);
            *(arg1 + 0x128) = &_Str;
            int128_t* rcx_21 = &_Str;
            int32_t rdi_9 = 1;
            arg5 = r12_3;
            int64_t var_b0_5 = rax_22;
            rax = r12_3;
            arg5 = _mm_unpacklo_epi64(arg5, arg3);
            var_b8 = 0;
            _Str = arg5;
            
            if (r12_3)
            {
                while (**(rax + 8) - 0x19 <= 2)
                {
                    if (!*(rax + 0x10))
                    {
                        if (rdi_9 > 3)
                            goto label_140006df0;
                        
                        uint64_t rdx_21 = rdi_9;
                        rdi_9 += 1;
                        (&_Str)[rdx_21 * 2] = *rax;
                        int128_t zmm2 = *(rax + 0x10);
                        (&_Str)[rdx_21 * 2] = rcx_21;
                        rcx_21 = &(&_Str)[rdx_21 * 2];
                        *(arg1 + 0x128) = rcx_21;
                        *(&var_b8 + (rdx_21 << 5)) = zmm2;
                        *(rax + 0x10) = 1;
                    }
                    
                    rax = *rax;
                    
                    if (!rax)
                        break;
                }
                
                sub_14000b540(arg1, 0x11, *(rsi + 0x18));
                *(arg1 + 0x128) = r12_3;
                
                if (!var_b8)
                {
                    if (rdi_9 > 1)
                    {
                        uint64_t rax_23 = rdi_9 - 1;
                        int32_t rdi_10 = rax_23;
                        void* rbp_9 = &(&_Str)[rax_23 * 2];
                        
                        while (true)
                        {
                            int32_t* r8_22 = *(rbp_9 + 8);
                            rbp_9 -= 0x20;
                            sub_14000b5e0(arg1, 0x11, r8_22);
                            
                            if (rdi_10 == 1)
                                break;
                            
                            rdi_10 -= 1;
                        }
                    }
                    
                    sub_14000ca40(arg1, 0x11, rsi, *(arg1 + 0x128));
                }
            }
            else
            {
                sub_14000b540(arg1, 0x11, *(arg3 + 0x18));
                bool cond:0_1 = var_b8;
                *(arg1 + 0x128) = 0;
                
                if (!cond:0_1)
                    sub_14000ca40(arg1, 0x11, rsi, *(arg1 + 0x128));
            }
            
            return;
            break;
        }
        case 0x2c:
        case 0x2e:
        {
            arg5 = *(arg1 + 0x128);
            int32_t* r8_6 = *(arg3 + 0x18);
            *(arg1 + 0x128) = &_Str;
            int64_t rax_8 = *(arg1 + 0x120);
            arg5 = _mm_unpacklo_epi64(arg5, arg3);
            var_b8 = 0;
            int64_t var_b0_3 = rax_8;
            _Str = arg5;
            sub_14000b540(arg1, 0x11, r8_6);
            
            if (!var_b8)
                sub_14000b5e0(arg1, 0x11, rsi);
            
            *(arg1 + 0x128) = _Str;
            return;
            break;
        }
        case 0x2d:
        case 0x35:
        case 0x3a:
        case 0x3c:
        case 0x3d:
        case 0x49:
        {
            goto label_140006df0;
        }
        case 0x2f:
        case 0x30:
        {
            int32_t* r8_11 = *(arg3 + 0x10);
            
            if (r8_11)
                sub_14000b540(arg1, 0x11, r8_11);
            
            if (*(rsi + 0x18))
            {
                int64_t rdx_11 = *(arg1 + 0x100);
                
                if (rdx_11 > 0xfd)
                {
                    arg1[rdx_11] = 0;
                    (*(arg1 + 0x110))(arg1, rdx_11, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 0;
                }
                
                sub_140003100(arg1, ", ");
                int32_t rdi_6 = *(arg1 + 0x140);
                int64_t rbp_2 = *(arg1 + 0x100);
                sub_14000b540(arg1, 0x11, *(rsi + 0x18));
                
                if (*(arg1 + 0x140) == rdi_6)
                {
                    rax = *(arg1 + 0x100);
                    
                    if (rax == rbp_2)
                        *(arg1 + 0x100) = rax - 2;
                }
            }
            
            return;
            break;
        }
        case 0x31:
        {
            char const* const i_22 = "template parameter object for ";
            int64_t rax_63 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_31 = *i_22;
                int64_t rdx_56;
                
                if (rax_63 != 0xff)
                    rdx_56 = rax_63;
                else
                {
                    i_22 = &i_22[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_31;
                    arg1[0x108] = rbp_31;
                    
                    if (&data_1400247c0[0x1e] == i_22)
                        break;
                    
                    rbp_31 = *i_22;
                    rdx_56 = 1;
                }
                
                rax_63 = rdx_56 + 1;
                i_22 = &i_22[1];
                *(arg1 + 0x100) = rax_63;
                arg1[rdx_56] = rbp_31;
                arg1[0x108] = rbp_31;
            } while (i_22 != &data_1400247c0[0x1e]);
            
            goto label_140006e10;
        }
        case 0x32:
        {
            int32_t* r8_19 = *(arg3 + 0x10);
            int32_t* rsi_1 = *(rsi + 0x18);
            
            if (r8_19)
                sub_14000b540(arg1, 0x11, r8_19);
            
            int64_t rax_21 = *(arg1 + 0x100);
            int64_t rdx_19;
            
            if (rax_21 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_19 = 1;
                rax_21 = 0;
            }
            else
                rdx_19 = rax_21 + 1;
            
            *(arg1 + 0x100) = rdx_19;
            arg1[rax_21] = 0x7b;
            arg1[0x108] = 0x7b;
            sub_14000b540(arg1, 0x11, rsi_1);
            rax = *(arg1 + 0x100);
            void* rdx_20;
            
            if (rax == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_20 = 1;
                rax = nullptr;
            }
            else
                rdx_20 = rax + 1;
            
            *(arg1 + 0x100) = rdx_20;
            *(arg1 + rax) = 0x7d;
            arg1[0x108] = 0x7d;
            return;
            break;
        }
        case 0x33:
        {
            void* r12_2 = *(arg3 + 0x10);
            char const* const i_23 = "operator";
            int64_t rax_20 = *(arg1 + 0x100);
            int64_t rbp_8 = *(r12_2 + 0x10);
            
            do
            {
                char const rdi_8 = *i_23;
                int64_t rdx_18;
                
                if (rax_20 != 0xff)
                    rdx_18 = rax_20;
                else
                {
                    i_23 = &i_23[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_8;
                    arg1[0x108] = rdi_8;
                    
                    if (i_23 == &data_140024954[8])
                        break;
                    
                    rdi_8 = *i_23;
                    rdx_18 = 1;
                }
                
                rax_20 = rdx_18 + 1;
                i_23 = &i_23[1];
                *(arg1 + 0x100) = rax_20;
                arg1[rdx_18] = rdi_8;
                arg1[0x108] = rdi_8;
            } while (i_23 != &data_140024954[8]);
            
            char* rsi_9 = *(r12_2 + 8);
            
            if (*rsi_9 - 0x61 <= 0x19)
            {
                sub_140003030(arg1, 0x20, arg5);
                rsi_9 = *(r12_2 + 8);
            }
            
            if (rsi_9[rbp_8 - 1] == 0x20)
                rbp_8 -= 1;
            
            if (rbp_8)
            {
                rax = *(arg1 + 0x100);
                void* rbp_52 = &rsi_9[rbp_8];
                
                do
                {
                    char rdi_33 = *rsi_9;
                    void* rdx_85;
                    
                    if (rax != 0xff)
                        rdx_85 = rax;
                    else
                    {
                        rsi_9 = &rsi_9[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_33;
                        arg1[0x108] = rdi_33;
                        
                        if (rsi_9 == rbp_52)
                            break;
                        
                        rdi_33 = *rsi_9;
                        rdx_85 = 1;
                    }
                    
                    rax = rdx_85 + 1;
                    rsi_9 = &rsi_9[1];
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_85) = rdi_33;
                    arg1[0x108] = rdi_33;
                } while (rsi_9 != rbp_52);
            }
            
            return;
            break;
        }
        case 0x34:
        {
            char const* const i_24 = "operator ";
            int64_t rax_66 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_34 = *i_24;
                int64_t rdx_60;
                
                if (rax_66 != 0xff)
                    rdx_60 = rax_66;
                else
                {
                    i_24 = &i_24[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_34;
                    arg1[0x108] = rbp_34;
                    
                    if (i_24 == &data_14002495d[9])
                        break;
                    
                    rbp_34 = *i_24;
                    rdx_60 = 1;
                }
                
                rax_66 = rdx_60 + 1;
                i_24 = &i_24[1];
                *(arg1 + 0x100) = rax_66;
                arg1[rdx_60] = rbp_34;
                arg1[0x108] = rbp_34;
            } while (&data_14002495d[9] != i_24);
            
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0x36:
        {
            char const* const i_25 = "operator ";
            int64_t rax_65 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_33 = *i_25;
                int64_t rdx_59;
                
                if (rax_65 != 0xff)
                    rdx_59 = rax_65;
                else
                {
                    i_25 = &i_25[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_33;
                    arg1[0x108] = rbp_33;
                    
                    if (i_25 == &data_14002495d[9])
                        break;
                    
                    rbp_33 = *i_25;
                    rdx_59 = 1;
                }
                
                rax_65 = rdx_59 + 1;
                i_25 = &i_25[1];
                *(arg1 + 0x100) = rax_65;
                arg1[rdx_59] = rbp_33;
                arg1[0x108] = rbp_33;
            } while (&data_14002495d[9] != i_25);
            
            int32_t* rax_86 = *(arg1 + 0x170);
            int32_t* r8_100 = *(rsi + 0x10);
            
            if (rax_86)
            {
                arg5 = *(arg1 + 0x120);
                *(arg1 + 0x120) = &_Str;
                arg5 = _mm_unpacklo_epi64(arg5, rax_86);
                _Str = arg5;
            }
            
            sub_14000b540(arg1, 0x11, r8_100);
            
            if (*(arg1 + 0x170))
                *(arg1 + 0x120) = _Str;
            
            return;
            break;
        }
        case 0x37:
        {
            /* tailcall */
            return sub_14000cd80(arg1, 0x11, *(arg3 + 0x10));
        }
        case 0x38:
        {
            int32_t* rdi_11 = *(arg3 + 0x10);
            rsi_2 = *(arg3 + 0x18);
            int32_t rax_28 = *rdi_11;
            
            if (rax_28 != 0x33)
            {
                if (rax_28 == 0x35)
                {
                    sub_140003030(arg1, 0x28, arg5);
                    sub_140003030(arg1, 0x29, sub_14000b540(arg1, 0x11, *(rdi_11 + 0x10)));
                }
                else
                    sub_14000cd80(arg1, 0x11, rdi_11);
                
                /* tailcall */
                return sub_14000d470(arg1, 0x11, rsi_2);
            }
            
            char* rbp_60 = **(rdi_11 + 0x10);
            uint32_t rax_101 = *rbp_60;
            uint32_t rdx_95 = rax_101 - 0x61;
            
            if (rax_101 == 0x61)
            {
                uint32_t rdx_96 = rbp_60[1];
                rdx_95 = rdx_96 - 0x64;
                
                if (rdx_96 == 0x64)
                    rdx_95 = rbp_60[2];
            }
            
            int32_t rcx_125 = *rsi_2;
            
            if (!rdx_95 && rcx_125 == 3)
            {
                int32_t* rdx_121 = *(rsi_2 + 0x10);
                
                if (*rdx_121 == 1 && **(rsi_2 + 0x18) == 0x2a)
                    rsi_2 = rdx_121;
            }
            else if (rcx_125 == 0x3a)
            {
                sub_14000d470(arg1, 0x11, *(rsi_2 + 0x10));
                /* tailcall */
                return sub_14000cd80(arg1, 0x11, rdi_11);
            }
            
            if (rax_101 == 0x73)
            {
                if (rbp_60[1] == 0x5a && !rbp_60[2])
                    /* tailcall */
                    return sub_140003360(arg1, sub_140002e20(sub_1400031d0(arg1, rsi_2)));
                
                if (rax_101 == 0x73 && rbp_60[1] == 0x50)
                {
                    int32_t r8_157 = 0;
                    
                    if (!rbp_60[2])
                    {
                        while (*rsi_2 == 0x30)
                        {
                            int32_t* rax_128 = *(rsi_2 + 0x10);
                            
                            if (!rax_128)
                                break;
                            
                            if (*rax_128 != 0x4d)
                                r8_157 += 1;
                            else
                            {
                                int32_t* rax_129;
                                int32_t r8_158;
                                rax_129 = sub_1400031d0(arg1, *(rax_128 + 0x10));
                                int32_t rdx_119 = 0;
                                
                                if (rax_129)
                                {
                                    while (*rax_129 == 0x30)
                                    {
                                        if (!*(rax_129 + 0x10))
                                            break;
                                        
                                        rax_129 = *(rax_129 + 0x18);
                                        rdx_119 += 1;
                                        
                                        if (!rax_129)
                                            break;
                                    }
                                }
                                
                                r8_157 = r8_158 + rdx_119;
                            }
                            
                            rsi_2 = *(rsi_2 + 0x18);
                            
                            if (!rsi_2)
                                break;
                        }
                        
                        /* tailcall */
                        return sub_140003360(arg1, r8_157);
                    }
                }
            }
            
            int512_t zmm0_13 = sub_14000cd80(arg1, 0x11, rdi_11);
            uint32_t rax_105 = *rbp_60;
            int32_t* r8_1;
            
            if (rax_105 == 0x67 && rbp_60[1] == 0x73)
                r8_1 = rsi_2;
            
            if (rax_105 == 0x67 && rbp_60[1] == 0x73 && !rbp_60[2])
                /* tailcall */
                return sub_14000b540(arg1, 0x11, r8_1);
            
            if (rax_105 != 0x73 || rbp_60[1] != 0x74)
            {
                if (rax_105 != 0x6e || rbp_60[1] != 0x78 || rbp_60[2])
                    /* tailcall */
                    return sub_14000d470(arg1, 0x11, rsi_2);
            }
            else if (rbp_60[2] && (rax_105 != 0x6e || rbp_60[1] != 0x78 || rbp_60[2]))
                /* tailcall */
                return sub_14000d470(arg1, 0x11, rsi_2);
            
            sub_140003030(arg1, 0x28, zmm0_13);
            /* tailcall */
            return sub_140003030(arg1, 0x29, sub_14000b540(arg1, 0x11, rsi_2));
        }
        case 0x39:
        {
            if (**(arg3 + 0x18) != 0x3a)
                goto label_140006df0;
            
            int32_t* r8_50 = *(arg3 + 0x10);
            char* rax_47 = **(r8_50 + 0x10);
            char rax_121;
            
            if (rax_47[1] == 0x63)
                rax_121 = *rax_47;
            
            if (rax_47[1] == 0x63 && (rax_121 - 0x72 <= 1 || rax_121 - 0x63 <= 1))
            {
                sub_140003030(arg1, 0x3c, sub_14000cd80(arg1, 0x11, r8_50));
                sub_14000b540(arg1, 0x11, *(*(rsi + 0x18) + 0x10));
                sub_140003100(arg1, ">(");
                /* tailcall */
                return sub_140003030(arg1, 0x29, 
                    sub_14000b540(arg1, 0x11, *(*(rsi + 0x18) + 0x18)));
            }
            
            if (sub_14000d650(arg1, 0x11, rsi))
                return;
            
            int512_t zmm0_6;
            rax = sub_14000dab0(arg1, 0x11, rsi);
            
            if (rax)
                return;
            
            int32_t* rax_48 = *(rsi + 0x10);
            
            if (*rax_48 == 0x33)
            {
                void* rdx_122 = *(rax_48 + 0x10);
                
                if (*(rdx_122 + 0x10) == 1 && **(rdx_122 + 8) == 0x3e)
                {
                    sub_140003030(arg1, 0x28, zmm0_6);
                    rax_48 = *(rsi + 0x10);
                }
            }
            
            int32_t rax_50 = strcmp(**(rax_48 + 0x10), "cl");
            int32_t* r8_53 = *(*(rsi + 0x18) + 0x10);
            
            if (rax_50 || *r8_53 != 3)
                sub_14000d470(arg1, 0x11, r8_53);
            else
            {
                if (**(r8_53 + 0x18) != 0x2a)
                    *(arg1 + 0x130) = 1;
                
                sub_14000d470(arg1, 0x11, *(r8_53 + 0x10));
            }
            
            int32_t* rdi_20 = *(rsi + 0x10);
            char* _Str1 = **(rdi_20 + 0x10);
            int32_t rax_52;
            int512_t zmm0_7;
            rax_52 = strcmp(_Str1, "ix");
            
            if (!rax_52)
            {
                sub_140003030(arg1, 0x5b, zmm0_7);
                zmm0_2 = sub_14000b540(arg1, 0x11, *(*(rsi + 0x18) + 0x18));
                sub_140003030(arg1, 0x5d, zmm0_2);
            }
            else
            {
                if (strcmp(_Str1, "cl"))
                    sub_14000cd80(arg1, 0x11, rdi_20);
                
                zmm0_2 = sub_14000d470(arg1, 0x11, *(*(rsi + 0x18) + 0x18));
            }
            
            rax = *(rsi + 0x10);
            
            if (*rax != 0x33)
                return;
            
            rax = *(rax + 0x10);
            
            if (*(rax + 0x10) != 1)
                return;
            
            if (**(rax + 8) != 0x3e)
                return;
            
            /* tailcall */
            return sub_140003030(arg1, 0x29, zmm0_2);
        }
        case 0x3b:
        {
            rax = *(arg3 + 0x18);
            
            if (*rax != 0x3c || **(rax + 0x18) != 0x3d)
                goto label_140006df0;
            
            if (sub_14000d650(arg1, 0x11, arg3))
                return;
            
            if (sub_14000dab0(arg1, 0x11, rsi))
                return;
            
            void* rax_42 = *(rsi + 0x18);
            int32_t* r12_6 = *(rsi + 0x10);
            int32_t* rdi_19 = *(rax_42 + 0x10);
            void* rax_43 = *(rax_42 + 0x18);
            int32_t* rbp_22 = *(rax_43 + 0x10);
            rsi_2 = *(rax_43 + 0x18);
            
            if (!strcmp(**(r12_6 + 0x10), "qu"))
            {
                sub_14000d470(arg1, 0x11, rdi_19);
                sub_14000cd80(arg1, 0x11, r12_6);
                sub_14000d470(arg1, 0x11, rbp_22);
                sub_140003100(arg1, " : ");
                /* tailcall */
                return sub_14000d470(arg1, 0x11, rsi_2);
            }
            
            sub_140003100(arg1, "new ");
            
            if (*(rdi_19 + 0x10))
                sub_140003030(arg1, 0x20, sub_14000d470(arg1, 0x11, rdi_19));
            
            sub_14000b540(arg1, 0x11, rbp_22);
            
            if (rsi_2)
                /* tailcall */
                return sub_14000d470(arg1, 0x11, rsi_2);
            
            return;
            break;
        }
        case 0x3e:
        case 0x3f:
        {
            int32_t* r8_8 = *(arg3 + 0x10);
            int32_t rdi_4;
            
            if (*r8_8 != 0x28)
                rdi_4 = 0;
            else
            {
                rdi_4 = *(*(r8_8 + 0x10) + 0x1c);
                
                if (rdi_4 > 6)
                {
                    if (rdi_4 == 7)
                    {
                        int32_t* rax_107 = *(rsi + 0x18);
                        
                        if (!*rax_107 && rax_107[6] == 1 && r9_1 == 0x3e)
                        {
                            char rax_109 = **(rax_107 + 0x10);
                            
                            if (rax_109 == 0x30)
                                /* tailcall */
                                return sub_140003100(arg1, "false");
                            
                            if (rax_109 == 0x31)
                                /* tailcall */
                                return sub_140003100(arg1, "true");
                        }
                    }
                }
                else if (rdi_4)
                {
                    int32_t* rax_11 = *(rsi + 0x18);
                    
                    if (!*rax_11)
                    {
                        if (r9_1 == 0x3f)
                        {
                            sub_140003030(arg1, 0x2d, arg5);
                            rax_11 = *(rsi + 0x18);
                        }
                        
                        uint64_t rdi_40 = rdi_4 - 2;
                        rax = sub_14000b540(arg1, 0x11, rax_11);
                        
                        if (rdi_40 > 4)
                            return;
                        
                        switch (rdi_40)
                        {
                            case 0:
                            {
                                /* tailcall */
                                return sub_140003030(arg1, 0x75, zmm0_2);
                            }
                            case 1:
                            {
                                /* tailcall */
                                return sub_140003030(arg1, 0x6c, zmm0_2);
                            }
                            case 2:
                            {
                                /* tailcall */
                                return sub_140003100(arg1, "ul");
                            }
                            case 3:
                            {
                                /* tailcall */
                                return sub_140003100(arg1, "ll");
                            }
                            case 4:
                            {
                                /* tailcall */
                                return sub_140003100(arg1, "ull");
                            }
                        }
                    }
                }
            }
            
            int64_t rax_12 = *(arg1 + 0x100);
            int64_t rdx_7;
            
            if (rax_12 == 0xff)
            {
                int64_t r8_147 = *(arg1 + 0x118);
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, r8_147);
                *(arg1 + 0x140) += 1;
                r8_8 = *(rsi + 0x10);
                rax_12 = 0;
                rdx_7 = 1;
            }
            else
                rdx_7 = rax_12 + 1;
            
            *(arg1 + 0x100) = rdx_7;
            arg1[rax_12] = 0x28;
            arg1[0x108] = 0x28;
            int512_t zmm0_1 = sub_14000b540(arg1, 0x11, r8_8);
            int64_t rax_13 = *(arg1 + 0x100);
            int64_t rdx_8;
            
            if (rax_13 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_8 = 1;
                rax_13 = 0;
            }
            else
                rdx_8 = rax_13 + 1;
            
            *(arg1 + 0x100) = rdx_8;
            arg1[rax_13] = 0x29;
            arg1[0x108] = 0x29;
            
            if (*rsi == 0x3f)
                sub_140003030(arg1, 0x2d, zmm0_1);
            
            if (rdi_4 != 8)
                /* tailcall */
                return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
            
            sub_140003030(arg1, 0x5b, zmm0_1);
            /* tailcall */
            return sub_140003030(arg1, 0x5d, sub_14000b540(arg1, 0x11, *(rsi + 0x18)));
        }
        case 0x40:
        {
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            int64_t rax_25 = *(arg1 + 0x100);
            int64_t rdx_26;
            
            if (rax_25 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_26 = 1;
                rax_25 = 0;
            }
            else
                rdx_26 = rax_25 + 1;
            
            *(arg1 + 0x100) = rdx_26;
            arg1[rax_25] = 0x28;
            arg1[0x108] = 0x28;
            r8_24 = *(rsi + 0x18);
        label_140007816:
            sub_14000b540(arg1, 0x11, r8_24);
            rax = *(arg1 + 0x100);
            void* rdx_27;
            
            if (rax == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_27 = 1;
                rax = nullptr;
            }
            else
                rdx_27 = rax + 1;
            
            *(arg1 + 0x100) = rdx_27;
            *(arg1 + rax) = 0x29;
            arg1[0x108] = 0x29;
            return;
            break;
        }
        case 0x41:
        {
            char const* const i_26 = "java resource ";
            int64_t rax_57 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_25 = *i_26;
                int64_t rdx_49;
                
                if (rax_57 != 0xff)
                    rdx_49 = rax_57;
                else
                {
                    i_26 = &i_26[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_25;
                    arg1[0x108] = rbp_25;
                    
                    if (i_26 == &data_140024991[0xe])
                        break;
                    
                    rbp_25 = *i_26;
                    rdx_49 = 1;
                }
                
                rax_57 = rdx_49 + 1;
                i_26 = &i_26[1];
                *(arg1 + 0x100) = rax_57;
                arg1[rdx_49] = rbp_25;
                arg1[0x108] = rbp_25;
            } while (i_26 != &data_140024991[0xe]);
            
            goto label_140006e10;
        }
        case 0x42:
        {
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0x43:
        {
            rsi_5 = arg3[4];
        label_140007e85:
            rax = *(arg1 + 0x100);
            void* rdx_40;
            
            if (rax == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_40 = 1;
                rax = nullptr;
            }
            else
                rdx_40 = rax + 1;
            
            *(arg1 + 0x100) = rdx_40;
            *(arg1 + rax) = rsi_5;
            arg1[0x108] = rsi_5;
            return;
            break;
        }
        case 0x44:
        {
            sub_140002f60(&_Str, &data_140024478, arg3[4]);
            rax = strlen(&_Str);
            
            if (rax)
            {
                void* rdx_39 = *(arg1 + 0x100);
                int128_t* rsi_4 = &_Str;
                int64_t rbp_17 = &_Str + rax;
                
                do
                {
                    char rdi_17 = *rsi_4;
                    
                    if (rdx_39 != 0xff)
                        rax = rdx_39;
                    else
                    {
                        rsi_4 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_17;
                        arg1[0x108] = rdi_17;
                        
                        if (rbp_17 == rsi_4)
                            break;
                        
                        rdi_17 = *rsi_4;
                        rax = 1;
                    }
                    
                    rdx_39 = rax + 1;
                    rsi_4 += 1;
                    *(arg1 + 0x100) = rdx_39;
                    *(arg1 + rax) = rdi_17;
                    arg1[0x108] = rdi_17;
                } while (rbp_17 != rsi_4);
            }
            
            return;
            break;
        }
        case 0x45:
        {
            char const* const i_27 = "decltype (";
            int64_t rax_59 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_27 = *i_27;
                int64_t rdx_51;
                
                if (rax_59 != 0xff)
                    rdx_51 = rax_59;
                else
                {
                    i_27 = &i_27[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_27;
                    arg1[0x108] = rbp_27;
                    
                    if (i_27 == &data_1400249a0[0xa])
                        break;
                    
                    rbp_27 = *i_27;
                    rdx_51 = 1;
                }
                
                rax_59 = rdx_51 + 1;
                i_27 = &i_27[1];
                *(arg1 + 0x100) = rax_59;
                arg1[rdx_51] = rbp_27;
                arg1[0x108] = rbp_27;
            } while (i_27 != &data_1400249a0[0xa]);
            
            r8_24 = *(rsi + 0x10);
            goto label_140007816;
        }
        case 0x46:
        {
            char const* const i_28 = "global constructors keyed to ";
            int64_t rax_58 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_26 = *i_28;
                int64_t rdx_50;
                
                if (rax_58 != 0xff)
                    rdx_50 = rax_58;
                else
                {
                    i_28 = &i_28[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_26;
                    arg1[0x108] = rbp_26;
                    
                    if (&data_1400249bb[0x1d] == i_28)
                        break;
                    
                    rbp_26 = *i_28;
                    rdx_50 = 1;
                }
                
                rax_58 = rdx_50 + 1;
                i_28 = &i_28[1];
                *(arg1 + 0x100) = rax_58;
                arg1[rdx_50] = rbp_26;
                arg1[0x108] = rbp_26;
            } while (&data_1400249bb[0x1d] != i_28);
            
            goto label_140006e10;
        }
        case 0x47:
        {
            char const* const i_29 = "global destructors keyed to ";
            int64_t rax_19 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_7 = *i_29;
                int64_t rdx_17;
                
                if (rax_19 != 0xff)
                    rdx_17 = rax_19;
                else
                {
                    i_29 = &i_29[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_7;
                    arg1[0x108] = rbp_7;
                    
                    if (&data_1400249d9[0x1c] == i_29)
                        break;
                    
                    rbp_7 = *i_29;
                    rdx_17 = 1;
                }
                
                rax_19 = rdx_17 + 1;
                i_29 = &i_29[1];
                *(arg1 + 0x100) = rax_19;
                arg1[rdx_17] = rbp_7;
                arg1[0x108] = rbp_7;
            } while (&data_1400249d9[0x1c] != i_29);
            
            goto label_140006e10;
        }
        case 0x48:
        {
            char const* const rdi_7 = "{lambda";
            int64_t rax_18 = *(arg1 + 0x100);
            int64_t rdx_89;
            int32_t* rbp_54;
            int32_t r12_11;
            
            while (true)
            {
                char const rbp_6 = *rdi_7;
                int64_t rdx_16;
                int32_t rdx_88;
                
                if (rax_18 != 0xff)
                {
                    rdx_16 = rax_18;
                label_140007443:
                    rax_18 = rdx_16 + 1;
                    rdi_7 = &rdi_7[1];
                    *(arg1 + 0x100) = rax_18;
                    arg1[rdx_16] = rbp_6;
                    arg1[0x108] = rbp_6;
                    
                    if (&data_1400249f6[7] == rdi_7)
                    {
                        int64_t rdx_87 = *(arg1 + 0x120);
                        rbp_54 = *(rsi + 0x10);
                        int64_t var_d0_1 = 0;
                        r12_11 = *(arg1 + 0x138);
                        *(arg1 + 0x138) = 0;
                        var_d8 = rdx_87;
                        *(arg1 + 0x120) = &var_d8;
                        rdx_88 = 1;
                        
                        if (rbp_54 && *rbp_54 == 0x59)
                            goto label_14000b02c;
                        
                    label_14000a09a:
                        *(arg1 + 0x138) = rdx_88;
                        
                        if (rax_18 == 0xff)
                        {
                            arg1[0xff] = 0;
                            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                            *(arg1 + 0x140) += 1;
                            rdx_89 = 1;
                            rax_18 = 0;
                            break;
                        }
                    }
                    else
                        continue;
                }
                else
                {
                    rdi_7 = &rdi_7[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_6;
                    arg1[0x108] = rbp_6;
                    
                    if (&data_1400249f6[7] != rdi_7)
                    {
                        rbp_6 = *rdi_7;
                        rdx_16 = 1;
                        goto label_140007443;
                    }
                    
                    int64_t rax_113 = *(arg1 + 0x120);
                    rbp_54 = *(rsi + 0x10);
                    int64_t var_d0_2 = 0;
                    r12_11 = *(arg1 + 0x138);
                    *(arg1 + 0x138) = 0;
                    var_d8 = rax_113;
                    *(arg1 + 0x120) = &var_d8;
                    
                    if (rbp_54 && *rbp_54 == 0x59)
                    {
                    label_14000b02c:
                        int32_t* var_d0_3 = rbp_54;
                        sub_140003030(arg1, 0x3c, arg5);
                        int32_t* i_30 = *(rbp_54 + 0x10);
                        
                        if (i_30)
                        {
                            do
                            {
                                int32_t rax_126 = *(arg1 + 0x138);
                                *(arg1 + 0x138) = rax_126 + 1;
                                
                                if (rax_126)
                                    sub_140003100(arg1, ", ");
                                
                                sub_14000b540(arg1, 0x11, i_30);
                                int64_t rax_125 = *(arg1 + 0x100);
                                int64_t rdx_115;
                                
                                if (rax_125 == 0xff)
                                {
                                    arg1[0xff] = 0;
                                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                                    *(arg1 + 0x140) += 1;
                                    rdx_115 = 1;
                                    rax_125 = 0;
                                }
                                else
                                    rdx_115 = rax_125 + 1;
                                
                                *(arg1 + 0x100) = rdx_115;
                                arg1[rax_125] = 0x20;
                                arg1[0x108] = 0x20;
                                int32_t rdx_116 = *i_30;
                                
                                if (rdx_116 == 0x5d)
                                {
                                    i_30 = *(i_30 + 0x10);
                                    rdx_116 = *i_30;
                                }
                                
                                arg5 = sub_140003450(arg1, rdx_116, *(arg1 + 0x138) - 1);
                                i_30 = *(i_30 + 0x18);
                            } while (i_30);
                        }
                        
                        sub_140003030(arg1, 0x3e, arg5);
                        rbp_54 = *(rbp_54 + 0x18);
                        rdx_88 = *(arg1 + 0x138) + 1;
                        rax_18 = *(arg1 + 0x100);
                        goto label_14000a09a;
                    }
                    
                    *(arg1 + 0x138) = 1;
                    rax_18 = 1;
                }
                rdx_89 = rax_18 + 1;
                break;
            }
            
            *(arg1 + 0x100) = rdx_89;
            arg1[rax_18] = 0x28;
            void* const i_31 = &data_1400249fe;
            arg1[0x108] = 0x28;
            sub_14000b540(arg1, 0x11, rbp_54);
            int64_t rax_90 = var_d8;
            *(arg1 + 0x138) = r12_11;
            *(arg1 + 0x120) = rax_90;
            int64_t rax_91 = *(arg1 + 0x100);
            
            do
            {
                char rbp_55 = *i_31;
                int64_t rdx_90;
                
                if (rax_91 != 0xff)
                    rdx_90 = rax_91;
                else
                {
                    i_31 += 1;
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_55;
                    arg1[0x108] = rbp_55;
                    
                    if (&data_140024a00 == i_31)
                        break;
                    
                    rbp_55 = *i_31;
                    rdx_90 = 1;
                }
                
                rax_91 = rdx_90 + 1;
                i_31 += 1;
                *(arg1 + 0x100) = rax_91;
                arg1[rdx_90] = rbp_55;
                arg1[0x108] = rbp_55;
            } while (&data_140024a00 != i_31);
            
            int128_t* rsi_10 = &_Str;
            sub_140002f60(&_Str, &data_140024478, rsi[6] + 1);
            uint64_t rax_93 = strlen(&_Str);
            rdx_81 = *(arg1 + 0x100);
            
            if (rax_93)
            {
                void* rbp_56 = &_Str + rax_93;
                
                do
                {
                    char rdi_34 = *rsi_10;
                    void* rax_94;
                    
                    if (rdx_81 != 0xff)
                        rax_94 = rdx_81;
                    else
                    {
                        rsi_10 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_34;
                        arg1[0x108] = rdi_34;
                        
                        if (rbp_56 == rsi_10)
                        {
                        label_14000a5fe:
                            rdx_81 = 1;
                            goto label_140009c0d;
                        }
                        
                        rdi_34 = *rsi_10;
                        rax_94 = 1;
                    }
                    
                    rdx_81 = rax_94 + 1;
                    rsi_10 += 1;
                    *(arg1 + 0x100) = rdx_81;
                    *(arg1 + rax_94) = rdi_34;
                    arg1[0x108] = rdi_34;
                } while (rsi_10 != rbp_56);
            }
            
            goto label_140009c07;
        }
        case 0x4a:
        {
            char const* const i_32 = "{unnamed type#";
            int64_t rax_17 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_5 = *i_32;
                int64_t rdx_15;
                
                if (rax_17 != 0xff)
                    rdx_15 = rax_17;
                else
                {
                    i_32 = &i_32[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_5;
                    arg1[0x108] = rbp_5;
                    
                    if (&data_140024a01[0xe] == i_32)
                        break;
                    
                    rbp_5 = *i_32;
                    rdx_15 = 1;
                }
                
                rax_17 = rdx_15 + 1;
                i_32 = &i_32[1];
                *(arg1 + 0x100) = rax_17;
                arg1[rdx_15] = rbp_5;
                arg1[0x108] = rbp_5;
            } while (&data_140024a01[0xe] != i_32);
            
            int128_t* rsi_8 = &_Str;
            sub_140002f60(&_Str, &data_140024478, rsi[4] + 1);
            uint64_t rax_84 = strlen(&_Str);
            rdx_81 = *(arg1 + 0x100);
            
            if (rax_84)
            {
                void* rbp_50 = &_Str + rax_84;
                
                do
                {
                    char rdi_30 = *rsi_8;
                    void* rax_85;
                    
                    if (rdx_81 != 0xff)
                        rax_85 = rdx_81;
                    else
                    {
                        rsi_8 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rdi_30;
                        arg1[0x108] = rdi_30;
                        
                        if (rbp_50 == rsi_8)
                            goto label_14000a5fe;
                        
                        rdi_30 = *rsi_8;
                        rax_85 = 1;
                    }
                    
                    rdx_81 = rax_85 + 1;
                    rsi_8 += 1;
                    *(arg1 + 0x100) = rdx_81;
                    *(arg1 + rax_85) = rdi_30;
                    arg1[0x108] = rdi_30;
                } while (rbp_50 != rsi_8);
            }
            
        label_140009c07:
            
            if (rdx_81 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rax = 1;
                rdx_81 = nullptr;
            }
            else
            {
            label_140009c0d:
                rax = rdx_81 + 1;
            }
            
            *(arg1 + 0x100) = rax;
            *(arg1 + rdx_81) = 0x7d;
            arg1[0x108] = 0x7d;
            return;
            break;
        }
        case 0x4b:
        {
            char const* const i_33 = "transaction clone for ";
            int64_t rax_16 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_4 = *i_33;
                int64_t rdx_14;
                
                if (rax_16 != 0xff)
                    rdx_14 = rax_16;
                else
                {
                    i_33 = &i_33[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_4;
                    arg1[0x108] = rbp_4;
                    
                    if (&data_140024922[0x16] == i_33)
                        break;
                    
                    rbp_4 = *i_33;
                    rdx_14 = 1;
                }
                
                rax_16 = rdx_14 + 1;
                i_33 = &i_33[1];
                *(arg1 + 0x100) = rax_16;
                arg1[rdx_14] = rbp_4;
                arg1[0x108] = rbp_4;
            } while (i_33 != &data_140024922[0x16]);
            
            goto label_140006e10;
        }
        case 0x4c:
        {
            char const* const i_34 = "non-transaction clone for ";
            int64_t rax_41 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_21 = *i_34;
                int64_t rdx_45;
                
                if (rax_41 != 0xff)
                    rdx_45 = rax_41;
                else
                {
                    i_34 = &i_34[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_21;
                    arg1[0x108] = rbp_21;
                    
                    if (&data_140024939[0x1a] == i_34)
                        break;
                    
                    rbp_21 = *i_34;
                    rdx_45 = 1;
                }
                
                rax_41 = rdx_45 + 1;
                i_34 = &i_34[1];
                *(arg1 + 0x100) = rax_41;
                arg1[rdx_45] = rbp_21;
                arg1[0x108] = rbp_21;
            } while (i_34 != &data_140024939[0x1a]);
            
            goto label_140006e10;
        }
        case 0x4d:
        {
            int32_t r14_1 = *(arg1 + 0x138);
            int32_t* r12_5 = *(arg3 + 0x10);
            int32_t rbp_20;
            
            if (!r14_1)
            {
                rbp_20 = 0;
                rax = sub_1400031d0(arg1, r12_5);
            }
            
            if (r14_1 || !rax)
            {
                sub_14000d470(arg1, 0x11, r12_5);
                /* tailcall */
                return sub_140003100(arg1, "...");
            }
            
            while (true)
            {
                if (*rax == 0x30 && *(rax + 0x10))
                {
                    rax = *(rax + 0x18);
                    rbp_20 += 1;
                    
                    if (rax)
                        continue;
                }
                else if (!rbp_20)
                    break;
                
                while (true)
                {
                    *(arg1 + 0x13c) = r14_1;
                    r14_1 += 1;
                    sub_14000b540(arg1, 0x11, r12_5);
                    
                    if (r14_1 == rbp_20)
                        break;
                    
                    int64_t rax_40 = *(arg1 + 0x100);
                    void* const i_35 = &data_14002479d;
                    
                    do
                    {
                        char rdi_18 = *i_35;
                        int64_t rdx_44;
                        
                        if (rax_40 != 0xff)
                            rdx_44 = rax_40;
                        else
                        {
                            i_35 += 1;
                            arg1[0xff] = 0;
                            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                            *(arg1 + 0x140) += 1;
                            *(arg1 + 0x100) = 1;
                            *arg1 = rdi_18;
                            arg1[0x108] = rdi_18;
                            
                            if (&data_14002479f == i_35)
                                break;
                            
                            rdi_18 = *i_35;
                            rdx_44 = 1;
                        }
                        
                        rax_40 = rdx_44 + 1;
                        i_35 += 1;
                        *(arg1 + 0x100) = rax_40;
                        arg1[rdx_44] = rdi_18;
                        arg1[0x108] = rdi_18;
                    } while (&data_14002479f != i_35);
                }
                
                break;
            }
            
            return;
            break;
        }
        case 0x4e:
        {
            char const* const i_36 = "[abi:";
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            int64_t rax_39 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_19 = *i_36;
                int64_t rdx_42;
                
                if (rax_39 != 0xff)
                    rdx_42 = rax_39;
                else
                {
                    i_36 = &i_36[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_19;
                    arg1[0x108] = rbp_19;
                    
                    if (&data_140024797[5] == i_36)
                        break;
                    
                    rbp_19 = *i_36;
                    rdx_42 = 1;
                }
                
                rax_39 = rdx_42 + 1;
                i_36 = &i_36[1];
                *(arg1 + 0x100) = rax_39;
                arg1[rdx_42] = rbp_19;
                arg1[0x108] = rbp_19;
            } while (&data_140024797[5] != i_36);
            
            sub_14000b540(arg1, 0x11, *(rsi + 0x18));
            rax = *(arg1 + 0x100);
            break;
        }
        case 0x50:
        {
            char const* const i_37 = " [clone ";
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            int64_t rax_38 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_18 = *i_37;
                int64_t rdx_41;
                
                if (rax_38 != 0xff)
                    rdx_41 = rax_38;
                else
                {
                    i_37 = &i_37[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_18;
                    arg1[0x108] = rbp_18;
                    
                    if (&data_140024a10[8] == i_37)
                        break;
                    
                    rbp_18 = *i_37;
                    rdx_41 = 1;
                }
                
                rax_38 = rdx_41 + 1;
                i_37 = &i_37[1];
                *(arg1 + 0x100) = rax_38;
                arg1[rdx_41] = rbp_18;
                arg1[0x108] = rbp_18;
            } while (&data_140024a10[8] != i_37);
            
            sub_14000b540(arg1, 0x11, *(rsi + 0x18));
            rax = *(arg1 + 0x100);
            break;
        }
        case 0x51:
        {
            char const* const i_38 = "[friend]";
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            rax = *(arg1 + 0x100);
            
            do
            {
                char const rdi_24 = *i_38;
                void* rdx_63;
                
                if (rax != 0xff)
                    rdx_63 = rax;
                else
                {
                    i_38 = &i_38[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_24;
                    arg1[0x108] = rdi_24;
                    
                    if (&data_140024a19[8] == i_38)
                        break;
                    
                    rdi_24 = *i_38;
                    rdx_63 = 1;
                }
                
                rax = rdx_63 + 1;
                i_38 = &i_38[1];
                *(arg1 + 0x100) = rax;
                *(arg1 + rdx_63) = rdi_24;
                arg1[0x108] = rdi_24;
            } while (&data_140024a19[8] != i_38);
            
            return;
            break;
        }
        case 0x54:
        {
            int64_t rax_67 = *(arg1 + 0x100);
            int64_t rdx_61;
            
            if (rax_67 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_61 = 1;
                rax_67 = 0;
            }
            else
                rdx_61 = rax_67 + 1;
            
            *(arg1 + 0x100) = rdx_61;
            arg1[rax_67] = 0x5b;
            arg1[0x108] = 0x5b;
            
            while (true)
            {
                sub_14000b540(arg1, 0x11, *(rsi + 0x10));
                rsi = *(rsi + 0x18);
                rax = *(arg1 + 0x100);
                
                if (!rsi)
                    break;
                
                void* const i_39 = &data_14002479d;
                
                do
                {
                    char rbp_35 = *i_39;
                    void* rdx_62;
                    
                    if (rax != 0xff)
                        rdx_62 = rax;
                    else
                    {
                        i_39 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rbp_35;
                        arg1[0x108] = rbp_35;
                        
                        if (&data_14002479f == i_39)
                            break;
                        
                        rbp_35 = *i_39;
                        rdx_62 = 1;
                    }
                    
                    rax = rdx_62 + 1;
                    i_39 += 1;
                    *(arg1 + 0x100) = rax;
                    *(arg1 + rdx_62) = rbp_35;
                    arg1[0x108] = rbp_35;
                } while (&data_14002479f != i_39);
            }
            break;
        }
        case 0x55:
        case 0x56:
        {
            int32_t* r8_7 = *(arg3 + 0x10);
            char rdi_3;
            
            if (r8_7)
            {
                sub_14000b540(arg1, 0x11, r8_7);
                
                if (*rsi == 0x56)
                    goto label_14000a56e;
                
                if (*(rsi + 0x10))
                {
                    rdi_3 = 0x2e;
                    goto label_140007008;
                }
            }
            else if (r9_1 == 0x56)
            {
            label_14000a56e:
                rdi_3 = 0x3a;
            label_140007008:
                int64_t rax_9 = *(arg1 + 0x100);
                int64_t rdx_6;
                
                if (rax_9 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_6 = 1;
                    rax_9 = 0;
                }
                else
                    rdx_6 = rax_9 + 1;
                
                *(arg1 + 0x100) = rdx_6;
                arg1[rax_9] = rdi_3;
                arg1[0x108] = rdi_3;
            }
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0x57:
        {
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            int64_t rax_4 = *(arg1 + 0x100);
            int64_t rdx_3;
            
            if (rax_4 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_3 = 1;
                rax_4 = 0;
            }
            else
                rdx_3 = rax_4 + 1;
            
            *(arg1 + 0x100) = rdx_3;
            arg1[rax_4] = 0x40;
            arg1[0x108] = 0x40;
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0x58:
        {
            char const* const i_40 = "initializer for module ";
            int64_t rax_62 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_28 = *i_40;
                int64_t rdx_54;
                
                if (rax_62 != 0xff)
                    rdx_54 = rax_62;
                else
                {
                    i_40 = &i_40[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_28;
                    arg1[0x108] = rbp_28;
                    
                    if (&data_1400247df[0x17] == i_40)
                        break;
                    
                    rbp_28 = *i_40;
                    rdx_54 = 1;
                }
                
                rax_62 = rdx_54 + 1;
                i_40 = &i_40[1];
                *(arg1 + 0x100) = rax_62;
                arg1[rdx_54] = rbp_28;
                arg1[0x108] = rbp_28;
            } while (&data_1400247df[0x17] != i_40);
            
            goto label_140006e10;
        }
        case 0x59:
        {
            int64_t rax_60 = *(arg1 + 0x100);
            int64_t rdx_52;
            
            if (rax_60 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_52 = 1;
                rax_60 = 0;
            }
            else
                rdx_52 = rax_60 + 1;
            
            *(arg1 + 0x100) = rdx_52;
            int32_t r12_7 = 0;
            arg1[rax_60] = 0x3c;
            arg1[0x108] = 0x3c;
            int32_t* i_41 = *(rsi + 0x10);
            
            if (i_41)
            {
                do
                {
                    if (r12_7)
                    {
                        int64_t rax_61 = *(arg1 + 0x100);
                        
                        for (void* const j = &data_14002479d; j != &data_14002479f; )
                        {
                            char rdi_21 = *j;
                            int64_t rdx_53;
                            
                            if (rax_61 != 0xff)
                                rdx_53 = rax_61;
                            else
                            {
                                j += 1;
                                arg1[0xff] = 0;
                                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                                *(arg1 + 0x140) += 1;
                                *(arg1 + 0x100) = 1;
                                *arg1 = rdi_21;
                                arg1[0x108] = rdi_21;
                                
                                if (j == &data_14002479f)
                                    break;
                                
                                rdi_21 = *j;
                                rdx_53 = 1;
                            }
                            
                            rax_61 = rdx_53 + 1;
                            j += 1;
                            *(arg1 + 0x100) = rax_61;
                            arg1[rdx_53] = rdi_21;
                            arg1[0x108] = rdi_21;
                        }
                    }
                    
                    r12_7 += 1;
                    sub_14000b540(arg1, 0x11, i_41);
                    i_41 = *(i_41 + 0x18);
                } while (i_41);
            }
            
            rax = *(arg1 + 0x100);
            void* rdx_83 = rax + 1;
            
            if (rax == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_83 = 1;
                rax = nullptr;
            }
            
            *(arg1 + 0x100) = rdx_83;
            *(arg1 + rax) = 0x3e;
            arg1[0x108] = 0x3e;
            return;
            break;
        }
        case 0x5a:
        {
            char const* const i_42 = "typename";
            rax = *(arg1 + 0x100);
            
            do
            {
                char const rdi_25 = *i_42;
                void* rdx_65;
                
                if (rax != 0xff)
                    rdx_65 = rax;
                else
                {
                    i_42 = &i_42[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_25;
                    arg1[0x108] = rdi_25;
                    
                    if (&data_140024a22[8] == i_42)
                        break;
                    
                    rdi_25 = *i_42;
                    rdx_65 = 1;
                }
                
                rax = rdx_65 + 1;
                i_42 = &i_42[1];
                *(arg1 + 0x100) = rax;
                *(arg1 + rdx_65) = rdi_25;
                arg1[0x108] = rdi_25;
            } while (&data_140024a22[8] != i_42);
            
            return;
            break;
        }
        case 0x5c:
        {
            char const* const i_43 = "template";
            int64_t rax_68 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_36 = *i_43;
                int64_t rdx_64;
                
                if (rax_68 != 0xff)
                    rdx_64 = rax_68;
                else
                {
                    i_43 = &i_43[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_36;
                    arg1[0x108] = rbp_36;
                    
                    if (&data_140024a2b[8] == i_43)
                        break;
                    
                    rbp_36 = *i_43;
                    rdx_64 = 1;
                }
                
                rax_68 = rdx_64 + 1;
                i_43 = &i_43[1];
                *(arg1 + 0x100) = rax_68;
                arg1[rdx_64] = rbp_36;
                arg1[0x108] = rbp_36;
            } while (i_43 != &data_140024a2b[8]);
            
            char const* const i_44 = " class";
            sub_14000b540(arg1, 0x11, *(rsi + 0x10));
            rax = *(arg1 + 0x100);
            
            do
            {
                char const rdi_32 = *i_44;
                void* rdx_84;
                
                if (rax != 0xff)
                    rdx_84 = rax;
                else
                {
                    i_44 = &i_44[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_32;
                    arg1[0x108] = rdi_32;
                    
                    if (&data_140024a34[6] == i_44)
                        break;
                    
                    rdi_32 = *i_44;
                    rdx_84 = 1;
                }
                
                rax = rdx_84 + 1;
                i_44 = &i_44[1];
                *(arg1 + 0x100) = rax;
                *(arg1 + rdx_84) = rdi_32;
                arg1[0x108] = rdi_32;
            } while (&data_140024a34[6] != i_44);
            
            return;
            break;
        }
        case 0x5d:
        {
            void* const i_45 = &data_1400249ab;
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            rax = *(arg1 + 0x100);
            
            do
            {
                char rdi_28 = *i_45;
                void* rdx_75;
                
                if (rax != 0xff)
                    rdx_75 = rax;
                else
                {
                    i_45 += 1;
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_28;
                    arg1[0x108] = rdi_28;
                    
                    if (i_45 == &data_1400249ae)
                        break;
                    
                    rdi_28 = *i_45;
                    rdx_75 = 1;
                }
                
                rax = rdx_75 + 1;
                i_45 += 1;
                *(arg1 + 0x100) = rax;
                *(arg1 + rdx_75) = rdi_28;
                arg1[0x108] = rdi_28;
            } while (i_45 != &data_1400249ae);
            
            return;
            break;
        }
        case 0x5e:
        {
            char const* const i_46 = " requires ";
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            int64_t rax_77 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_46 = *i_46;
                int64_t rdx_74;
                
                if (rax_77 != 0xff)
                    rdx_74 = rax_77;
                else
                {
                    i_46 = &i_46[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_46;
                    arg1[0x108] = rbp_46;
                    
                    if (i_46 == &data_140024a3b[0xa])
                        break;
                    
                    rbp_46 = *i_46;
                    rdx_74 = 1;
                }
                
                rax_77 = rdx_74 + 1;
                i_46 = &i_46[1];
                *(arg1 + 0x100) = rax_77;
                arg1[rdx_74] = rbp_46;
                arg1[0x108] = rbp_46;
            } while (i_46 != &data_140024a3b[0xa]);
            
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(rsi + 0x18));
        }
        case 0x5f:
        {
            int64_t* rax_69 = *(arg3 + 0x10);
            int64_t r12_8 = rax_69[1];
            char* rdi_27 = *rax_69;
            
            if (r12_8)
            {
                int64_t rax_70 = *(arg1 + 0x100);
                void* r12_9 = &rdi_27[r12_8];
                
                do
                {
                    char rbp_39 = *rdi_27;
                    int64_t rdx_67;
                    
                    if (rax_70 != 0xff)
                        rdx_67 = rax_70;
                    else
                    {
                        rdi_27 = &rdi_27[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rbp_39;
                        arg1[0x108] = rbp_39;
                        
                        if (r12_9 == rdi_27)
                            break;
                        
                        rbp_39 = *rdi_27;
                        rdx_67 = 1;
                    }
                    
                    rax_70 = rdx_67 + 1;
                    rdi_27 = &rdi_27[1];
                    *(arg1 + 0x100) = rax_70;
                    arg1[rdx_67] = rbp_39;
                    arg1[0x108] = rbp_39;
                } while (rdi_27 != r12_9);
            }
            
            int128_t* rdi_31 = &_Str;
            sub_140002f60(&_Str, &data_140024478, rsi[6]);
            rax = strlen(&_Str);
            
            if (rax)
            {
                void* rdx_82 = *(arg1 + 0x100);
                int64_t r12_10 = &_Str + rax;
                
                do
                {
                    char rbp_51 = *rdi_31;
                    
                    if (rdx_82 != 0xff)
                        rax = rdx_82;
                    else
                    {
                        rdi_31 += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rbp_51;
                        arg1[0x108] = rbp_51;
                        
                        if (r12_10 == rdi_31)
                            break;
                        
                        rbp_51 = *rdi_31;
                        rax = 1;
                    }
                    
                    rdx_82 = rax + 1;
                    rdi_31 += 1;
                    *(arg1 + 0x100) = rdx_82;
                    *(arg1 + rax) = rbp_51;
                    arg1[0x108] = rbp_51;
                } while (r12_10 != rdi_31);
            }
            
            rsi_5 = *(rsi + 0x1a);
            
            if (!rsi_5)
                return;
            
            goto label_140007e85;
        }
    }
    
    void* rdx_79;
    
    if (rax == 0xff)
    {
        arg1[0xff] = 0;
        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
        *(arg1 + 0x140) += 1;
        rdx_79 = 1;
        rax = nullptr;
    }
    else
        rdx_79 = rax + 1;
    
    *(arg1 + 0x100) = rdx_79;
    *(arg1 + rax) = 0x5d;
    arg1[0x108] = 0x5d;
}

void sub_14000b540(char* arg1, int64_t arg2, int32_t* arg3)
{
    if (arg3)
    {
        int32_t rax = arg3[1];
        
        if (rax <= 1)
        {
            int32_t rdx = *(arg1 + 0x134);
            
            if (rdx <= 0x400)
            {
                int512_t zmm0;
                zmm0 = arg3;
                arg3[1] = rax + 1;
                zmm0 = zmm0 | *(arg1 + 0x148) << 0x40;
                *(arg1 + 0x134) = rdx + 1;
                int128_t var_28;
                *(arg1 + 0x148) = &var_28;
                var_28 = zmm0;
                int64_t rdi;
                sub_140006d10(arg1, 0x11, arg3, rdi, zmm0);
                *(arg1 + 0x148) = *var_28[8];
                arg3[1] -= 1;
                *(arg1 + 0x134) -= 1;
                return;
            }
        }
    }
    
    *(arg1 + 0x130) = 1;
}

void* sub_14000b5e0(char* arg1, int64_t arg2, int32_t* arg3)
{
    uint64_t rax_1 = *arg3 - 3;
    
    if (rax_1 > 0x50)
        /* tailcall */
        return sub_14000b540(arg1, 0x11, arg3);
    
    void* rax_3 = jump_table_140024c44[rax_1] + &jump_table_140024c44;
    int64_t rax_5;
    int64_t rdx_5;
    int32_t* r8;
    
    switch (rax_3)
    {
        case 0x14000b64a:
        {
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000b658:
        {
            /* tailcall */
            return sub_14000b540(arg1, 0x11, arg3);
        }
        case 0x14000b678:
        {
            char const* const i = " restrict";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_1 = *i;
                void* rdx_2;
                
                if (rax_3 != 0xff)
                    rdx_2 = rax_3;
                else
                {
                    i = &i[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_1;
                    arg1[0x108] = rdi_1;
                    
                    if (i == &data_140024bdc[9])
                        break;
                    
                    rdi_1 = *i;
                    rdx_2 = 1;
                }
                
                rax_3 = rdx_2 + 1;
                i = &i[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_2) = rdi_1;
                arg1[0x108] = rdi_1;
            } while (&data_140024bdc[9] != i);
            
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000b740:
        {
            char const* const i_1 = " volatile";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_2 = *i_1;
                void* rdx_3;
                
                if (rax_3 != 0xff)
                    rdx_3 = rax_3;
                else
                {
                    i_1 = &i_1[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_2;
                    arg1[0x108] = rdi_2;
                    
                    if (&data_140024be6[9] == i_1)
                        break;
                    
                    rdi_2 = *i_1;
                    rdx_3 = 1;
                }
                
                rax_3 = rdx_3 + 1;
                i_1 = &i_1[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_3) = rdi_2;
                arg1[0x108] = rdi_2;
            } while (&data_140024be6[9] != i_1);
            
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000b800:
        {
            char const* const i_2 = " const";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_3 = *i_2;
                void* rdx_4;
                
                if (rax_3 != 0xff)
                    rdx_4 = rax_3;
                else
                {
                    i_2 = &i_2[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_3;
                    arg1[0x108] = rdi_3;
                    
                    if (&data_140024bf0[6] == i_2)
                        break;
                    
                    rdi_3 = *i_2;
                    rdx_4 = 1;
                }
                
                rax_3 = rdx_4 + 1;
                i_2 = &i_2[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_4) = rdi_3;
                arg1[0x108] = rdi_3;
            } while (&data_140024bf0[6] != i_2);
            
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000b8c0:
        {
            rax_5 = *(arg1 + 0x100);
        label_14000b8c7:
            
            if (rax_5 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_5 = 1;
                rax_5 = 0;
            }
            else
                rdx_5 = rax_5 + 1;
            break;
        }
        case 0x14000b8f8:
        {
            char const* const i_3 = " throw";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_1 = *i_3;
                void* rdx_6;
                
                if (rax_3 != 0xff)
                    rdx_6 = rax_3;
                else
                {
                    i_3 = &i_3[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_1;
                    arg1[0x108] = rbp_1;
                    
                    if (i_3 == &data_140024c13[6])
                        goto label_14000c180;
                    
                    rbp_1 = *i_3;
                    rdx_6 = 1;
                }
                
                rax_3 = rdx_6 + 1;
                i_3 = &i_3[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_6) = rbp_1;
                arg1[0x108] = rbp_1;
            } while (&data_140024c13[6] != i_3);
            
        label_14000bff0:
            r8 = *(arg3 + 0x18);
            
            if (!r8)
            {
            labelid_9:
                return rax_3;
            }
            
            void* rdx_18;
            
            if (rax_3 == 0xff)
            {
                int64_t r8_21 = *(arg1 + 0x118);
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, r8_21);
                *(arg1 + 0x140) += 1;
                r8 = *(arg3 + 0x18);
                rax_3 = nullptr;
                rdx_18 = 1;
            }
            else
            {
            label_14000c009:
                rdx_18 = rax_3 + 1;
            }
            
            *(arg1 + 0x100) = rdx_18;
            *(arg1 + rax_3) = 0x28;
            arg1[0x108] = 0x28;
        label_14000b61c:
            sub_14000b540(arg1, 0x11, r8);
            rax_3 = *(arg1 + 0x100);
            void* rdx;
            
            if (rax_3 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx = 1;
                rax_3 = nullptr;
            }
            else
                rdx = rax_3 + 1;
            
            *(arg1 + 0x100) = rdx;
            *(arg1 + rax_3) = 0x29;
            arg1[0x108] = 0x29;
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000b9c0:
        {
            void* const rdx_7 = *(arg1 + 0x100);
            
            if (rdx_7 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rax_3 = 1;
                rdx_7 = nullptr;
            }
            else
                rax_3 = rdx_7 + 1;
            
            *(arg1 + 0x100) = rax_3;
            *(arg1 + rdx_7) = 0x20;
            arg1[0x108] = 0x20;
            goto label_14000ba77;
        }
        case 0x14000b9f0:
        {
            int64_t rax_6 = *(arg1 + 0x100);
            int64_t rdx_8;
            
            if (rax_6 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_8 = 1;
                rax_6 = 0;
            }
            else
                rdx_8 = rax_6 + 1;
            
            *(arg1 + 0x100) = rdx_8;
            arg1[rax_6] = 0x20;
            arg1[0x108] = 0x20;
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(arg3 + 0x18));
        }
        case 0x14000ba28:
        {
            rax_3 = *(arg1 + 0x100);
            void* rdx_9;
            
            if (rax_3 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_9 = 1;
                rax_3 = nullptr;
            }
            else
                rdx_9 = rax_3 + 1;
            
            *(arg1 + 0x100) = rdx_9;
            *(arg1 + rax_3) = 0x2a;
            arg1[0x108] = 0x2a;
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000ba60:
        {
            /* tailcall */
            return sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
        }
        case 0x14000ba70:
        {
            rax_3 = *(arg1 + 0x100);
        label_14000ba77:
            void* const i_4 = &data_140024c1a;
            
            do
            {
                char rdi_4 = *i_4;
                void* rdx_10;
                
                if (rax_3 != 0xff)
                    rdx_10 = rax_3;
                else
                {
                    i_4 += 1;
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_4;
                    arg1[0x108] = rdi_4;
                    
                    if (&data_140024c1c == i_4)
                        break;
                    
                    rdi_4 = *i_4;
                    rdx_10 = 1;
                }
                
                rax_3 = rdx_10 + 1;
                i_4 += 1;
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_10) = rdi_4;
                arg1[0x108] = rdi_4;
            } while (&data_140024c1c != i_4);
            
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000bb40:
        {
            char const* const i_5 = " _Complex";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_5 = *i_5;
                void* rdx_11;
                
                if (rax_3 != 0xff)
                    rdx_11 = rax_3;
                else
                {
                    i_5 = &i_5[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_5;
                    arg1[0x108] = rdi_5;
                    
                    if (&data_140024c1d[9] == i_5)
                        break;
                    
                    rdi_5 = *i_5;
                    rdx_11 = 1;
                }
                
                rax_3 = rdx_11 + 1;
                i_5 = &i_5[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_11) = rdi_5;
                arg1[0x108] = rdi_5;
            } while (&data_140024c1d[9] != i_5);
            
        labelid_9:
            return rax_3;
            break;
        }
        case 0x14000bc00:
        {
            char const* const i_6 = " _Imaginary";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_6 = *i_6;
                void* rdx_12;
                
                if (rax_3 != 0xff)
                    rdx_12 = rax_3;
                else
                {
                    i_6 = &i_6[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_6;
                    arg1[0x108] = rdi_6;
                    
                    if (i_6 == &data_140024c27[0xb])
                        break;
                    
                    rdi_6 = *i_6;
                    rdx_12 = 1;
                }
                
                rax_3 = rdx_12 + 1;
                i_6 = &i_6[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_12) = rdi_6;
                arg1[0x108] = rdi_6;
            } while (i_6 != &data_140024c27[0xb]);
            
        label_14000b654:
            return rax_3;
            break;
        }
        case 0x14000bcc0:
        {
            if (arg1[0x108] != 0x28)
            {
                int64_t rax_8 = *(arg1 + 0x100);
                int64_t rdx_19;
                
                if (rax_8 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_19 = 1;
                    rax_8 = 0;
                }
                else
                    rdx_19 = rax_8 + 1;
                
                *(arg1 + 0x100) = rdx_19;
                arg1[rax_8] = 0x20;
                arg1[0x108] = 0x20;
            }
            
            void* const i_7 = &data_140024c33;
            sub_14000b540(arg1, 0x11, *(arg3 + 0x10));
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char rdi_7 = *i_7;
                void* rdx_13;
                
                if (rax_3 != 0xff)
                    rdx_13 = rax_3;
                else
                {
                    i_7 += 1;
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_7;
                    arg1[0x108] = rdi_7;
                    
                    if (&data_140024c36 == i_7)
                        break;
                    
                    rdi_7 = *i_7;
                    rdx_13 = 1;
                }
                
                rax_3 = rdx_13 + 1;
                i_7 += 1;
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_13) = rdi_7;
                arg1[0x108] = rdi_7;
            } while (&data_140024c36 != i_7);
            
        label_14000b654_1:
            return rax_3;
            break;
        }
        case 0x14000bd80:
        {
            char const* const i_8 = " __vector(";
            int64_t rax_7 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_2 = *i_8;
                int64_t rdx_14;
                
                if (rax_7 != 0xff)
                    rdx_14 = rax_7;
                else
                {
                    i_8 = &i_8[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_2;
                    arg1[0x108] = rbp_2;
                    
                    if (&data_140024c37[0xa] == i_8)
                        break;
                    
                    rbp_2 = *i_8;
                    rdx_14 = 1;
                }
                
                rax_7 = rdx_14 + 1;
                i_8 = &i_8[1];
                *(arg1 + 0x100) = rax_7;
                arg1[rdx_14] = rbp_2;
                arg1[0x108] = rbp_2;
            } while (&data_140024c37[0xa] != i_8);
            
            r8 = *(arg3 + 0x10);
            goto label_14000b61c;
        }
        case 0x14000be40:
        {
            char const* const i_9 = " transaction_safe";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rdi_8 = *i_9;
                void* rdx_15;
                
                if (rax_3 != 0xff)
                    rdx_15 = rax_3;
                else
                {
                    i_9 = &i_9[1];
                    arg1[0xff] = 0;
                    rax_3 = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rdi_8;
                    arg1[0x108] = rdi_8;
                    
                    if (&data_140024bf7[0x11] == i_9)
                        break;
                    
                    rdi_8 = *i_9;
                    rdx_15 = 1;
                }
                
                rax_3 = rdx_15 + 1;
                i_9 = &i_9[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_15) = rdi_8;
                arg1[0x108] = rdi_8;
            } while (i_9 != &data_140024bf7[0x11]);
            
        label_14000b654_2:
            return rax_3;
            break;
        }
        case 0x14000bf00:
        {
            char const* const i_10 = " noexcept";
            rax_3 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_3 = *i_10;
                void* rdx_16;
                
                if (rax_3 != 0xff)
                    rdx_16 = rax_3;
                else
                {
                    i_10 = &i_10[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_3;
                    arg1[0x108] = rbp_3;
                    
                    if (i_10 == &data_140024c09[9])
                    {
                    label_14000c180:
                        r8 = *(arg3 + 0x18);
                        rax_3 = 1;
                        
                        if (r8)
                            goto label_14000c009;
                        
                        goto label_14000b654_2;
                    }
                    
                    rbp_3 = *i_10;
                    rdx_16 = 1;
                }
                
                rax_3 = rdx_16 + 1;
                i_10 = &i_10[1];
                *(arg1 + 0x100) = rax_3;
                *(arg1 + rdx_16) = rbp_3;
                arg1[0x108] = rbp_3;
            } while (i_10 != &data_140024c09[9]);
            
            goto label_14000bff0;
        }
        case 0x14000bfc0:
        {
            int64_t rdx_17 = *(arg1 + 0x100);
            
            if (rdx_17 != 0xff)
            {
                rax_5 = rdx_17 + 1;
                *(arg1 + 0x100) = rax_5;
                arg1[rdx_17] = 0x20;
                arg1[0x108] = 0x20;
                goto label_14000b8c7;
            }
            
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *arg1 = 0x20;
            rax_5 = 1;
            *(arg1 + 0x140) += 1;
            rdx_5 = rax_5 + 1;
            break;
        }
    }
    
    *(arg1 + 0x100) = rdx_5;
    arg1[rax_5] = 0x26;
    arg1[0x108] = 0x26;
    return rax_5;
}

int64_t sub_14000c200(char* arg1, int64_t arg2, void* arg3, void** arg4)
{
    int64_t* rbp = arg4;
    int64_t rax_2;
    int64_t rdx_4;
    int32_t rsi;
    int64_t r13;
    
    if (!arg4)
    {
        rsi = 0;
    label_14000c27b:
        r13 = *(arg1 + 0x128);
        *(arg1 + 0x128) = 0;
        sub_14000c610(arg1, 0x11, rbp, 0);
        rdx_4 = *(arg1 + 0x100);
        
        if (rdx_4 == 0xff)
        {
        label_14000c3d9:
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *(arg1 + 0x140) += 1;
            rax_2 = 1;
            rdx_4 = 0;
        }
        else
            rax_2 = rdx_4 + 1;
    }
    else
    {
        void** rax_1 = arg4;
        rsi = 0;
        
        while (true)
        {
            if (rax_1[2])
                goto label_14000c27b;
            
            int32_t rcx = *rax_1[1];
            
            if (rcx <= 0x2c)
            {
                int64_t rdx_2 = 1 << rcx;
                int64_t rax_4;
                char rdx_6;
                int64_t rdx_7;
                
                if (rdx_2 & 0x10c40e000000)
                {
                    rdx_6 = arg1[0x108];
                label_14000c347:
                    rax_4 = *(arg1 + 0x100);
                    
                    if (rdx_6 == 0x20)
                        goto label_14000c357;
                    
                    if (rax_4 != 0xff)
                    {
                        *(arg1 + 0x100) = rax_4 + 1;
                        arg1[rax_4] = 0x20;
                        rax_4 += 1;
                        arg1[0x108] = 0x20;
                    label_14000c357:
                        
                        if (rax_4 == 0xff)
                            goto label_14000c4ec;
                        
                        goto label_14000c363;
                    }
                    
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *arg1 = 0x20;
                    rax_4 = 1;
                    *(arg1 + 0x140) += 1;
                label_14000c363:
                    rdx_7 = rax_4 + 1;
                label_14000c367:
                    *(arg1 + 0x100) = rdx_7;
                    arg1[rax_4] = 0x28;
                    r13 = *(arg1 + 0x128);
                    arg1[0x108] = 0x28;
                    *(arg1 + 0x128) = 0;
                    sub_14000c610(arg1, 0x11, rbp, 0);
                    int64_t rax_5 = *(arg1 + 0x100);
                    
                    if (rax_5 == 0xff)
                    {
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *arg1 = 0x29;
                        rdx_4 = 1;
                        *(arg1 + 0x140) += 1;
                        break;
                    }
                    
                    rdx_4 = rax_5 + 1;
                    *(arg1 + 0x100) = rdx_4;
                    arg1[rax_5] = 0x29;
                    arg1[0x108] = 0x29;
                    
                    if (rdx_4 != 0xff)
                        break;
                    
                    goto label_14000c3d9;
                }
                
                if (rdx_2 & 0x3800000000)
                {
                    rdx_6 = arg1[0x108];
                    
                    if ((rdx_6 & 0xfd) != 0x28)
                        goto label_14000c347;
                    
                    rax_4 = *(arg1 + 0x100);
                    
                    if (rax_4 != 0xff)
                        goto label_14000c363;
                    
                label_14000c4ec:
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_7 = 1;
                    rax_4 = 0;
                    goto label_14000c367;
                }
                
                int32_t rdx_3;
                rdx_3 = rcx == 0x21;
                rsi |= rdx_3;
            }
            
            rax_1 = *rax_1;
            
            if (!rax_1)
                goto label_14000c27b;
        }
        
        rax_2 = rdx_4 + 1;
    }
    
    *(arg1 + 0x100) = rax_2;
    arg1[rdx_4] = 0x28;
    arg1[0x108] = 0x28;
    int64_t rax_3;
    int64_t rdx_5;
    int32_t* r8_1;
    
    if (rsi)
    {
        char const* const rsi_1 = "this ";
        
        while (true)
        {
            char const rdi_1 = *rsi_1;
            int64_t rdx_8;
            
            if (rax_2 != 0xff)
                rdx_8 = rax_2;
            else
            {
                rsi_1 = &rsi_1[1];
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_1;
                arg1[0x108] = rdi_1;
                
                if (&data_140024d88[5] == rsi_1)
                    break;
                
                rdi_1 = *rsi_1;
                rdx_8 = 1;
            }
            
            rax_2 = rdx_8 + 1;
            rsi_1 = &rsi_1[1];
            *(arg1 + 0x100) = rax_2;
            arg1[rdx_8] = rdi_1;
            arg1[0x108] = rdi_1;
            
            if (&data_140024d88[5] == rsi_1)
                goto label_14000c2d2;
        }
        
        r8_1 = *(arg3 + 0x18);
        
        if (r8_1)
            goto label_14000c2e4;
        
        rax_3 = 1;
        rdx_5 = rax_3 + 1;
    }
    else
    {
    label_14000c2d2:
        r8_1 = *(arg3 + 0x18);
        
        if (!r8_1)
            goto label_14000c2e9;
        
    label_14000c2e4:
        sub_14000b540(arg1, 0x11, r8_1);
    label_14000c2e9:
        rax_3 = *(arg1 + 0x100);
        
        if (rax_3 == 0xff)
        {
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *(arg1 + 0x140) += 1;
            rdx_5 = 1;
            rax_3 = 0;
        }
        else
            rdx_5 = rax_3 + 1;
    }
    *(arg1 + 0x100) = rdx_5;
    arg1[rax_3] = 0x29;
    arg1[0x108] = 0x29;
    int64_t result = sub_14000c610(arg1, 0x11, rbp, 1);
    *(arg1 + 0x128) = r13;
    return result;
}

void sub_14000c610(char* arg1, int64_t arg2, int64_t* arg3, int32_t arg4)
{
    int64_t* rbx = arg3;
    
    if (!arg3)
        return;
    
    while (!*(arg1 + 0x130))
    {
        if (!rbx[2])
        {
            int32_t* r8 = rbx[1];
            int32_t rax = *r8;
            int64_t rdi_1;
            
            if (arg4)
            {
            label_14000c684:
                rbx[2] = 1;
                rdi_1 = *(arg1 + 0x120);
                *(arg1 + 0x120) = rbx[3];
                
                if (rax == 0x2a)
                {
                    sub_14000c200(arg1, 0x11, r8, *rbx);
                    *(arg1 + 0x120) = rdi_1;
                    return;
                }
                
                if (rax == 0x2b)
                {
                    sub_14000ca40(arg1, 0x11, r8, *rbx);
                    *(arg1 + 0x120) = rdi_1;
                    return;
                }
                
                if (rax == 2)
                    goto label_14000c6fe;
                
                goto label_14000c6bc;
            }
            
            uint64_t rdx = rax - 0x1c;
            
            if (rdx > 0x37)
            {
                rbx[2] = 1;
                rdi_1 = *(arg1 + 0x120);
                *(arg1 + 0x120) = rbx[3];
                
                if (rax != 2)
                {
                label_14000c6bc:
                    sub_14000b5e0(arg1, 0x11, r8);
                    rbx = *rbx;
                    *(arg1 + 0x120) = rdi_1;
                    
                    if (!rbx)
                        break;
                    
                    continue;
                }
                
            label_14000c6fe:
                int64_t rbp_1 = *(arg1 + 0x128);
                int32_t* r8_1 = *(r8 + 0x10);
                *(arg1 + 0x128) = 0;
                sub_14000b540(arg1, 0x11, r8_1);
                *(arg1 + 0x128) = rbp_1;
                void* const i = &data_1400247a0;
                int64_t rax_1 = *(arg1 + 0x100);
                
                do
                {
                    char r12_1 = *i;
                    int64_t rdx_4;
                    
                    if (rax_1 != 0xff)
                        rdx_4 = rax_1;
                    else
                    {
                        i += 1;
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = r12_1;
                        arg1[0x108] = r12_1;
                        
                        if (&data_1400247a2 == i)
                        {
                            rax_1 = 1;
                            break;
                        }
                        
                        r12_1 = *i;
                        rdx_4 = 1;
                    }
                    
                    rax_1 = rdx_4 + 1;
                    i += 1;
                    *(arg1 + 0x100) = rax_1;
                    arg1[rdx_4] = r12_1;
                    arg1[0x108] = r12_1;
                } while (i != &data_1400247a2);
                
                int32_t* rbp_2 = *(rbx[1] + 0x18);
                int32_t rdx_6 = *rbp_2;
                
                if (rdx_6 == 0x49)
                {
                    for (char const* const i_1 = "{default arg#"; i_1 != &data_1400247a3[0xd]; )
                    {
                        char const r12_2 = *i_1;
                        int64_t rdx_8;
                        
                        if (rax_1 != 0xff)
                            rdx_8 = rax_1;
                        else
                        {
                            i_1 = &i_1[1];
                            arg1[0xff] = 0;
                            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                            *(arg1 + 0x140) += 1;
                            *(arg1 + 0x100) = 1;
                            *arg1 = r12_2;
                            arg1[0x108] = r12_2;
                            
                            if (i_1 == &data_1400247a3[0xd])
                                break;
                            
                            r12_2 = *i_1;
                            rdx_8 = 1;
                        }
                        
                        rax_1 = rdx_8 + 1;
                        i_1 = &i_1[1];
                        *(arg1 + 0x100) = rax_1;
                        arg1[rdx_8] = r12_2;
                        arg1[0x108] = r12_2;
                    }
                    
                    void _Str;
                    void* rbx_1 = &_Str;
                    sub_140002f60(&_Str, &data_140024478, rbp_2[6] + 1);
                    uint64_t rax_7 = strlen(&_Str);
                    int64_t rax_8 = *(arg1 + 0x100);
                    
                    if (rax_7)
                    {
                        void* r13_2 = rax_7 + &_Str;
                        
                        do
                        {
                            char r12_3 = *rbx_1;
                            int64_t rdx_9;
                            
                            if (rax_8 != 0xff)
                                rdx_9 = rax_8;
                            else
                            {
                                rbx_1 += 1;
                                arg1[0xff] = 0;
                                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                                *(arg1 + 0x140) += 1;
                                *(arg1 + 0x100) = 1;
                                *arg1 = r12_3;
                                arg1[0x108] = r12_3;
                                
                                if (r13_2 == rbx_1)
                                {
                                    rax_8 = 1;
                                    break;
                                }
                                
                                r12_3 = *rbx_1;
                                rdx_9 = 1;
                            }
                            
                            rax_8 = rdx_9 + 1;
                            rbx_1 += 1;
                            *(arg1 + 0x100) = rax_8;
                            arg1[rdx_9] = r12_3;
                            arg1[0x108] = r12_3;
                        } while (rbx_1 != r13_2);
                    }
                    
                    for (void* const i_2 = &data_1400247b1; i_2 != &data_1400247b4; )
                    {
                        char r12_4 = *i_2;
                        int64_t rdx_10;
                        
                        if (rax_8 != 0xff)
                            rdx_10 = rax_8;
                        else
                        {
                            i_2 += 1;
                            arg1[0xff] = 0;
                            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                            *(arg1 + 0x140) += 1;
                            *(arg1 + 0x100) = 1;
                            *arg1 = r12_4;
                            arg1[0x108] = r12_4;
                            
                            if (&data_1400247b4 == i_2)
                                break;
                            
                            r12_4 = *i_2;
                            rdx_10 = 1;
                        }
                        
                        rax_8 = rdx_10 + 1;
                        i_2 += 1;
                        *(arg1 + 0x100) = rax_8;
                        arg1[rdx_10] = r12_4;
                        arg1[0x108] = r12_4;
                    }
                    
                    rbp_2 = *(rbp_2 + 0x10);
                    rdx_6 = *rbp_2;
                }
                
                uint64_t rax_4 = rdx_6 - 0x1c;
                
                if (rax_4 <= 0x37)
                {
                    while (TEST_BITQ(0xc800000000003f, rax_4))
                    {
                        rbp_2 = *(rbp_2 + 0x10);
                        rax_4 = *rbp_2 - 0x1c;
                        
                        if (rax_4 > 0x37)
                            break;
                    }
                }
                
                sub_14000b540(arg1, 0x11, rbp_2);
                *(arg1 + 0x120) = rdi_1;
                return;
            }
            else if (!TEST_BITQ(0xc800000000003f, rdx))
                goto label_14000c684;
        }
        
        rbx = *rbx;
        
        if (!rbx)
            break;
    }
}

int64_t sub_14000ca40(char* arg1, int64_t arg2, void* arg3, int64_t* arg4)
{
    void** rax = arg4;
    int64_t rax_1;
    int64_t result;
    int64_t rdx;
    int32_t* r8_1;
    
    if (!arg4)
    {
    label_14000ca86:
        rax_1 = *(arg1 + 0x100);
    label_14000ca8d:
        int64_t rdx_1;
        
        if (rax_1 == 0xff)
        {
            int64_t r8_5 = *(arg1 + 0x118);
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, r8_5);
            arg1[0x108] = 0x5b;
            *arg1 = 0x5b20;
            r8_1 = *(arg3 + 0x10);
            result = 2;
            *(arg1 + 0x140) += 1;
            *(arg1 + 0x100) = 2;
            
            if (r8_1)
            {
            label_14000cae3:
                sub_14000b540(arg1, 0x11, r8_1);
                result = *(arg1 + 0x100);
            label_14000caef:
                
                if (result == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_1 = 1;
                    result = 0;
                }
                else
                    rdx_1 = result + 1;
            }
            else
                rdx_1 = result + 1;
        }
        else
        {
            rdx = rax_1 + 1;
            *(arg1 + 0x100) = rdx;
            arg1[rax_1] = 0x20;
            arg1[0x108] = 0x20;
            
            if (rdx != 0xff)
                goto label_14000cabc;
            
        label_14000cb54:
            int64_t r8_3 = *(arg1 + 0x118);
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, r8_3);
            *arg1 = 0x5b;
            arg1[0x108] = 0x5b;
            r8_1 = *(arg3 + 0x10);
            *(arg1 + 0x140) += 1;
            *(arg1 + 0x100) = 1;
            
            if (r8_1)
                goto label_14000cae3;
            
            result = 1;
            rdx_1 = result + 1;
        }
        
        *(arg1 + 0x100) = rdx_1;
        arg1[result] = 0x5d;
        arg1[0x108] = 0x5d;
        return result;
    }
    
    while (rax[2])
    {
        rax = *rax;
        
        if (!rax)
        {
            sub_14000c610(arg1, 0x11, arg4, 0);
            goto label_14000ca86;
        }
    }
    
    if (*rax[1] == 0x2b)
    {
        sub_14000c610(arg1, 0x11, arg4, 0);
        rdx = *(arg1 + 0x100);
        
        if (rdx != 0xff)
            goto label_14000cabc;
        
        goto label_14000cb54;
    }
    
    void* const i = &data_140024d8e;
    int64_t rax_3 = *(arg1 + 0x100);
    
    do
    {
        char r12_1 = *i;
        int64_t rdx_2;
        
        if (rax_3 != 0xff)
            rdx_2 = rax_3;
        else
        {
            i += 1;
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *(arg1 + 0x140) += 1;
            *(arg1 + 0x100) = 1;
            *arg1 = r12_1;
            arg1[0x108] = r12_1;
            
            if (&data_140024d90 == i)
                break;
            
            r12_1 = *i;
            rdx_2 = 1;
        }
        
        rax_3 = rdx_2 + 1;
        i += 1;
        *(arg1 + 0x100) = rax_3;
        arg1[rdx_2] = r12_1;
        arg1[0x108] = r12_1;
    } while (i != &data_140024d90);
    
    sub_14000c610(arg1, 0x11, arg4, 0);
    int64_t rdx_3 = *(arg1 + 0x100);
    
    if (rdx_3 != 0xff)
    {
        rax_1 = rdx_3 + 1;
        *(arg1 + 0x100) = rax_1;
        arg1[rdx_3] = 0x29;
        arg1[0x108] = 0x29;
        goto label_14000ca8d;
    }
    
    arg1[0xff] = 0;
    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
    *(arg1 + 0x140) += 1;
    *arg1 = 0x2029;
    rdx = 2;
label_14000cabc:
    result = rdx + 1;
    *(arg1 + 0x100) = result;
    arg1[rdx] = 0x5b;
    arg1[0x108] = 0x5b;
    r8_1 = *(arg3 + 0x10);
    
    if (!r8_1)
        goto label_14000caef;
    
    goto label_14000cae3;
}

void* sub_14000cd80(char* arg1, int64_t arg2, int32_t* arg3)
{
    if (*arg3 != 0x33)
        /* tailcall */
        return sub_14000b540(arg1, 0x11, arg3);
    
    void* result = *(arg3 + 0x10);
    int64_t rbp = *(result + 0x10);
    char* rsi = *(result + 8);
    
    if (rbp)
    {
        result = *(arg1 + 0x100);
        void* rbp_1 = &rsi[rbp];
        
        do
        {
            char rdi_1 = *rsi;
            void* result_1;
            
            if (result != 0xff)
                result_1 = result;
            else
            {
                rsi = &rsi[1];
                arg1[0xff] = 0;
                result = (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rdi_1;
                arg1[0x108] = rdi_1;
                
                if (rbp_1 == rsi)
                    break;
                
                rdi_1 = *rsi;
                result_1 = 1;
            }
            
            result = result_1 + 1;
            rsi = &rsi[1];
            *(arg1 + 0x100) = result;
            *(arg1 + result_1) = rdi_1;
            arg1[0x108] = rdi_1;
        } while (rsi != rbp_1);
    }
    
    return result;
}

int64_t sub_14000ce90(char* arg1, int64_t arg2, int64_t arg3)
{
    int32_t r11;
    int32_t r13;
    
    if (*arg1 == 0x5f && arg1[1] == 0x5a)
    {
        r11 = 0;
        r13 = 1;
    }
    else
    {
        int32_t rax_1;
        rax_1 = strncmp(arg1, "_GLOBAL_", 8);
        uint64_t rax_31;
        
        if (!rax_1)
            rax_31 = arg1[8] - 0x24;
        
        if (rax_1 || rax_31 > 0x3b)
        {
            r11 = 0;
            r13 = 0;
        }
        else
        {
            r11 = TEST_BITQ(0x800000000000401, rax_31);
            r13 = 0;
            
            if (r11)
            {
                char rax_32 = arg1[9];
                r11 = rax_32 == 0x44;
                r11 |= rax_32 == 0x49;
                
                if (r11)
                {
                    if (arg1[0xa] == 0x5f)
                    {
                        r13 = 2;
                        
                        if (rax_32 != 0x49)
                        {
                            r11 = 0;
                            r13 = 3;
                        }
                    }
                    else
                        r11 = 0;
                }
            }
        }
    }
    
    int32_t var_1d4 = 1;
    char* var_228;
    int64_t* var_230 = &var_228;
    
    while (true)
    {
        uint64_t rax_7 = strlen(arg1);
        var_228 = arg1;
        int32_t rcx_5 = rax_7;
        char var_218_1 = 0x11;
        int32_t r15_2 = rcx_5 * 2;
        void* var_220_1 = &arg1[rax_7];
        int32_t var_1fc_1 = r15_2;
        int32_t var_200_2 = 0;
        int32_t var_1ec_1 = rcx_5;
        int32_t var_1f0_1 = 0;
        int64_t var_1e8;
        __builtin_memset(&var_1e8, 0, 0x14);
        int32_t var_1d0_1 = 0;
        
        if (r15_2 > 0x800)
            return 0;
        
        uint64_t rax_10 = r15_2 << 5;
        sub_14000efc0(rax_10);
        void var_268;
        void* rsp_1 = &var_268 - rax_10;
        void* rax_12 = ((rcx_5 << 3) + 0xf) & 0xfffffffffffffff0;
        void* r8_2 = (rsp_1 + 0x27) & 0xfffffffffffffff8;
        uint64_t r14_3 = (rsp_1 + 0x27) >> 3;
        sub_14000efc0(rax_12);
        void* rsp_2 = rsp_1 - rax_12;
        void* var_208_1 = r8_2;
        void* var_1f8_1 = rsp_2 + 0x20;
        char rax_6;
        int32_t* r15_1;
        
        if (r13 != 1)
        {
            if (r13 - 2 > 1)
            {
                r15_1 = sub_140003a30(var_230);
                rax_6 = *arg1;
            }
            else
            {
                void* _Str = &arg1[0xb];
                void* _Str_1 = _Str;
                int32_t* r8;
                int64_t* r14_1;
                
                if (arg1[0xb] != 0x5f || arg1[0xc] != 0x5a)
                {
                    int32_t rax_3 = strlen(_Str);
                    
                    if (r15_2)
                    {
                        int32_t var_200_1 = 1;
                        r8 = r8_2;
                        *((r14_3 << 3) + 4) = 0;
                    }
                    
                    if (!r15_2 || rax_3 <= 0)
                    {
                        r8 = nullptr;
                        r14_1 = &var_228;
                    }
                    else
                    {
                        *(r14_3 << 3) = 0;
                        *((r14_3 << 3) + 0x10) = _Str;
                        *((r14_3 << 3) + 0x18) = rax_3;
                        r14_1 = var_230;
                    }
                }
                else
                {
                    r14_1 = &var_228;
                    char rax_28 = arg1[0xd];
                    
                    if (rax_28 == 0x47 || rax_28 == 0x54)
                    {
                        _Str = &arg1[0xd];
                        r8 = sub_140006060(&var_228);
                    }
                    else
                    {
                        _Str = &arg1[0xd];
                        r8 = sub_140006b30(&var_228, 0);
                    }
                }
                
                r15_1 = sub_140002940(r14_1, (r11 << 0x1f >> 0x1f) + 0x47, r8, 0);
                void* r11_4 = _Str + strlen(_Str);
                void* var_210_1 = r11_4;
                rax_6 = *r11_4;
            }
            
        label_14000cfba:
            
            if (!rax_6 && r15_1)
            {
                int64_t var_c8_1 = 0;
                char var_c0_1 = 0;
                int64_t var_a8;
                __builtin_memset(&var_a8, 0, 0x18);
                int32_t var_88_1 = 0;
                int64_t var_80_1 = 0;
                int64_t var_70_1 = 0;
                int64_t var_60_1 = 0;
                void var_1c8;
                sub_140002cd0(&var_1c8, r15_1);
                int64_t var_98;
                
                if (*var_98[4] <= 0x7ff)
                    *var_98[4] = 0;
                
                int64_t rax_36 = *var_70_1[4];
                int64_t var_58_1 = 0;
                int32_t rdx_5 = *var_60_1[4] * rax_36;
                
                if (rax_36 <= 0)
                    rax_36 = 1;
                
                int64_t rax_37 = rax_36 << 4;
                *var_60_1[4] = rdx_5;
                sub_14000efc0(rax_37);
                void* rsp_3 = rsp_2 - rax_37;
                int32_t rax_38 = 1;
                
                if (rdx_5 > 0)
                    rax_38 = rdx_5;
                
                int64_t rax_40 = rax_38 << 4;
                sub_14000efc0(rax_40);
                void* var_78_1 = rsp_3 + 0x20;
                void* var_68_1 = rsp_3 - rax_40 + 0x20;
                sub_14000b540(&var_1c8, 0x11, r15_1);
                *(&var_1c8 + var_c8_1) = 0;
                arg2(&var_1c8, var_c8_1, arg3);
                int64_t result;
                result = !var_98;
                return result;
            }
        }
        else if (*arg1 == 0x5f)
        {
            void* var_210_3 = &arg1[1];
            
            if (arg1[1] == 0x5a)
            {
                void* var_210_4 = &arg1[2];
                char rax_16 = arg1[2];
                
                if (rax_16 == 0x47 || rax_16 == 0x54)
                    r15_1 = sub_140006060(&var_228);
                else
                    r15_1 = sub_140006b30(&var_228, 1);
                
                void* rdx_1 = var_210_4;
                rax_6 = *rdx_1;
                
                if (var_218_1 & 1 && rax_6 == 0x2e)
                {
                    while (true)
                    {
                        char rax_18 = *(rdx_1 + 1);
                        
                        if (rax_18 - 0x61 > 0x19 && rax_18 != 0x5f && rax_18 - 0x30 > 9)
                        {
                            rax_6 = *var_210_4;
                            break;
                        }
                        
                        char i = *(rdx_1 + 2);
                        void* r11_5 = rdx_1 + 2;
                        
                        while (i - 0x61 <= 0x19 | i - 0x30 <= 9 || i == 0x5f)
                        {
                            i = *(r11_5 + 1);
                            r11_5 += 1;
                        }
                        
                        while (i == 0x2e)
                        {
                            while (true)
                            {
                                if (*(r11_5 + 1) - 0x30 > 9)
                                    goto label_14000d1b8;
                                
                                i = *(r11_5 + 2);
                                r11_5 += 2;
                                
                                if (i - 0x30 > 9)
                                    break;
                                
                                char rax_22;
                                
                                do
                                {
                                    rax_22 = *(r11_5 + 1);
                                    r11_5 += 1;
                                } while (rax_22 - 0x30 <= 9);
                                
                                if (rax_22 != 0x2e)
                                    goto label_14000d1b8;
                            }
                        }
                        
                    label_14000d1b8:
                        int64_t* rcx_12 = &var_228;
                        var_210_4 = r11_5;
                        r15_1 = sub_140002940(rcx_12, 0x50, r15_1, 
                            sub_140002a40(rcx_12, rdx_1, r11_5 - rdx_1));
                        rax_6 = *r11_5;
                        
                        if (rax_6 != 0x2e)
                            break;
                        
                        rdx_1 = r11_5;
                    }
                }
                
                goto label_14000cfba;
            }
        }
        
        if (var_1d4 != 0xffffffff)
            break;
        
        var_1d4 = 0;
    }
    
    return 0;
}

uint64_t sub_14000d470(char* arg1, int64_t arg2, int32_t* arg3)
{
    uint64_t rax = *arg3;
    uint64_t rax_1;
    int32_t rdx;
    int64_t rdi_1;
    
    if (rax > 0x32 || !TEST_BITQ(0x4000000000043, rax))
    {
        int64_t rax_2 = *(arg1 + 0x100);
        int64_t rax_4;
        int64_t rcx;
        
        if (rax_2 != 0xff)
        {
            rcx = rax_2 + 1;
            *(arg1 + 0x100) = rcx;
            arg1[rax_2] = 0x28;
            arg1[0x108] = 0x28;
            rax_1 = arg3[1];
            
            if (rax_1 <= 1)
                rdx = *(arg1 + 0x134);
            
            if (rax_1 <= 1 && rdx <= 0x400)
                goto label_14000d507;
            
            *(arg1 + 0x130) = 1;
        label_14000d582:
            
            if (rcx != 0xff)
                goto label_14000d58f;
            
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *(arg1 + 0x140) += 1;
            rax_4 = 1;
            rcx = 0;
            goto label_14000d593;
        }
        
        arg1[0xff] = 0;
        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
        *arg1 = 0x28;
        arg1[0x108] = 0x28;
        rax_1 = arg3[1];
        *(arg1 + 0x140) += 1;
        *(arg1 + 0x100) = 1;
        
        if (rax_1 <= 1)
            rdx = *(arg1 + 0x134);
        
        if (rax_1 > 1 || rdx > 0x400)
        {
            *(arg1 + 0x130) = 1;
            rcx = 1;
        label_14000d58f:
            rax_4 = rcx + 1;
        label_14000d593:
            *(arg1 + 0x100) = rax_4;
            arg1[rcx] = 0x29;
            arg1[0x108] = 0x29;
            return rax_4;
        }
        
    label_14000d507:
        rdi_1 = 0;
    label_14000d516:
        int512_t zmm0;
        zmm0 = arg3;
        arg3[1] = rax_1 + 1;
        zmm0 = zmm0 | *(arg1 + 0x148) << 0x40;
        *(arg1 + 0x134) = rdx + 1;
        int128_t var_28;
        *(arg1 + 0x148) = &var_28;
        var_28 = zmm0;
        sub_140006d10(arg1, 0x11, arg3, rdi_1, zmm0);
        rax_1 = *var_28[8];
        *(arg1 + 0x148) = rax_1;
        arg3[1] -= 1;
        *(arg1 + 0x134) -= 1;
        
        if (!rdi_1)
        {
            rcx = *(arg1 + 0x100);
            goto label_14000d582;
        }
    }
    else
    {
        rax_1 = arg3[1];
        
        if (rax_1 <= 1)
        {
            rdx = *(arg1 + 0x134);
            rdi_1 = 1;
        }
        
        if (rax_1 <= 1 && rdx <= 0x400)
            goto label_14000d516;
        
        *(arg1 + 0x130) = 1;
    }
    return rax_1;
}

int64_t sub_14000d650(char* arg1, int64_t arg2, void* arg3)
{
    char* rdx = **(*(arg3 + 0x10) + 0x10);
    
    if (*rdx != 0x66)
        return 0;
    
    void* rax_3 = *(arg3 + 0x18);
    int32_t* r13_1 = nullptr;
    int32_t* r14_1 = *(rax_3 + 0x18);
    int32_t* r12_1 = *(rax_3 + 0x10);
    
    if (*r14_1 == 0x3d)
    {
        r13_1 = *(r14_1 + 0x18);
        r14_1 = *(r14_1 + 0x10);
    }
    
    int32_t rdi_1 = *(arg1 + 0x13c);
    *(arg1 + 0x13c) = 0xffffffff;
    char rax_4 = rdx[1];
    int32_t* r8_4;
    
    if (rax_4 == 0x6c)
    {
        char const* const i = "(...";
        int64_t rax_10 = *(arg1 + 0x100);
        
        do
        {
            char const rbp_3 = *i;
            int64_t rdx_6;
            
            if (rax_10 != 0xff)
                rdx_6 = rax_10;
            else
            {
                i = &i[1];
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                *(arg1 + 0x100) = 1;
                *arg1 = rbp_3;
                arg1[0x108] = rbp_3;
                
                if (&data_140024d9a[4] == i)
                    break;
                
                rbp_3 = *i;
                rdx_6 = 1;
            }
            
            rax_10 = rdx_6 + 1;
            i = &i[1];
            *(arg1 + 0x100) = rax_10;
            arg1[rdx_6] = rbp_3;
            arg1[0x108] = rbp_3;
        } while (i != &data_140024d9a[4]);
        
        sub_14000cd80(arg1, 0x11, r12_1);
        r8_4 = r14_1;
    label_14000d7db:
        sub_14000d470(arg1, 0x11, r8_4);
        int64_t rax_7 = *(arg1 + 0x100);
        int64_t rdx_3;
        
        if (rax_7 == 0xff)
        {
            arg1[0xff] = 0;
            (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
            *(arg1 + 0x140) += 1;
            rdx_3 = 1;
            rax_7 = 0;
        }
        else
            rdx_3 = rax_7 + 1;
        
        *(arg1 + 0x100) = rdx_3;
        arg1[rax_7] = 0x29;
        arg1[0x108] = 0x29;
    }
    else
    {
        if (rax_4 == 0x72)
        {
            int64_t rax_8 = *(arg1 + 0x100);
            int64_t rdx_4;
            
            if (rax_8 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_4 = 1;
                rax_8 = 0;
            }
            else
                rdx_4 = rax_8 + 1;
            
            *(arg1 + 0x100) = rdx_4;
            arg1[rax_8] = 0x28;
            char const* const i_1 = "...)";
            arg1[0x108] = 0x28;
            sub_14000d470(arg1, 0x11, r14_1);
            sub_14000cd80(arg1, 0x11, r12_1);
            int64_t rax_9 = *(arg1 + 0x100);
            
            do
            {
                char const rbp_2 = *i_1;
                int64_t rdx_5;
                
                if (rax_9 != 0xff)
                    rdx_5 = rax_9;
                else
                {
                    i_1 = &i_1[1];
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_2;
                    arg1[0x108] = rbp_2;
                    
                    if (&data_140024d9f[4] == i_1)
                        break;
                    
                    rbp_2 = *i_1;
                    rdx_5 = 1;
                }
                
                rax_9 = rdx_5 + 1;
                i_1 = &i_1[1];
                *(arg1 + 0x100) = rax_9;
                arg1[rdx_5] = rbp_2;
                arg1[0x108] = rbp_2;
            } while (&data_140024d9f[4] != i_1);
        }
        
        if (rax_4 == 0x4c || rax_4 == 0x52)
        {
            int64_t rax_5 = *(arg1 + 0x100);
            int64_t rdx_1;
            
            if (rax_5 == 0xff)
            {
                arg1[0xff] = 0;
                (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                *(arg1 + 0x140) += 1;
                rdx_1 = 1;
                rax_5 = 0;
            }
            else
                rdx_1 = rax_5 + 1;
            
            *(arg1 + 0x100) = rdx_1;
            arg1[rax_5] = 0x28;
            void* const i_2 = &data_1400249ab;
            arg1[0x108] = 0x28;
            sub_14000d470(arg1, 0x11, r14_1);
            sub_14000cd80(arg1, 0x11, r12_1);
            int64_t rax_6 = *(arg1 + 0x100);
            
            do
            {
                char rbp_1 = *i_2;
                int64_t rdx_2;
                
                if (rax_6 != 0xff)
                    rdx_2 = rax_6;
                else
                {
                    i_2 += 1;
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    *(arg1 + 0x100) = 1;
                    *arg1 = rbp_1;
                    arg1[0x108] = rbp_1;
                    
                    if (&data_1400249ae == i_2)
                        break;
                    
                    rbp_1 = *i_2;
                    rdx_2 = 1;
                }
                
                rax_6 = rdx_2 + 1;
                i_2 += 1;
                *(arg1 + 0x100) = rax_6;
                arg1[rdx_2] = rbp_1;
                arg1[0x108] = rbp_1;
            } while (&data_1400249ae != i_2);
            
            sub_14000cd80(arg1, 0x11, r12_1);
            r8_4 = r13_1;
            goto label_14000d7db;
        }
    }
    *(arg1 + 0x13c) = rdi_1;
    return 1;
}

uint64_t sub_14000dab0(char* arg1, int64_t arg2, int32_t* arg3)
{
    int32_t rsi = 0;
    
    if ((*arg3 & 0xfffffffd) == 0x39)
    {
        void* rcx = *(arg3 + 0x10);
        int32_t rax_2 = sub_140002f90(rcx);
        rsi = rax_2;
        
        if (rax_2)
        {
            void* rax_3 = *(arg3 + 0x18);
            void* r13_1 = **(rcx + 0x10);
            int32_t* rdi_1 = *(rax_3 + 0x10);
            int32_t* r12_1 = *(rax_3 + 0x18);
            int64_t rax_4 = *(arg1 + 0x100);
            char rax_5;
            
            if (*(r13_1 + 1) == 0x69)
            {
                int64_t rdx_3;
                
                if (rax_4 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_3 = 1;
                    rax_4 = 0;
                }
                else
                    rdx_3 = rax_4 + 1;
                
                *(arg1 + 0x100) = rdx_3;
                arg1[rax_4] = 0x2e;
                rax_5 = 0x2e;
            }
            else
            {
                int64_t rdx_1;
                
                if (rax_4 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_1 = 1;
                    rax_4 = 0;
                }
                else
                    rdx_1 = rax_4 + 1;
                
                *(arg1 + 0x100) = rdx_1;
                arg1[rax_4] = 0x5b;
                rax_5 = 0x5b;
            }
            
            arg1[0x108] = rax_5;
            sub_14000b540(arg1, 0x11, rdi_1);
            char rax_6 = *(r13_1 + 1);
            
            if (rax_6 == 0x58)
            {
                char const* const i = " ... ";
                int64_t rax_13 = *(arg1 + 0x100);
                
                do
                {
                    char const rbp_1 = *i;
                    int64_t rdx_5;
                    
                    if (rax_13 != 0xff)
                        rdx_5 = rax_13;
                    else
                    {
                        i = &i[1];
                        arg1[0xff] = 0;
                        (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                        *(arg1 + 0x140) += 1;
                        *(arg1 + 0x100) = 1;
                        *arg1 = rbp_1;
                        arg1[0x108] = rbp_1;
                        
                        if (&data_140024da4[5] == i)
                            break;
                        
                        rbp_1 = *i;
                        rdx_5 = 1;
                    }
                    
                    rax_13 = rdx_5 + 1;
                    i = &i[1];
                    *(arg1 + 0x100) = rax_13;
                    arg1[rdx_5] = rbp_1;
                    arg1[0x108] = rbp_1;
                } while (&data_140024da4[5] != i);
                
                sub_14000b540(arg1, 0x11, *(r12_1 + 0x10));
                r12_1 = *(r12_1 + 0x18);
                rax_6 = *(r13_1 + 1);
            }
            
            if (rax_6 != 0x69)
            {
                int64_t rax_7 = *(arg1 + 0x100);
                int64_t rdx_2;
                
                if (rax_7 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_2 = 1;
                    rax_7 = 0;
                }
                else
                    rdx_2 = rax_7 + 1;
                
                *(arg1 + 0x100) = rdx_2;
                arg1[rax_7] = 0x5d;
                arg1[0x108] = 0x5d;
            }
            
            int32_t rax_10;
            
            if ((*r12_1 & 0xfffffffd) == 0x39)
                rax_10 = sub_140002f90(*(r12_1 + 0x10));
            
            if ((*r12_1 & 0xfffffffd) != 0x39 || !rax_10)
            {
                int64_t rax_12 = *(arg1 + 0x100);
                int64_t rdx_4;
                
                if (rax_12 == 0xff)
                {
                    arg1[0xff] = 0;
                    (*(arg1 + 0x110))(arg1, 0xff, *(arg1 + 0x118));
                    *(arg1 + 0x140) += 1;
                    rdx_4 = 1;
                    rax_12 = 0;
                }
                else
                    rdx_4 = rax_12 + 1;
                
                *(arg1 + 0x100) = rdx_4;
                arg1[rax_12] = 0x3d;
                arg1[0x108] = 0x3d;
                sub_14000d470(arg1, 0x11, r12_1);
            }
            else
                sub_14000b540(arg1, 0x11, r12_1);
        }
    }
    
    return rsi;
}

char* sub_14000ddb0(char* arg1, char* arg2, int64_t* arg3, int32_t* arg4)
{
    if (arg1 && (!arg2 || arg3))
    {
        char* _Str_1;
        __builtin_memset(&_Str_1, 0, 0x1c);
        int32_t rax_1 = sub_14000ce90(arg1, sub_140002e90, &_Str_1);
        char* _Str = _Str_1;
        int32_t var_30;
        
        if (!rax_1)
        {
            free(_Str);
            
            if (arg4)
                *arg4 = 0xfffffffe;
        }
        else
        {
            int64_t r12_1;
            
            if (!var_30)
            {
                int128_t var_40;
                r12_1 = *var_40[8];
                
                if (_Str)
                {
                label_14000de2c:
                    
                    if (arg2)
                    {
                        uint64_t rax_3 = strlen(_Str);
                        
                        if (rax_3 >= *arg3)
                        {
                            free(arg2);
                            *arg3 = r12_1;
                        }
                        else
                        {
                            memcpy(arg2, _Str, rax_3 + 1);
                            char* _Str_2 = _Str;
                            _Str = arg2;
                            free(_Str_2);
                        }
                    }
                    else if (arg3)
                        *arg3 = r12_1;
                    
                    if (arg4)
                        *arg4 = 0;
                    
                    return _Str;
                }
                
                if (arg4)
                {
                    if (r12_1 != 1)
                        *arg4 = 0xfffffffe;
                    else
                        *arg4 = 0xffffffff;
                }
            }
            else
            {
                r12_1 = 1;
                
                if (_Str)
                    goto label_14000de2c;
                
                if (arg4)
                    *arg4 = 0xffffffff;
            }
        }
    }
    else if (arg4)
        *arg4 = 0xfffffffd;
    
    return 0;
}

int64_t sub_14000df00(char* arg1, int64_t arg2, int64_t arg3)
{
    if (!arg1 || !arg2)
        return 0xfffffffd;
    
    if (!sub_14000ce90(arg1, arg2, arg3))
        return 0xfffffffe;
    
    return 0;
}

int64_t sub_14000df40()
{
    int64_t i = **&data_140023060;
    
    while (i)
    {
        i();
        void* rax_1 = data_140023060;
        i = *(rax_1 + 8);
        data_140023060 = rax_1 + 8;
    }
    
    return i;
}

int64_t sub_14000df80()
{
    int32_t rax_4 = 0;
    int32_t rcx;
    uint64_t r8_2;
    
    do
    {
        r8_2 = rax_4 + 1;
        rcx = rax_4;
        rax_4 = r8_2;
    } while (*(&data_140029260 + (r8_2 << 3)));
    
    if (rcx)
    {
        uint64_t rax_1 = rcx;
        void* i = &data_140029260 + (rax_1 << 3);
        
        do
        {
            (*i)();
            i -= 8;
        } while (i != ((rax_1 - (rcx - 1)) << 3) + 0x140029258);
    }
    
    /* tailcall */
    return sub_140001410(sub_14000df40);
}

int64_t sub_14000dff0()
{
    int32_t result = data_1400300a0;
    
    if (result)
        return result;
    
    data_1400300a0 = 1;
    /* tailcall */
    return sub_14000df80();
}

int64_t sub_14000e010() __pure
{
    return 0;
}

int64_t _TLS_Entry_1(int64_t arg1, int32_t arg2)
{
    if (arg2 != 3 && arg2)
        return 1;
    
    sub_14000eac0(arg1, arg2);
    return 1;
}

int64_t _TLS_Entry_0(int64_t arg1, int32_t arg2)
{
    if (data_140023080 != 2)
        data_140023080 = 2;
    
    if (arg2 != 2 && arg2 == 1)
        sub_14000eac0(arg1, arg2);
    
    return 1;
}

int64_t sub_14000e0e0() __pure
{
    return 0;
}

int64_t sub_14000e0f0(int32_t* arg1)
{
    char const* const rbx;
    
    if (*arg1 > 6)
        rbx = "Unknown error";
    else
        switch (*arg1)
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
    
    fprintf(sub_140014cc0(2), "_matherr(): %s in %s(%g, %g)  (retval=%g)\n", rbx, *(arg1 + 8), 
        *(arg1 + 0x10), *(arg1 + 0x18), *(arg1 + 0x20));
    return 0;
}

int64_t sub_14000e1f0() __pure
{
    return;
}

void sub_14000e200(char* arg1, int64_t arg2) __noreturn
{
    int64_t _ArgList = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    fwrite("Mingw-w64 runtime failure:\n", 1, 0x1b, sub_140014cc0(2));
    vfprintf(sub_140014cc0(2), arg1, &_ArgList);
    abort();
    /* no return */
}

int64_t* sub_14000e270(int64_t arg1)
{
    int64_t rsi = data_140030114;
    int64_t* Protect;
    
    if (rsi <= 0)
        rsi = 0;
    else
    {
        int32_t i = 0;
        Protect = data_140030118 + 0x18;
        
        do
        {
            int64_t r8_1 = *Protect;
            
            if (arg1 >= r8_1 && arg1 < r8_1 + *(Protect[1] + 8))
                return Protect;
            
            i += 1;
            Protect = &Protect[5];
        } while (i != rsi);
    }
    
    struct Section_Header* rax_2 = sub_14000ece0(arg1);
    
    if (!rax_2)
    {
        sub_14000e200("Address %p has no image-section", arg1);
        /* no return */
    }
    
    int64_t rbx_2 = rsi * 0x28;
    int32_t* rax_4 = data_140030118 + rbx_2;
    *(rax_4 + 0x20) = rax_2;
    *rax_4 = 0;
    void* lpAddress = &sub_14000ee20()->e_magic[rax_2->virtualAddress];
    *(data_140030118 + rbx_2 + 0x18) = lpAddress;
    MEMORY_BASIC_INFORMATION buffer;
    
    if (!VirtualQuery(lpAddress, &buffer, 0x30))
    {
        *(data_140030118 + rbx_2 + 0x18);
        sub_14000e200("  VirtualQuery failed for %d bytes at address %p", rax_2->virtualSize);
        /* no return */
    }
    
    Protect = buffer.Protect;
    
    if ((Protect - 4) & 0xfffffffb && &Protect[-8] & 0xffffffbf)
    {
        void* BaseAddress = buffer.BaseAddress;
        uint64_t RegionSize = buffer.RegionSize;
        enum PAGE_PROTECTION_FLAGS flNewProtect = PAGE_EXECUTE_READWRITE;
        
        if (Protect == 2)
            flNewProtect = PAGE_READWRITE;
        
        enum PAGE_PROTECTION_FLAGS* lpflOldProtect = rbx_2 + data_140030118;
        *(lpflOldProtect + 8) = BaseAddress;
        *(lpflOldProtect + 0x10) = RegionSize;
        Protect = VirtualProtect(BaseAddress, RegionSize, flNewProtect, lpflOldProtect);
        
        if (!Protect)
        {
            sub_14000e200("  VirtualProtect failed with code 0x%x", GetLastError());
            /* no return */
        }
    }
    
    data_140030114 += 1;
    return Protect;
}

void sub_14000e3e0()
{
    if (data_140030110)
        return;
    
    data_140030110 = 1;
    void* rax_5 = (sub_14000ed60() * 0x28 + 0xf) & 0xfffffffffffffff0;
    sub_14000efc0(rax_5);
    data_140030114 = 0;
    void var_88;
    data_140030118 = &var_88 - rax_5 + 0x30;
}

int64_t sub_14000e740(int32_t arg1, int64_t arg2, double arg3[0x2] @ zmm2, int64_t arg4 @ zmm3, int64_t arg5)
{
    int64_t result = data_140030120;
    double temp0[0x2] = _mm_unpacklo_pd(arg3, arg4);
    
    if (!result)
        return result;
    
    int32_t var_38 = arg1;
    int64_t var_30_1 = arg2;
    double var_28_1[0x2] = temp0;
    int64_t var_18_1 = arg5;
    return result(&var_38);
}

int64_t sub_14000e780(_UserMathErrorFunctionPointer arg1)
{
    data_140030120 = arg1;
    /* tailcall */
    return __setusermatherr(arg1);
}

int64_t sub_14000e790(int64_t* arg1)
{
    int32_t* rdx = *arg1;
    int32_t rax = *rdx;
    
    if ((rax & 0x20ffffff) == 0x20474343 && !(rdx[1] & 1))
        return 0xffffffff;
    
    if (rax <= 0xc0000096)
    {
        if (rax > 0xc000008b)
        {
            uint64_t rax_1 = rax + 0x3fffff73;
            
            if (rax_1 > 9)
                return 0xffffffff;
            
            _crt_signal_t rax_4;
            
            switch (rax_1)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                {
                    rax_4 = signal(8, nullptr);
                    
                    if (rax_4 == 1)
                    {
                        signal(8, 1);
                        return 0xffffffff;
                    }
                    
                label_14000e7f6:
                    
                    if (rax_4)
                    {
                        rax_4(8);
                        return 0xffffffff;
                    }
                    break;
                }
                case 5:
                case 8:
                {
                    return 0xffffffff;
                    break;
                }
                case 7:
                {
                    rax_4 = signal(8, nullptr);
                    
                    if (rax_4 != 1)
                        goto label_14000e7f6;
                    
                    signal(8, 1);
                    return 0xffffffff;
                    break;
                }
                case 9:
                {
                label_14000e842:
                    _crt_signal_t rax_7 = signal(4, nullptr);
                    
                    if (rax_7 == 1)
                    {
                        signal(4, 1);
                        return 0xffffffff;
                    }
                    
                    if (rax_7)
                    {
                        rax_7(4);
                        return 0xffffffff;
                    }
                    break;
                }
            }
        }
        else if (rax == 0xc0000005)
        {
            _crt_signal_t rax_9 = signal(0xb, nullptr);
            
            if (rax_9 == 1)
            {
                signal(0xb, 1);
                return 0xffffffff;
            }
            
            if (rax_9)
            {
                rax_9(0xb);
                return 0xffffffff;
            }
        }
        else
        {
            if (rax == 0xc0000008)
                return 0xffffffff;
            
            if (rax == 0xc000001d)
                goto label_14000e842;
            
            if (rax == 0x80000002)
                return 0xffffffff;
        }
    }
    
    int64_t rax_5 = data_140030140;
    
    if (!rax_5)
        return 0;
    
    /* tailcall */
    return rax_5(arg1);
}

int64_t sub_14000e950()
{
    EnterCriticalSection(&data_140030180);
    
    for (int32_t* i = data_140030160; i; i = *(i + 0x10))
    {
        int64_t rax_1 = TlsGetValue(*i);
        
        if (rax_1 && !GetLastError())
            (*(i + 8))(rax_1);
    }
    
    /* tailcall */
    return LeaveCriticalSection(&data_140030180);
}

int64_t sub_14000e9c0(int32_t arg1, int64_t arg2)
{
    if (data_140030168)
    {
        int32_t* rax_2 = calloc(1, 0x18);
        
        if (!rax_2)
            return 0xffffffff;
        
        *(rax_2 + 8) = arg2;
        *rax_2 = arg1;
        EnterCriticalSection(&data_140030180);
        int64_t rax_3 = data_140030160;
        data_140030160 = rax_2;
        *(rax_2 + 0x10) = rax_3;
        LeaveCriticalSection(&data_140030180);
    }
    
    return 0;
}

int64_t sub_14000ea30(int32_t arg1)
{
    if (!data_140030168)
        return 0;
    
    EnterCriticalSection(&data_140030180);
    int32_t* rcx = data_140030160;
    
    if (rcx)
    {
        int32_t* rdx_1 = nullptr;
        
        while (true)
        {
            int32_t* rax_3 = *(rcx + 0x10);
            
            if (*rcx == arg1)
            {
                if (!rdx_1)
                    data_140030160 = rax_3;
                else
                    *(rdx_1 + 0x10) = rax_3;
                
                free(rcx);
                break;
            }
            
            rdx_1 = rcx;
            
            if (!rax_3)
                break;
            
            rcx = rax_3;
        }
    }
    
    LeaveCriticalSection(&data_140030180);
    return 0;
}

int64_t sub_14000eac0(int64_t arg1, int32_t arg2)
{
    if (arg2 == 2)
        return 1;
    
    if (arg2 > 2)
    {
        if (arg2 == 3 && data_140030168)
            sub_14000e950();
    }
    else if (!arg2)
    {
        if (data_140030168)
            sub_14000e950();
        
        if (data_140030168 == 1)
        {
            void* i = data_140030160;
            
            while (i)
            {
                void* i_1 = i;
                i = *(i + 0x10);
                free(i_1);
            }
            
            data_140030160 = 0;
            data_140030168 = 0;
            DeleteCriticalSection(&data_140030180);
        }
    }
    else
    {
        if (!data_140030168)
            InitializeCriticalSection(&data_140030180);
        
        data_140030168 = 1;
    }
    
    return 1;
}

int64_t sub_14000ebc0(int16_t* arg1)
{
    if (*arg1 == 0x5a4d)
    {
        void* rcx = arg1 + *(arg1 + 0x3c);
        
        if (*rcx == 0x4550)
        {
            int64_t result;
            result = *(rcx + 0x18) == 0x20b;
            return result;
        }
    }
    
    return 0;
}

void* sub_14000ebf0(void* arg1, int64_t arg2)
{
    void* rcx = arg1 + *(arg1 + 0x3c);
    uint32_t r8 = *(rcx + 6);
    void* result = rcx + *(rcx + 0x14) + 0x18;
    
    if (r8)
    {
        void* r9_1 = result + (r8 - 1) * 0x28 + 0x28;
        
        do
        {
            uint64_t r8_1 = *(result + 0xc);
            
            if (arg2 >= r8_1 && arg2 < r8_1 + *(result + 8))
                return result;
            
            result += 0x28;
        } while (result != r9_1);
    }
    
    return nullptr;
}

struct Section_Header* const sub_14000ec40(char* arg1)
{
    if (strlen(arg1) <= 8)
    {
        for (struct Section_Header* const _Str1 = &__section_headers; _Str1 != 0x140000318; 
            _Str1 = &_Str1[1])
        {
            if (!strncmp(_Str1, arg1, 8))
                return _Str1;
        }
    }
    
    return 0;
}

struct Section_Header* const sub_14000ece0(int64_t arg1)
{
    for (struct Section_Header* const i = &__section_headers; i != 0x140000318; i = &i[1])
    {
        uint64_t virtualAddress = i->virtualAddress;
        
        if (arg1 - &__dos_header >= virtualAddress
                && arg1 - &__dos_header < virtualAddress + i->virtualSize)
            return i;
    }
    
    return 0;
}

int64_t sub_14000ed60() __pure
{
    return 0xa;
}

struct Section_Header* const sub_14000eda0(int64_t arg1)
{
    struct Section_Header* const i = &__section_headers;
    
    do
    {
        if (*i->characteristics[3] & 0x20)
        {
            if (!arg1)
                return i;
            
            arg1 -= 1;
        }
        
        i = &i[1];
    } while (0x140000318 != i);
    
    return 0;
}

struct DOS_Header* const sub_14000ee20() __pure
{
    return &__dos_header;
}

uint64_t sub_14000ee60(int64_t arg1)
{
    for (struct Section_Header* const i = &__section_headers; i != 0x140000318; i = &i[1])
    {
        uint64_t virtualAddress = i->virtualAddress;
        
        if (arg1 - &__dos_header >= virtualAddress
                && arg1 - &__dos_header < virtualAddress + i->virtualSize)
            return ~i->characteristics >> 0x1f;
    }
    
    return 0;
}

void* sub_14000eef0(int32_t arg1)
{
    struct Section_Header* const i = &__section_headers;
    
    do
    {
        uint64_t virtualAddress = i->virtualAddress;
        
        if (0x31000 >= virtualAddress && 0x31000 < virtualAddress + i->virtualSize)
        {
            struct Import_Directory_Table* const rax_3 = &__import_directory_entries;
            
            while (rax_3->timeDateStamp || rax_3->nameRva)
            {
                if (arg1 <= 0)
                    return &__dos_header.e_magic[rax_3->nameRva];
                
                arg1 -= 1;
                rax_3 = &rax_3[1];
            }
            
            break;
        }
        
        i = &i[1];
    } while (0x140000318 != i);
    
    return 0;
}

int64_t sub_14000efc0(int64_t arg1 @ rax)
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

int64_t x4352f0a0::close::operator[]::environment_strings_traits::close(HANDLE arg1)
{
    CloseHandle(arg1);
    return 0;
}

uint64_t sub_14000f020(HANDLE arg1, HANDLE arg2)
{
    uint32_t rax_1;
    rax_1 = GetThreadId(arg1) == GetThreadId(arg2);
    return rax_1;
}

int64_t sub_14000f050()
{
    Sleep(0);
    return 0;
}

int64_t sub_14000f070(int32_t* arg1, int64_t arg2)
{
    int32_t rcx = *arg1;
    
    if (!rcx)
    {
        int32_t temp0_1 = arg1[1];
        arg1[1] += 1;
        
        if (temp0_1 == 0xffffffff)
        {
            arg2(rcx);
            *arg1 = 1;
        }
        else
        {
            while (!*arg1)
            {
                Sleep(0);
                
                if (*arg1)
                    break;
                
                Sleep(0);
            }
        }
    }
    
    return 0;
}

int64_t sub_14000f0e0(uint32_t* arg1, int64_t arg2)
{
    uint32_t rax = TlsAlloc();
    
    if (rax == 0xffffffff)
        /* tailcall */
        return GetLastError();
    
    *arg1 = rax;
    /* tailcall */
    return sub_140015430(rax, arg2);
}

int64_t sub_14000f120(uint32_t arg1)
{
    if (!TlsFree(arg1))
        /* tailcall */
        return GetLastError();
    
    return 0;
}

int64_t sub_14000f150(uint32_t arg1)
{
    enum WIN32_ERROR dwErrCode = GetLastError();
    int64_t result = TlsGetValue(arg1);
    SetLastError(dwErrCode);
    return result;
}

int64_t sub_14000f180(uint32_t arg1, int64_t arg2)
{
    if (!TlsSetValue(arg1, arg2))
        /* tailcall */
        return GetLastError();
    
    return 0;
}

void InitializeCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return InitializeCriticalSection(lpCriticalSection);
}

void DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return DeleteCriticalSection(lpCriticalSection);
}

int64_t x17d69fb8::close::operator[]::environment_strings_traits::close(CRITICAL_SECTION* arg1)
{
    EnterCriticalSection(arg1);
    return 0;
}

int64_t sub_14000f1f0(CRITICAL_SECTION* arg1)
{
    if (TryEnterCriticalSection(arg1))
    {
        if (arg1->RecursionCount <= 1)
            return 0;
        
        LeaveCriticalSection(arg1);
    }
    
    return 1;
}

int64_t x1bf47908::close::operator[]::environment_strings_traits::close(CRITICAL_SECTION* arg1)
{
    LeaveCriticalSection(arg1);
    return 0;
}

uint64_t sub_14000f250(CRITICAL_SECTION* arg1)
{
    BOOL rax;
    rax = !TryEnterCriticalSection(arg1);
    return rax;
}

void sub_14000f270(int64_t arg1) __noreturn
{
    int64_t arguments = arg1;
    RaiseException(0x22474343, 0, 1, &arguments);
    /* no return */
}

int64_t sub_14000f2c0(int64_t arg1, int32_t arg2)
{
    if (arg2 <= 1)
        return *(arg1 + (arg2 << 3) + 0x10);
    
    abort();
    /* no return */
}

void sub_14000f2e0(int64_t arg1, int32_t arg2, int64_t arg3)
{
    if (arg2 > 1)
    {
        abort();
        /* no return */
    }
    
    *(arg1 + (arg2 << 3) + 0x10) = arg3;
}

int64_t sub_14000f300(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_14000f310(void* arg1)
{
    return *(arg1 + 8);
}

int64_t sub_14000f320(void* arg1, int32_t* arg2)
{
    int64_t result = *(arg1 + 8);
    *arg2 = 0;
    return result;
}

int64_t sub_14000f330(void* arg1, int64_t arg2)
{
    *(arg1 + 8) = arg2;
}

int64_t sub_14000f340(void* arg1)
{
    return *(*(arg1 + 0x20) + 0x38);
}

int64_t sub_14000f350(void* arg1)
{
    void* rdx = *(arg1 + 0x20);
    return **(rdx + 0x10) + *(rdx + 8);
}

uint64_t sub_14000f360(uint64_t arg1)
{
    uint64_t ImageBase[0x2];
    IMAGE_RUNTIME_FUNCTION_ENTRY* rax = RtlLookupFunctionEntry(arg1, &ImageBase, nullptr);
    
    if (!rax)
        return 0;
    
    return rax->BeginAddress + ImageBase[0];
}

int64_t sub_14000f390() __pure
{
    return 0;
}

int64_t PortablePDB::PdbGUID(void* arg1)
{
    return *(*(arg1 + 0x20) + 8);
}

int64_t sub_14000f3b0(int32_t* arg1, int64_t arg2, CONTEXT* arg3, void* arg4, int64_t arg5)
{
    char rax = arg1[1];
    EXCEPTION_RECORD* ExceptionRecord = arg1;
    
    if (rax & 0x20)
        *(*(arg4 + 0x28) + 0x88) = *(arg1 + 0x38);
    else
    {
        int32_t rdx = *arg1;
        int64_t* ReturnValue = *(arg1 + 0x20);
        
        if (rdx != 0x21474343)
        {
            void* var_48_1 = arg4;
            uint128_t var_68 = *(*(arg4 + 0x28) + 0x98) | *arg4 << 0x40;
            uint128_t zmm0 = 0xdeadbeef;
            uint128_t var_58_1 = _mm_unpacklo_epi64(zmm0, zmm0);
            int64_t rdx_1;
            
            if (rdx == 0x22474343)
            {
                int64_t var_70 = ReturnValue[6];
                ReturnValue[2](1, 0xa, *ReturnValue, ReturnValue, &var_68, var_70);
                rdx_1 = 0xa;
            label_14000f449:
                int32_t rax_1 = arg5(1, rdx_1, *ReturnValue, ReturnValue, &var_68, var_70);
                
                if (rax_1 != 8)
                {
                    if (rax_1 != 7)
                    {
                        abort();
                        /* no return */
                    }
                    
                    zmm0 = arg2 | *var_68[8] << 0x40;
                    ExceptionRecord->ExceptionInformation[3] = *var_58_1[8];
                    ExceptionRecord->ExceptionInformation[1] = zmm0;
                    ExceptionRecord->ExceptionInformation[2] = *zmm0[8];
                    RaiseException(0x21474343, 1, 4, &ExceptionRecord->ExceptionInformation);
                    /* no return */
                }
            }
            else if (rdx == 0x20474343)
            {
                if (rax & 6)
                {
                    rdx_1 = 2;
                    goto label_14000f449;
                }
                
                int32_t rax_6 = arg5(1, 1, *ReturnValue, ReturnValue, &var_68);
                
                if (rax_6 != 8)
                {
                    if (rax_6 == 6 && arg5(1, 6, *ReturnValue, ReturnValue, &var_68) == 7)
                    {
                        zmm0 = arg2 | *var_68[8] << 0x40;
                        int64_t TargetIp = *var_68[8];
                        *(ReturnValue + 0x18) = zmm0;
                        uint64_t rax_8 = *var_58_1[8];
                        ReturnValue[5] = rax_8;
                        ExceptionRecord->ExceptionInformation[3] = rax_8;
                        UNWIND_HISTORY_TABLE* HistoryTable = *(arg4 + 0x40);
                        ExceptionRecord->NumberParameters = 4;
                        ExceptionRecord->ExceptionInformation[1] = zmm0;
                        ExceptionRecord->ExceptionInformation[2] = *zmm0[8];
                        RtlUnwindEx(arg2, TargetIp, ExceptionRecord, var_58_1, arg3, HistoryTable);
                    }
                    
                    abort();
                    /* no return */
                }
            }
        }
        else if (arg2 == *(arg1 + 0x28))
        {
            RtlUnwindEx(arg2, *(arg1 + 0x30), arg1, ReturnValue, arg3, *(arg4 + 0x40));
            abort();
            /* no return */
        }
    }
    
    return 1;
}

void sub_14000f5e0(int64_t arg1) __noreturn
{
    int64_t arguments = arg1;
    __builtin_memset(arg1 + 0x10, 0, 0x30);
    RaiseException(0x20474343, 0, 1, &arguments);
    /* no return */
}

void sub_14000f620(void* arg1) __noreturn
{
    CONTEXT ContextRecord;
    ContextRecord.ContextFlags = 0x10001f;
    var_650;
    __builtin_memset(&var_650, 0, 0x90);
    EXCEPTION_RECORD ExceptionRecord;
    ExceptionRecord.NumberParameters = 4;
    UNWIND_HISTORY_TABLE HistoryTable;
    __builtin_memset(&HistoryTable, 0, 0xd8);
    ExceptionRecord.ExceptionCode = 0x20474343;
    ExceptionRecord.ExceptionFlags = 1;
    uint128_t zmm0 = *(arg1 + 0x20) | *(arg1 + 0x28) << 0x40;
    uint128_t zmm1 = arg1 | *(arg1 + 0x18) << 0x40;
    ExceptionRecord.ExceptionInformation[0] = zmm1;
    ExceptionRecord.ExceptionInformation[1] = *zmm1[8];
    ExceptionRecord.ExceptionInformation[2] = zmm0;
    ExceptionRecord.ExceptionInformation[3] = *zmm0[8];
    RtlCaptureContext(&ContextRecord);
    RtlUnwindEx(*(arg1 + 0x18), *(arg1 + 0x20), &ExceptionRecord, arg1, &ContextRecord, 
        &HistoryTable);
    abort();
    /* no return */
}

void sub_14000f700(void* arg1) __noreturn
{
    if (*(arg1 + 0x10))
    {
        sub_14000f270(arg1);
        /* no return */
    }
    
    uint64_t arguments[0x2];
    arguments[0] = arg1;
    __builtin_memset(arg1 + 0x10, 0, 0x30);
    RaiseException(0x20474343, 0, 1, &arguments);
    /* no return */
}

void sub_14000f750(void* arg1, int64_t arg2, int64_t arg3) __noreturn
{
    __builtin_memset(arg1 + 0x28, 0, 0x18);
    *(arg1 + 0x10) = arg2;
    *(arg1 + 0x30) = arg3;
    *(arg1 + 0x18) = {0};
    sub_14000f270(arg1);
    /* no return */
}

int64_t sub_14000f780(void* arg1)
{
    int64_t result = *(arg1 + 8);
    
    if (!result)
        return result;
    
    /* jump -> result */
}

int64_t sub_14000f7a0(int64_t arg1, int64_t arg2)
{
    UNWIND_HISTORY_TABLE HistoryTable;
    __builtin_memset(&HistoryTable, 0, 0xd8);
    uint128_t var_658;
    __builtin_memset(&var_658, 0, 0x28);
    CONTEXT ContextRecord;
    ContextRecord.ContextFlags = 0x10001f;
    int128_t var_628;
    __builtin_memset(&var_628, 0, 0x50);
    RtlCaptureContext(&ContextRecord);
    uint64_t Rip = ContextRecord.Rip;
    int128_t* rbx = &var_628;
    int128_t* var_638 = &var_628;
    int128_t var_608;
    *var_608[8] = &ContextRecord;
    int128_t var_5e8;
    var_5e8 = &HistoryTable;
    
    while (true)
    {
        *rbx = Rip;
        rbx[1] = RtlLookupFunctionEntry(Rip, rbx + 8, &HistoryTable);
        IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry = var_638[1];
        
        if (!FunctionEntry)
            return 5;
        
        var_638[3] = RtlVirtualUnwind(UNW_FLAG_NHANDLER, *(var_638 + 8), ContextRecord.Rip, 
            FunctionEntry, &ContextRecord, var_638 + 0x38, var_638 + 0x18, nullptr);
        var_658 = ContextRecord.Rsp | ContextRecord.Rip << 0x40;
        
        if (arg1(&var_658, arg2))
            return 3;
        
        Rip = ContextRecord.Rip;
        
        if (!Rip)
            return 5;
        
        rbx = var_638;
    }
}

int64_t sub_14000f940(int64_t* arg1)
{
    int64_t rdi = *arg1;
    
    if (rdi)
    {
        int64_t rbx_1 = 0;
        
        do
        {
            void* rax_1 = arg1[rbx_1 + 1];
            
            if (rax_1)
                free(*(rax_1 - 8));
            
            rbx_1 += 1;
        } while (rdi != rbx_1);
    }
    
    /* tailcall */
    return free(arg1);
}

int64_t sub_14000f990(int64_t* arg1)
{
    int64_t rsi = arg1[1];
    uint64_t _Size = *arg1;
    int64_t rdx;
    void* r9;
    
    if (rsi > 8)
    {
        int64_t rax_3 = malloc(rsi + _Size + 7);
        
        if (rax_3)
        {
            r9 = (rax_3 + rsi + 7) & -(rsi);
            *(r9 - 8) = rax_3;
            rdx = arg1[3];
            
            if (rdx)
                return memcpy(r9, rdx, _Size);
            
            return memset(r9, 0, _Size);
        }
    }
    else
    {
        int64_t* rax = malloc(_Size + 8);
        
        if (rax)
        {
            rdx = arg1[3];
            *rax = rax;
            r9 = &rax[1];
            
            if (!rdx)
                return memset(r9, 0, _Size);
            
            return memcpy(r9, rdx, _Size);
        }
    }
    abort();
    /* no return */
}

int64_t sub_14000fa30(int64_t* arg1)
{
    int64_t result;
    
    if (data_140023080)
    {
        int64_t r12_1 = arg1[2];
        
        if (!r12_1)
        {
            if (data_140023080 && !data_140023090)
            {
                int32_t temp0_1 = data_140023094;
                data_140023094 += 1;
                
                if (temp0_1 == 0xffffffff)
                {
                    InitializeCriticalSection(&data_140030220);
                    uint32_t rax_5 = TlsAlloc();
                    enum WIN32_ERROR rax_6;
                    
                    if (rax_5 == 0xffffffff)
                        rax_6 = GetLastError();
                    else
                    {
                        data_140030208 = rax_5;
                        rax_6 = sub_140015430(rax_5, sub_14000f940);
                    }
                    
                    if (rax_6)
                    {
                        abort();
                        /* no return */
                    }
                    
                    data_140023090 = 1;
                }
                else
                {
                    while (!data_140023090)
                        Sleep(0);
                }
            }
            
            if (data_140023080 && (data_140023090 || data_140023080))
            {
                EnterCriticalSection(&data_140030220);
                r12_1 = arg1[2];
                
                if (!r12_1)
                    goto label_14000fc25;
                
                goto label_14000fb18;
            }
            
            r12_1 = arg1[2];
            
            if (!r12_1)
            {
            label_14000fc25:
                r12_1 = data_140030200 + 1;
                data_140030200 = r12_1;
                arg1[2] = r12_1;
            label_14000fb18:
                
                if (data_140023080)
                    LeaveCriticalSection(&data_140030220);
            }
        }
        
        uint32_t dwTlsIndex = data_140030208;
        enum WIN32_ERROR dwErrCode = GetLastError();
        int64_t* lpTlsValue = TlsGetValue(dwTlsIndex);
        SetLastError(dwErrCode);
        
        if (!lpTlsValue)
        {
            int64_t* lpTlsValue_1 = calloc(r12_1 + 0x21, 8);
            lpTlsValue = lpTlsValue_1;
            
            if (!lpTlsValue_1)
            {
                abort();
                /* no return */
            }
            
            *lpTlsValue_1 = r12_1 + 0x20;
        label_14000fb64:
            
            if (!TlsSetValue(data_140030208, lpTlsValue))
                GetLastError();
        }
        else
        {
            int64_t rbp_1 = *lpTlsValue;
            
            if (rbp_1 < r12_1)
            {
                int64_t rdi_3 = rbp_1 * 2;
                
                if (rdi_3 < r12_1)
                    rdi_3 = r12_1 + 0x20;
                
                int64_t* lpTlsValue_2 = realloc(lpTlsValue, (rdi_3 << 3) + 8);
                lpTlsValue = lpTlsValue_2;
                
                if (!lpTlsValue_2)
                {
                    abort();
                    /* no return */
                }
                
                *lpTlsValue_2 = rdi_3;
                memset(&lpTlsValue_2[rbp_1 + 1], 0, (rdi_3 - rbp_1) << 3);
                goto label_14000fb64;
            }
        }
        
        result = lpTlsValue[r12_1];
        
        if (!result)
        {
            result = sub_14000f990(arg1);
            lpTlsValue[r12_1] = result;
        }
    }
    else
    {
        result = arg1[2];
        
        if (!result)
        {
            result = sub_14000f990(arg1);
            arg1[2] = result;
        }
    }
    
    return result;
}

int64_t sub_14000fc80(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    if (*arg1 < arg2)
    {
        *arg1 = arg2;
        arg1[3] = 0;
    }
    
    if (arg1[1] < arg3)
        arg1[1] = arg3;
    
    if (!arg4 || *arg1 != arg2)
        return;
    
    arg1[3] = arg4;
}

int64_t sub_14000fcb0(char* arg1, char* arg2, int64_t* arg3)
{
    int32_t result = sub_1400118a0(0x4000, arg1, 0, arg2, arg3);
    arg1[result] = 0;
    return result;
}

void* sub_14000fce0(int32_t arg1, int64_t* arg2, int32_t arg3, int32_t* arg4, int32_t* arg5)
{
    int64_t rax = *arg2;
    int32_t rdx = arg2[1];
    int64_t var_18 = rax;
    int32_t var_10 = rdx;
    int16_t r10 = rdx & 0x7fff;
    int32_t var_24;
    int32_t rcx_1;
    int32_t rdx_4;
    
    if (!r10)
    {
        uint32_t rdx_2 = rax >> 0x20;
        
        if (!(rax | rdx_2))
        {
            rdx_4 = 0;
            var_24 = 0;
            rcx_1 = rdx & 0x8000;
        }
        else
        {
            if (rdx_2 < 0)
                goto label_14000fd22;
            
            rdx_4 = -0x403d;
            var_24 = 2;
            rcx_1 = rdx & 0x8000;
        }
    }
    else if (r10 != 0x7fff)
    {
    label_14000fd22:
        rdx_4 = r10 - 0x403e;
        var_24 = 1;
        rcx_1 = rdx & 0x8000;
    }
    else if (!((rax >> 0x20 & 0x7fffffff) | rax))
    {
        rdx_4 = 0;
        var_24 = 3;
        rcx_1 = rdx & 0x8000;
    }
    else
    {
        var_24 = 4;
        rdx_4 = 0;
        rcx_1 = 0;
    }
    
    *arg5 = rcx_1;
    void* var_20;
    return sub_1400125e0(&data_1400230b0, rdx_4, &var_18, &var_24, arg1, arg3, arg4, &var_20);
}

int64_t sub_14000fdd0(int32_t arg1, int64_t* arg2)
{
    int16_t rdx = arg2[1];
    int32_t rax_1;
    
    if (!(*rdx[1] & 0x40))
        rax_1 = *(arg2 + 0x24);
    
    if (*rdx[1] & 0x40 || arg2[5] > rax_1)
    {
        char* _Stream = *arg2;
        *rdx[1] &= 0x20;
        
        if (*rdx[1])
        {
            fputc(arg1, _Stream);
            int32_t result = *(arg2 + 0x24) + 1;
            *(arg2 + 0x24) = result;
            return result;
        }
        
        _Stream[*(arg2 + 0x24)] = arg1;
        rax_1 = *(arg2 + 0x24);
    }
    
    *(arg2 + 0x24) = rax_1 + 1;
    return rax_1 + 1;
}

int64_t sub_14000fe30(int64_t arg1, int32_t arg2, char** arg3)
{
    int32_t rsi = arg2;
    char var_58[0x18];
    sub_140014d70(&var_58, 0);
    int32_t rax = arg3[2];
    int32_t rdx = rax;
    
    if (rsi <= rax)
        rdx = rsi;
    
    int32_t i_1 = *(arg3 + 0xc);
    
    if (rax >= 0)
        rsi = rdx;
    
    int32_t r12;
    
    if (i_1 > rsi)
    {
        int32_t rax_9 = i_1 - rsi;
        *(arg3 + 0xc) = rax_9;
        
        if (!(*(arg3 + 9) & 4))
        {
            *(arg3 + 0xc) = rax_9 - 1;
            int32_t i;
            
            do
            {
                sub_14000fdd0(0x20, arg3);
                i = *(arg3 + 0xc);
                *(arg3 + 0xc) = i - 1;
            } while (i);
            r12 = rsi - 1;
            
            if (rsi <= 0)
                goto label_14000ff3d;
            
            goto label_14000fe8c;
        }
        
        r12 = rsi - 1;
        
        if (rsi > 0)
            goto label_14000fe8c;
        
        *(arg3 + 0xc) -= 1;
    label_14000ff48:
        
        do
        {
            sub_14000fdd0(0x20, arg3);
        label_14000ff3d:
            i_1 = *(arg3 + 0xc);
            *(arg3 + 0xc) = i_1 - 1;
        } while (i_1 > 0);
        
        return i_1;
    }
    
    *(arg3 + 0xc) = 0xffffffff;
    r12 = rsi - 1;
    
    if (rsi <= 0)
        *(arg3 + 0xc) = 0xfffffffe;
    else
    {
    label_14000fe8c:
        int64_t rsi_1 = 0;
        
        while (true)
        {
            int32_t rax_1 = sub_140014d70(&var_58, *(arg1 + (rsi_1 << 1)));
            
            if (rax_1 <= 0)
                goto label_14000ff3d;
            
            void* r14_1 = &var_58;
            
            while (true)
            {
                int16_t rdx_3 = arg3[1];
                r14_1 += 1;
                int32_t rax_3;
                
                if (!(*rdx_3[1] & 0x40))
                    rax_3 = *(arg3 + 0x24);
                
                if (*rdx_3[1] & 0x40 || arg3[5] > rax_3)
                {
                    int32_t _Character = *(r14_1 - 1);
                    char* _Stream = *arg3;
                    *rdx_3[1] &= 0x20;
                    
                    if (!*rdx_3[1])
                    {
                        _Stream[*(arg3 + 0x24)] = _Character;
                        rax_3 = *(arg3 + 0x24);
                    }
                    else
                    {
                        fputc(_Character, _Stream);
                        *(arg3 + 0x24) += 1;
                        
                        if (r14_1 == &var_58[rax_1 - 1 + 1])
                            break;
                        
                        continue;
                    }
                }
                
                *(arg3 + 0x24) = rax_3 + 1;
                
                if (r14_1 == &var_58[rax_1 - 1 + 1])
                    break;
            }
            
            rsi_1 += 1;
            
            if (r12 + 1 - rsi_1 <= 0)
                break;
        }
        
        i_1 = *(arg3 + 0xc);
        *(arg3 + 0xc) = i_1 - 1;
        
        if (i_1 > 0)
            goto label_14000ff48;
    }
    
    return i_1;
}

int64_t sub_14000ffc0(void* arg1, int32_t arg2, char** arg3)
{
    int32_t rax = arg3[2];
    int32_t rdi = arg2;
    int32_t rdx = rax;
    void* rsi = arg1;
    
    if (arg2 <= rax)
        rdx = rdi;
    
    int32_t result = *(arg3 + 0xc);
    
    if (rax >= 0)
        rdi = rdx;
    
    int32_t rdx_1;
    
    if (result <= rdi)
    {
        *(arg3 + 0xc) = 0xffffffff;
        rdx_1 = rdi - 1;
        
        if (rdi)
            goto label_14000fffe;
        
        *(arg3 + 0xc) = 0xfffffffe;
        return result;
    }
    
    int32_t rax_4 = result - rdi;
    *(arg3 + 0xc) = rax_4;
    int16_t rax_1 = arg3[1];
    
    if (*rax_1[1] & 4)
    {
        rdx_1 = rdi - 1;
        
        if (rdi)
            goto label_140010004;
        
        *(arg3 + 0xc) -= 1;
        goto label_140010071;
    }
    
    *(arg3 + 0xc) = rax_4 - 1;
    int32_t i;
    
    do
    {
        sub_14000fdd0(0x20, arg3);
        i = *(arg3 + 0xc);
        *(arg3 + 0xc) = i - 1;
    } while (i);
    rdx_1 = rdi - 1;
    
    if (rdi)
    {
    label_14000fffe:
        rax_1 = arg3[1];
    label_140010004:
        void* rdi_2 = rdx_1 + 1 + rsi;
        
        while (true)
        {
            rsi += 1;
            int32_t rdx_2;
            
            if (!(*rax_1[1] & 0x40))
                rdx_2 = *(arg3 + 0x24);
            
            if (*rax_1[1] & 0x40 || arg3[5] > rdx_2)
            {
                int32_t _Character = *(rsi - 1);
                char* _Stream = *arg3;
                
                if (!(*rax_1[1] & 0x20))
                {
                    _Stream[*(arg3 + 0x24)] = _Character;
                    rdx_2 = *(arg3 + 0x24);
                }
                else
                {
                    fputc(_Character, _Stream);
                    rdx_2 = *(arg3 + 0x24);
                }
            }
            
            *(arg3 + 0x24) = rdx_2 + 1;
            
            if (rsi == rdi_2)
                break;
            
            rax_1 = arg3[1];
        }
    }
    
    while (true)
    {
        result = *(arg3 + 0xc);
        *(arg3 + 0xc) = result - 1;
        
        if (result <= 0)
            return result;
        
        rax_1 = arg3[1];
    label_140010071:
        int32_t rdx_4;
        
        if (!(*rax_1[1] & 0x40))
            rdx_4 = *(arg3 + 0x24);
        
        if (*rax_1[1] & 0x40 || arg3[5] > rdx_4)
        {
            char* _Stream_1 = *arg3;
            
            if (!(*rax_1[1] & 0x20))
            {
                _Stream_1[*(arg3 + 0x24)] = 0x20;
                rdx_4 = *(arg3 + 0x24);
            }
            else
            {
                fputc(0x20, _Stream_1);
                rdx_4 = *(arg3 + 0x24);
            }
        }
        
        *(arg3 + 0x24) = rdx_4 + 1;
    }
}

int64_t sub_140010110(char* arg1, char** arg2)
{
    char* _Str = arg1;
    int64_t rdx = arg2[2];
    
    if (!arg1)
        _Str = "(null)";
    
    int32_t rax;
    
    if (rdx < 0)
        rax = strlen(_Str);
    else
        rax = sub_140014b40(_Str, rdx);
    
    /* tailcall */
    return sub_14000ffc0(_Str, rax, arg2);
}

int64_t sub_140010160(int32_t arg1, char* arg2, char** arg3)
{
    int32_t r10 = arg3[1];
    arg3[2] = 0xffffffff;
    char var_c;
    void* r9;
    void var_b;
    
    if (arg1)
    {
        var_c = 0x2d;
        r9 = &var_b;
    }
    else if (r10 & 0x100)
    {
        var_c = 0x2b;
        r9 = &var_b;
    }
    else if (!(r10 & 0x40))
        r9 = &var_c;
    else
    {
        r9 = &var_b;
        var_c = 0x20;
    }
    
    for (int64_t i = 0; i != 3; i += 1)
        *(r9 + i) = (arg2[i] & 0xdf) | (r10 & 0x20);
    
    return sub_14000ffc0(&var_c, r9 + 3 - &var_c, arg3);
}

void* sub_140010200(int32_t arg1, uint64_t arg2, int64_t* arg3)
{
    void var_78;
    int32_t var_4c;
    int32_t rax_1;
    char rcx;
    int32_t rdi;
    char r9_1;
    void* result_5;
    int32_t r14;
    
    if (arg1 != 0x6f)
    {
        r14 = arg3[2];
        int32_t rax = 0;
        rdi = arg3[1];
        
        if (r14 >= 0)
            rax = r14;
        
        rax_1 = rax + 0x12;
        
        if (rdi & 0x1000)
        {
            rcx = 4;
            goto label_14001024e;
        }
        
        int32_t rcx_2 = *(arg3 + 0xc);
        var_4c = rcx_2;
        
        if (rcx_2 >= rax_1)
            rax_1 = rcx_2;
        
        int64_t rax_8 = (rax_1 + 0xf) & 0xfffffffffffffff0;
        sub_14000efc0(rax_8);
        rcx = 4;
        r9_1 = 0xf;
        result_5 = &var_78 - rax_8 + 0x20;
        goto label_140010355;
    }
    
    r14 = arg3[2];
    int32_t rax_22 = 0;
    rdi = arg3[1];
    
    if (r14 >= 0)
        rax_22 = r14;
    
    rax_1 = rax_22 + 0x18;
    
    if (rdi & 0x1000)
    {
        rcx = 3;
    label_14001024e:
        
        if (arg3[4])
            rax_1 += rax_1 / 3;
        
        int32_t rsi_1 = *(arg3 + 0xc);
        var_4c = rsi_1;
        
        if (rsi_1 >= rax_1)
            rax_1 = rsi_1;
        
        int64_t rax_4 = (rax_1 + 0xf) & 0xfffffffffffffff0;
        sub_14000efc0(rax_4);
        int64_t r9;
        r9 = arg1 != 0x6f;
        result_5 = &var_78 - rax_4 + 0x20;
        r9_1 = (r9 << 3) + 7;
        
        if (arg2)
            goto label_140010361;
        
        goto label_1400102ae;
    }
    
    int32_t rcx_4 = *(arg3 + 0xc);
    var_4c = rcx_4;
    
    if (rcx_4 >= rax_1)
        rax_1 = rcx_4;
    
    int64_t rax_27 = (rax_1 + 0xf) & 0xfffffffffffffff0;
    sub_14000efc0(rax_27);
    rcx = 3;
    r9_1 = 7;
    result_5 = &var_78 - rax_27 + 0x20;
label_140010355:
    void* result;
    int32_t rdx;
    void* result_1;
    int32_t rdi_2;
    int32_t r15_1;
    
    if (!arg2)
    {
    label_1400102ae:
        arg3[1] = rdi & 0xfffff7ff;
        
        if (r14 > 0)
        {
            rdi_2 = r14 - 1;
            result_1 = result_5;
        label_1400102c4:
            void* result_2 = result_1;
            int64_t _Size = rdi_2 + 1;
            result_1 += _Size;
            memset(result_2, 0x30, _Size);
        label_1400102da:
            
            if (result_1 == result_5 && r14)
                goto label_140010594;
            
            goto label_1400102e9;
        }
        
        result_1 = result_5;
        
        if (!r14)
        {
        label_1400102e9:
            result = result_1 - result_5;
            rdx = result;
            
            if (result < var_4c)
                goto label_1400105b1;
            
            goto label_1400102f6;
        }
        
    label_140010594:
        void* result_3 = result_1 + 1;
        *result_1 = 0x30;
        result_1 = result_3;
        result = result_3 - result_5;
        rdx = result;
        
        if (result >= var_4c)
        {
        label_1400102f6:
            *(arg3 + 0xc) = 0xffffffff;
            
            if (arg1 == 0x6f)
                goto label_140010307;
            
            rdi = arg3[1];
        label_14001067d:
            result = result_1;
            r15_1 = -1;
            
            if (rdi & 0x800)
            {
                *result_1 = arg1;
                result = result_1 + 2;
                r15_1 = -1;
                *(result_1 + 1) = 0x30;
            }
            
            goto label_140010658;
        }
        
    label_1400105b1:
        rdi = arg3[1];
    label_1400105b8:
        r15_1 = var_4c - rdx;
        *(arg3 + 0xc) = r15_1;
        
        if (arg1 != 0x6f)
            goto label_1400103e0;
        
        if (r14 >= 0 || (rdi & 0x600) != 0x200)
            goto label_1400103f5;
        
        uint64_t _Size_1 = r15_1;
        memset(result_1, 0x30, _Size_1);
        result = result_1 + _Size_1;
    label_1400105fb:
        r15_1 = -1;
        goto label_140010658;
    }
    
label_140010361:
    result_1 = result_5;
    void* result_4;
    
    do
    {
        result_4 = result_1;
        result_1 += 1;
        char rax_10 = r9_1 & arg2;
        char rax_12 = (rax_10 + 0x37) | (arg1 & 0x20);
        
        if (rax_10 + 0x30 <= 0x39)
            rax_12 = rax_10 + 0x30;
        
        arg2 u>>= rcx;
        *(result_1 - 1) = rax_12;
    } while (arg2);
    
    if (result_1 == result_5)
        goto label_1400102ae;
    
    if (r14 > 0)
    {
        int32_t rdx_2 = result_1 - result_5;
        int32_t rax_14 = r14 - rdx_2;
        
        if (rax_14 > 0)
        {
            rdi_2 = rax_14 - 1;
            goto label_1400102c4;
        }
        
        if (arg1 == 0x6f)
            goto label_140010608;
        
        if (rdx_2 >= var_4c)
            goto label_140010670;
        
        r15_1 = var_4c - rdx_2;
        *(arg3 + 0xc) = r15_1;
        goto label_1400103e0;
    }
    
    int32_t r13_1;
    
    if (arg1 == 0x6f)
    {
    label_140010608:
        
        if (rdi & 0x800)
        {
            *result_1 = 0x30;
            result_1 = result_4 + 2;
            goto label_1400102da;
        }
        
        result = result_1 - result_5;
        rdx = result;
        
        if (var_4c > result)
            goto label_1400105b8;
        
        *(arg3 + 0xc) = 0xffffffff;
    label_140010307:
        
        if (result_5 < result_1)
        {
            rdi = arg3[1];
            r13_1 = -2;
            r15_1 = -1;
        label_140010450:
            
            while (true)
            {
                result_1 -= 1;
                int32_t rax_17;
                
                if (!(rdi & 0x4000))
                    rax_17 = *(arg3 + 0x24);
                
                if (!(rdi & 0x4000) && arg3[5] <= rax_17)
                    goto label_140010442;
                
                int32_t _Character = *result_1;
                char* _Stream = *arg3;
                
                if (!(rdi & 0x2000))
                {
                    _Stream[*(arg3 + 0x24)] = _Character;
                    rax_17 = *(arg3 + 0x24);
                label_140010442:
                    result = rax_17 + 1;
                    *(arg3 + 0x24) = result;
                    
                    if (result_5 >= result_1)
                        break;
                }
                else
                {
                    fputc(_Character, _Stream);
                    result = *(arg3 + 0x24) + 1;
                    *(arg3 + 0x24) = result;
                    
                    if (result_5 >= result_1)
                        break;
                }
                
            label_14001044d:
                rdi = arg3[1];
            }
            
            if (r15_1 > 0)
            {
                while (true)
                {
                    rdi = arg3[1];
                label_1400104aa:
                    int32_t rax_20;
                    
                    if (!(rdi & 0x4000))
                        rax_20 = *(arg3 + 0x24);
                    
                    if (rdi & 0x4000 || arg3[5] > rax_20)
                    {
                        char* _Stream_1 = *arg3;
                        
                        if (!(rdi & 0x2000))
                        {
                            _Stream_1[*(arg3 + 0x24)] = 0x20;
                            rax_20 = *(arg3 + 0x24);
                        }
                        else
                        {
                            fputc(0x20, _Stream_1);
                            result = *(arg3 + 0x24) + 1;
                            *(arg3 + 0x24) = result;
                            int32_t temp1_1 = r13_1;
                            r13_1 -= 1;
                            
                            if (temp1_1 < 1)
                                return result;
                            
                            continue;
                        }
                    }
                    
                    result = rax_20 + 1;
                    *(arg3 + 0x24) = result;
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
        int32_t rax_24 = result_1 - result_5;
        
        if (rax_24 >= var_4c)
        {
        label_140010670:
            *(arg3 + 0xc) = 0xffffffff;
            goto label_14001067d;
        }
        
        r15_1 = var_4c - rax_24;
        *(arg3 + 0xc) = r15_1;
    label_1400103e0:
        
        if (!(rdi & 0x800))
        {
            if (r14 >= 0 || (rdi & 0x600) != 0x200)
                goto label_1400103f5;
            
        label_1400106cb:
            uint64_t _Size_2 = r15_1;
            memset(result_1, 0x30, _Size_2);
            result = result_1 + _Size_2;
            
            if (!(rdi & 0x800))
                goto label_1400105fb;
            
            *result = arg1;
            r15_1 = -1;
            result += 2;
            *(result - 1) = 0x30;
            goto label_140010658;
        }
        
        r15_1 -= 2;
        
        if (r15_1 > 0)
        {
            if (r14 < 0 && (rdi & 0x600) == 0x200)
                goto label_1400106cb;
            
            *result_1 = arg1;
            result_1 += 2;
            *(result_1 - 1) = 0x30;
        label_1400103f5:
            r13_1 = r15_1 - 1;
            
            if (rdi & 0x400)
            {
                if (result_5 >= result_1)
                    goto label_1400104aa;
                
                goto label_140010450;
            }
            
            r15_1 = r13_1;
            int32_t i;
            
            do
            {
                result = sub_14000fdd0(0x20, arg3);
                i = r15_1;
                r15_1 -= 1;
            } while (i >= 1);
            r13_1 = -2;
            
            if (result_5 < result_1)
                goto label_14001044d;
        }
        else
        {
            *result_1 = arg1;
            result = result_1 + 2;
            *(result_1 + 1) = 0x30;
        label_140010658:
            
            if (result_5 < result)
            {
                rdi = arg3[1];
                r13_1 = r15_1 - 1;
                result_1 = result;
                goto label_140010450;
            }
        }
    }
    return result;
}

int64_t sub_140010730(uint64_t arg1, char** arg2)
{
    int32_t _Size_5 = 0;
    int32_t _Size_4 = arg2[2];
    int32_t rdi = arg2[1];
    
    if (_Size_4 >= 0)
        _Size_5 = _Size_4;
    
    int32_t rax = _Size_5 + 0x17;
    
    if (rdi & 0x1000 && arg2[4])
        rax += rax / 3;
    
    int32_t rsi = *(arg2 + 0xc);
    
    if (rsi >= rax)
        rax = rsi;
    
    int64_t rax_3 = (rax + 0xf) & 0xfffffffffffffff0;
    sub_14000efc0(rax_3);
    
    if (!(rdi & 0x80))
        goto label_1400107a3;
    
    void var_68;
    void* r13_1;
    int32_t _Size_3;
    
    if (arg1 < 0)
    {
        arg1 = -(arg1);
    label_1400107b9:
        void* r8 = &var_68 - rax_3 + 0x20;
        
        while (true)
        {
            if (&var_68 - rax_3 + 0x20 != r8 && rdi & 0x1000 && arg2[4]
                && ((r8 - (&var_68 - rax_3 + 0x20)) & 0x8000000000000003) == 3)
            {
                *r8 = 0x2c;
                r8 += 1;
            }
            
            r13_1 = r8 + 1;
            uint64_t rdx_1 = arg1 / 0xa;
            *r8 = arg1 - (rdx_1 + (rdx_1 << 2)) * 2 + 0x30;
            
            if (arg1 <= 9)
                break;
            
            arg1 = rdx_1;
            r8 = r13_1;
        }
        
        if (_Size_4 <= 0)
            goto label_140010863;
        
        _Size_3 = _Size_4 - (r13_1 - (&var_68 - rax_3 + 0x20));
        
        if (_Size_3 > 0)
            goto label_14001084a;
        
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
        arg2[1] = rdi;
    label_1400107a3:
        
        if (arg1)
            goto label_1400107b9;
        
        r13_1 = &var_68 - rax_3 + 0x20;
        _Size_3 = _Size_4;
        bool rax_11 = true;
        
        if (_Size_4 > 0)
        {
        label_14001084a:
            int64_t _Size_1 = _Size_3;
            void* rcx = r13_1;
            r13_1 += _Size_1;
            memset(rcx, 0x30, _Size_1);
        label_140010863:
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
        *(arg2 + 0xc) = rsi_1;
        
        if (rsi_1 > 0)
        {
            if (!(rdi & 0x1c0))
            {
                if (_Size_4 < 0 && (rdi & 0x600) == 0x200)
                    goto label_140010a41;
                
                goto label_14001089b;
            }
            
            *(arg2 + 0xc) = rsi_1 - 1;
            
            if (_Size_4 >= 0 || (rdi & 0x600) != 0x200)
            {
            label_14001089b:
                
                if (!(rdi & 0x400))
                {
                    int32_t rax_25 = *(arg2 + 0xc);
                    *(arg2 + 0xc) = rax_25 - 1;
                    
                    if (rax_25 > 0)
                    {
                        int32_t i;
                        
                        do
                        {
                            sub_14000fdd0(0x20, arg2);
                            i = *(arg2 + 0xc);
                            *(arg2 + 0xc) = i - 1;
                        } while (i > 0);
                        rdi = arg2[1];
                    }
                }
            }
            else
            {
            label_140010a41:
                int32_t _Size_2 = *(arg2 + 0xc);
                *(arg2 + 0xc) = _Size_2 - 1;
                
                if (_Size_2 > 0)
                {
                    uint64_t _Size = _Size_2;
                    void* rcx_2 = r13_1;
                    r13_1 += _Size;
                    memset(rcx_2, 0x30, _Size);
                    *(arg2 + 0xc) = 0xffffffff;
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
                rax_17 = *(arg2 + 0x24);
            
            if (!(rdi & 0x4000) && arg2[5] <= rax_17)
                goto label_1400108dd;
            
            int32_t _Character = *rsi_2;
            FILE* _Stream = *arg2;
            
            if (!(rdi & 0x2000))
            {
                *(_Stream + *(arg2 + 0x24)) = _Character;
                rax_17 = *(arg2 + 0x24);
            label_1400108dd:
                *(arg2 + 0x24) = rax_17 + 1;
                
                if (&var_68 - rax_3 + 0x20 == rsi_2)
                    break;
            }
            else
            {
                fputc(_Character, _Stream);
                *(arg2 + 0x24) += 1;
                
                if (&var_68 - rax_3 + 0x20 == rsi_2)
                    break;
            }
            
            rdi = arg2[1];
        }
    }
    
    int32_t result = *(arg2 + 0xc);
    
    while (true)
    {
        int32_t result_1 = result;
        result -= 1;
        *(arg2 + 0xc) = result;
        
        if (result_1 <= 0)
            break;
        
        int16_t rcx_1 = arg2[1];
        int32_t rdx_2;
        
        if (!(*rcx_1[1] & 0x40))
            rdx_2 = *(arg2 + 0x24);
        
        if (*rcx_1[1] & 0x40 || arg2[5] > rdx_2)
        {
            char* _Stream_1 = *arg2;
            *rcx_1[1] &= 0x20;
            
            if (!*rcx_1[1])
            {
                _Stream_1[*(arg2 + 0x24)] = 0x20;
                rdx_2 = *(arg2 + 0x24);
                result = *(arg2 + 0xc);
            }
            else
            {
                fputc(0x20, _Stream_1);
                rdx_2 = *(arg2 + 0x24);
                result = *(arg2 + 0xc);
            }
        }
        
        *(arg2 + 0x24) = rdx_2 + 1;
    }
    
    return result;
}

int64_t sub_140010ae0(char** arg1)
{
    int64_t var_30;
    wchar16 rdx;
    
    if (*(arg1 + 0x14) == 0xfffffffd)
    {
        var_30 = 0;
        wchar16 var_32;
        int32_t rax_10 = sub_140015010(&var_32, localeconv()->decimal_point, 0x10, &var_30);
        
        if (rax_10 <= 0)
            rdx = arg1[3];
        else
        {
            rdx = var_32;
            arg1[3] = rdx;
        }
        
        *(arg1 + 0x14) = rax_10;
    }
    else
        rdx = arg1[3];
    
    if (!rdx)
        return sub_14000fdd0(0x2e, arg1);
    
    int64_t rax_3 = (*(arg1 + 0x14) + 0xf) & 0xfffffffffffffff0;
    sub_14000efc0(rax_3);
    var_30 = 0;
    void var_58;
    void* rsi = &var_58 - rax_3 + 0x20;
    int32_t rax_4 = sub_140014d70(rsi, rdx);
    
    if (rax_4 <= 0)
        return sub_14000fdd0(0x2e, arg1);
    
    void* r12_1 = rsi + rax_4 - 1 + 1;
    int32_t result;
    
    while (true)
    {
        int16_t rdx_2 = arg1[1];
        rsi += 1;
        int32_t rax_6;
        
        if (!(*rdx_2[1] & 0x40))
            rax_6 = *(arg1 + 0x24);
        
        if (*rdx_2[1] & 0x40 || arg1[5] > rax_6)
        {
            int32_t _Character = *(rsi - 1);
            char* _Stream = *arg1;
            *rdx_2[1] &= 0x20;
            
            if (!*rdx_2[1])
            {
                _Stream[*(arg1 + 0x24)] = _Character;
                rax_6 = *(arg1 + 0x24);
            }
            else
            {
                fputc(_Character, _Stream);
                result = *(arg1 + 0x24) + 1;
                *(arg1 + 0x24) = result;
                
                if (r12_1 == rsi)
                    break;
                
                continue;
            }
        }
        
        result = rax_6 + 1;
        *(arg1 + 0x24) = result;
        
        if (r12_1 == rsi)
            break;
    }
    
    return result;
}

int64_t sub_140010c30(int32_t arg1, char* arg2, int32_t arg3, char** arg4)
{
    int32_t rax = *(arg4 + 0xc);
    char* rdi = arg2;
    int32_t i_5 = arg3;
    int32_t rax_1;
    int32_t i_4;
    int32_t rdx;
    
    if (arg3 <= 0)
    {
        if (rax > 0)
        {
            rdx = arg4[2];
            rax_1 = rax - 1;
            
            if (rax_1 <= rdx)
                goto label_140010db7;
            
        label_140010c64:
            i_4 = rax_1 - rdx;
            *(arg4 + 0xc) = i_4;
            
            if (rdx > 0)
                goto label_140010c71;
            
            int16_t rdx_18 = arg4[1];
            
            if (*rdx_18[1] & 8)
                goto label_140010c71;
            
            if (i_5 <= 0)
                goto label_140010c8c;
            
            *rdx_18[1] &= 0x10;
            
            if (!*rdx_18[1])
                goto label_140010c8c;
            
            if (!arg4[4])
                goto label_140010c88;
            
            goto label_140010f1e;
        }
        
        int32_t rdx_1;
        
        if (rax)
        {
        label_140010db7:
            *(arg4 + 0xc) = 0xffffffff;
            
            if (!arg1)
            {
            label_140010cdb:
                rdx_1 = arg4[1];
            label_140010cde:
                
                if (*rdx_1[1] & 1)
                    sub_14000fdd0(0x2b, arg4);
                else if (rdx_1 & 0x40)
                    sub_14000fdd0(0x20, arg4);
            }
            else
                sub_14000fdd0(0x2d, arg4);
        }
        else
        {
            int32_t rax_13 = arg4[2];
            
            if (rax_13 >= 0)
                goto label_140010db7;
            
            i_4 = -(rax_13);
            *(arg4 + 0xc) = i_4;
            
            if (*(arg4 + 9) & 8)
            {
            label_140010c71:
                i_4 -= 1;
                *(arg4 + 0xc) = i_4;
                
                if (i_5 <= 0 || !(*(arg4 + 9) & 0x10) || !arg4[4])
                    goto label_140010c88;
                
                goto label_140010f1e;
            }
            
        label_140010c8c:
            int32_t rax_9;
            
            if (arg1)
            {
                *(arg4 + 0xc) = i_4 - 1;
                
                if (i_4 != 1 && !(arg4[1] & 0x600))
                {
                label_140010e93:
                    rax_9 = i_4 - 2;
                    goto label_140010e96;
                }
                
                sub_14000fdd0(0x2d, arg4);
            }
            else
            {
                rdx_1 = arg4[1];
                
                if (rdx_1 & 0x1c0)
                {
                    *(arg4 + 0xc) = i_4 - 1;
                    
                    if (i_4 == 1 || *rdx_1[1] & 6)
                        goto label_140010cde;
                    
                    goto label_140010e93;
                }
                
                *rdx_1[1] &= 6;
                
                if (!*rdx_1[1])
                {
                    rax_9 = i_4 - 1;
                label_140010e96:
                    *(arg4 + 0xc) = rax_9;
                    int32_t i;
                    
                    do
                    {
                        sub_14000fdd0(0x20, arg4);
                        i = *(arg4 + 0xc);
                        *(arg4 + 0xc) = i - 1;
                    } while (i > 0);
                    goto label_140010cd3;
                }
            }
        }
    }
    else
    {
        if (arg3 <= rax)
        {
            rdx = arg4[2];
            rax_1 = rax - arg3;
            
            if (rax_1 > rdx)
                goto label_140010c64;
            
            *(arg4 + 0xc) = 0xffffffff;
            i_4 = -1;
            
            if (*(arg4 + 9) & 0x10 && arg4[4])
                goto label_140010f1e;
            
        label_140010c88:
            
            if (i_4 <= 0)
                goto label_140010cd3;
            
            goto label_140010c8c;
        }
        
        *(arg4 + 0xc) = 0xffffffff;
        
        if (*(arg4 + 9) & 0x10 && arg4[4])
        {
            i_4 = -1;
        label_140010f1e:
            int32_t i_1 = i_4;
            uint32_t r8_3 = (i_5 + 2) / 3;
            
            if (r8_3 == 1)
                goto label_140010c88;
            
            while (i_1 > 0)
            {
                i_1 -= 1;
                *(arg4 + 0xc) = i_1;
                
                if (r8_3 - 1 - i_4 == -(i_1))
                {
                    i_4 = i_1;
                    goto label_140010c88;
                }
            }
            
            goto label_140010cd3;
        }
        
    label_140010cd3:
        
        if (!arg1)
            goto label_140010cdb;
        
        sub_14000fdd0(0x2d, arg4);
    }
    int32_t rax_2 = *(arg4 + 0xc);
    
    if (rax_2 > 0 && (arg4[1] & 0x600) == 0x200)
    {
        *(arg4 + 0xc) = rax_2 - 1;
        int32_t i_2;
        
        do
        {
            sub_14000fdd0(0x30, arg4);
            i_2 = *(arg4 + 0xc);
            *(arg4 + 0xc) = i_2 - 1;
        } while (i_2 > 0);
    }
    
    int32_t rax_5;
    
    if (i_5 <= 0)
    {
        sub_14000fdd0(0x30, arg4);
        rax_5 = arg4[2];
        
        if (rax_5 <= 0 && !(*(arg4 + 9) & 8))
        {
            if (i_5)
                goto label_140010e59;
            
            arg4[2] = rax_5 - 1;
            return rax_5 - 1;
        }
        
    label_140010e4b:
        sub_140010ae0(arg4);
        
        if (i_5)
        {
            rax_5 = arg4[2];
        label_140010e59:
            arg4[2] = rax_5 + i_5;
            int32_t i_3;
            
            do
            {
                sub_14000fdd0(0x30, arg4);
                i_3 = i_5;
                i_5 += 1;
            } while (i_3 != 0xffffffff);
        }
    }
    else
    {
        while (true)
        {
            char rax_3 = *rdi;
            int32_t rcx_1 = 0x30;
            
            if (rax_3)
            {
                rdi = &rdi[1];
                rcx_1 = rax_3;
            }
            
            sub_14000fdd0(rcx_1, arg4);
            int32_t i_6 = i_5;
            i_5 -= 1;
            
            if (i_6 == 1)
                break;
            
            if (*(arg4 + 9) & 0x10 && arg4[4] && i_5 * 0xaaaaaaab <= 0x55555555)
                sub_14000fe30(&arg4[4], 1, arg4);
        }
        
        rax_5 = arg4[2];
        
        if (rax_5 <= 0)
        {
            if (*(arg4 + 9) & 8)
                goto label_140010e4b;
            
            arg4[2] = rax_5 - 1;
            return rax_5 - 1;
        }
        
        sub_140010ae0(arg4);
    }
    int32_t result;
    
    while (true)
    {
        result = arg4[2];
        arg4[2] = result - 1;
        
        if (result <= 0)
            break;
        
        char rax_7 = *rdi;
        int32_t rcx_4 = 0x30;
        
        if (rax_7)
        {
            rdi = &rdi[1];
            rcx_4 = rax_7;
        }
        
        sub_14000fdd0(rcx_4, arg4);
    }
    
    return result;
}

int64_t sub_140011010(int32_t arg1, char* arg2, int32_t arg3, char** arg4)
{
    int32_t r10 = 1;
    int64_t rdi = arg3 - 1;
    int32_t r8_1 = (arg3 - 1) >> 0x1f;
    int32_t rcx_1 = (rdi * 0x66666667) >> 0x22;
    int32_t rcx_2 = rcx_1 - r8_1;
    
    if (rcx_1 != r8_1)
    {
        int32_t rax_3;
        int32_t rcx_3;
        
        do
        {
            rcx_3 = rcx_2 >> 0x1f;
            r10 += 1;
            rax_3 = (rcx_2 * 0x66666667) >> 0x22;
            rcx_2 s/= 0xa;
        } while (rax_3 != rcx_3);
    }
    
    int32_t rax_5 = *(arg4 + 0x2c);
    
    if (rax_5 == 0xffffffff)
    {
        *(arg4 + 0x2c) = 2;
        rax_5 = 2;
    }
    
    int32_t r8_2 = *(arg4 + 0xc);
    
    if (r10 >= rax_5)
        rax_5 = r10;
    
    int32_t rax_7 = r8_2 - (rax_5 + 2);
    
    if (r8_2 <= rax_5 + 2)
        rax_7 = -1;
    
    *(arg4 + 0xc) = rax_7;
    sub_140010c30(arg1, arg2, 1, arg4);
    int32_t rcx_6 = arg4[1];
    arg4[2] = *(arg4 + 0x2c);
    arg4[1] = rcx_6 | 0x1c0;
    sub_14000fdd0((rcx_6 & 0x20) | 0x45, arg4);
    *(arg4 + 0xc) += rax_5 + 1;
    /* tailcall */
    return sub_140010730(rdi, arg4);
}

int64_t sub_1400110e0(int80_t* arg1, char** arg2)
{
    int32_t r8 = arg2[2];
    int32_t r8_1;
    
    if (r8 < 0)
    {
        arg2[2] = 6;
        r8_1 = 7;
    }
    else
        r8_1 = r8 + 1;
    
    int80_t var_38 = *arg1;
    int32_t var_20;
    int32_t var_1c;
    void* rax = sub_14000fce0(2, &var_38, r8_1, &var_1c, &var_20);
    int32_t r8_2 = var_1c;
    
    if (r8_2 == 0xffff8000)
    {
        sub_140010160(var_20, rax, arg2);
        return sub_140012430(rax);
    }
    
    sub_140011010(var_20, rax, r8_2, arg2);
    return sub_140012430(rax);
}

int64_t sub_140011180(int80_t* arg1, char** arg2)
{
    int32_t r8 = arg2[2];
    
    if (r8 < 0)
    {
        arg2[2] = 6;
        r8 = 6;
    }
    
    int80_t var_38 = *arg1;
    int32_t var_20;
    int32_t var_1c;
    void* rax = sub_14000fce0(3, &var_38, r8, &var_1c, &var_20);
    int32_t r8_1 = var_1c;
    
    if (r8_1 == 0xffff8000)
        sub_140010160(var_20, rax, arg2);
    else
    {
        sub_140010c30(var_20, rax, r8_1, arg2);
        int32_t rax_1 = *(arg2 + 0xc);
        
        while (true)
        {
            int32_t rdx_4 = rax_1;
            rax_1 -= 1;
            *(arg2 + 0xc) = rax_1;
            
            if (rdx_4 <= 0)
                break;
            
            int16_t rcx_1 = arg2[1];
            int32_t rdx_2;
            
            if (!(*rcx_1[1] & 0x40))
                rdx_2 = *(arg2 + 0x24);
            
            if (*rcx_1[1] & 0x40 || arg2[5] > rdx_2)
            {
                char* _Stream = *arg2;
                *rcx_1[1] &= 0x20;
                
                if (!*rcx_1[1])
                {
                    _Stream[*(arg2 + 0x24)] = 0x20;
                    rdx_2 = *(arg2 + 0x24);
                    rax_1 = *(arg2 + 0xc);
                }
                else
                {
                    fputc(0x20, _Stream);
                    rdx_2 = *(arg2 + 0x24);
                    rax_1 = *(arg2 + 0xc);
                }
            }
            
            *(arg2 + 0x24) = rdx_2 + 1;
        }
    }
    
    return sub_140012430(rax);
}

int64_t sub_140011260(int80_t* arg1, int64_t* arg2)
{
    int32_t r8 = arg2[2];
    
    if (r8 < 0)
    {
        arg2[2] = 6;
        r8 = 6;
    }
    else if (!r8)
    {
        arg2[2] = 1;
        r8 = 1;
    }
    
    int80_t var_38 = *arg1;
    int32_t var_20;
    int32_t var_1c;
    void* _Str = sub_14000fce0(2, &var_38, r8, &var_1c, &var_20);
    int32_t rdi = var_1c;
    
    if (rdi == 0xffff8000)
    {
        sub_140010160(var_20, _Str, arg2);
        return sub_140012430(_Str);
    }
    
    int32_t rax_1 = arg2[1] & 0x800;
    
    if (rdi >= 0xfffffffd)
    {
        int32_t rdx_1 = arg2[2];
        
        if (rdi <= rdx_1)
        {
            if (!rax_1)
            {
                int32_t rax_9 = strlen(_Str);
                int32_t rax_10 = rax_9 - rdi;
                arg2[2] = rax_10;
                
                if (rax_9 - rdi < 0)
                {
                    int32_t rdx_8 = *(arg2 + 0xc);
                    
                    if (rdx_8 > 0)
                        *(arg2 + 0xc) = rax_10 + rdx_8;
                }
            }
            else
                arg2[2] = rdx_1 - rdi;
            
            sub_140010c30(var_20, _Str, rdi, arg2);
            
            while (true)
            {
                int32_t rax_2 = *(arg2 + 0xc);
                *(arg2 + 0xc) = rax_2 - 1;
                
                if (rax_2 <= 0)
                    break;
                
                sub_14000fdd0(0x20, arg2);
            }
            
            return sub_140012430(_Str);
        }
    }
    
    int32_t rax_5;
    
    if (rax_1)
        rax_5 = arg2[2] - 1;
    else
        rax_5 = strlen(_Str) - 1;
    
    arg2[2] = rax_5;
    sub_140011010(var_20, _Str, rdi, arg2);
    return sub_140012430(_Str);
}

int64_t sub_1400113e0(uint64_t arg1, int16_t arg2, char** arg3)
{
    int32_t r10 = arg3[2];
    uint64_t r9 = arg1;
    int64_t rax_6;
    int32_t rcx_8;
    int32_t i_4;
    int64_t rbp;
    int16_t r8;
    
    if (arg2 || arg1)
    {
        r8 = arg2 - 3;
        
        if (r10 > 0xe)
        {
            rbp = r8;
            i_4 = 0x10;
            
            if (!r9 && r10 <= 0)
            {
                rcx_8 = arg3[1];
                goto label_140011538;
            }
            
            goto label_140011424;
        }
        
        uint64_t r9_1 = r9 >> 1;
        int64_t rax_5 = 4 << (0xe - r10) << 2;
        rax_6 = rax_5 + r9_1;
        
        if (rax_5 + r9_1 >= 0)
        {
            rbp = r8;
            goto label_140011520;
        }
        
        r8 = arg2 + 1;
        rbp = r8;
        r9 = rax_6 >> 3 >> (0xf - r10) << 2;
    label_1400114e4:
        i_4 = r10 + 1;
        goto label_140011424;
    }
    
    if (r10 <= 0xe)
    {
        rbp = 0;
        r8 = 0;
        rax_6 = 4 << (0xe - r10) << 2;
    label_140011520:
        uint64_t rax_10 = (rax_6 * 2) >> (0xf - r10) << 2;
        r9 = rax_10;
        
        if (rax_10 || r10)
            goto label_1400114e4;
        
        rcx_8 = arg3[1];
        goto label_140011538;
    }
    
    char var_58;
    char* i_3;
    int32_t r10_4;
    int32_t r12_3;
    
    if (r10 > 0)
    {
        rbp = 0;
        r8 = 0;
        r9 = 0;
        i_4 = 0x10;
    label_140011424:
        rcx_8 = arg3[1];
        i_3 = &var_58;
        int32_t i;
        
        do
        {
            int32_t rax_3 = r9 & 0xf;
            char* i_5;
            
            if (i_4 != 1)
            {
                int32_t r10_1 = arg3[2];
                
                if (r10_1 > 0)
                    arg3[2] = r10_1 - 1;
                
                i_5 = i_3;
                goto label_140011492;
            }
            
            int32_t r10_3;
            
            if (&var_58 >= i_3 && !(rcx_8 & 0x800))
                r10_3 = arg3[2];
            
            if (&var_58 >= i_3 && !(rcx_8 & 0x800) && r10_3 <= 0)
            {
                if (rax_3)
                {
                    i_5 = i_3;
                    goto label_140011496;
                }
                
                if (!r10_3)
                {
                    *i_3 = 0x30;
                    i_3 = &i_3[1];
                }
                
                break;
            }
            
            *i_3 = 0x2e;
            i_5 = &i_3[1];
        label_140011492:
            
            if (rax_3)
            {
            label_140011496:
                
                if (rax_3 <= 9)
                    goto label_140011458;
                
                *i_5 = (rax_3 + 0x37) | (rcx_8 & 0x20);
                i_3 = &i_5[1];
            }
            else if (&var_58 < i_5 || arg3[2] >= 0)
            {
            label_140011458:
                *i_5 = rax_3 + 0x30;
                i_3 = &i_5[1];
            }
            else
                i_3 = i_5;
            
            r9 u>>= 4;
            i = i_4;
            i_4 -= 1;
        } while (i != 1);
        
        if (i_3 == &var_58)
        {
            if (arg3[2] > 0)
                goto label_140011540;
            
            goto label_140011538;
        }
        
        r10_4 = *(arg3 + 0xc);
        r12_3 = 2;
        
        if (r10_4 <= 0)
            goto label_140011564;
        
        goto label_14001167c;
    }
    
    rcx_8 = arg3[1];
    rbp = 0;
    r8 = 0;
label_140011538:
    char* rax_11 = &var_58;
    
    if (!(*rcx_8[1] & 8))
        goto label_14001154a;
    
label_140011540:
    var_58 = 0x2e;
    void var_57;
    rax_11 = &var_57;
label_14001154a:
    r10_4 = *(arg3 + 0xc);
    *rax_11 = 0x30;
    i_3 = &rax_11[1];
    r12_3 = 2;
    
    if (r10_4 <= 0)
        goto label_140011564;
    
label_14001167c:
    int32_t rdx_5 = arg3[2];
    int32_t r9_3 = i_3 - &var_58;
    
    if (rdx_5 > 0)
        r9_3 += rdx_5;
    
    int32_t r9_4 = r9_3 + 6;
    int32_t rax_16 = r8 >> 0x1f;
    int32_t r11_4 = r9_4;
    int32_t rdx_10 = (r8 * 0x66666667) >> 0x22;
    int32_t rdx_11 = rdx_10 - rax_16;
    
    if (rdx_10 != rax_16)
    {
        int32_t rax_19;
        int32_t rdx_12;
        
        do
        {
            rdx_12 = rdx_11 >> 0x1f;
            r11_4 += 1;
            rax_19 = (rdx_11 * 0x66666667) >> 0x22;
            rdx_11 s/= 0xa;
        } while (rax_19 != rdx_12);
        r12_3 = r11_4 - r9_4 + 2;
    }
    
    int32_t r10_5;
    
    if (r10_4 <= r11_4)
    {
        r10_5 = -1;
    label_1400117e6:
        *(arg3 + 0xc) = r10_5;
    label_140011564:
        
        if (rcx_8 & 0x80)
            sub_14000fdd0(0x2d, arg3);
        else
        {
        label_14001156d:
            
            if (*rcx_8[1] & 1)
                sub_14000fdd0(0x2b, arg3);
            else if (rcx_8 & 0x40)
                sub_14000fdd0(0x20, arg3);
        }
    }
    else
    {
        r10_5 = r10_4 - r11_4;
        
        if (*rcx_8[1] & 6)
            goto label_1400117e6;
        
        *(arg3 + 0xc) = r10_5 - 1;
        int32_t i_1;
        
        do
        {
            sub_14000fdd0(0x20, arg3);
            i_1 = *(arg3 + 0xc);
            *(arg3 + 0xc) = i_1 - 1;
        } while (i_1 > 0);
        rcx_8 = arg3[1];
        
        if (!(rcx_8 & 0x80))
            goto label_14001156d;
        
        sub_14000fdd0(0x2d, arg3);
    }
    sub_14000fdd0(0x30, arg3);
    sub_14000fdd0((arg3[1] & 0x20) | 0x58, arg3);
    int32_t rax_12 = *(arg3 + 0xc);
    
    if (rax_12 > 0 && *(arg3 + 9) & 2)
    {
        *(arg3 + 0xc) = rax_12 - 1;
        int32_t i_2;
        
        do
        {
            sub_14000fdd0(0x30, arg3);
            i_2 = *(arg3 + 0xc);
            *(arg3 + 0xc) = i_2 - 1;
        } while (i_2 > 0);
    }
    
    if (&var_58 < i_3)
    {
        do
        {
            int32_t rcx_13 = i_3[-1];
            i_3 -= 1;
            
            if (rcx_13 == 0x2e)
                sub_140010ae0(arg3);
            else if (rcx_13 == 0x2c)
            {
                int16_t rax_14 = arg3[4];
                int16_t var_5a = rax_14;
                
                if (rax_14)
                    sub_14000fe30(&var_5a, 1, arg3);
            }
            else
                sub_14000fdd0(rcx_13, arg3);
        } while (i_3 != &var_58);
    }
    
    while (true)
    {
        int32_t rax_21 = arg3[2];
        arg3[2] = rax_21 - 1;
        
        if (rax_21 <= 0)
            break;
        
        sub_14000fdd0(0x30, arg3);
    }
    
    sub_14000fdd0((arg3[1] & 0x20) | 0x50, arg3);
    *(arg3 + 0xc) += r12_3;
    arg3[1] |= 0x1c0;
    /* tailcall */
    return sub_140010730(rbp, arg3);
}

uint64_t sub_1400118a0(int32_t arg1, char* arg2, int32_t arg3, char* arg4, int64_t* arg5)
{
    int64_t* r13 = arg5;
    int32_t* rax = _errno();
    int32_t _Character = *arg4;
    int32_t rdi_1 = arg1 & 0x6000;
    int32_t _ErrorMessage = *rax;
    void* rbx_1 = &arg4[1];
    char* _Stream_1 = arg2;
    int64_t var_68 = -0x200000001;
    int16_t var_60 = 0;
    char _Character_2 = _Character;
    int32_t var_70 = rdi_1;
    int32_t var_6c = 0xffffffff;
    int32_t var_5c = 0;
    int16_t var_58 = 0;
    int32_t _Character_1 = 0;
    int32_t var_4c = 0xffffffff;
    
    if (_Character)
    {
        do
        {
            if (_Character != 0x25)
            {
                int16_t rdx = var_70;
                
                if (*rdx[1] & 0x40 || arg3 > _Character_1)
                {
                    char* _Stream = _Stream_1;
                    *rdx[1] &= 0x20;
                    
                    if (*rdx[1])
                        fputc(_Character, _Stream);
                    else
                        _Stream[_Character_1] = _Character_2;
                }
                
                _Character_1 += 1;
            }
            else
            {
                char rax_1 = *rbx_1;
                var_70 = rdi_1;
                var_6c = -1;
                
                if (!rax_1)
                    break;
                
                void* rsi_3 = rbx_1;
                int32_t* r11_1 = &var_6c;
                int32_t r10_1 = 0;
                int32_t r14_1 = 0;
                
                while (true)
                {
                    int32_t rcx = rax_1;
                    long double var_a8;
                    int16_t var_88;
                    int32_t rax_12;
                    uint64_t* rcx_4;
                    int80_t* rdx_16;
                    double rdx_18;
                    long double* rdx_20;
                    void* rbx_5;
                    int64_t* rbx_6;
                    
                    if (rax_1 - 0x20 > 0x5a)
                    {
                    label_1400119fb:
                        
                        if (rax_1 - 0x30 > 9 || r14_1 > 3)
                        {
                        label_140011c21:
                            sub_14000fdd0(0x25, &_Stream_1);
                            break;
                            break;
                        }
                        
                        if (r14_1)
                            goto label_14001215f;
                        
                        r14_1 = 1;
                    label_140011a1c:
                        
                        if (!r11_1)
                        {
                            rax_1 = *(rsi_3 + 1);
                            rsi_3 += 1;
                        }
                        else
                        {
                            uint64_t rax_3 = *r11_1;
                            
                            if (rax_3 < 0)
                            {
                                rax_1 = *(rsi_3 + 1);
                                rsi_3 += 1;
                                *r11_1 = rcx - 0x30;
                            }
                            else
                            {
                                *r11_1 = rcx + ((rax_3 * 5) << 1) - 0x30;
                                rax_1 = *(rsi_3 + 1);
                                rsi_3 += 1;
                            }
                        }
                    }
                    else
                        switch (rax_1)
                        {
                            case 0x20:
                            {
                                if (r14_1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                else
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    var_70 |= 0x40;
                                    rsi_3 += 1;
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
                                goto label_1400119fb;
                            }
                            case 0x23:
                            {
                                if (r14_1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                else
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    var_70 |= 0x800;
                                    rsi_3 += 1;
                                }
                                break;
                            }
                            case 0x25:
                            {
                                rbx_1 = rsi_3 + 1;
                                sub_14000fdd0(0x25, &_Stream_1);
                                break;
                                break;
                                break;
                            }
                            case 0x27:
                            {
                                if (r14_1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                else
                                {
                                    var_70 |= 0x1000;
                                    var_88 = 0;
                                    wchar16 var_8a;
                                    int32_t rax_29 = sub_140015010(&var_8a, 
                                        localeconv()->thousands_sep, 0x10, &var_88);
                                    
                                    if (rax_29 > 0)
                                        wchar16 var_58_1 = var_8a;
                                    
                                    int32_t var_5c_1 = rax_29;
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                break;
                            }
                            case 0x2a:
                            {
                                if (!r11_1)
                                    goto label_140011e19;
                                
                                if (r14_1 & 0xfffffffd)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    r11_1 = nullptr;
                                    rsi_3 += 1;
                                    r14_1 = 4;
                                }
                                else
                                {
                                    int32_t rax_30 = *r13;
                                    *r11_1 = rax_30;
                                    
                                    if (rax_30 >= 0)
                                        goto label_140012073;
                                    
                                    if (r14_1)
                                    {
                                        rax_1 = *(rsi_3 + 1);
                                        r13 = &r13[1];
                                        rsi_3 += 1;
                                        r11_1 = nullptr;
                                        var_68 = 0xffffffff;
                                        r14_1 = 2;
                                    }
                                    else
                                    {
                                        var_70 |= 0x400;
                                        var_6c = -(var_6c);
                                    label_140012073:
                                        rax_1 = *(rsi_3 + 1);
                                        r13 = &r13[1];
                                        rsi_3 += 1;
                                        r11_1 = nullptr;
                                    }
                                }
                                break;
                            }
                            case 0x2b:
                            {
                                if (r14_1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                else
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    var_70 |= 0x100;
                                    rsi_3 += 1;
                                }
                                break;
                            }
                            case 0x2d:
                            {
                                if (r14_1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    rsi_3 += 1;
                                }
                                else
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    var_70 |= 0x400;
                                    rsi_3 += 1;
                                }
                                break;
                            }
                            case 0x2e:
                            {
                                if (r14_1 <= 1)
                                {
                                    rax_1 = *(rsi_3 + 1);
                                    r14_1 = 2;
                                    rsi_3 += 1;
                                    var_68 = 0;
                                    r11_1 = &var_68;
                                }
                                else
                                {
                                label_140011e19:
                                    rax_1 = *(rsi_3 + 1);
                                    r14_1 = 4;
                                    rsi_3 += 1;
                                }
                                break;
                            }
                            case 0x30:
                            {
                                if (r14_1)
                                {
                                    if (r14_1 > 3)
                                        goto label_140011c21;
                                    
                                    rcx = 0x30;
                                label_14001215f:
                                    
                                    if (r14_1 != 2)
                                        goto label_140011a1c;
                                    
                                    r14_1 = 3;
                                    goto label_140011a1c;
                                }
                                
                                rax_1 = *(rsi_3 + 1);
                                var_70 |= 0x200;
                                rsi_3 += 1;
                                break;
                            }
                            case 0x41:
                            {
                                rax_12 = var_70;
                                rcx_4 = *r13;
                                
                                if (rax_12 & 4)
                                    goto label_140011c5e;
                                
                                goto label_140011e5d;
                            }
                            case 0x43:
                            {
                                var_68 = 0xffffffff;
                                rbx_5 = &r13[1];
                            label_140011eff:
                                int16_t rax_24 = *r13;
                                r13 = rbx_5;
                                rbx_1 = rsi_3 + 1;
                                var_88 = rax_24;
                                sub_14000fe30(&var_88, 1, &_Stream_1);
                                break;
                                break;
                                break;
                            }
                            case 0x45:
                            {
                                rdx_20 = *r13;
                                
                                if (var_70 & 4)
                                    goto label_140011dcd;
                                
                                goto label_140011f4a;
                            }
                            case 0x46:
                            {
                                rdx_18 = *r13;
                                
                                if (var_70 & 4)
                                    goto label_140011d9f;
                                
                                goto label_140011f7b;
                            }
                            case 0x47:
                            {
                                rdx_16 = *r13;
                                
                                if (var_70 & 4)
                                    goto label_140011d67;
                                
                                goto label_140011fac;
                            }
                            case 0x49:
                            {
                                rax_1 = *(rsi_3 + 1);
                                
                                if (rax_1 == 0x36)
                                {
                                    if (*(rsi_3 + 2) != 0x34)
                                        goto label_140011c21;
                                    
                                    rax_1 = *(rsi_3 + 3);
                                    r10_1 = 3;
                                    rsi_3 += 3;
                                    r14_1 = 4;
                                }
                                else if (rax_1 != 0x33)
                                {
                                    rsi_3 += 1;
                                    r10_1 = 3;
                                    r14_1 = 4;
                                }
                                else
                                {
                                    if (*(rsi_3 + 2) != 0x32)
                                        goto label_140011c21;
                                    
                                    rax_1 = *(rsi_3 + 3);
                                    r10_1 = 2;
                                    rsi_3 += 3;
                                    r14_1 = 4;
                                }
                                break;
                            }
                            case 0x4c:
                            {
                                rax_1 = *(rsi_3 + 1);
                                var_70 |= 4;
                                rsi_3 += 1;
                                r14_1 = 4;
                                break;
                            }
                            case 0x53:
                            {
                                rbx_6 = &r13[1];
                            label_14001210a:
                                wchar16* _String = *r13;
                                
                                if (!_String)
                                    _String = u"(null)";
                                
                                int32_t rax_33 = var_68;
                                
                                if (rax_33 < 0)
                                    sub_14000fe30(_String, wcslen(_String), &_Stream_1);
                                else
                                    sub_14000fe30(_String, sub_140014b70(_String, rax_33), 
                                        &_Stream_1);
                                
                                r13 = rbx_6;
                                rbx_1 = rsi_3 + 1;
                                break;
                                break;
                                break;
                            }
                            case 0x58:
                            case 0x6f:
                            case 0x75:
                            case 0x78:
                            {
                                var_70 &= 0xfffffeff;
                                uint64_t rax_8;
                                
                                if (r10_1 == 3)
                                    rax_8 = *r13;
                                else if (r10_1 == 2)
                                    rax_8 = *r13;
                                else
                                {
                                    int32_t rax_7 = *r13;
                                    
                                    if (r10_1 == 1)
                                        rax_8 = rax_7;
                                    else
                                    {
                                        rax_8 = rax_7;
                                        
                                        if (r10_1 != 5)
                                            rax_8 = rax_7;
                                    }
                                }
                                
                                var_88 = rax_8;
                                
                                if (rcx == 0x75)
                                    sub_140010730(rax_8, &_Stream_1);
                                else
                                    sub_140010200(rcx, rax_8, &_Stream_1);
                                
                                goto label_140011d70;
                            }
                            case 0x61:
                            {
                                rcx_4 = *r13;
                                rax_12 = var_70 | 0x20;
                                var_70 = rax_12;
                                int32_t rdx_14;
                                
                                if (rax_12 & 4)
                                {
                                label_140011c5e:
                                    int32_t rbx_4 = rcx_4[1];
                                    uint64_t rcx_5 = *rcx_4;
                                    int32_t r10_2 = rbx_4;
                                    int32_t r9_3 = (rcx_5 >> 0x20 & 0x7fffffff) | rcx_5;
                                    
                                    if ((0xfffe - ((-(r9_3) | r9_3) >> 0x1f | (r10_2 * 2))) >> 0x10)
                                    {
                                        sub_140010160(0, "NaN", &_Stream_1);
                                        goto label_140011d70;
                                    }
                                    
                                    if (rbx_4 < 0)
                                    {
                                        rax_12 |= 0x80;
                                        var_70 = rax_12;
                                    }
                                    
                                    rdx_14 = rbx_4 & 0x7fff;
                                    
                                    if (!rdx_14)
                                    {
                                        if (rcx_5)
                                            rdx_14 = -0x3ffe;
                                        
                                        sub_1400113e0(rcx_5, rdx_14, &_Stream_1);
                                        goto label_140011d70;
                                    }
                                    
                                    if (rdx_14 != 0x7fff || r9_3)
                                    {
                                        rdx_14 -= 0x3fff;
                                        sub_1400113e0(rcx_5, rdx_14, &_Stream_1);
                                        goto label_140011d70;
                                    }
                                    
                                    sub_140010160(r10_2 & 0x8000, "Inf", &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                            label_140011e5d:
                                uint32_t r8_9 = rcx_4 >> 0x20;
                                
                                if (0x7ff00000 - ((-(rcx_4) | rcx_4) >> 0x1f | (r8_9 & 0x7fffffff))
                                    < 0)
                                {
                                    sub_140010160(0, "NaN", &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                                uint64_t* var_c8_1;
                                var_c8_1 = rcx_4;
                                int32_t var_c0;
                                
                                if (var_c0 < 0)
                                {
                                    rax_12 |= 0x80;
                                    var_70 = rax_12;
                                }
                                
                                int32_t r8_10 = r8_9 & 0x7ff00000;
                                int32_t rax_22 = (r8_9 & 0xfffff) | rcx_4;
                                rcx_4 = rax_22;
                                
                                if (!(r8_10 != 0x7ff00000 | rcx_4) && rax_22 | r8_10)
                                {
                                    sub_140010160(var_c0 & 0x8000, "Inf", &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                                uint64_t* rax_31 = var_c8_1;
                                rdx_14 = var_c0 & 0x7fff;
                                
                                if (!rdx_14)
                                {
                                label_1400121ef:
                                    
                                    if (rax_31)
                                        rdx_14 = -0x3fb;
                                }
                                else if (rdx_14 > 0x3c00)
                                {
                                    if (!rdx_14)
                                        goto label_1400121ef;
                                    
                                    rdx_14 -= 0x3ffc;
                                }
                                else
                                {
                                    rax_31 u>>= (0x3c01 - rdx_14);
                                    rdx_14 = (rdx_14 + 0x3c01 - rdx_14) - 0x3ffc;
                                }
                                
                                sub_1400113e0(rax_31 >> 3, rdx_14, &_Stream_1);
                                goto label_140011d70;
                            }
                            case 0x63:
                            {
                                rbx_5 = &r13[1];
                                var_68 = 0xffffffff;
                                
                                if (r10_1 - 2 <= 1)
                                    goto label_140011eff;
                                
                                var_88 = *r13;
                                r13 = rbx_5;
                                rbx_1 = rsi_3 + 1;
                                sub_14000ffc0(&var_88, 1, &_Stream_1);
                                break;
                                break;
                            }
                            case 0x64:
                            case 0x69:
                            {
                                var_70 |= 0x80;
                                int64_t rcx_1;
                                
                                if (r10_1 == 3)
                                    rcx_1 = *r13;
                                else
                                {
                                    rcx_1 = *r13;
                                    
                                    if (r10_1 != 2)
                                    {
                                        if (r10_1 == 1)
                                            rcx_1 = rcx_1;
                                        else if (r10_1 == 5)
                                            rcx_1 = rcx_1;
                                    }
                                }
                                
                                r13 = &r13[1];
                                rbx_1 = rsi_3 + 1;
                                sub_140010730(rcx_1, &_Stream_1);
                                break;
                                break;
                                break;
                            }
                            case 0x65:
                            {
                                rdx_20 = *r13;
                                int32_t rax_19 = var_70 | 0x20;
                                var_70 = rax_19;
                                
                                if (!(rax_19 & 4))
                                {
                                label_140011f4a:
                                    var_a8 = rdx_20;
                                    sub_1400110e0(&var_a8, &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                            label_140011dcd:
                                var_a8 = *rdx_20;
                                sub_1400110e0(&var_a8, &_Stream_1);
                                goto label_140011d70;
                            }
                            case 0x66:
                            {
                                rdx_18 = *r13;
                                int32_t rax_17 = var_70 | 0x20;
                                var_70 = rax_17;
                                
                                if (!(rax_17 & 4))
                                {
                                label_140011f7b:
                                    var_a8 = rdx_18;
                                    sub_140011180(&var_a8, &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                            label_140011d9f:
                                var_a8 = *rdx_18;
                                sub_140011180(&var_a8, &_Stream_1);
                                goto label_140011d70;
                            }
                            case 0x67:
                            {
                                rdx_16 = *r13;
                                int32_t rax_15 = var_70 | 0x20;
                                var_70 = rax_15;
                                
                                if (rax_15 & 4)
                                {
                                label_140011d67:
                                    var_a8 = *rdx_16;
                                    sub_140011260(&var_a8, &_Stream_1);
                                    goto label_140011d70;
                                }
                                
                            label_140011fac:
                                var_a8 = rdx_16;
                                sub_140011260(&var_a8, &_Stream_1);
                            label_140011d70:
                                r13 = &r13[1];
                                rbx_1 = rsi_3 + 1;
                                break;
                                break;
                                break;
                            }
                            case 0x68:
                            {
                                rax_1 = *(rsi_3 + 1);
                                
                                if (rax_1 == 0x68)
                                {
                                    rax_1 = *(rsi_3 + 2);
                                    r10_1 = 5;
                                    rsi_3 += 2;
                                    r14_1 = 4;
                                }
                                else
                                {
                                    rsi_3 += 1;
                                    r10_1 = 1;
                                    r14_1 = 4;
                                }
                                break;
                            }
                            case 0x6a:
                            case 0x74:
                            case 0x7a:
                            {
                                rax_1 = *(rsi_3 + 1);
                                r10_1 = 3;
                                rsi_3 += 1;
                                r14_1 = 4;
                                break;
                            }
                            case 0x6c:
                            {
                                rax_1 = *(rsi_3 + 1);
                                
                                if (rax_1 == 0x6c)
                                {
                                    rax_1 = *(rsi_3 + 2);
                                    r10_1 = 3;
                                    rsi_3 += 2;
                                    r14_1 = 4;
                                }
                                else
                                {
                                    rsi_3 += 1;
                                    r10_1 = 2;
                                    r14_1 = 4;
                                }
                                break;
                            }
                            case 0x6d:
                            {
                                rbx_1 = rsi_3 + 1;
                                sub_140010110(strerror(_ErrorMessage), &_Stream_1);
                                break;
                                break;
                                break;
                            }
                            case 0x6e:
                            {
                                int64_t* rdx_12 = *r13;
                                int64_t _Character_3 = _Character_1;
                                
                                if (r10_1 == 5)
                                    *rdx_12 = _Character_3;
                                else if (r10_1 == 1)
                                    *rdx_12 = _Character_3;
                                else if (r10_1 == 2 || r10_1 != 3)
                                    *rdx_12 = _Character_3;
                                else
                                    *rdx_12 = _Character_3;
                                
                                goto label_140011d70;
                            }
                            case 0x70:
                            {
                                if (!r14_1 && var_70 == rdi_1)
                                {
                                    var_68 = 0x10;
                                    int32_t rax_35;
                                    *rax_35[1] = *rdi_1[1] | 2;
                                    var_70 = rax_35;
                                }
                                
                                uint64_t rdx_10 = *r13;
                                r13 = &r13[1];
                                rbx_1 = rsi_3 + 1;
                                sub_140010200(0x78, rdx_10, &_Stream_1);
                                break;
                                break;
                                break;
                            }
                            case 0x73:
                            {
                                char* rcx_7 = *r13;
                                rbx_6 = &r13[1];
                                
                                if (r10_1 - 2 <= 1)
                                    goto label_14001210a;
                                
                                r13 = rbx_6;
                                rbx_1 = rsi_3 + 1;
                                sub_140010110(rcx_7, &_Stream_1);
                                break;
                                break;
                            }
                        }
                    
                    if (!rax_1)
                        goto label_140011a50;
                }
            }
            
            _Character_2 = *rbx_1;
            rbx_1 += 1;
            _Character = _Character_2;
        } while (_Character);
        
    label_140011a50:
        _Character = _Character_1;
    }
    
    return _Character;
}

void* sub_140012370(int32_t arg1)
{
    int32_t rbx = 0;
    
    if (arg1 > 0x1b)
    {
        int32_t rax_1 = 4;
        
        do
        {
            rax_1 *= 2;
            rbx += 1;
        } while (rax_1 + 0x17 < arg1);
    }
    
    int64_t* rax_2 = sub_140013fe0(rbx);
    *rax_2 = rbx;
    return rax_2 + 4;
}

void* sub_1400123b0(char* arg1, void** arg2, int32_t arg3)
{
    int32_t rbx;
    
    if (arg3 <= 0x1b)
        rbx = 0;
    else
    {
        int32_t rax_1 = 4;
        rbx = 0;
        
        do
        {
            rax_1 *= 2;
            rbx += 1;
        } while (arg3 > rax_1 + 0x17);
    }
    
    int64_t* rax_2 = sub_140013fe0(rbx);
    void* rdx_1 = &arg1[1];
    *rax_2 = rbx;
    char rcx_1 = *arg1;
    *(rax_2 + 4) = rcx_1;
    void* rax_3 = rax_2 + 4;
    
    if (rcx_1)
    {
        char i;
        
        do
        {
            i = *rdx_1;
            rax_3 += 1;
            rdx_1 += 1;
            *rax_3 = i;
        } while (i);
    }
    
    if (arg2)
        *arg2 = rax_3;
    
    return rax_2 + 4;
}

int64_t sub_140012430(void* arg1)
{
    int32_t rcx = *(arg1 - 4);
    *(arg1 + 4) = _mm_unpacklo_epi32(rcx, 1 << rcx);
    /* tailcall */
    return sub_1400140d0(arg1 - 4);
}

uint64_t sub_140012460(void* arg1, void* arg2)
{
    int32_t rsi = *(arg2 + 0x14);
    
    if (*(arg1 + 0x14) < rsi)
        return 0;
    
    int32_t rsi_1 = rsi - 1;
    void* rbx_1 = arg2 + 0x18;
    int64_t r10_2 = rsi_1 << 2;
    void* rdi_1 = rbx_1 + r10_2;
    void* r10_3 = r10_2 + arg1 + 0x18;
    int32_t r8_1 = *r10_3;
    int32_t rcx = *rdi_1 + 1;
    uint32_t temp0_1 = COMBINE(0, r8_1) / rcx;
    uint32_t var_4c_1 = temp0_1;
    
    if (r8_1 >= rcx)
    {
        void* r9_1 = rbx_1;
        void* r8_2 = arg1 + 0x18;
        uint64_t r14_1 = 0;
        uint64_t rcx_1 = 0;
        
        do
        {
            uint64_t rax_4 = *r9_1;
            uint64_t rdx_1 = *r8_2;
            r9_1 += 4;
            r8_2 += 4;
            int64_t rax_6 = rax_4 * temp0_1 + r14_1;
            r14_1 = rax_6 >> 0x20;
            uint64_t rax_9 = rdx_1 - rax_6 - rcx_1;
            *(r8_2 - 4) = rax_9;
            rcx_1 = rax_9 >> 0x20 & 1;
        } while (rdi_1 >= r9_1);
    }
    
    if (r8_1 >= rcx && !*r10_3)
    {
        while (true)
        {
            r10_3 -= 4;
            
            if (arg1 + 0x18 >= r10_3)
                break;
            
            if (*r10_3)
                break;
            
            rsi_1 -= 1;
        }
        
        *(arg1 + 0x14) = rsi_1;
        
        if (sub_1400146b0(arg1, arg2) >= 0)
            goto label_140012525;
    }
    else if (sub_1400146b0(arg1, arg2) >= 0)
    {
    label_140012525:
        void* rcx_5 = arg1 + 0x18;
        uint64_t rdx_4 = 0;
        
        do
        {
            uint64_t rax_11 = *rcx_5;
            uint64_t r8_3 = *rbx_1;
            rbx_1 += 4;
            rcx_5 += 4;
            uint64_t rax_13 = rax_11 - r8_3 - rdx_4;
            *(rcx_5 - 4) = rax_13;
            rdx_4 = rax_13 >> 0x20 & 1;
        } while (rdi_1 >= rbx_1);
        
        void* rax_15 = arg1 + 0x18 + (rsi_1 << 2);
        
        if (!*rax_15)
        {
            while (true)
            {
                rax_15 -= 4;
                
                if (arg1 + 0x18 >= rax_15)
                    break;
                
                if (*rax_15)
                    break;
                
                rsi_1 -= 1;
            }
            
            *(arg1 + 0x14) = rsi_1;
            var_4c_1 = temp0_1 + 1;
        }
        else
            var_4c_1 = temp0_1 + 1;
    }
    
    return var_4c_1;
}

void* sub_1400125e0(int32_t* arg1, int32_t arg2, int32_t* arg3, int32_t* arg4, int32_t arg5, int32_t arg6, int32_t* arg7, void** arg8)
{
    int32_t rbp = *arg4;
    int32_t var_c8 = arg5;
    int32_t* r15 = arg4;
    int32_t var_a8 = arg6;
    *arg4 = rbp & 0xffffffcf;
    int32_t rax_7 = rbp & 7;
    char* rcx_9;
    void** rdx_11;
    int32_t r8_4;
    
    if (rax_7 == 3)
    {
        rdx_11 = arg8;
        r8_4 = 8;
        rcx_9 = "Infinity";
        *arg7 = 0xffff8000;
    }
    else
    {
        int32_t rbx_2 = rbp & 4;
        int32_t var_b8_1 = rbx_2;
        
        if (!rbx_2)
        {
            if (!rax_7)
            {
                *arg7 = 1;
                return sub_1400123b0(U"0", arg8, 1);
            }
            
            int32_t r12_1 = *arg1;
            int32_t rax_8 = 0x20;
            int32_t rcx = 0;
            
            if (r12_1 > 0x20)
            {
                do
                {
                    rax_8 *= 2;
                    rcx += 1;
                } while (r12_1 > rax_8);
            }
            
            int64_t* rax_9 = sub_140013fe0(rcx);
            int64_t* rsi_1 = rax_9;
            void* rdx = &rax_9[3];
            int32_t* rax_10 = arg3;
            int64_t r8_2 = (r12_1 - 1) >> 5;
            void* rcx_1 = &arg3[r8_2];
            
            do
            {
                int32_t r9 = *rax_10;
                rax_10 = &rax_10[1];
                rdx += 4;
                *(rdx - 4) = r9;
            } while (rcx_1 >= rax_10);
            
            void* rax_11 = (r8_2 << 2) + 4;
            
            if (rcx_1 + 1 < arg3 + 1)
                rax_11 = 4;
            
            void* rax_12 = rax_11 + rsi_1;
            int32_t r14_2 = rax_11 >> 2;
            
            while (true)
            {
                int32_t rdx_2 = r14_2;
                r14_2 -= 1;
                
                if (*(rax_12 + 0x14))
                {
                    *(rsi_1 + 0x14) = rdx_2;
                    uint64_t rflags_1;
                    int32_t temp0_1;
                    temp0_1 = __bsr_gprv_memv(*(rsi_1 + (r14_2 << 2) + 0x18));
                    r14_2 = (rdx_2 << 5) - (temp0_1 ^ 0x1f);
                    break;
                }
                
                rax_12 -= 4;
                
                if (!r14_2)
                {
                    *(rsi_1 + 0x14) = 0;
                    break;
                }
            }
            
            int32_t rax_15 = sub_140013e70(rsi_1);
            int32_t var_4c = rax_15;
            int32_t var_a0_1 = arg2;
            
            if (rax_15)
            {
                sub_140013d70(rsi_1, rax_15);
                int32_t rax_33 = var_4c;
                r14_2 -= rax_33;
                var_a0_1 = arg2 + rax_33;
            }
            
            if (!*(rsi_1 + 0x14))
            {
                sub_1400140d0(rsi_1);
                *arg7 = 1;
                return sub_1400123b0(U"0", arg8, 1);
            }
            
            uint64_t zmm0_1 = sub_1400148e0(rsi_1, &var_4c);
            int32_t r8_3 = var_a0_1 + r14_2;
            uint128_t zmm1;
            zmm1 = r8_3 - 1;
            zmm1 = zmm1 * 0.30102999566398098;
            uint64_t rax_21 = (zmm0_1 >> 0x20 & 0xfffff) | 0x3ff00000;
            uint64_t rdx_8 = zmm0_1 | rax_21 << 0x20;
            int32_t r9_3 = 1 - r8_3;
            
            if (r8_3 - 1 >= 0)
                r9_3 = r8_3 - 1;
            
            zmm0_1 = (rdx_8 - 1.5) * 0.28952965460216801 + 0.1760912590558 + zmm1;
            
            if (r9_3 - 0x435 > 0)
            {
                zmm1 = r9_3 - 0x435;
                zmm1 = zmm1 * 7.0000000000000003e-17;
                zmm0_1 = zmm0_1 + zmm1;
            }
            
            int32_t r10_1 = zmm0_1;
            
            if (0.0 > zmm0_1)
            {
                zmm1 = r10_1;
                zmm1 - zmm0_1;
                
                if (FCMP_UO(zmm1, zmm0_1) || !(zmm1 == zmm0_1))
                    r10_1 -= 1;
            }
            
            uint64_t rdx_10 = rdx_8 | (rax_21 + ((r8_3 - 1) << 0x14)) << 0x20;
            int32_t rax_26 = r14_2 - (r8_3 - 1);
            int32_t r11_1 = rax_26 - 1;
            int32_t var_98_1;
            int32_t var_7c_1;
            
            if (r10_1 > 0x16)
                var_7c_1 = 1;
            else
            {
                if (!(*(&data_140027640 + (r10_1 << 3)) > rdx_10))
                {
                    var_7c_1 = 0;
                    var_98_1 = 0;
                    
                    if (rax_26 <= 0)
                    {
                        r11_1 = 0;
                        var_98_1 = 1 - rax_26;
                    }
                    
                    goto label_140012860;
                }
                
                var_7c_1 = 0;
                r10_1 -= 1;
            }
            
            var_98_1 = 0;
            
            if (r11_1 < 0)
            {
                r11_1 = 0;
                var_98_1 = 1 - rax_26;
            }
            
            int32_t var_90_1;
            int32_t var_88_1;
            
            if (r10_1 >= 0)
            {
            label_140012860:
                var_90_1 = r10_1;
                r11_1 += r10_1;
                var_88_1 = 0;
            }
            else
            {
                var_98_1 -= r10_1;
                int32_t rax_35 = -(r10_1);
                var_90_1 = r10_1;
                r10_1 = 0;
                var_88_1 = rax_35;
            }
            
            int32_t var_a8_1;
            void* result_1;
            void* result;
            int32_t var_b0_1;
            int32_t var_a4_1;
            int32_t var_a0_2;
            int32_t var_80_1;
            int32_t var_60_1;
            int64_t* rbp_4;
            int64_t* r9_8;
            int32_t r10_3;
            int32_t r11_3;
            int32_t r12_4;
            uint128_t zmm2;
            
            if (var_c8 > 9)
            {
                var_c8 = 0;
            label_140012c70:
                var_4c = r12_1 * 0.30103000000000002 + 3;
                var_a8 = 0;
                r10_3 = r10_1;
                var_a4_1 = 0;
                r11_3 = r11_1;
                result_1 = sub_140012370(r12_1 * 0.30103000000000002 + 3);
                var_80_1 = 1;
                var_60_1 = 0xffffffff;
                var_b0_1 = 0xffffffff;
            label_140012cc0:
                int64_t rax_66;
                
                if (var_a0_1 >= 0)
                    rax_66 = var_90_1;
                
                if (var_a0_1 < 0 || rax_66 > arg1[5])
                {
                    uint64_t var_78_1;
                    
                    if (var_80_1)
                    {
                        int32_t r12_3 = r12_1 - r14_2;
                        int32_t rdx_16 = arg1[1];
                        int32_t rax_70 = r12_3 + 1;
                        var_4c = rax_70;
                        int32_t rax_140;
                        
                        if (var_a0_1 - r12_3 < rdx_16)
                        {
                            if (!((var_c8 - 3) & 0xfffffffd))
                                goto label_1400134cb;
                            
                            rax_70 = var_a0_1 - rdx_16 + 1;
                            int32_t rcx_27;
                            rcx_27 = var_c8 > 1;
                            var_4c = rax_70;
                            rdx_16 = var_b0_1 > 0;
                            
                            if (!(rcx_27 & rdx_16) || rax_70 <= var_b0_1)
                                goto label_140012da3;
                            
                            rax_140 = var_b0_1 - 1;
                            
                            if (var_88_1 < rax_140)
                                goto label_140013770;
                            
                            var_4c = var_b0_1;
                            r11_3 += var_b0_1;
                            r12_4 = var_88_1 - rax_140;
                            var_a0_2 = var_98_1;
                            var_98_1 += var_b0_1;
                        }
                        else if (var_c8 <= 1)
                        {
                        label_140012da3:
                            r11_3 += rax_70;
                            r12_4 = var_88_1;
                            var_a0_2 = var_98_1;
                            var_98_1 += rax_70;
                        }
                        else
                        {
                        label_1400134cb:
                            rax_140 = var_b0_1 - 1;
                            
                            if (var_88_1 < rax_140)
                            {
                            label_140013770:
                                int32_t rcx_62 = var_88_1;
                                var_88_1 = rax_140;
                                r12_4 = 0;
                                r10_3 += rax_140 - rcx_62;
                                var_a0_2 = var_98_1;
                                var_4c = var_b0_1;
                                r11_3 += var_b0_1;
                                var_98_1 += var_b0_1;
                            }
                            else
                            {
                                r12_4 = var_88_1 - rax_140;
                                
                                if (var_b0_1 >= 0)
                                {
                                    var_4c = var_b0_1;
                                    r11_3 += var_b0_1;
                                    var_a0_2 = var_98_1;
                                    var_98_1 += var_b0_1;
                                }
                                else
                                {
                                    var_4c = 0;
                                    var_a0_2 = var_98_1 - var_b0_1;
                                }
                            }
                        }
                        var_78_1 = r10_3;
                        r10_3 = var_78_1;
                        rbp_4 = sub_140014200(1);
                        goto label_140012ded;
                    }
                    
                    r12_4 = var_88_1;
                    rbp_4 = nullptr;
                    var_a0_2 = var_98_1;
                label_140012ded:
                    
                    if (var_a0_2 > 0 && r11_3 > 0)
                    {
                        int32_t rax_77 = var_a0_2;
                        
                        if (var_a0_2 > r11_3)
                            rax_77 = r11_3;
                        
                        var_98_1 -= rax_77;
                        var_4c = rax_77;
                        r11_3 -= rax_77;
                        var_a0_2 -= rax_77;
                    }
                    
                    if (var_88_1)
                    {
                        if (!var_80_1)
                        {
                            var_78_1 = r10_3;
                            r10_3 = var_78_1;
                            rsi_1 = sub_140014420(rsi_1, var_88_1);
                        }
                        else
                        {
                            int32_t temp2_1;
                            
                            if (r12_4)
                            {
                                int64_t* rax_153 = sub_140014420(rbp_4, r12_4);
                                rbp_4 = rax_153;
                                var_78_1 = sub_1400142c0(rax_153, rsi_1);
                                sub_1400140d0(rsi_1);
                                temp2_1 = var_88_1;
                                var_88_1 -= r12_4;
                                rsi_1 = var_78_1;
                            }
                            
                            if (!r12_4 || temp2_1 != r12_4)
                            {
                                var_78_1 = r10_3;
                                r10_3 = var_78_1;
                                rsi_1 = sub_140014420(rsi_1, var_88_1);
                            }
                        }
                    }
                    
                    var_78_1 = r11_3;
                    int64_t* rax_79 = sub_140014200(1);
                    int32_t r10_4 = r10_3;
                    int32_t r11_4 = var_78_1;
                    r9_8 = rax_79;
                    int32_t r12_5;
                    
                    if (r10_4)
                    {
                        r9_8 = sub_140014420(rax_79, r10_4);
                        
                        if (var_c8 <= 1 && r14_2 == 1 && arg1[1] + 1 < arg2)
                        {
                            var_98_1 += 1;
                            r11_4 += 1;
                            r10_4 = 1;
                        }
                        else
                            r10_4 = 0;
                        
                        uint64_t rflags_2;
                        int32_t temp0_3;
                        temp0_3 = __bsr_gprv_memv(*(r9_8 + ((*(r9_8 + 0x14) - 1) << 2) + 0x18));
                        r12_5 = temp0_3 ^ 0x1f;
                    }
                    else
                    {
                        if (var_c8 <= 1 && r14_2 == 1 && arg1[1] + 1 < arg2)
                        {
                            var_98_1 += 1;
                            r11_4 += 1;
                            r10_4 = 1;
                        }
                        
                        r12_5 = 0x1f;
                    }
                    
                    int32_t r12_8 = (r12_5 - r11_4 - 4) & 0x1f;
                    int32_t rax_81 = var_98_1 + r12_8;
                    var_4c = r12_8;
                    int32_t rdx_19 = r12_8;
                    int32_t var_88_2;
                    
                    if (rax_81 > 0)
                    {
                        var_88_2 = r9_8;
                        int64_t* rax_82 = sub_1400145a0(rsi_1, rax_81);
                        r9_8 = var_88_2;
                        rdx_19 = var_4c;
                        rsi_1 = rax_82;
                    }
                    
                    int32_t rdx_21 = rdx_19 + r11_4;
                    
                    if (rdx_21 > 0)
                        r9_8 = sub_1400145a0(r9_8, rdx_21);
                    
                    int32_t* r13;
                    r13 = var_c8 > 2;
                    
                    if (!var_7c_1)
                    {
                    label_140012f29:
                        
                        if (var_b0_1 <= 0 && r13)
                            goto label_140012f3e;
                        
                        var_a8_1 = var_90_1 + 1;
                        
                        if (!var_80_1)
                            goto label_140013375;
                        
                        goto label_1400130e3;
                    }
                    
                    int32_t var_c0;
                    var_c0 = r9_8;
                    int32_t rax_118 = sub_1400146b0(rsi_1, r9_8);
                    r9_8 = var_c0;
                    
                    if (rax_118 >= 0)
                        goto label_140012f29;
                    
                    var_b0_1 = r9_8;
                    r9_8 = var_b0_1;
                    rsi_1 = sub_140014140(rsi_1, 0xa, 0);
                    int32_t rax_121;
                    rax_121 = var_60_1 <= 0;
                    char r13_2 = r13 & rax_121;
                    int64_t* rdi_1;
                    int32_t r8_12;
                    int64_t* r9_10;
                    void* result_7;
                    
                    if (!var_80_1)
                    {
                        if (r13_2)
                            goto label_140013b86;
                        
                        var_a8_1 = var_90_1;
                        var_b0_1 = var_60_1;
                    label_140013375:
                        result_7 = result_1;
                        int32_t rax_124 = 1;
                        
                        while (true)
                        {
                            var_4c = rax_124;
                            result_7 += 1;
                            r8_12 = sub_140012460(rsi_1, r9_8) + 0x30;
                            *(result_7 - 1) = r8_12;
                            
                            if (var_4c >= var_b0_1)
                                break;
                            
                            rsi_1 = sub_140014140(rsi_1, 0xa, 0);
                            rax_124 = var_4c + 1;
                        }
                        
                        r9_10 = r9_8;
                        rdi_1 = nullptr;
                        goto label_1400133d8;
                    }
                    
                    r9_8 = var_b0_1;
                    rbp_4 = sub_140014140(rbp_4, 0xa, 0);
                    
                    if (r13_2)
                    {
                    label_140013b86:
                        var_90_1 -= 1;
                        var_b0_1 = var_60_1;
                    label_140012f3e:
                        
                        if (var_b0_1)
                            goto label_1400130af;
                        
                        int64_t* rax_86 = sub_140014140(r9_8, 5, 0);
                        var_c8 = rax_86;
                        r9_8 = var_c8;
                        
                        if (sub_1400146b0(rsi_1, rax_86) <= 0)
                            goto label_1400130af;
                        
                        result = result_1;
                        var_a8_1 = var_90_1 + 2;
                        goto label_140012f81;
                    }
                    
                    var_a8_1 = var_90_1;
                    var_b0_1 = var_60_1;
                label_1400130e3:
                    int32_t rdx_24 = var_a0_2 + r12_8;
                    
                    if (rdx_24 > 0)
                    {
                        var_a0_2 = r9_8;
                        r9_8 = var_a0_2;
                        rbp_4 = sub_1400145a0(rbp_4, rdx_24);
                    }
                    
                    int64_t* r13_1 = rbp_4;
                    
                    if (r10_4)
                    {
                        var_c0 = r9_8;
                        int64_t* rax_163 = sub_140013fe0(rbp_4[1]);
                        memcpy(&rax_163[2], &rbp_4[2], (*(rbp_4 + 0x14) << 2) + 8);
                        r9_8 = var_c0;
                        r13_1 = sub_1400145a0(rax_163, 1);
                    }
                    
                    var_88_2 = r15;
                    int32_t rax_102 = 1;
                    void* result_4 = result_1;
                    var_c0 = r9_8;
                    var_90_1 = result_1;
                    void* result_6;
                    
                    while (true)
                    {
                        var_4c = rax_102;
                        int32_t rax_108 = sub_140012460(rsi_1, var_c0);
                        int32_t rax_109 = sub_1400146b0(rsi_1, rbp_4);
                        int64_t* rax_110 = sub_140014700(var_c0, r13_1);
                        int32_t rdx_25;
                        void* result_8;
                        
                        if (rax_110[2])
                        {
                            sub_1400140d0(rax_110);
                            rdx_25 = 1;
                        }
                        else
                        {
                            var_98_1 = rax_110;
                            int32_t rax_112 = sub_1400146b0(rsi_1, rax_110);
                            sub_1400140d0(var_98_1);
                            rdx_25 = rax_112 | var_c8;
                            
                            if (rdx_25)
                                rdx_25 = rax_112;
                            else if (!((*arg3 & 1) | var_a4_1))
                            {
                                int32_t r8_11 = rax_108 + 0x30;
                                r9_10 = var_c0;
                                result_1 = var_90_1;
                                result_8 = result_4;
                                r15 = var_88_2;
                                
                                if (r8_11 == 0x39)
                                {
                                    result_6 = result_4 + 1;
                                    goto label_140013cdb;
                                }
                                
                                if (rax_109 <= 0)
                                {
                                    var_b8_1 = 0x10;
                                    
                                    if (*(rsi_1 + 0x14) <= 1)
                                    {
                                        int32_t rax_187;
                                        rax_187 = rsi_1[3];
                                        var_b8_1 = rax_187 << 4;
                                    }
                                }
                                else
                                {
                                    var_b8_1 = 0x20;
                                    r8_11 = rax_108 + 0x31;
                                }
                                
                                *result_8 = r8_11;
                                rdi_1 = rbp_4;
                                result_6 = result_8 + 1;
                                rbp_4 = r13_1;
                                goto label_1400132a3;
                            }
                        }
                        
                        if (rax_109 >= 0 && (rax_109 | var_c8 || *arg3 & 1))
                        {
                            result_6 = result_4 + 1;
                            result_7 = result_6;
                            
                            if (rdx_25 <= 0 || var_a4_1 == 2)
                            {
                                *(result_6 - 1) = (rax_108 + 0x30);
                                
                                if (var_4c == var_b0_1)
                                {
                                    r8_12 = rax_108 + 0x30;
                                    rdi_1 = rbp_4;
                                    r9_10 = var_c0;
                                    result_1 = var_90_1;
                                    r15 = var_88_2;
                                    rbp_4 = r13_1;
                                    break;
                                }
                                
                                rsi_1 = sub_140014140(rsi_1, 0xa, 0);
                                
                                if (rbp_4 == r13_1)
                                {
                                    int64_t* rax_117 = sub_140014140(rbp_4, 0xa, 0);
                                    rbp_4 = rax_117;
                                    r13_1 = rax_117;
                                }
                                else
                                {
                                    rbp_4 = sub_140014140(rbp_4, 0xa, 0);
                                    r13_1 = sub_140014140(r13_1, 0xa, 0);
                                }
                                
                                result_4 = result_6;
                                rax_102 = var_4c + 1;
                                continue;
                            }
                            else
                            {
                                r9_10 = var_c0;
                                result_1 = var_90_1;
                                result_8 = result_4;
                                r15 = var_88_2;
                                
                                if (rax_108 != 9)
                                {
                                    var_b8_1 = 0x20;
                                    *result_4 = (rax_108 + 0x30) + 1;
                                    rdi_1 = rbp_4;
                                    rbp_4 = r13_1;
                                    goto label_1400132a3;
                                }
                            }
                            
                            goto label_140013cdb;
                        }
                        
                        result_8 = result_4;
                        int32_t r8_15 = rax_108 + 0x30;
                        r9_10 = var_c0;
                        result_1 = var_90_1;
                        r15 = var_88_2;
                        
                        if (!var_a4_1)
                        {
                            if (rdx_25 <= 0)
                                goto label_140013b24;
                            
                        label_140013ad3:
                            var_c8 = r9_10;
                            var_b8_1 = result_8;
                            int64_t* rax_166 = sub_1400145a0(rsi_1, 1);
                            rsi_1 = rax_166;
                            int32_t rax_167 = sub_1400146b0(rax_166, var_c8);
                            r9_10 = var_c8;
                            result_8 = var_b8_1;
                            
                            if (rax_167 <= 0 && (rax_167 || !(r8_15 & 1)))
                            {
                                var_a4_1 = 0x20;
                            label_140013b24:
                                
                                if (*(rsi_1 + 0x14) > 1)
                                {
                                label_140013b2e:
                                    rdi_1 = rbp_4;
                                    var_b8_1 = 0x10;
                                    rbp_4 = r13_1;
                                    result_6 = result_8 + 1;
                                    *result_8 = r8_15;
                                    goto label_1400132a3;
                                }
                                
                                rdi_1 = rbp_4;
                                rbp_4 = r13_1;
                                
                                if (!rsi_1[3])
                                {
                                    result_6 = result_8 + 1;
                                    var_b8_1 = var_a4_1;
                                }
                                else
                                {
                                    var_b8_1 = 0x10;
                                    result_6 = result_8 + 1;
                                }
                                
                                *result_8 = r8_15;
                                goto label_1400132a3;
                            }
                            
                            if (r8_15 != 0x39)
                            {
                                var_a4_1 = 0x20;
                                r8_15 = rax_108 + 0x31;
                                goto label_140013b24;
                            }
                            
                            rdi_1 = rbp_4;
                            result_6 = result_8 + 1;
                            rbp_4 = r13_1;
                        }
                        else
                        {
                            if (*(rsi_1 + 0x14) <= 1 && !rsi_1[3])
                            {
                                if (rdx_25 > 0)
                                    goto label_140013ad3;
                                
                                rdi_1 = rbp_4;
                                result_6 = result_8 + 1;
                                rbp_4 = r13_1;
                                *result_8 = r8_15;
                                goto label_1400132a3;
                            }
                            
                            if (var_a4_1 == 2)
                                goto label_140013b2e;
                            
                            var_c8 = result_1;
                            int32_t r14_6 = r8_15;
                            void* result_9 = result_8;
                            var_c0 = r15;
                            
                            while (sub_1400146b0(r9_10, r13_1) > 0)
                            {
                                *result_9 = r14_6;
                                result_9 += 1;
                                int64_t* rax_157 = sub_140014140(r13_1, 0xa, 0);
                                
                                if (rbp_4 == r13_1)
                                    rbp_4 = rax_157;
                                
                                int64_t* rax_158 = sub_140014140(rsi_1, 0xa, 0);
                                r13_1 = rax_157;
                                rsi_1 = rax_158;
                                r14_6 = sub_140012460(rax_158, r9_10) + 0x30;
                            }
                            
                            result_8 = result_9;
                            result_6 = result_9 + 1;
                            result_1 = var_c8;
                            r15 = var_c0;
                            
                            if (r14_6 != 0x39)
                            {
                                var_b8_1 = 0x20;
                                rdi_1 = rbp_4;
                                rbp_4 = r13_1;
                                *result_8 = (r14_6 + 1);
                                goto label_1400132a3;
                            }
                            
                        label_140013cdb:
                            rdi_1 = rbp_4;
                            rbp_4 = r13_1;
                        }
                        
                        *result_8 = 0x39;
                        result_7 = result_6;
                        goto label_140013419;
                    }
                    
                label_1400133d8:
                    int32_t rax_129;
                    
                    if (var_a4_1)
                    {
                        if (var_a4_1 == 2)
                            goto label_1400138a2;
                        
                        if (*(rsi_1 + 0x14) > 1)
                            goto label_140013419;
                        
                        rax_129 = rsi_1[3];
                        
                        if (rax_129)
                            goto label_140013419;
                        
                        goto label_1400133f8;
                    }
                    
                    var_c8 = r9_10;
                    int64_t* rax_155 = sub_1400145a0(rsi_1, 1);
                    rsi_1 = rax_155;
                    int32_t rax_156 = sub_1400146b0(rax_155, var_c8);
                    r9_10 = var_c8;
                    
                    if (rax_156 > 0 || (!rax_156 && r8_12 & 1))
                    {
                    label_140013419:
                        
                        while (true)
                        {
                            result_6 = result_7;
                            result_7 -= 1;
                            char rax_132 = *(result_6 - 1);
                            
                            if (rax_132 != 0x39)
                            {
                                var_b8_1 = 0x20;
                                *result_7 = rax_132 + 1;
                                break;
                            }
                            
                            if (result_7 == result_1)
                            {
                                var_a8_1 += 1;
                                *result_1 = 0x31;
                                var_b8_1 = 0x20;
                                break;
                            }
                        }
                    }
                    else
                    {
                    label_1400138a2:
                        var_b8_1 = 0x10;
                        result_6 = result_7;
                        
                        if (*(rsi_1 + 0x14) <= 1)
                        {
                            rax_129 = rsi_1[3];
                        label_1400133f8:
                            result_6 = result_7;
                            rax_129 = rax_129;
                            var_b8_1 = rax_129 << 4;
                        }
                    }
                    
                label_1400132a3:
                    sub_1400140d0(r9_10);
                    
                    if (!rbp_4)
                    {
                        result = result_1;
                        result_1 = result_6;
                    }
                    else
                    {
                        if (rdi_1 && rdi_1 != rbp_4)
                            sub_1400140d0(rdi_1);
                        
                        result = result_1;
                        result_1 = result_6;
                        sub_1400140d0(rbp_4);
                    }
                }
                else
                {
                    zmm2 = *(&data_140027640 + (rax_66 << 3));
                    
                    if (var_a8 >= 0 || var_b0_1 > 0)
                        goto label_1400135ea;
                    
                    if (!var_b0_1)
                    {
                    label_140012cf9:
                        zmm2 = zmm2 * 5.0;
                        
                        if (zmm2 >= rdx_10)
                            goto label_1400130a6;
                        
                        result = result_1;
                        r9_8 = nullptr;
                        rbp_4 = nullptr;
                        var_a8_1 = var_90_1 + 2;
                    label_140012f81:
                        *result = 0x31;
                        result_1 += 1;
                        var_b8_1 = 0x20;
                        goto label_140012f93;
                    }
                    
                label_1400130a6:
                    r9_8 = nullptr;
                    rbp_4 = nullptr;
                label_1400130af:
                    var_b8_1 = 0x10;
                    result = result_1;
                    var_a8_1 = -(var_a8);
                label_140012f93:
                    sub_1400140d0(r9_8);
                    
                    if (rbp_4)
                        sub_1400140d0(rbp_4);
                }
            }
            else
            {
                char var_5c_1;
                
                if (var_c8 <= 5)
                {
                    var_5c_1 = r8_3 + 0x3fd <= 0x7f7;
                    
                    if (var_c8 == 4)
                        goto label_14001307a;
                    
                    if (var_c8 == 5)
                        goto label_140013502;
                    
                    var_80_1 = 0;
                    
                    if (var_c8 == 2)
                        goto label_140013086;
                    
                    if (var_c8 != 3)
                        goto label_140012c70;
                    
                    goto label_140012a0a;
                }
                
                var_5c_1 = 0;
                int32_t rax_94 = var_c8 - 4;
                var_c8 = rax_94;
                int32_t rax_41;
                int32_t rcx_14;
                
                if (rax_94 == 4)
                {
                label_14001307a:
                    var_80_1 = 1;
                label_140013086:
                    rcx_14 = 1;
                    
                    if (var_a8 > 0)
                        rcx_14 = var_a8;
                    
                    var_60_1 = rcx_14;
                    rax_41 = rcx_14;
                    var_b0_1 = rcx_14;
                    var_a8 = rcx_14;
                }
                else
                {
                    if (rax_94 != 5)
                    {
                        var_80_1 = 0;
                        
                        if (rax_94 == 2)
                            goto label_140013086;
                        
                        var_c8 = 3;
                        goto label_140012a0a;
                    }
                    
                label_140013502:
                    var_80_1 = 1;
                label_140012a0a:
                    int32_t rax_40 = var_90_1 + var_a8;
                    var_60_1 = rax_40;
                    rax_41 = 1;
                    var_b0_1 = rax_40 + 1;
                    
                    if (rax_40 + 1 > 0)
                        rax_41 = rax_40 + 1;
                    
                    rcx_14 = rax_41;
                }
                
                var_4c = rax_41;
                r10_3 = r10_1;
                r11_3 = r11_1;
                result_1 = sub_140012370(rcx_14);
                int32_t rax_43 = arg1[3];
                uint64_t rdx_15 = rdx_10;
                var_a4_1 = rax_43 - 1;
                
                if (rax_43 != 1)
                {
                    int32_t rax_45 = 2;
                    
                    if (rax_43 - 1 >= 0)
                        rax_45 = var_a4_1;
                    
                    var_a4_1 = rax_45;
                    
                    if (!(rbp & 8))
                        goto label_140012cc0;
                    
                    var_a4_1 = 3 - rax_45;
                }
                
                char r8_7 = var_b0_1 <= 0xe & var_5c_1;
                
                if (!r8_7 || var_90_1 | var_a4_1)
                    goto label_140012cc0;
                
                var_4c = 0;
                uint128_t zmm0_3 = rdx_10;
                int32_t var_a4_2;
                uint64_t rax_51;
                int32_t rbp_3;
                
                if (var_7c_1 && 0x3ff0000000000000 > zmm0_3)
                {
                    if (var_b0_1)
                    {
                        rbp_3 = var_60_1;
                        
                        if (rbp_3 <= 0)
                        {
                        label_140013724:
                            var_a4_1 = 0;
                            goto label_140012cc0;
                        }
                        
                        zmm0_3 = zmm0_3 * 10.0;
                        var_a4_2 = 0xffffffff;
                        zmm1 = 0x4008000000000000 * zmm0_3;
                        rdx_15 = zmm0_3;
                        zmm1 = zmm1 + 7.0;
                        int64_t rax_161 = zmm1;
                        rax_51 = rax_161 | ((rax_161 >> 0x20) - 0x3400000) << 0x20;
                        goto label_140012b36;
                    }
                    
                    zmm1 = zmm0_3 + zmm0_3;
                    zmm1 = zmm1 + 7.0;
                    int64_t rax_148 = zmm1;
                    rax_51 = rax_148 | ((rax_148 >> 0x20) - 0x3400000) << 0x20;
                label_1400136fb:
                    zmm0_3 = zmm0_3 - 5.0;
                    zmm1 = rax_51;
                    
                    if (zmm0_3 > zmm1)
                    {
                        var_a8_1 = 2;
                        result = result_1;
                        r9_8 = nullptr;
                        rbp_4 = nullptr;
                        goto label_140012f81;
                    }
                    
                    if (__xorpd_xmmxuq_memxuq(zmm1, data_140027600) > zmm0_3)
                        goto label_1400130a6;
                    
                    goto label_140013724;
                }
                
                zmm1 = zmm0_3 + zmm0_3;
                zmm1 = zmm1 + 7.0;
                int64_t rax_49 = zmm1;
                rax_51 = rax_49 | ((rax_49 >> 0x20) - 0x3400000) << 0x20;
                
                if (!var_b0_1)
                    goto label_1400136fb;
                
                var_a4_2 = 0;
                rbp_3 = var_b0_1;
            label_140012b36:
                zmm2 = rax_51;
                uint128_t zmm3 = *(&data_140027640 + ((rbp_3 - 1) << 3));
                char rcx_21;
                
                if (!var_80_1)
                {
                    zmm3 = zmm3 * zmm2;
                    zmm2 = rdx_15;
                    char rdx_39 = 0;
                    zmm0_3 = zmm2;
                    void* result_5 = result_1;
                    uint128_t zmm5_3 = zmm2;
                    var_4c = 1;
                    
                    while (true)
                    {
                        int32_t rax_144 = zmm0_3;
                        
                        if (rax_144)
                        {
                            rdx_39 = r8_7;
                            zmm2 = rax_144;
                            zmm0_3 = zmm0_3 - zmm2;
                        }
                        
                        rcx_21 = rax_144 + 0x30;
                        result_5 += 1;
                        *(result_5 - 1) = rcx_21;
                        int32_t rax_145 = var_4c;
                        
                        if (rax_145 == rbp_3)
                            break;
                        
                        zmm0_3 = zmm0_3 * 0x4024000000000000;
                        rdx_39 = r8_7;
                        var_4c = rax_145 + 1;
                    }
                    
                    if (!rdx_39)
                        zmm0_3 = zmm5_3;
                    
                    zmm1 = 0x3fe0000000000000;
                    zmm2 = zmm3 + zmm1;
                    
                    if (zmm0_3 > zmm2)
                    {
                        result = result_1;
                        result_1 = result_5;
                        goto label_140012c17;
                    }
                    
                    zmm1 = zmm1 - zmm3;
                    
                    if (zmm1 > zmm0_3)
                    {
                        result = result_1;
                        zmm0_3 - 0.0;
                        result_1 = result_5;
                        int32_t rax_180;
                        rax_180 = FCMP_UO(zmm0_3, 0.0);
                        
                        if (zmm0_3 != 0.0)
                            rax_180 = 1;
                        
                        var_b8_1 = rax_180 << 4;
                        var_a8_1 = var_a4_2 + 1;
                    }
                    else
                    {
                        if (var_a0_1 < 0 || arg1[5] < 0)
                        {
                            var_a4_1 = 0;
                            rbp_4 = nullptr;
                            r12_4 = var_88_1;
                            var_a0_2 = var_98_1;
                            goto label_140012ded;
                        }
                        
                        zmm2 = 0x3ff0000000000000;
                        
                        if (var_a8 < 0 && var_b0_1 <= 0)
                            goto label_140012cf9;
                        
                        var_a4_1 = 0;
                    label_1400135ea:
                        zmm0_3 = rdx_10;
                        void* result_2 = result_1 + 1;
                        var_4c = 1;
                        zmm1 = zmm0_3 / zmm2;
                        var_a8_1 = var_90_1 + 1;
                        int32_t rdx_41 = zmm1;
                        zmm1 = rdx_41;
                        *result_1 = rdx_41 + 0x30;
                        zmm1 = zmm1 * zmm2;
                        zmm0_3 = zmm0_3 - zmm1;
                        zmm1 = {0};
                        zmm0_3 - zmm1;
                        
                        if (FCMP_UO(zmm0_3, zmm1) || !(zmm0_3 == zmm1))
                        {
                            zmm3 = {0};
                            
                            while (true)
                            {
                                int32_t rcx_60 = var_4c;
                                
                                if (rcx_60 == var_b0_1)
                                    break;
                                
                                zmm0_3 = zmm0_3 * 0x4024000000000000;
                                result_2 += 1;
                                var_4c = rcx_60 + 1;
                                zmm1 = zmm0_3 / zmm2;
                                rdx_41 = zmm1;
                                zmm1 = rdx_41;
                                *(result_2 - 1) = rdx_41 + 0x30;
                                zmm1 = zmm1 * zmm2;
                                zmm0_3 = zmm0_3 - zmm1;
                                zmm0_3 - zmm3;
                                
                                if (!FCMP_UO(zmm0_3, zmm3))
                                {
                                    if (zmm0_3 == zmm3)
                                        goto label_14001384e;
                                }
                            }
                            
                            if (!var_a4_1)
                            {
                                zmm0_3 = zmm0_3 + zmm0_3;
                                
                                if (!(zmm0_3 > zmm2))
                                {
                                    zmm0_3 - zmm2;
                                    
                                    if (FCMP_UO(zmm0_3, zmm2) || zmm0_3 != zmm2)
                                        goto label_1400136b4;
                                    
                                    rdx_41 &= 1;
                                    
                                    if (!rdx_41)
                                        goto label_1400136b4;
                                    
                                    goto label_140013b68;
                                }
                                
                            label_140013b68:
                                rcx_21 = *(result_2 - 1);
                                result = result_1;
                                result_1 = result_2;
                                var_a4_2 = var_90_1;
                            label_140012c17:
                                char rcx_22;
                                
                                while (true)
                                {
                                    if (rcx_21 != 0x39)
                                    {
                                        rcx_22 = rcx_21 + 1;
                                        break;
                                    }
                                    
                                    if (result_1 - 1 == result)
                                    {
                                        var_a4_2 += 1;
                                        rcx_22 = 0x31;
                                        break;
                                    }
                                    
                                    rcx_21 = *(result_1 - 2);
                                    result_1 -= 1;
                                }
                                
                                *(result_1 - 1) = rcx_22;
                                var_b8_1 = 0x20;
                                var_a8_1 = var_a4_2 + 1;
                            }
                            else
                            {
                                if (var_a4_1 == 1)
                                    goto label_140013b68;
                                
                            label_1400136b4:
                                result = result_1;
                                var_b8_1 = 0x10;
                                result_1 = result_2;
                            }
                        }
                        else
                        {
                        label_14001384e:
                            result = result_1;
                            result_1 = result_2;
                        }
                    }
                }
                else
                {
                    int32_t rax_55 = zmm0_3;
                    void* result_3 = result_1 + 1;
                    zmm1 = 0x3fe0000000000000 / zmm3;
                    zmm1 = zmm1 - zmm2;
                    zmm2 = rax_55;
                    *result_1 = rax_55 + 0x30;
                    zmm0_3 = zmm0_3 - zmm2;
                    
                    if (!(zmm1 > zmm0_3))
                    {
                        zmm3 = 0x4024000000000000;
                        
                        while (true)
                        {
                            zmm2 = 0x3ff0000000000000 - zmm0_3;
                            
                            if (!(zmm1 <= zmm2))
                            {
                                result = result_1;
                                rcx_21 = *(result_3 - 1);
                                result_1 = result_3;
                                break;
                            }
                            
                            int32_t rax_58 = var_4c + 1;
                            var_4c = rax_58;
                            
                            if (rax_58 >= rbp_3)
                                goto label_140013724;
                            
                            zmm0_3 = zmm0_3 * zmm3;
                            result_3 += 1;
                            zmm1 = zmm1 * zmm3;
                            int32_t rax_59 = zmm0_3;
                            zmm2 = rax_59;
                            *(result_3 - 1) = rax_59 + 0x30;
                            zmm0_3 = zmm0_3 - zmm2;
                            
                            if (zmm1 > zmm0_3)
                                goto label_140013b9f;
                        }
                        
                        goto label_140012c17;
                    }
                    
                label_140013b9f:
                    result = result_1;
                    zmm0_3 - 0.0;
                    result_1 = result_3;
                    int32_t rax_170;
                    rax_170 = FCMP_UO(zmm0_3, 0.0);
                    
                    if (zmm0_3 != 0.0)
                        rax_170 = 1;
                    
                    var_b8_1 = rax_170 << 4;
                    var_a8_1 = var_a4_2 + 1;
                }
            }
            
            if (result < result_1)
            {
                while (*(result_1 - 1) == 0x30)
                {
                    result_1 -= 1;
                    
                    if (result_1 == result)
                        break;
                }
            }
            
            sub_1400140d0(rsi_1);
            *result_1 = 0;
            *arg7 = var_a8_1;
            
            if (arg8)
                *arg8 = result_1;
            
            *r15 |= var_b8_1;
            return result;
        }
        
        if (rax_7 != 4)
            return nullptr;
        
        rdx_11 = arg8;
        r8_4 = 3;
        rcx_9 = &data_140027599;
        *arg7 = 0xffff8000;
    }
    
    /* tailcall */
    return sub_1400123b0(rcx_9, rdx_11, r8_4);
}

void sub_140013d70(void* arg1, int32_t arg2)
{
    int64_t rbx = *(arg1 + 0x14);
    int32_t rbp_1 = arg2 >> 5;
    
    if (rbx > rbp_1)
    {
        int64_t rbp_2 = rbp_1;
        void* r11_1 = arg1 + 0x18 + (rbx << 2);
        void* rsi_1 = arg1 + 0x18 + (rbp_2 << 2);
        int32_t rdx = arg2 & 0x1f;
        void* rax_4;
        
        if (!rdx)
        {
            int32_t* rdi_2 = arg1 + 0x18;
            
            if (rsi_1 < r11_1)
            {
                do
                {
                    *rdi_2 = *rsi_1;
                    rdi_2 = &rdi_2[1];
                    rsi_1 += 4;
                } while (rsi_1 < r11_1);
                
                rax_4 = arg1 + 0x18 + ((rbx - rbp_2) << 2);
                goto label_140013e38;
            }
            
            *(arg1 + 0x14) = 0;
        }
        else
        {
            void* r8_1 = rsi_1 + 4;
            uint32_t r9_2 = *rsi_1 >> rdx;
            
            if (r8_1 < r11_1)
            {
                void* rsi_2 = arg1 + 0x18;
                
                do
                {
                    int32_t rax_1 = *r8_1;
                    rsi_2 += 4;
                    r8_1 += 4;
                    *(rsi_2 - 4) = rax_1 << (0x20 - rdx) | r9_2;
                    r9_2 = *(r8_1 - 4) >> rdx;
                } while (r8_1 < r11_1);
                
                rax_4 = arg1 + 0x18 + ((rbx - rbp_2) << 2) - 4;
                *rax_4 = r9_2;
                
                if (!r9_2)
                    goto label_140013e38;
                
                goto label_140013e0b;
            }
            
            *(arg1 + 0x18) = r9_2;
            
            if (!r9_2)
                *(arg1 + 0x14) = 0;
            else
            {
                rax_4 = arg1 + 0x18;
            label_140013e0b:
                rax_4 += 4;
            label_140013e38:
                int32_t rax = (rax_4 - (arg1 + 0x18)) >> 2;
                *(arg1 + 0x14) = rax;
                
                if (rax)
                    return;
            }
        }
    }
    else
        *(arg1 + 0x14) = 0;
    
    *(arg1 + 0x18) = 0;
}

uint64_t sub_140013e70(void* arg1)
{
    void* rax = arg1 + 0x18;
    void* rcx = rax + (*(arg1 + 0x14) << 2);
    int32_t rdx = 0;
    
    if (rax < rcx)
    {
        do
        {
            if (*rax)
            {
                if (rax < rcx)
                    rdx += _tzcnt_u32(*rax);
                
                break;
            }
            
            rax += 4;
            rdx += 0x20;
        } while (rax < rcx);
    }
    
    return rdx;
}

int64_t sub_140013eb0(int32_t arg1)
{
    int32_t i = data_140030bd0;
    
    if (i != 2)
    {
        if (i)
        {
            if (i != 1)
                return i;
            
        label_140013ef0:
            
            do
            {
                Sleep(1);
                i = data_140030bd0;
            } while (i == 1);
            
            goto label_140013ef2;
        }
        
        int32_t temp0_1 = data_140030bd0;
        data_140030bd0 = 1;
        
        if (!temp0_1)
        {
            InitializeCriticalSection(&data_140030be0);
            InitializeCriticalSection(&data_140030c08);
            sub_140001410(sub_140013f90);
            data_140030bd0 = 2;
        }
        else if (temp0_1 == 2)
            data_140030bd0 = 2;
        else
        {
            i = data_140030bd0;
            
            if (i == 1)
                goto label_140013ef0;
            
        label_140013ef2:
            
            if (i != 2)
                return i;
        }
    }
    
    /* tailcall */
    return EnterCriticalSection((-(arg1) & 0x28) + &data_140030be0);
}

int64_t sub_140013f90()
{
    int32_t result = data_140030bd0;
    data_140030bd0 = 3;
    
    if (result != 2)
        return result;
    
    DeleteCriticalSection(&data_140030be0);
    /* tailcall */
    return DeleteCriticalSection(&data_140030c08);
}

int64_t* sub_140013fe0(int32_t arg1)
{
    sub_140013eb0(0);
    int64_t* result;
    uint64_t rcx_4;
    int32_t rsi_1;
    
    if (arg1 > 9)
    {
        rsi_1 = 1 << arg1;
        rcx_4 = (((rsi_1 - 1) << 2) + 0x27) >> 3;
    label_140014050:
        result = malloc(rcx_4 << 3);
        
        if (result)
            goto label_14001405a;
    }
    else
    {
        int64_t rcx = arg1;
        result = *(&data_140030b80 + (rcx << 3));
        
        if (!result)
        {
            rsi_1 = 1 << arg1;
            result = data_1400230d0;
            rcx_4 = (((rsi_1 - 1) << 2) + 0x27) >> 3;
            
            if (((result - &data_140030280) >> 3) + rcx_4 > 0x120)
                goto label_140014050;
            
            data_1400230d0 = &result[rcx_4];
        label_14001405a:
            bool cond:0_1 = data_140030bd0 == 2;
            result[1] = arg1;
            *(result + 0xc) = rsi_1;
            
            if (cond:0_1)
            {
                LeaveCriticalSection(&data_140030be0);
                result[2] = 0;
            }
            else
                result[2] = 0;
        }
        else
        {
            bool cond:1_1 = data_140030bd0 != 2;
            *(&data_140030b80 + (rcx << 3)) = *result;
            
            if (cond:1_1)
                result[2] = 0;
            else
            {
                LeaveCriticalSection(&data_140030be0);
                result[2] = 0;
            }
        }
    }
    return result;
}

void sub_1400140d0(int64_t* arg1)
{
    if (!arg1)
        return;
    
    if (arg1[1] > 9)
        /* tailcall */
        return free(arg1);
    
    sub_140013eb0(0);
    int64_t rdx_2 = arg1[1];
    bool cond:0_1 = data_140030bd0 == 2;
    int64_t rcx_1 = *(&data_140030b80 + (rdx_2 << 3));
    *(&data_140030b80 + (rdx_2 << 3)) = arg1;
    *arg1 = rcx_1;
    
    if (cond:0_1)
        /* tailcall */
        return LeaveCriticalSection(&data_140030be0);
}

int64_t* sub_140014140(int64_t* arg1, int32_t arg2, int32_t arg3)
{
    int32_t i = *(arg1 + 0x14);
    int64_t rsi = arg3;
    int64_t rcx = 0;
    
    do
    {
        int64_t rax_3 = *(arg1 + (rcx << 2) + 0x18) * arg2 + rsi;
        *(arg1 + (rcx << 2) + 0x18) = rax_3;
        rcx += 1;
        rsi = rax_3 >> 0x20;
    } while (i > rcx);
    
    int64_t* result = arg1;
    
    if (rsi)
    {
        if (*(arg1 + 0xc) <= i)
        {
            int64_t* result_1 = sub_140013fe0(arg1[1] + 1);
            result = result_1;
            
            if (result_1)
            {
                memcpy(&result_1[2], &arg1[2], (*(arg1 + 0x14) << 2) + 8);
                int64_t* result_2 = result;
                sub_1400140d0(arg1);
                result = result_2;
                *(result_2 + (i << 2) + 0x18) = rsi;
                *(result_2 + 0x14) = i + 1;
            }
        }
        else
        {
            result = arg1;
            *(arg1 + (i << 2) + 0x18) = rsi;
            *(arg1 + 0x14) = i + 1;
        }
    }
    
    return result;
}

int64_t* sub_140014200(int32_t arg1)
{
    sub_140013eb0(0);
    int64_t* result = data_140030b88;
    
    if (!result)
    {
        result = data_1400230d0;
        
        if (((result - &data_140030280) >> 3) + 5 <= 0x120)
        {
            data_1400230d0 = &result[5];
        label_140014283:
            bool cond:1_1 = data_140030bd0 != 2;
            result[1] = 0x200000001;
            
            if (!cond:1_1)
                goto label_14001429c;
            
            result[3] = arg1;
            result[2] = 0x100000000;
        }
        else
        {
            result = malloc(0x28);
            
            if (result)
                goto label_140014283;
        }
    }
    else
    {
        bool cond:0_1 = data_140030bd0 == 2;
        data_140030b88 = *result;
        
        if (cond:0_1)
        {
        label_14001429c:
            LeaveCriticalSection(&data_140030be0);
            result[3] = arg1;
            result[2] = 0x100000000;
        }
        else
        {
            result[3] = arg1;
            result[2] = 0x100000000;
        }
    }
    
    return result;
}

int64_t* sub_1400142c0(void* arg1, void* arg2)
{
    int64_t r12 = *(arg1 + 0x14);
    int64_t rbp = *(arg2 + 0x14);
    void* r13 = arg1;
    void* r15 = arg2;
    
    if (r12 >= rbp)
    {
        int32_t rax_1 = rbp;
        r15 = arg1;
        rbp = r12;
        r13 = arg2;
        r12 = rax_1;
    }
    
    int32_t rcx = *(r15 + 8);
    int32_t i_1 = rbp + r12;
    
    if (*(r15 + 0xc) < i_1)
        rcx += 1;
    
    int64_t* result = sub_140013fe0(rcx);
    
    if (result)
    {
        void* r11_1 = &result[3];
        void* rsi_1 = r11_1 + (i_1 << 2);
        
        if (r11_1 < rsi_1)
            r11_1 = memset(r11_1, 0, ((rsi_1 - result - 0x19) >> 2 << 2) + 4);
        
        void* r9_1 = r13 + 0x18;
        void* r12_1 = r9_1 + (r12 << 2);
        void* rbp_1 = r15 + 0x18 + (rbp << 2);
        
        if (r9_1 < r12_1)
        {
            void* r13_1 = ((rbp_1 - r15 - 0x19) >> 2 << 2) + 4;
            
            if (rbp_1 < r15 + 0x19)
                r13_1 = 4;
            
            while (true)
            {
                uint64_t r10_1 = *r9_1;
                r9_1 += 4;
                
                if (!r10_1)
                {
                    r11_1 += 4;
                    
                    if (r9_1 >= r12_1)
                        break;
                }
                else
                {
                    void* rcx_2 = r11_1;
                    void* rdx = r15 + 0x18;
                    uint64_t r8_2 = 0;
                    
                    do
                    {
                        uint64_t rax_12 = *rdx;
                        uint64_t r15_2 = *rcx_2;
                        rdx += 4;
                        rcx_2 += 4;
                        int64_t rax_15 = rax_12 * r10_1 + r15_2 + r8_2;
                        *(rcx_2 - 4) = rax_15;
                        r8_2 = rax_15 >> 0x20;
                    } while (rdx < rbp_1);
                    
                    *(r11_1 + r13_1) = r8_2;
                    r11_1 += 4;
                    
                    if (r9_1 >= r12_1)
                        break;
                }
            }
        }
        
        if (i_1 > 0)
        {
            int32_t i;
            
            do
            {
                int32_t rax_16 = *(rsi_1 - 4);
                rsi_1 -= 4;
                
                if (rax_16)
                    break;
                
                i = i_1;
                i_1 -= 1;
            } while (i != 1);
        }
        
        *(result + 0x14) = i_1;
    }
    
    return result;
}

int64_t* sub_140014420(int64_t* arg1, int32_t arg2)
{
    int64_t* rsi = arg1;
    int32_t rax_1 = arg2 & 3;
    
    if (rax_1)
    {
        int64_t* rax_7 = sub_140014140(arg1, *(&data_140027620 + ((rax_1 - 1) << 2)), 0);
        rsi = rax_7;
        
        if (!rax_7)
            return nullptr;
    }
    
    int32_t rbx_1 = arg2 >> 2;
    
    if (!rbx_1)
        return rsi;
    
    int64_t* rdi_1 = data_140030260;
    
    if (!rdi_1)
    {
        sub_140013eb0(1);
        rdi_1 = data_140030260;
        
        if (!rdi_1)
        {
            int64_t* rax_8 = sub_140013fe0(1);
            rdi_1 = rax_8;
            
            if (!rax_8)
            {
                data_140030260 = 0;
                return nullptr;
            }
            
            data_140030260 = rdi_1;
            *(rdi_1 + 0x14) = 0x27100000001;
            *rdi_1 = 0;
        }
        
        if (data_140030bd0 == 2)
            LeaveCriticalSection(&data_140030c08);
    }
    
    int64_t* rbp_1 = rsi;
    
    while (true)
    {
        if (!(rbx_1 & 1))
        {
            rbx_1 s>>= 1;
            
            if (!rbx_1)
                return rbp_1;
        }
        else
        {
            int64_t* rax_2 = sub_1400142c0(rbp_1, rdi_1);
            
            if (!rax_2)
                return nullptr;
            
            int64_t* rcx_1 = rbp_1;
            rbp_1 = rax_2;
            sub_1400140d0(rcx_1);
            rbx_1 s>>= 1;
            
            if (!rbx_1)
                return rbp_1;
        }
        
        int64_t* rsi_1 = *rdi_1;
        
        if (!rsi_1)
        {
            sub_140013eb0(1);
            rsi_1 = *rdi_1;
            
            if (!rsi_1)
            {
                int64_t* rax_4 = sub_1400142c0(rdi_1, rdi_1);
                *rdi_1 = rax_4;
                rsi_1 = rax_4;
                
                if (!rax_4)
                    return nullptr;
                
                *rax_4 = 0;
            }
            
            if (data_140030bd0 == 2)
                LeaveCriticalSection(&data_140030c08);
        }
        
        rdi_1 = rsi_1;
    }
}

int64_t* sub_1400145a0(int64_t* arg1, int32_t arg2)
{
    int32_t rcx = arg1[1];
    uint64_t rsi_1 = arg2 >> 5;
    int32_t rax = *(arg1 + 0xc);
    int32_t rbx_1 = *(arg1 + 0x14) + rsi_1;
    int32_t rbp = rbx_1 + 1;
    
    while (rbp > rax)
    {
        rax *= 2;
        rcx += 1;
    }
    
    int64_t* result = sub_140013fe0(rcx);
    
    if (result)
    {
        void* rdi_1 = &result[3];
        
        if (rsi_1 > 0)
        {
            uint64_t _Size = rsi_1 << 2;
            void* rcx_1 = rdi_1;
            rdi_1 += _Size;
            memset(rcx_1, 0, _Size);
        }
        
        void* rsi_2 = &arg1[3];
        void* r9_1 = rsi_2 + (*(arg1 + 0x14) << 2);
        int32_t r13_1 = arg2 & 0x1f;
        
        if (!r13_1)
        {
            do
            {
                *rdi_1 = *rsi_2;
                void* rdi_2 = rdi_1 + 4;
                void* rsi_3 = rsi_2 + 4;
                
                if (rsi_3 >= r9_1)
                    break;
                
                *rdi_2 = *rsi_3;
                rdi_1 = rdi_2 + 4;
                rsi_2 = rsi_3 + 4;
            } while (rsi_2 < r9_1);
            
            rbp = rbx_1;
        }
        else
        {
            void* r8_2 = rdi_1;
            uint32_t rdx = 0;
            
            do
            {
                int32_t rax_2 = *rsi_2;
                r8_2 += 4;
                rsi_2 += 4;
                *(r8_2 - 4) = rax_2 << r13_1 | rdx;
                rdx = *(rsi_2 - 4) >> (0x20 - r13_1);
            } while (rsi_2 < r9_1);
            
            void* rax_9 = ((r9_1 - arg1 - 0x19) >> 2 << 2) + 4;
            
            if (r9_1 < arg1 + 0x19)
                rax_9 = 4;
            
            *(rdi_1 + rax_9) = rdx;
            
            if (!rdx)
                rbp = rbx_1;
        }
        
        *(result + 0x14) = rbp;
        sub_1400140d0(arg1);
    }
    
    return result;
}

uint64_t sub_1400146b0(void* arg1, void* arg2)
{
    int64_t rax_1 = *(arg2 + 0x14);
    int32_t r9 = *(arg1 + 0x14);
    int32_t r9_1 = r9 - rax_1;
    
    if (r9 == rax_1)
    {
        int64_t r8_1 = rax_1 << 2;
        void* i = arg1 + 0x18 + r8_1;
        void* rdx = arg2 + r8_1 + 0x18;
        
        do
        {
            i -= 4;
            rdx -= 4;
            int32_t r10_1 = *rdx;
            int32_t temp1_1 = *i;
            
            if (temp1_1 != r10_1)
            {
                r9_1 = (r9_1 - r9_1) | 1;
                break;
            }
        } while (arg1 + 0x18 < i);
    }
    
    return r9_1;
}

int64_t* sub_140014700(void* arg1, void* arg2)
{
    int64_t rax = *(arg2 + 0x14);
    void* rbx = arg1;
    void* rsi = arg2;
    int32_t temp0 = *(arg1 + 0x14);
    int64_t* result;
    int32_t rdi_2;
    
    if (temp0 != rax)
    {
        rdi_2 = 1;
        
        if (temp0 - rax >= 0)
        {
        label_14001475e:
            void* rax_2 = rsi;
            rdi_2 = 0;
            rsi = rbx;
            rbx = rax_2;
        }
        
    label_14001476c:
        int64_t* result_1 = sub_140013fe0(*(rsi + 8));
        result = result_1;
        
        if (result_1)
        {
            result_1[2] = rdi_2;
            int64_t rax_3 = *(rsi + 0x14);
            void* r9_1 = rsi + 0x18;
            void* rcx_2 = 0x18;
            uint64_t rdx_2 = 0;
            int32_t r11_1 = rax_3;
            void* rdi_3 = r9_1 + (rax_3 << 2);
            void* i = rbx + (*(rbx + 0x14) << 2) + 0x18;
            int32_t rbp_2;
            
            do
            {
                uint64_t rax_7 = *(rsi + rcx_2) - *(rbx + rcx_2) - rdx_2;
                *(result + rcx_2) = rax_7;
                rcx_2 += 4;
                rbp_2 = rax_7;
                rdx_2 = rax_7 >> 0x20 & 1;
            } while (rcx_2 + rbx < i);
            
            rsi = i >= rbx + 0x19;
            uint64_t r13_2 = (i - rbx - 0x19) >> 2;
            void* rax_10 = (r13_2 << 2) + 4;
            
            if (!rsi)
                rax_10 = 4;
            
            void* rbx_1 = r9_1 + rax_10;
            void* r8_2 = &result[3] + rax_10;
            void* r9_2 = r8_2;
            void* rcx_3 = rbx_1;
            void* rax_13;
            
            if (rbx_1 >= rdi_3)
            {
                uint64_t r13_3 = r13_2 << 2;
                
                if (!rsi)
                    r13_3 = 0;
                
                rax_13 = &result[3] + r13_3;
            }
            else
            {
                do
                {
                    uint64_t rax_11 = *rcx_3;
                    rcx_3 += 4;
                    r9_2 += 4;
                    uint64_t rax_12 = rax_11 - rdx_2;
                    *(r9_2 - 4) = rax_12;
                    rbp_2 = rax_12;
                    rdx_2 = rax_12 >> 0x20 & 1;
                } while (rcx_3 < rdi_3);
                
                rax_13 = r8_2 + ((rdi_3 - 1 - rbx_1) & 0xfffffffffffffffc);
            }
            
            if (!rbp_2)
            {
                int32_t i_1;
                
                do
                {
                    i_1 = *(rax_13 - 4);
                    rax_13 -= 4;
                    r11_1 -= 1;
                } while (!i_1);
            }
            
            *(result + 0x14) = r11_1;
        }
    }
    else
    {
        int64_t rdx = rax << 2;
        void* rax_1 = arg1 + 0x18 + rdx;
        void* rdx_1 = rsi + rdx + 0x18;
        
        while (true)
        {
            rax_1 -= 4;
            rdx_1 -= 4;
            int32_t rdi_1 = *rdx_1;
            int32_t temp1_1 = *rax_1;
            
            if (temp1_1 != rdi_1)
            {
                rdi_2 = 1;
                
                if (temp1_1 < rdi_1)
                    goto label_14001476c;
                
                goto label_14001475e;
            }
            
            if (arg1 + 0x18 >= rax_1)
            {
                int64_t* result_2 = sub_140013fe0(0);
                result = result_2;
                
                if (!result_2)
                    break;
                
                *(result_2 + 0x14) = 1;
                return result;
            }
        }
    }
    return result;
}

int512_t sub_1400148e0(void* arg1, int32_t* arg2)
{
    void* rbx = arg1 + 0x18 + (*(arg1 + 0x14) << 2);
    int32_t r11 = *(rbx - 4);
    uint64_t rflags;
    int32_t temp0;
    temp0 = _bit_scan_reverse(r11);
    int32_t rdi_1 = temp0 ^ 0x1f;
    *arg2 = 0x20 - rdi_1;
    int512_t result;
    
    if (rdi_1 <= 0xa)
    {
        uint32_t r8_2 = 0;
        
        if (arg1 + 0x18 < rbx - 4)
            r8_2 = *(rbx - 8) >> (0xb - rdi_1);
        
        result = (r11 >> (0xb - rdi_1) | 0x3ff00000) << 0x20 | r11 << (rdi_1 + 0x15) | r8_2;
        return result;
    }
    
    uint64_t rax_5;
    uint64_t rdx;
    
    if (arg1 + 0x18 >= rbx - 4)
    {
        rdx = 0;
        
        if (rdi_1 != 0xb)
        {
            result = (r11 << (rdi_1 - 0xb) | 0x3ff00000) << 0x20;
            return result;
        }
        
        rax_5 = (r11 | 0x3ff00000) << 0x20;
    }
    else
    {
        rdx = *(rbx - 8);
        
        if (rdi_1 == 0xb)
            rax_5 = (r11 | 0x3ff00000) << 0x20;
        else
        {
            int32_t rax_3 = r11 << (rdi_1 - 0xb) | rdx >> (0x20 - (rdi_1 - 0xb));
            rdx = rdx << (rdi_1 - 0xb);
            rax_5 = (rax_3 | 0x3ff00000) << 0x20;
            
            if (arg1 + 0x18 < rbx - 8)
            {
                result = rax_5 | rdx | *(rbx - 0xc) >> (0x20 - (rdi_1 - 0xb));
                return result;
            }
        }
    }
    
    result = rax_5 | rdx;
    return result;
}

int64_t* sub_1400149f0(int128_t arg1 @ zmm0, int32_t* arg2, int32_t* arg3)
{
    int64_t* result = sub_140013fe0(1);
    
    if (result)
    {
        int64_t rax = arg1;
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
            label_140014ae7:
                *arg2 = rcx_4 + r8_2 - 0x433;
                *arg3 = 0x35 - r8_2;
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
                goto label_140014ae7;
        }
        
        uint64_t rflags_1;
        int32_t temp0_2;
        temp0_2 = __bsr_gprv_memv(*(result + (rax_2 << 2) + 0x14));
        *arg2 = r8_2 - 0x432;
        *arg3 = (rax_2 << 5) - (temp0_2 ^ 0x1f);
    }
    
    return result;
}

char* sub_140014b10(char* arg1, char* arg2)
{
    char* result = arg1;
    char* rcx = &arg2[1];
    char rdx = *arg2;
    *result = rdx;
    
    if (rdx)
    {
        char i;
        
        do
        {
            i = *rcx;
            result = &result[1];
            rcx = &rcx[1];
            *result = i;
        } while (i);
    }
    
    return result;
}

void* sub_140014b40(char* arg1, int64_t arg2)
{
    void* result = nullptr;
    char* rax = arg1;
    
    if (arg2)
    {
        while (*rax)
        {
            rax = &rax[1];
            result = rax - arg1;
            
            if (result >= arg2)
                break;
        }
    }
    
    return result;
}

int64_t sub_140014b70(int64_t arg1, int64_t arg2)
{
    int64_t r8 = 0;
    
    if (arg2)
    {
        do
        {
            if (!*(arg1 + (r8 << 1)))
                return r8;
            
            r8 += 1;
        } while (arg2 != r8);
    }
    
    return arg2;
}

int64_t sub_140014ba0() __pure
{
    return _fmode;
}

int64_t sub_140014bb0() __pure
{
    return _commode;
}

int64_t sub_140014bc0() __pure
{
    return _acmdln;
}

int64_t sub_140014bd0(int64_t arg1)
{
    if (arg1)
    {
        int64_t rax_1 = data_140030c40;
        
        if (rax_1 && rax_1(arg1, 4))
            return 0;
    }
    
    return 0x16;
}

int64_t sub_140014c10()
{
    void* rax_1 = GetProcAddress(GetModuleHandleW(u"msvcrt.dll"), "rand_s");
    
    if (!rax_1)
    {
        data_140030c40 = GetProcAddress(LoadLibraryW(u"advapi32.dll"), "SystemFunction036");
        rax_1 = sub_140014bd0;
    }
    
    data_140023110 = rax_1;
    /* jump -> rax_1 */
}

int64_t j_sub_140014c10()
{
    /* jump -> data_140023110 */
}

int64_t sub_140014ca0()
{
    return data_140030c50;
}

int64_t sub_140014cb0(int64_t arg1)
{
    int64_t result = data_140030c50;
    data_140030c50 = arg1;
    return result;
}

void* sub_140014cc0(int32_t arg1)
{
    return &__iob_func()[arg1 * 6];
}

int32_t sub_140014ce0(char* arg1, wchar16 arg2, uint32_t arg3, int32_t arg4)
{
    wchar16 wideCharStr = arg2;
    
    if (arg3)
    {
        BOOL usedDefaultChar = 0;
        int32_t result =
            WideCharToMultiByte(arg3, 0, &wideCharStr, 1, arg1, arg4, nullptr, &usedDefaultChar);
        
        if (result && !usedDefaultChar)
            return result;
    }
    else if (arg2 <= 0xff)
    {
        *arg1 = arg2;
        return 1;
    }
    
    *_errno() = 0x2a;
    return 0xffffffff;
}

int64_t sub_140014d70(char* arg1, wchar16 arg2)
{
    char* rbx = arg1;
    void var_1d;
    
    if (!arg1)
        rbx = &var_1d;
    int32_t rax = ___mb_cur_max_func();
    return sub_140014ce0(rbx, arg2, ___lc_codepage_func(), rax);
}

int64_t sub_140014db0(char* arg1, int64_t* arg2, int64_t arg3)
{
    int64_t result = 0;
    char* rbx = arg1;
    uint32_t rax = ___lc_codepage_func();
    int32_t rax_1 = ___mb_cur_max_func();
    wchar16* r13 = *arg2;
    
    if (r13)
    {
        if (!rbx)
        {
            while (true)
            {
                char var_3d[0x5];
                int32_t rax_7 = sub_140014ce0(&var_3d, *r13, rax, rax_1);
                
                if (rax_7 <= 0)
                    break;
                
                result += rax_7;
                
                if (!var_3d[rax_7 - 1])
                    return result - 1;
                
                r13 = &r13[1];
            }
            
            return -1;
        }
        
        if (arg3)
        {
            do
            {
                int32_t rax_3 = sub_140014ce0(rbx, *r13, rax, rax_1);
                
                if (rax_3 <= 0)
                    return -1;
                
                int64_t rax_2 = rax_3;
                rbx = &rbx[rax_2];
                result += rax_2;
                
                if (!rbx[-1])
                {
                    *arg2 = 0;
                    return result - 1;
                }
                
                r13 = &r13[1];
            } while (result < arg3);
        }
        
        *arg2 = r13;
    }
    
    return result;
}

int64_t sub_140014eb0(wchar16* arg1, char* arg2, int64_t arg3, int32_t* arg4, uint32_t arg5, int32_t arg6)
{
    if (arg2)
    {
        if (!arg3)
            return 0xfffffffe;
        
        int32_t rax_1 = *arg4;
        uint8_t TestChar = *arg2;
        *arg4 = 0;
        int32_t var_1c = rax_1;
        
        if (TestChar)
        {
            if (arg6 <= 1)
            {
            label_140014f6f:
                
                if (!arg5)
                {
                    *arg1 = *arg2;
                    return 1;
                }
                
                if (MultiByteToWideChar(arg5, MB_ERR_INVALID_CHARS, arg2, 1, arg1, 1))
                    return 1;
                
                *_errno() = 0x2a;
                return 0xffffffff;
            }
            
            wchar16* lpWideCharStr;
            char* lpMultiByteStr;
            
            if (rax_1)
            {
                *var_1c[1] = TestChar;
                lpMultiByteStr = &var_1c;
                int32_t var_30_2 = 1;
                lpWideCharStr = arg1;
            label_140014f4a:
                
                if (MultiByteToWideChar(arg5, MB_ERR_INVALID_CHARS, lpMultiByteStr, 2, 
                        lpWideCharStr, 1))
                    return 2;
                
                *_errno() = 0x2a;
                return 0xffffffff;
            }
            
            if (!IsDBCSLeadByteEx(arg5, TestChar))
                goto label_140014f6f;
            
            if (arg3 == 1)
            {
                *arg4 = *arg2;
                return 0xfffffffe;
            }
            
            lpWideCharStr = arg1;
            lpMultiByteStr = arg2;
            int32_t var_30_1 = 1;
            goto label_140014f4a;
        }
        
        *arg1 = 0;
    }
    
    return 0;
}

int64_t sub_140015010(wchar16* arg1, char* arg2, int64_t arg3, int32_t* arg4)
{
    wchar16* rbx = arg1;
    wchar16 var_2a = 0;
    
    if (!arg1)
        rbx = &var_2a;
    
    int32_t rax = ___mb_cur_max_func();
    uint32_t rax_1 = ___lc_codepage_func();
    int32_t* r9 = &data_140030c68;
    
    if (arg4)
        r9 = arg4;
    
    return sub_140014eb0(rbx, arg2, arg3, r9, rax_1, rax);
}

int64_t sub_140015080(wchar16* arg1, char** arg2, int64_t arg3, int32_t* arg4)
{
    int32_t* rsi = arg4;
    wchar16* r14 = arg1;
    
    if (!arg4)
        rsi = &data_140030c64;
    
    uint32_t rax = ___lc_codepage_func();
    int32_t rax_1 = ___mb_cur_max_func();
    
    if (arg2)
    {
        char* rdx = *arg2;
        
        if (rdx)
        {
            int64_t result;
            
            if (!r14)
            {
                result = 0;
                wchar16 var_3a = 0;
                
                while (true)
                {
                    int32_t rax_6 = sub_140014eb0(&var_3a, &rdx[result], rax_1, rsi, rax, rax_1);
                    
                    if (rax_6 <= 0)
                        break;
                    
                    rdx = *arg2;
                    result += rax_6;
                }
            }
            else
            {
                result = 0;
                
                if (arg3)
                {
                    do
                    {
                        int32_t rax_3 = sub_140014eb0(r14, rdx, arg3 - result, rsi, rax, rax_1);
                        
                        if (rax_3 <= 0)
                        {
                            if (result < arg3 && !rax_3)
                                *arg2 = nullptr;
                            
                            break;
                        }
                        
                        int64_t rax_2 = rax_3;
                        r14 = &r14[1];
                        result += rax_2;
                        rdx = &(*arg2)[rax_2];
                        *arg2 = rdx;
                    } while (result < arg3);
                }
            }
            
            return result;
        }
    }
    
    return 0;
}

int64_t sub_140015190(char* arg1, int64_t arg2, int32_t* arg3)
{
    int32_t* rbx = arg3;
    wchar16 var_2a = 0;
    int32_t rax = ___mb_cur_max_func();
    uint32_t rax_1 = ___lc_codepage_func();
    
    if (!rbx)
        rbx = &data_140030c60;
    
    return sub_140014eb0(&var_2a, arg1, arg2, rbx, rax_1, rax);
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

int32_t _ismbblead(uint32_t _C)
{
    /* tailcall */
    return _ismbblead(_C);
}

_onexit_t_1 _onexit(_onexit_t_1 _Func)
{
    /* tailcall */
    return _onexit(_Func);
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

int32_t fputs(char const* _Buffer, FILE* _Stream)
{
    /* tailcall */
    return fputs(_Buffer, _Stream);
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

char* getenv(char const* _VarName)
{
    /* tailcall */
    return getenv(_VarName);
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

int64_t memchr(void const* _Buf, int32_t _Val, uint64_t _MaxCount)
{
    /* tailcall */
    return memchr(_Buf, _Val, _MaxCount);
}

int32_t memcmp(void const* _Buf1, void const* _Buf2, uint64_t _Size)
{
    /* tailcall */
    return memcmp(_Buf1, _Buf2, _Size);
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

char const* strchr(char const* _Str, int32_t _Val)
{
    /* tailcall */
    return strchr(_Str, _Val);
}

int32_t strcmp(char const* _Str1, char const* _Str2)
{
    /* tailcall */
    return strcmp(_Str1, _Str2);
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

char const* strstr(char const* _Str, char const* _SubStr)
{
    /* tailcall */
    return strstr(_Str, _SubStr);
}

uint32_t strtoul(char const* _String, char** _EndPtr, int32_t _Radix)
{
    /* tailcall */
    return strtoul(_String, _EndPtr, _Radix);
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

int32_t _read(int32_t _FileHandle, void* _DstBuf, uint32_t _MaxCharCount)
{
    /* tailcall */
    return _read(_FileHandle, _DstBuf, _MaxCharCount);
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

BOOL TryEnterCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return TryEnterCriticalSection(lpCriticalSection);
}

BOOL TlsSetValue(uint32_t dwTlsIndex, void* lpTlsValue)
{
    /* tailcall */
    return TlsSetValue(dwTlsIndex, lpTlsValue);
}

int64_t TlsGetValue(uint32_t dwTlsIndex)
{
    /* tailcall */
    return TlsGetValue(dwTlsIndex);
}

BOOL TlsFree(uint32_t dwTlsIndex)
{
    /* tailcall */
    return TlsFree(dwTlsIndex);
}

uint32_t TlsAlloc()
{
    /* tailcall */
    return TlsAlloc();
}

void SetLastError(enum WIN32_ERROR dwErrCode)
{
    /* tailcall */
    return SetLastError(dwErrCode);
}

EXCEPTION_ROUTINE RtlVirtualUnwind(enum RTL_VIRTUAL_UNWIND_HANDLER_TYPE HandlerType, uint64_t ImageBase, uint64_t ControlPc, IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry, CONTEXT* ContextRecord, void** HandlerData, uint64_t* EstablisherFrame, KNONVOLATILE_CONTEXT_POINTERS* ContextPointers)
{
    /* tailcall */
    return RtlVirtualUnwind(HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, 
        HandlerData, EstablisherFrame, ContextPointers);
}

void RtlUnwindEx(void* TargetFrame, void* TargetIp, EXCEPTION_RECORD* ExceptionRecord, void* ReturnValue, CONTEXT* ContextRecord, UNWIND_HISTORY_TABLE* HistoryTable)
{
    /* tailcall */
    return RtlUnwindEx(TargetFrame, TargetIp, ExceptionRecord, ReturnValue, ContextRecord, 
        HistoryTable);
}

IMAGE_RUNTIME_FUNCTION_ENTRY* RtlLookupFunctionEntry(uint64_t ControlPc, uint64_t* ImageBase, UNWIND_HISTORY_TABLE* HistoryTable)
{
    /* tailcall */
    return RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable);
}

void RtlCaptureContext(CONTEXT* ContextRecord)
{
    /* tailcall */
    return RtlCaptureContext(ContextRecord);
}

void RaiseException(uint32_t dwExceptionCode, uint32_t dwExceptionFlags, uint32_t nNumberOfArguments, uint64_t* lpArguments) __noreturn
{
    /* tailcall */
    return RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
}

int32_t MultiByteToWideChar(uint32_t CodePage, enum MULTI_BYTE_TO_WIDE_CHAR_FLAGS dwFlags, uint8_t* lpMultiByteStr, int32_t cbMultiByte, wchar16* lpWideCharStr, int32_t cchWideChar)
{
    /* tailcall */
    return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, 
        cchWideChar);
}

HLOCAL LocalFree(HLOCAL hMem)
{
    /* tailcall */
    return LocalFree(hMem);
}

HMODULE LoadLibraryW(PWSTR lpLibFileName)
{
    /* tailcall */
    return LoadLibraryW(lpLibFileName);
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

uint32_t GetThreadId(HANDLE Thread)
{
    /* tailcall */
    return GetThreadId(Thread);
}

void GetStartupInfoA(STARTUPINFOA* lpStartupInfo)
{
    /* tailcall */
    return GetStartupInfoA(lpStartupInfo);
}

int64_t GetProcAddress(HMODULE hModule, PSTR lpProcName)
{
    /* tailcall */
    return GetProcAddress(hModule, lpProcName);
}

HMODULE GetModuleHandleW(PWSTR lpModuleName)
{
    /* tailcall */
    return GetModuleHandleW(lpModuleName);
}

enum WIN32_ERROR GetLastError()
{
    /* tailcall */
    return GetLastError();
}

uint32_t FormatMessageA(enum FORMAT_MESSAGE_OPTIONS dwFlags, void* lpSource, uint32_t dwMessageId, uint32_t dwLanguageId, PSTR lpBuffer, uint32_t nSize, char** Arguments)
{
    /* tailcall */
    return FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
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

BOOL CloseHandle(HANDLE hObject)
{
    /* tailcall */
    return CloseHandle(hObject);
}

int64_t j_sub_14000ea30(int32_t arg1)
{
    /* tailcall */
    return sub_14000ea30(arg1);
}

int64_t sub_140015430(int32_t arg1, int64_t arg2)
{
    if (arg2)
        /* tailcall */
        return sub_14000e9c0(arg1, arg2);
    
    return 0;
}

int64_t sub_140015450() __pure
{
    return;
}

int64_t sub_140015460() __pure
{
    return;
}

int64_t sub_140015470(int64_t* arg1, int64_t* arg2, int64_t* arg3)
{
    int64_t* var_20 = *arg3;
    
    if ((*(*arg2 + 0x10))(arg2))
        var_20 = *var_20;
    
    char result = (*(*arg1 + 0x20))(arg1, arg2, &var_20, 1);
    
    if (result)
        *arg3 = var_20;
    
    return result;
}

void* sub_1400154e0(void* arg1, char* arg2, int64_t* arg3)
{
    int64_t rax = 0;
    
    if (arg1)
        rax = sub_14000f350(arg1);
    
    *arg3 = rax;
    char rcx = *arg2;
    void* rbp = &arg2[1];
    
    if (rcx != 0xff)
        rbp = sub_1400157c0(rcx, sub_140015700(rcx, arg1), rbp, &arg3[1]);
    else
        arg3[1] = rax;
    
    char rax_1 = *rbp;
    void* r9_1 = rbp + 1;
    void* r8 = nullptr;
    arg3[5] = rax_1;
    
    if (rax_1 != 0xff)
    {
        int32_t rcx_1 = 0;
        uint32_t rdx;
        
        do
        {
            rdx = *r9_1;
            r9_1 += 1;
            uint64_t rax_4 = (rdx & 0x7f) << rcx_1;
            rcx_1 += 7;
            r8 |= rax_4;
        } while (rdx < 0);
        r8 += r9_1;
    }
    
    arg3[3] = r8;
    void* result = r9_1 + 1;
    void* const r10 = nullptr;
    int32_t rcx_2 = 0;
    *(arg3 + 0x29) = *r9_1;
    uint32_t r9_2;
    
    do
    {
        r9_2 = *result;
        result += 1;
        uint64_t rax_8 = (r9_2 & 0x7f) << rcx_2;
        rcx_2 += 7;
        r10 |= rax_8;
    } while (r9_2 < 0);
    arg3[4] = r10 + result;
    return result;
}

int64_t sub_1400155e0(void* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    int64_t arg_18 = arg3;
    char* rbx_2 = ~arg4 + *(arg1 + 0x18);
    char i;
    
    do
    {
        int64_t r9 = 0;
        int32_t rcx = 0;
        uint32_t rdx;
        
        do
        {
            rdx = *rbx_2;
            rbx_2 = &rbx_2[1];
            uint64_t rax_3 = (rdx & 0x7f) << rcx;
            rcx += 7;
            r9 |= rax_3;
        } while (rdx < 0);
        
        if (!r9)
            return 0;
        
        char rcx_1 = *(arg1 + 0x28);
        int64_t r8_1;
        
        if (rcx_1 == 0xff)
            r8_1 = 0;
        else
        {
            char rax_5 = rcx_1 & 7;
            
            if (rax_5 == 2)
                r8_1 = -((r9 * 2));
            else if (rax_5 <= 2)
            {
                if (rax_5)
                {
                    abort();
                    /* no return */
                }
                
                r8_1 = -((r9 << 3));
            }
            else
            {
                r8_1 = -((r9 << 2));
                
                if (rax_5 != 3)
                {
                    if (rax_5 != 4)
                    {
                        abort();
                        /* no return */
                    }
                    
                    r8_1 = -((r9 << 3));
                }
            }
        }
        
        int64_t* var_30;
        sub_1400157c0(rcx_1, *(arg1 + 0x10), r8_1 + *(arg1 + 0x18), &var_30);
        i = sub_140015470(var_30, arg2, &arg_18);
    } while (!i);
    
    return i;
}

int64_t sub_140015700(char arg1, void* arg2)
{
    if (arg1 != 0xff)
    {
        char rax_1 = arg1 & 0x70;
        
        if (rax_1 == 0x30)
            /* tailcall */
            return sub_14000f390();
        
        if (rax_1 > 0x30)
        {
            if (rax_1 == 0x40)
                /* tailcall */
                return sub_14000f350(arg2);
            
            if (rax_1 != 0x50)
            {
                abort();
                /* no return */
            }
        }
        else
        {
            if (rax_1 == 0x20)
                /* tailcall */
                return PortablePDB::PdbGUID(arg2);
            
            if (rax_1 > 0x20)
            {
                abort();
                /* no return */
            }
        }
    }
    
    return 0;
}

void sub_140015770(int32_t arg1, void* arg2)
{
    if (arg1 > 1)
    {
        sub_140015940(*(arg2 - 0x38));
        /* no return */
    }
    
    int32_t temp0 = *(arg2 - 0x60);
    *(arg2 - 0x60) -= 1;
    
    if (temp0 != 1)
        return;
    
    int64_t rax = *(arg2 - 0x48);
    
    if (rax)
        rax(arg2 + 0x40);
    
    /* tailcall */
    return sub_140021910(arg2 + 0x40);
}

void* sub_1400157c0(char arg1, char* arg2, char* arg3, int64_t* arg4)
{
    char* r11 = arg2;
    
    if (arg1 == 0x50)
    {
        void* rax_6 = &arg3[7] & 0xfffffffffffffff8;
        *arg4 = *rax_6;
        return rax_6 + 8;
    }
    
    char* result;
    int64_t* rdx;
    
    switch (arg1 & 0xf)
    {
        case 0:
        case 4:
        case 0xc:
        {
            rdx = *arg3;
            result = &arg3[8];
        label_1400157ff:
            
            if (rdx)
                goto label_14001580d;
            
            *arg4 = rdx;
            return result;
            break;
        }
        case 1:
        {
            result = arg3;
            rdx = nullptr;
            int32_t rcx_2 = 0;
            uint32_t rsi_1;
            
            do
            {
                rsi_1 = *result;
                result = &result[1];
                uint64_t rbx_3 = (rsi_1 & 0x7f) << rcx_2;
                rcx_2 += 7;
                rdx |= rbx_3;
            } while (rsi_1 < 0);
            goto label_1400157ff;
        }
        case 2:
        {
            rdx = *arg3;
            result = &arg3[2];
            goto label_1400157ff;
        }
        case 3:
        {
            rdx = *arg3;
            result = &arg3[4];
            goto label_1400157ff;
        }
        case 9:
        {
            result = arg3;
            rdx = nullptr;
            int32_t rcx_3 = 0;
            uint32_t rsi_2;
            
            do
            {
                rsi_2 = *result;
                result = &result[1];
                uint64_t rbx_6 = (rsi_2 & 0x7f) << rcx_3;
                rcx_3 += 7;
                rdx |= rbx_6;
            } while (rsi_2 < 0);
            
            if (rcx_3 > 0x3f || !(rsi_2 & 0x40))
                goto label_1400157ff;
            
            rdx |= 0xffffffffffffffff << rcx_3;
        label_14001580d:
            
            if ((arg1 & 0x70) == 0x10)
                r11 = arg3;
            
            rdx += r11;
            
            if (arg1 < 0)
            {
                *arg4 = *rdx;
                return result;
            }
            
            *arg4 = rdx;
            return result;
            break;
        }
        case 0xa:
        {
            rdx = *arg3;
            result = &arg3[2];
            goto label_1400157ff;
        }
        case 0xb:
        {
            rdx = *arg3;
            result = &arg3[4];
            goto label_1400157ff;
        }
    }
    
    abort();
    /* no return */
}

void sub_140015940(int64_t arg1) __noreturn
{
    arg1();
    abort();
    /* no return */
}

void sub_140015960(int64_t arg1) __noreturn
{
    arg1();
    sub_140021b00();
    /* no return */
}

int64_t sub_140015970(int64_t arg1)
{
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140015980() __pure
{
    return;
}

int64_t sub_140015990(struct std::type_info::__cxxabiv1::__class_type_info::VTable** arg1)
{
    *arg1 = &_vtable_for___cxxabiv1::__class_type_info{for `std::type_info'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_1400159c0(struct std::type_info::__cxxabiv1::__class_type_info::VTable** arg1)
{
    *arg1 = &_vtable_for___cxxabiv1::__class_type_info{for `std::type_info'};
    /* tailcall */
    return sub_1400210a0();
}

int64_t sub_1400159d0(int64_t arg1)
{
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_1400159e0() __pure
{
    return;
}

int64_t sub_1400159f0(struct std::type_info::__cxxabiv1::__si_class_type_info::VTable** arg1)
{
    *arg1 = &_vtable_for___cxxabiv1::__si_class_type_info{for `std::type_info'};
    sub_1400159c0(arg1);
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140015a20(struct std::type_info::__cxxabiv1::__si_class_type_info::VTable** arg1)
{
    *arg1 = &_vtable_for___cxxabiv1::__si_class_type_info{for `std::type_info'};
    /* tailcall */
    return sub_1400159c0(arg1);
}

int64_t sub_140015a40(int32_t arg1, int32_t arg2, int64_t arg3, char* arg4, void* arg5)
{
    int128_t zmm6;
    int128_t var_58 = zmm6;
    int32_t var_ac = 0;
    void* var_a8 = nullptr;
    
    if (arg1 != 1)
        return 3;
    
    bool cond:0_1 = -0x474e5543432b2b00 + arg3 <= 1;
    int64_t rax;
    rax = arg2 == 6;
    rax &= cond:0_1;
    char* var_f8_1;
    char var_e9;
    int64_t var_88;
    void* rbx_1;
    uint64_t rdi_2;
    int64_t rdi_3;
    
    if (!rax)
    {
        char* rax_3 = sub_14000f340(arg5);
        var_f8_1 = rax_3;
        
        if (!rax_3)
        {
        label_140015d25:
            return 8;
        }
        
        int64_t var_70;
        __builtin_memset(&var_70, 0, 0x11);
        void* rax_4 = sub_1400154e0(arg5, rax_3, &var_88);
        zmm6 = var_70;
        void* r13_1 = rax_4;
        int64_t zmm0 = zmm6 >> 0x40;
        char var_60;
        var_e9 = var_60;
        char* rax_6 = sub_140015700(var_60, arg5);
        char* var_78_1 = rax_6;
        int64_t rax_8 = sub_14000f320(arg5, &var_ac) - 0;
        void* r13_4;
        
        if (r13_1 < zmm0)
        {
            int64_t r15_1 = var_88;
            int64_t* var_90;
            int64_t** var_110_1 = &var_90;
            
            do
            {
                int64_t var_a0;
                char var_5f;
                void* rax_10 =
                    sub_1400157c0(var_5f, sub_140015700(var_5f, nullptr), r13_1, &var_a0);
                int64_t var_98;
                void* rax_12 =
                    sub_1400157c0(var_5f, sub_140015700(var_5f, nullptr), rax_10, &var_98);
                int64_t rdx_7 = 0;
                int32_t rcx_13 = 0;
                r13_1 = sub_1400157c0(var_5f, sub_140015700(var_5f, nullptr), rax_12, var_110_1);
                uint32_t r8_6;
                
                do
                {
                    r8_6 = *r13_1;
                    r13_1 += 1;
                    uint64_t rax_17 = (r8_6 & 0x7f) << rcx_13;
                    rcx_13 += 7;
                    rdx_7 |= rax_17;
                } while (r8_6 < 0);
                int64_t rax_19 = var_a0 + r15_1;
                
                if (rax_8 < rax_19)
                    break;
                
                if (rax_8 < rax_19 + var_98)
                {
                    int64_t* rbx_3 = var_90;
                    
                    if (!rbx_3)
                        goto label_140015d25;
                    
                    int64_t var_80;
                    rbx_1 = rbx_3 + var_80;
                    
                    if (!rdx_7)
                    {
                        if (!rbx_1)
                            goto label_140015d25;
                        
                    label_1400160f6:
                        
                        if (arg2 & 1)
                            goto label_140015d25;
                        
                        rdi_3 = 0;
                        goto label_140015af0;
                    }
                    
                    r13_4 = zmm0 + rdx_7 - 1;
                    
                    if (!rbx_1)
                        goto label_140015d25;
                    
                    char rdx_8 = 1;
                    struct __cxxabiv1::__class_type_info* const r10_1 =
                        &_typeinfo_for___cxxabiv1::__forced_unwind;
                    int32_t r12_3 = arg2 & 8;
                    
                    if (!r12_3)
                    {
                        r10_1 = &_typeinfo_for___cxxabiv1::__foreign_exception;
                        
                        if (-0x474e5543432b2b00 + arg3 <= 1)
                        {
                            void* rax_51 = &arg4[0x40];
                            
                            if (*arg4 & 1)
                                rax_51 = *(arg4 - 0x50);
                            
                            r10_1 = *(rax_51 - 0x90);
                            var_a8 = rax_51;
                            rdx_8 = r10_1;
                        }
                    }
                    
                    char* r15_2 = zmm6;
                    int64_t* var_d8_1 = r10_1;
                    char rsi_1 = rax;
                    int64_t* var_108_1;
                    var_108_1 = var_e9 & 7;
                    
                    while (true)
                    {
                        char* rbx_4 = r13_4;
                        rdi_2 = 0;
                        int32_t rcx_15 = 0;
                        uint32_t rdx_9;
                        
                        do
                        {
                            rdx_9 = *rbx_4;
                            rbx_4 = &rbx_4[1];
                            uint64_t rax_29 = (rdx_9 & 0x7f) << rcx_15;
                            rcx_15 += 7;
                            rdi_2 |= rax_29;
                        } while (rdx_9 < 0);
                        
                        if (rcx_15 <= 0x3f && rdx_9 & 0x40)
                            rdi_2 |= -((1 << rcx_15));
                        
                        char* rdx_11 = rbx_4;
                        int64_t r12_4 = 0;
                        int32_t rcx_16 = 0;
                        uint32_t r8_7;
                        
                        do
                        {
                            r8_7 = *rdx_11;
                            rdx_11 = &rdx_11[1];
                            uint64_t rax_34 = (r8_7 & 0x7f) << rcx_16;
                            rcx_16 += 7;
                            r12_4 |= rax_34;
                        } while (r8_7 < 0);
                        
                        if (rcx_16 > 0x3f || !(r8_7 & 0x40))
                        {
                            if (!rdi_2)
                                rsi_1 = 1;
                            else
                            {
                                if (arg2 == 2)
                                    goto label_140015f05;
                                
                            label_140015ea9:
                                
                                if (rdi_2 > 0)
                                {
                                    char* r8_13;
                                    
                                    if (var_e9 == 0xff)
                                        r8_13 = r15_2;
                                    else
                                    {
                                        char temp1_1 = var_108_1;
                                        
                                        if (temp1_1 == 2)
                                            r8_13 = r15_2 - rdi_2 * 2;
                                        else if (temp1_1 <= 2)
                                        {
                                            if (var_108_1)
                                            {
                                                abort();
                                                /* no return */
                                            }
                                            
                                            r8_13 = r15_2 - (rdi_2 << 3);
                                        }
                                        else
                                        {
                                            r8_13 = r15_2 - (rdi_2 << 2);
                                            
                                            if (var_108_1 != 3)
                                            {
                                                if (var_108_1 != 4)
                                                {
                                                    abort();
                                                    /* no return */
                                                }
                                                
                                                r8_13 = r15_2 - (rdi_2 << 3);
                                            }
                                        }
                                    }
                                    
                                    sub_1400157c0(var_60, rax_6, r8_13, var_110_1);
                                    int64_t* rcx_23 = var_90;
                                    
                                    if (!rcx_23)
                                        break;
                                    
                                    if (var_d8_1 && sub_140015470(rcx_23, var_d8_1, &var_a8))
                                        break;
                                }
                                else if ((r12_3 >> 3 ^ 1) & cond:0_1 & rdx_8)
                                {
                                    var_70 = zmm6;
                                    char var_60_1 = var_e9;
                                    
                                    if (!sub_1400155e0(&var_88, var_d8_1, var_a8, rdi_2))
                                    {
                                        int32_t rbp;
                                        rbp = arg2 & 1;
                                        
                                        if (!rbp)
                                            goto label_14001609a;
                                        
                                        goto label_140015f65;
                                    }
                                }
                                else
                                {
                                    int64_t r9_3 = 0;
                                    int32_t rcx_17 = 0;
                                    void* rdx_14 = &r15_2[~rdi_2];
                                    uint32_t r8_9;
                                    
                                    do
                                    {
                                        r8_9 = *rdx_14;
                                        rdx_14 += 1;
                                        uint64_t rax_39 = (r8_9 & 0x7f) << rcx_17;
                                        rcx_17 += 7;
                                        r9_3 |= rax_39;
                                    } while (r8_9 < 0);
                                    
                                    if (!r9_3)
                                        break;
                                }
                            }
                            
                        label_140015f05:
                            
                            if (!r12_4)
                            {
                                if (!rsi_1)
                                    goto label_140015d25;
                                
                                goto label_1400160f6;
                            }
                        }
                        else
                        {
                            r12_4 |= -((1 << rcx_16));
                            
                            if (!rdi_2)
                                rsi_1 = 1;
                            else if (arg2 != 2)
                                goto label_140015ea9;
                        }
                        
                        r13_4 = &rbx_4[r12_4];
                    }
                    
                    if (arg2 & 1)
                        goto label_140015cfa;
                    
                    if (!r12_3)
                    {
                    label_14001609a:
                        
                        if (-0x474e5543432b2b00 + arg3 <= 1)
                            goto label_140015acd;
                    }
                    
                    if (rdi_2 >= 0)
                        goto label_140015ae0;
                    
                    sub_140021b20();
                    /* no return */
                }
            } while (r13_1 < zmm0);
        }
        
        if (arg2 & 1)
        {
            r13_4 = nullptr;
            rbx_1 = nullptr;
            rdi_2 = 0;
        label_140015cfa:
            
            if (-0x474e5543432b2b00 + arg3 <= 1)
            {
            label_140015f65:
                *(arg4 - 0x24) = rdi_2;
                *(arg4 - 0x20) = r13_4;
                *(arg4 - 0x18) = var_f8_1;
                void* rax_43 = var_a8;
                *(arg4 - 0x10) = rbx_1;
                *(arg4 - 8) = rax_43;
            }
            
            return 6;
        }
        
        if (arg2 & 8 || -0x474e5543432b2b00 + arg3 > 1)
        {
            sub_140021b00();
            /* no return */
        }
    }
    else
    {
        rbx_1 = *(arg4 - 0x10);
        
        if (rbx_1)
        {
            rdi_2 = *(arg4 - 0x24);
            var_f8_1 = *(arg4 - 0x18);
        label_140015acd:
            
            if (rdi_2 < 0)
            {
                sub_1400154e0(arg5, var_f8_1, &var_88);
                sub_140015700(var_e9, arg5);
                *(arg4 - 0x10) = sub_140015700(var_e9, arg5);
            }
            
        label_140015ae0:
            rdi_3 = rdi_2;
        label_140015af0:
            sub_14000f2e0(arg5, 0, arg4);
            sub_14000f2e0(arg5, 1, rdi_3);
            sub_14000f330(arg5, rbx_1);
            return 7;
        }
    }
    sub_140021d80(arg4);
    /* no return */
}

void sub_140016180(void* _Block)
{
    /* tailcall */
    return sub_140021540(_Block);
}

int64_t sub_140016190() __pure
{
    return;
}

void sub_1400161a0(void* _Block)
{
    /* tailcall */
    return sub_140021540(_Block);
}

int64_t sub_1400161b0() __pure
{
    return;
}

void sub_1400161c0(void* arg1)
{
    int32_t r9 = data_140023080;
    int64_t* rdx;
    int64_t rsi_1;
    void* r8_1;
    void* r10;
    
    if (r9)
    {
        x17d69fb8::close::operator[]::environment_strings_traits::close(&data_1400231a0);
        rdx = data_1400231c8;
        r9 = data_140023080;
        r10 = arg1 - 0x10;
        
        if (rdx)
        {
            rsi_1 = *(arg1 - 0x10);
            r8_1 = r10 + rsi_1;
        }
        
        if (rdx && r8_1 >= rdx)
            goto label_14001626c;
        
        *(arg1 - 8) = rdx;
        data_1400231c8 = r10;
    label_1400162fb:
        
        if (r9)
            x1bf47908::close::operator[]::environment_strings_traits::close(&data_1400231a0);
        
        return;
    }
    
    rdx = data_1400231c8;
    r10 = arg1 - 0x10;
    
    if (!rdx)
    {
        *(arg1 - 8) = 0;
        data_1400231c8 = r10;
        return;
    }
    
    rsi_1 = *(arg1 - 0x10);
    r8_1 = r10 + rsi_1;
    
    if (r8_1 >= rdx)
    {
    label_14001626c:
        int64_t* rax = rdx[1];
        
        if (r8_1 == rdx)
        {
            int64_t rsi_2 = rsi_1 + *r8_1;
            *(arg1 - 8) = rax;
            *(arg1 - 0x10) = rsi_2;
            data_1400231c8 = r10;
        }
        else
        {
            void* r11_1 = &data_1400231c8;
            
            if (rax)
            {
                while (true)
                {
                    bool cond:0_1 = rax != r8_1;
                    
                    if (rax >= r8_1)
                    {
                        rax = rdx;
                        
                        if (!cond:0_1)
                        {
                            void* rax_1 = rdx[1];
                            rsi_1 += *rax_1;
                            rdx[1] = *(rax_1 + 8);
                            rax = *r11_1;
                        }
                        
                        break;
                    }
                    
                    int64_t* rcx = rax[1];
                    r11_1 = &rdx[1];
                    rdx = rax;
                    
                    if (!rcx)
                        break;
                    
                    rax = rcx;
                }
            }
            else
                rax = rdx;
            
            int64_t rdx_1 = *rax;
            
            if (r10 == rax + rdx_1)
                *rax = rdx_1 + rsi_1;
            else
            {
                int64_t rax_3 = rax[1];
                *(arg1 - 0x10) = rsi_1;
                *(arg1 - 8) = rax_3;
                (*r11_1)[1] = r10;
            }
        }
        
        goto label_1400162fb;
    }
    
    *(arg1 - 8) = rdx;
    data_1400231c8 = r10;
}

int64_t* sub_140016360(int64_t arg1)
{
    int32_t rcx = data_140023080;
    int64_t* result;
    int64_t i;
    
    if (rcx)
    {
        x17d69fb8::close::operator[]::environment_strings_traits::close(&data_1400231a0);
        int64_t rax_3 = arg1 + 0x10;
        result = data_1400231c8;
        rcx = data_140023080;
        
        if (rax_3 < 0x10)
            rax_3 = 0x10;
        
        i = (rax_3 + 0xf) & 0xfffffffffffffff0;
        
        if (result)
            goto label_14001639e;
        
    label_140016480:
        result = nullptr;
    label_1400163f9:
        
        if (rcx)
            x1bf47908::close::operator[]::environment_strings_traits::close(&data_1400231a0);
    }
    else
    {
        int64_t rax = arg1 + 0x10;
        result = data_1400231c8;
        
        if (rax < 0x10)
            rax = 0x10;
        
        i = (rax + 0xf) & 0xfffffffffffffff0;
        
        if (result)
        {
        label_14001639e:
            int64_t* rdx_1 = &data_1400231c8;
            
            while (*result < i)
            {
                rdx_1 = &result[1];
                result = result[1];
                
                if (!result)
                    goto label_140016480;
            }
            
            int64_t* rbx_1 = *rdx_1;
            int64_t r8_1 = *rbx_1;
            void* r10_1 = rbx_1[1];
            int64_t r9_2 = r8_1 - i;
            void* r8_2;
            
            if (r9_2 > 0xf)
            {
                r8_2 = rbx_1 + i;
                *(r8_2 + 8) = r10_1;
                rbx_1 = *rdx_1;
                *r8_2 = r9_2;
                *rbx_1 = i;
            }
            else
            {
                *rbx_1 = r8_1;
                r8_2 = r10_1;
            }
            
            *rdx_1 = r8_2;
            result = &rbx_1[2];
            goto label_1400163f9;
        }
    }
    return result;
}

uint64_t sub_1400164c0(int64_t arg1, int64_t arg2, uint64_t arg3)
{
    uint64_t i_1 = arg3;
    void var_30;
    void* r10 = &var_30;
    uint64_t i;
    
    do
    {
        r10 -= 1;
        *r10 = data_1400260a9[i_1 % 0xa];
        i = i_1;
        i_1 u/= 0xa;
    } while (i > 9);
    uint64_t _Size = &var_30 - r10;
    
    if (arg2 < _Size)
        return 0xffffffff;
    
    void var_48;
    memcpy(arg1, &var_48 - _Size + 0x18, _Size);
    return _Size;
}

uint64_t sub_140016580(char* arg1, int64_t arg2, char* arg3, uint64_t* arg4)
{
    char rax = *arg3;
    char* rsi = arg3;
    char* rbx = arg1;
    uint64_t result;
    
    if (rax)
    {
        while (true)
        {
            if (rbx < &arg1[arg2 - 1])
            {
                char rax_1;
                
                if (rax != 0x25)
                {
                label_1400165a8:
                    rax_1 = *rsi;
                label_1400165ab:
                    *rbx = rax_1;
                    rsi = &rsi[1];
                    rbx = &rbx[1];
                label_1400165b5:
                    rax = *rsi;
                    
                    if (!rax)
                        break;
                    
                    continue;
                }
                else
                {
                    rax_1 = rsi[1];
                    
                    if (rax_1 == 0x73)
                    {
                        uint64_t rdx_2 = *arg4;
                        char rax_5 = *rdx_2;
                        
                        if (rax_5)
                        {
                            while (true)
                            {
                                rdx_2 += 1;
                                *rbx = rax_5;
                                rbx = &rbx[1];
                                rax_5 = *rdx_2;
                                
                                if (!rax_5)
                                    break;
                                
                                if (&arg1[arg2 - 1] == rbx)
                                {
                                    sub_140022270(arg1, &arg1[arg2 - 1]);
                                    /* no return */
                                }
                            }
                        }
                        
                        rsi = &rsi[2];
                        arg4 = &arg4[1];
                        goto label_1400165b5;
                    }
                    
                    if (rax_1 != 0x7a)
                    {
                        if (rax_1 != 0x25)
                            goto label_1400165a8;
                        
                        rsi = &rsi[1];
                        goto label_1400165ab;
                    }
                    
                    if (rsi[2] != 0x75)
                        goto label_1400165a8;
                    
                    int32_t rax_3 = sub_1400164c0(rbx, &arg1[arg2 - 1] - rbx, *arg4);
                    
                    if (rax_3 > 0)
                    {
                        rsi = &rsi[3];
                        arg4 = &arg4[1];
                        rbx = &rbx[rax_3];
                        goto label_1400165b5;
                    }
                }
            }
            
            sub_140022270(arg1, rbx);
            /* no return */
        }
        
        result = rbx - arg1;
    }
    else
        result = 0;
    
    *rbx = 0;
    return result;
}

int64_t sub_1400166a0(struct std::exception::__concurrence_lock_error::VTable** arg1)
{
    *arg1 = &_vtable_for___concurrence_lock_error{for `std::exception'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_1400166d0(struct std::exception::__concurrence_lock_error::VTable** arg1)
{
    *arg1 = &_vtable_for___concurrence_lock_error{for `std::exception'};
    /* tailcall */
    return sub_140021080();
}

int64_t sub_1400166e0(struct std::exception::__concurrence_unlock_error::VTable** arg1)
{
    *arg1 = &_vtable_for___concurrence_unlock_error{for `std::exception'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140016710(struct std::exception::__concurrence_unlock_error::VTable** arg1)
{
    *arg1 = &_vtable_for___concurrence_unlock_error{for `std::exception'};
    /* tailcall */
    return sub_140021080();
}

void sub_140016720() __noreturn
{
    if (data_140023220)
    {
        fwrite("terminate called recursively\n", 1, 0x1d, data_140023130(2));
        abort();
        /* no return */
    }
    
    data_140023220 = 1;
    void** rax = sub_140021820();
    
    if (!rax)
    {
        fwrite("terminate called without an active exception\n", 1, 0x2d, data_140023130(2));
        abort();
        /* no return */
    }
    
    void* rbx = rax[1];
    bool cond:0 = *rbx == 0x2a;
    int32_t var_1c = 0xffffffff;
    int64_t rax_1;
    rax_1 = cond:0;
    char* _Buffer_1 = rbx + rax_1;
    char* _Buffer = sub_14000ddb0(_Buffer_1, nullptr, nullptr, &var_1c);
    void* rsi = data_140023130;
    fwrite("terminate called after throwing an instance of '", 1, 0x30, rsi(2));
    int32_t rdx = var_1c;
    
    if (!rdx)
        fputs(_Buffer, rsi(2, rdx));
    else
        fputs(_Buffer_1, rsi(2, rdx));
    
    fwrite(&data_1400241e1, 1, 2, rsi(2));
    
    if (!var_1c)
        free(_Buffer);
    
    sub_1400219e0();
    /* no return */
}

void sub_1400168e0() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for___concurrence_lock_error{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for___concurrence_lock_error, sub_1400166d0);
    /* no return */
}

void sub_140016910() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for___concurrence_unlock_error{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for___concurrence_unlock_error, sub_140016710);
    /* no return */
}

int64_t std::_String_const_iterator<class std::_String_val<struct std::_Simple_types<uint16_t> > >::operator==(int64_t* arg1, int64_t* arg2)
{
    int64_t result;
    result = *arg1 == *arg2;
    return result;
}

int64_t SymBuffer::iterator::operator==(int64_t* arg1, int64_t* arg2)
{
    int64_t result;
    result = *arg1 == *arg2;
    return result;
}

int64_t StrList<char>::iterator::operator==(int64_t* arg1, int64_t* arg2)
{
    int64_t result;
    result = *arg1 == *arg2;
    return result;
}

int64_t std::_String_const_iterator<class std::_String_val<struct std::_Simple_types<wchar_t> > >::operator==(int64_t* arg1, int64_t* arg2)
{
    int64_t result;
    result = *arg1 == *arg2;
    return result;
}

int64_t sub_140016980(void* arg1, int64_t* arg2, int64_t arg3, int32_t arg4)
{
    char result = sub_1400193f0(arg1, arg2);
    
    if (!result && arg4 <= 3)
        /* jump -> *(*arg2 + 0x28) */
    
    return result;
}

int64_t sub_1400169d0(void* arg1, void* arg2, int64_t arg3, int64_t* arg4)
{
    char result = sub_1400193f0(arg1, arg2);
    
    if (result)
    {
        *arg4 = arg3;
        arg4[2] = 0x10;
        arg4[1] = 6;
    }
    
    return result;
}

uint64_t sub_140016a00(int64_t* arg1, int64_t arg2, int64_t* arg3)
{
    int64_t var_20 = 0x1000000000;
    int64_t rax = *arg1;
    int64_t var_28 = 0;
    (*(rax + 0x30))(arg1, arg2, *arg3, &var_28, var_28, var_20, 0);
    int32_t rdx = 0;
    
    if (!(~var_20 & 6))
    {
        rdx = 1;
        *arg3 = var_28;
    }
    
    return rdx;
}

int64_t sub_140016a60(void* arg1, int64_t arg2, int32_t arg3, void* arg4, int64_t arg5, void* arg6, int64_t arg7, int64_t* arg8)
{
    if (arg5 == arg7 && sub_1400193f0(arg1, arg6))
    {
        *(arg8 + 0xc) = arg3;
        return 0;
    }
    
    if (sub_1400193f0(arg1, arg4))
    {
        *arg8 = arg5;
        arg8[1] = arg3;
        arg8[2] = 1;
    }
    
    return 0;
}

uint64_t sub_140016ae0(int64_t, int64_t, int64_t arg3, int64_t arg4) __pure
{
    int64_t rax;
    rax = arg4 == arg3;
    return rax * 5 + 1;
}

int64_t sub_140016af0(void* arg1, void* arg2, int64_t arg3, int64_t* arg4)
{
    char result = sub_1400169d0(arg1, arg2, arg3, arg4);
    
    if (result)
        return result;
    
    /* jump -> *(**(arg1 + 0x10) + 0x30) */
}

int64_t sub_140016b40(void* arg1, int64_t arg2, int32_t arg3, void* arg4, int64_t arg5, void* arg6, int64_t arg7, int64_t* arg8)
{
    if (sub_1400193f0(arg1, arg4))
    {
        *arg8 = arg5;
        arg8[1] = arg3;
        
        if (arg2 >= 0)
        {
            int64_t rax_3;
            rax_3 = arg7 == arg5 + arg2;
            arg8[2] = rax_3 * 5 + 1;
        }
        else if (arg2 == -2)
            arg8[2] = 1;
    }
    else
    {
        if (arg5 != arg7)
            /* jump -> *(**(arg1 + 0x10) + 0x38) */
        
        if (!sub_1400193f0(arg1, arg6))
            /* jump -> *(**(arg1 + 0x10) + 0x38) */
        
        *(arg8 + 0xc) = arg3;
    }
    
    return 0;
}

int64_t sub_140016c50(void* arg1, int64_t arg2, int64_t arg3, void* arg4, int64_t arg5)
{
    if (arg5 == arg3)
    {
        int64_t var_20_1 = arg3;
        void* var_28_1 = arg4;
        
        if (sub_1400193f0(arg1, arg4))
            return 6;
    }
    
    /* jump -> *(**(arg1 + 0x10) + 0x40) */
}

int64_t sub_140016cc0(int64_t arg1, int32_t arg2, int32_t* arg3)
{
    int64_t var_18;
    sub_140016d10(&var_18, arg1, arg2);
    int64_t var_10;
    
    if (*(arg3 + 8) != var_10)
        return 0;
    
    int64_t result;
    result = *arg3 == var_18;
    return result;
}

int32_t* sub_140016d10(int32_t* arg1, int64_t arg2, int32_t arg3)
{
    if (arg3 > 0x217)
    {
        if (arg3 > 0x4c9)
        {
            if (arg3 > 0x5b4)
                switch (arg3)
                {
                    case 0x718:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x89a:
                    {
                        *arg1 = 0x16;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x961:
                    {
                        *arg1 = 0xb;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x962:
                    {
                        *arg1 = 0xb;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x964:
                    {
                        *arg1 = 0xb;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x2095:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                }
            else if (arg3 <= 0x56f)
            {
                if (arg3 == 0x522)
                {
                    *arg1 = 1;
                    *(arg1 + 8) = &data_1400231f0;
                    return arg1;
                }
                
                if (arg3 == 0x534)
                {
                    *arg1 = 0x16;
                    *(arg1 + 8) = &data_1400231f0;
                    return arg1;
                }
            }
            else
            {
                uint64_t rcx_9 = arg3 - 0x570;
                
                if (rcx_9 <= 0x44)
                    switch (rcx_9)
                    {
                        case 0:
                        {
                            *arg1 = 0x11;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            *arg1 = 5;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3a:
                        {
                            *arg1 = 0x1b;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3b:
                        {
                            *arg1 = 0xb;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3c:
                        {
                            *arg1 = 0xb;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3d:
                        {
                            *arg1 = 0xb;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3e:
                        {
                            *arg1 = 0xb;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x3f:
                        {
                            *arg1 = 0xb;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                        case 0x44:
                        {
                            *arg1 = 0x10;
                            *(arg1 + 8) = &data_1400231f0;
                            return arg1;
                            break;
                        }
                    }
            }
        }
        else if (arg3 > 0x44b)
        {
            uint64_t rcx_3 = arg3 - 0x44c;
            
            if (rcx_3 <= 0x7d)
                switch (rcx_3)
                {
                    case 0:
                    {
                        *arg1 = 0x1c;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 1:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 2:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 3:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 4:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 6:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0xb:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x11:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x1d:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x1f:
                    {
                        *arg1 = 0x24;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x2a:
                    {
                        *arg1 = 0x1f;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x41:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x42:
                    {
                        *arg1 = 5;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x64:
                    {
                        *arg1 = 0x13;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x7b:
                    {
                        *arg1 = 4;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0x7d:
                    {
                        *arg1 = 0x6b;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                }
        }
        else if (arg3 > 0x3f0)
        {
            if (arg3 == 0x41d)
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
            }
            
            if (arg3 == 0x42b)
            {
                *arg1 = 0xe;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
            }
        }
        else if (arg3 > 0x3e3)
        {
            uint64_t rcx_6 = arg3 - 0x3e4;
            
            if (rcx_6 <= 0xc)
                switch (rcx_6)
                {
                    case 0:
                    {
                        *arg1 = 0xb;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 1:
                    {
                        *arg1 = 0xb;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 2:
                    {
                        *arg1 = 0xe;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0xa:
                    {
                        *arg1 = 6;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                    case 0xc:
                    {
                        *arg1 = 0x16;
                        *(arg1 + 8) = &data_1400231f0;
                        return arg1;
                        break;
                    }
                }
        }
    }
    else if (arg3 >= 0 && arg3 <= 0x217)
        switch (arg3)
        {
            case 0:
            {
                *arg1 = 0;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 2:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 3:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 4:
            {
                *arg1 = 0x18;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 5:
            {
                *arg1 = 0xd;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 6:
            {
                *arg1 = 9;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 8:
            {
                *arg1 = 0xc;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xd:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xe:
            {
                *arg1 = 0xc;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xf:
            {
                *arg1 = 0x13;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x11:
            {
                *arg1 = 0x12;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x13:
            {
                *arg1 = 0x1e;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x14:
            {
                *arg1 = 0x13;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x17:
            {
                *arg1 = 5;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x19:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x1b:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x20:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x21:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x24:
            {
                *arg1 = 0x27;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x27:
            {
                *arg1 = 0x1c;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x32:
            {
                *arg1 = 0x28;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x35:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x37:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x3a:
            {
                *arg1 = 0x28;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x3b:
            {
                *arg1 = 5;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x40:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x43:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x50:
            {
                *arg1 = 0x11;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x52:
            {
                *arg1 = 1;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x57:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x59:
            {
                *arg1 = 0xb;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x68:
            {
                *arg1 = 4;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x6d:
            {
                *arg1 = 0x20;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x6e:
            {
                *arg1 = 5;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x70:
            {
                *arg1 = 0x1c;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x71:
            {
                *arg1 = 0x17;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x78:
            {
                *arg1 = 0x28;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x7b:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x7e:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x7f:
            {
                *arg1 = 3;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x81:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x83:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x91:
            {
                *arg1 = 0x29;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x9c:
            {
                *arg1 = 5;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xa1:
            {
                *arg1 = 2;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xa2:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xa4:
            {
                *arg1 = 0xb;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xaa:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xb7:
            {
                *arg1 = 0x11;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xbf:
            {
                *arg1 = 8;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xc0:
            {
                *arg1 = 8;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xc1:
            {
                *arg1 = 8;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xc5:
            {
                *arg1 = 8;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xcd:
            {
                *arg1 = 5;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xce:
            {
                *arg1 = 0x26;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xd0:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xd1:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xd2:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xd8:
            {
                *arg1 = 8;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xe6:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xe7:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xe8:
            {
                *arg1 = 0x20;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xea:
            {
                *arg1 = 0x73;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0xfe:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x10b:
            {
                *arg1 = 0x14;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x120:
            {
                *arg1 = 1;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x1e7:
            {
                *arg1 = 0x16;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
            case 0x217:
            {
                *arg1 = 0x10;
                *(arg1 + 8) = &data_1400231f0;
                return arg1;
                break;
            }
        }
    
    *arg1 = arg3;
    *(arg1 + 8) = arg2;
    return arg1;
}

int64_t sub_140017630() __pure
{
    return "system";
}

int64_t* sub_140017640(int64_t* arg1)
{
    char* buffer = nullptr;
    uint32_t entry_dwMessageId;
    uint32_t rax = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
        nullptr, entry_dwMessageId, 0x400, &buffer, 0, nullptr);
    
    if (!rax)
    {
        *arg1 = &arg1[2];
        sub_14001e380(arg1, "Unknown error code", &data_14002709a[0x12]);
        return arg1;
    }
    
    char* hMem = buffer;
    uint64_t r8 = rax;
    
    if (rax > 3 && *(hMem + r8 - 3) == 0xd2e && hMem[r8 - 1] == 0xa)
        r8 = rax - 3;
    
    *arg1 = &arg1[2];
    
    if (!hMem)
    {
        sub_140021f00("basic_string: construction from null is not valid");
        /* no return */
    }
    
    sub_14001e380(arg1, hMem, &hMem[r8]);
    LocalFree(hMem);
    return arg1;
}

void sub_140017704(void* arg1 @ rax, HLOCAL arg2 @ rsi) __noreturn
{
    LocalFree(arg2);
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_140017730(int64_t arg1, int32_t arg2, int32_t* arg3)
{
    if (arg2 != *arg3)
        return 0;
    
    int64_t result;
    result = *(arg3 + 8) == arg1;
    return result;
}

int64_t sub_140017750() __pure
{
    return "generic";
}

int64_t* sub_140017760(int64_t* arg1, int64_t arg2, int32_t arg3)
{
    char* _Str = strerror(arg3);
    *arg1 = &arg1[2];
    
    if (!_Str)
    {
        sub_140021f00("basic_string: construction from null is not valid");
        /* no return */
    }
    
    sub_14001e380(arg1, _Str, &_Str[strlen(_Str)]);
    return arg1;
}

int64_t sub_1400177b0() __pure
{
    return "__gnu_cxx::__concurrence_lock_error";
}

int64_t sub_1400177c0() __pure
{
    return "__gnu_cxx::__concurrence_unlock_error";
}

uint64_t sub_1400177d0(int64_t* arg1, int64_t arg2)
{
    int64_t rax_2 = *arg1;
    int32_t rcx = 1;
    
    if (arg2 >= rax_2)
        rcx = rax_2 + *(rax_2 - 0x18) < arg2;
    
    return rcx;
}

int64_t sub_1400177f0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017820(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140017820(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    void* rbp = *arg1;
    int64_t rbx = *(rbp - 0x18);
    
    if (!rbx || !arg4)
        return -1;
    
    int64_t result = rbx - 1;
    
    if (result > arg3)
        result = arg3;
    
    int64_t i;
    
    do
    {
        if (memchr(arg2, *(rbp + result), arg4))
            break;
        
        i = result;
        result -= 1;
    } while (i >= 1);
    return result;
}

int64_t sub_1400178a0(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    void* rdx_1 = *arg2;
    /* tailcall */
    return sub_140017820(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

int64_t sub_1400178b0(int64_t* arg1, char arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017f40(arg1, arg2, arg3);
}

int64_t sub_1400178c0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400178f0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_1400178f0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t result = arg3;
    
    if (arg4)
    {
        void* rbp_1 = *arg1;
        int64_t r12_1 = *(rbp_1 - 0x18);
        
        if (arg3 < r12_1)
        {
            do
            {
                if (memchr(arg2, *(rbp_1 + result), arg4))
                    return result;
                
                result += 1;
            } while (result != r12_1);
        }
    }
    
    return -1;
}

int64_t sub_140017970(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    void* rdx_1 = *arg2;
    /* tailcall */
    return sub_1400178f0(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

int64_t sub_140017980(int64_t* arg1, char arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017dc0(arg1, arg2, arg3);
}

int64_t sub_140017990(int64_t arg1) __pure
{
    return arg1;
}

void* sub_1400179a0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4)
{
    void* result = *arg1;
    
    if (arg2 + 0x3ffffffffffffff9 - *(result - 0x18) >= arg3)
        return result;
    
    sub_140021ff0(arg4);
    /* no return */
}

int64_t sub_1400179d0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017a00(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140017a00(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t result = -1;
    void* rbp = *arg1;
    int64_t rax = *(rbp - 0x18);
    
    if (rax)
    {
        result = arg3;
        
        if (rax - 1 <= arg3)
            result = rax - 1;
        
        if (arg4)
        {
            int64_t i;
            
            do
            {
                if (!memchr(arg2, *(rbp + result), arg4))
                    break;
                
                i = result;
                result -= 1;
            } while (i >= 1);
        }
    }
    
    return result;
}

int64_t sub_140017a60(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    void* rdx_1 = *arg2;
    /* tailcall */
    return sub_140017a00(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

int64_t sub_140017a70(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t result = -1;
    char* rcx = *arg1;
    int64_t r9 = *(rcx - 0x18);
    
    if (r9)
    {
        result = arg3;
        
        if (r9 - 1 <= arg3)
            result = r9 - 1;
        
        while (rcx[result] == arg2)
        {
            int64_t result_1 = result;
            result -= 1;
            
            if (result_1 < 1)
                break;
        }
    }
    
    return result;
}

int64_t sub_140017ab0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017ae0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140017ae0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    void* rbp = *arg1;
    int64_t r12 = *(rbp - 0x18);
    int64_t result = arg3;
    
    if (arg3 >= r12)
        return -1;
    
    if (!arg4)
        return result;
    
    while (true)
    {
        if (!memchr(arg2, *(rbp + result), arg4))
            return result;
        
        result += 1;
        
        if (result == r12)
            return -1;
    }
}

int64_t sub_140017b50(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    void* rdx_1 = *arg2;
    /* tailcall */
    return sub_140017ae0(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

int64_t sub_140017b60(int64_t* arg1, char arg2, int64_t arg3)
{
    char* rax_2 = *arg1;
    int64_t rcx = *(rax_2 - 0x18);
    
    if (arg3 < rcx)
    {
        do
        {
            if (rax_2[arg3] != arg2)
                return arg3;
            
            arg3 += 1;
        } while (arg3 != rcx);
    }
    
    return -1;
}

void* sub_140017b90(int64_t* arg1, uint64_t arg2)
{
    void* rax = *arg1;
    
    if (arg2 < *(rax - 0x18))
        return rax + arg2;
    
    sub_140022090("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", arg2);
    /* no return */
}

int64_t sub_140017bc0(int64_t* arg1)
{
    int64_t rax_1 = *arg1;
    return rax_1 + *(rax_1 - 0x18);
}

uint64_t sub_140017bd0(void* arg1)
{
    return *(arg1 + 0x10) >> 0x1f;
}

int64_t sub_140017be0(void* arg1)
{
    if (data_140023080)
    {
        int32_t rax_1;
        rax_1 = *(arg1 + 0x10) > 0;
        return rax_1;
    }
    
    int32_t rax;
    rax = *(arg1 + 0x10) > 0;
    return rax;
}

void* sub_140017c10(int64_t* arg1)
{
    void* rax_1 = *arg1;
    return rax_1 + *(rax_1 - 0x18) - 1;
}

int64_t sub_140017c20(int64_t* arg1)
{
    int64_t rax_1 = *arg1;
    return rax_1 + *(rax_1 - 0x18);
}

uint64_t sub_140017c30(int64_t* arg1, char* arg2, uint64_t arg3, int64_t arg4)
{
    void* rdx = *arg1;
    int64_t rbx = *(rdx - 0x18);
    
    if (rbx < arg4)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::copy");
        /* no return */
    }
    
    uint64_t _Size = rbx - arg4;
    
    if (_Size > arg3)
        _Size = arg3;
    
    if (_Size)
    {
        void* rdx_1 = rdx + arg4;
        
        if (_Size == 1)
        {
            *arg2 = *rdx_1;
            return _Size;
        }
        
        memcpy(arg2, rdx_1, _Size);
    }
    
    return _Size;
}

int64_t sub_140017ca0(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140017cb0(int64_t* arg1, char* arg2, void* arg3)
{
    /* tailcall */
    return sub_140017ce0(arg1, arg2, arg3, strlen(arg2));
}

void* sub_140017ce0(int64_t* arg1, char* arg2, void* arg3, uint64_t arg4)
{
    void* r13 = *arg1;
    int64_t rax = *(r13 - 0x18);
    
    if (!arg4)
    {
        if (rax >= arg3)
            return arg3;
        
        return -ffffffffffffffff;
    }
    
    if (arg3 < rax)
    {
        void* rax_1 = rax - arg3;
        int32_t _Val = *arg2;
        void* _Buf = r13 + arg3;
        
        if (rax_1 >= arg4)
        {
            void* _Buf1;
            
            while (true)
            {
                if (rax_1 != -((1 - arg4)))
                {
                    _Buf1 = memchr(_Buf, _Val, rax_1 + 1 - arg4);
                    
                    if (_Buf1)
                    {
                        if (!memcmp(_Buf1, arg2, arg4))
                            break;
                        
                        _Buf = _Buf1 + 1;
                        rax_1 = r13 + rax - _Buf;
                        
                        if (rax_1 >= arg4)
                            continue;
                    }
                }
                
                return -ffffffffffffffff;
            }
            
            return _Buf1 - r13;
        }
    }
    
    return -ffffffffffffffff;
}

int64_t sub_140017db0(int64_t* arg1, int64_t* arg2, void* arg3)
{
    char* rdx_1 = *arg2;
    /* tailcall */
    return sub_140017ce0(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

void* sub_140017dc0(int64_t* arg1, char arg2, int64_t arg3)
{
    void* rsi = *arg1;
    int64_t r8 = *(rsi - 0x18);
    
    if (arg3 < r8)
    {
        int64_t rax_1 = memchr(rsi + arg3, arg2, r8 - arg3);
        
        if (rax_1)
            return rax_1 - rsi;
    }
    
    return -ffffffffffffffff;
}

int64_t* sub_140017e10(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    return arg1;
}

int64_t sub_140017e20(int64_t* arg1)
{
    return *(*arg1 - 0x18);
}

int64_t sub_140017e30(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140017e40(int64_t* arg1)
{
    return *arg1;
}

int64_t* sub_140017e50(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    return arg1;
}

void* sub_140017e60(int64_t* arg1)
{
    void* result;
    result = !*(*arg1 - 0x18);
    return result;
}

int64_t sub_140017e70(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140017e80(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140017eb0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140017eb0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t rax = -1;
    void* rcx = *arg1;
    int64_t rdx = *(rcx - 0x18);
    
    if (rdx >= arg4)
    {
        int64_t rdx_1 = rdx - arg4;
        rax = arg3;
        
        if (rdx_1 <= arg3)
            rax = rdx_1;
        
        int64_t rbx_1 = rax;
        
        if (arg4)
        {
            while (true)
            {
                if (!memcmp(rcx + rbx_1, arg2, arg4))
                    return rbx_1;
                
                if (!rbx_1)
                    break;
                
                rbx_1 -= 1;
            }
            
            return -1;
        }
    }
    
    return rax;
}

int64_t sub_140017f30(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    void* rdx_1 = *arg2;
    /* tailcall */
    return sub_140017eb0(arg1, rdx_1, arg3, *(rdx_1 - 0x18));
}

int64_t sub_140017f40(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t i = -1;
    void* rcx = *arg1;
    int64_t r9 = *(rcx - 0x18);
    
    if (r9)
    {
        i = arg3;
        
        if (r9 - 1 <= arg3)
            i = r9 - 1;
        
        do
        {
            int64_t i_1 = i;
            i -= 1;
            
            if (*(rcx + i + 1) == arg2)
                return i_1;
        } while (i != -1);
    }
    
    return i;
}

int64_t sub_140017fa0(int64_t* arg1)
{
    return *arg1 - 0x18;
}

int64_t sub_140017fb0(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140017fc0(int64_t* arg1)
{
    return *(*arg1 - 0x18);
}

int64_t* sub_140017fd0(int64_t* arg1, int64_t* arg2)
{
    int64_t rdx_1 = *arg2;
    *arg1 = rdx_1 + *(rdx_1 - 0x18);
    return arg1;
}

void** sub_140017fe0(void** arg1, int64_t* arg2, int64_t arg3, void* arg4)
{
    if (*(*arg2 - 0x18) < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::substr");
        /* no return */
    }
    
    sub_14001b2c0(arg1, arg2, arg3, arg4);
    return arg1;
}

int64_t sub_140018020(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018030(int64_t* arg1)
{
    int64_t rax_1 = *arg1;
    return rax_1 + *(rax_1 - 0x18);
}

int32_t sub_140018040(int64_t* arg1, char* arg2)
{
    void* _Buf1 = *arg1;
    uint64_t _Size_2 = *(_Buf1 - 0x18);
    uint64_t _Size_1 = strlen(arg2);
    uint64_t _Size = _Size_2;
    
    if (_Size_1 <= _Size_2)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(_Buf1, arg2, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx = _Size_2 - _Size_1;
        result = 0x7fffffff;
        
        if (rbx <= 0x7fffffff)
        {
            if (rbx < -0x80000000)
                return -0x80000000;
            
            return rbx;
        }
    }
    
    return result;
}

int32_t sub_1400180b0(int64_t* arg1, int64_t* arg2)
{
    void* _Buf1 = *arg1;
    void* _Buf2 = *arg2;
    uint64_t _Size_1 = *(_Buf1 - 0x18);
    uint64_t _Size_2 = *(_Buf2 - 0x18);
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(_Buf1, _Buf2, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx <= 0x7fffffff)
        {
            if (rbx < -0x80000000)
                return -0x80000000;
            
            return rbx;
        }
    }
    
    return result;
}

int32_t sub_140018110(int64_t* arg1, int64_t arg2, uint64_t arg3, char* arg4)
{
    void* r12 = *arg1;
    int64_t rbx = *(r12 - 0x18);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_2 = rbx - arg2;
    
    if (_Size_2 > arg3)
        _Size_2 = arg3;
    
    uint64_t _Size_1 = strlen(arg4);
    uint64_t _Size = _Size_2;
    
    if (_Size_1 <= _Size_2)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(r12 + arg2, arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_2 - _Size_1;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_1400181c0(int64_t* arg1, int64_t arg2, uint64_t arg3, int64_t arg4, uint64_t arg5)
{
    void* rcx = *arg1;
    int64_t rbx = *(rcx - 0x18);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size = arg5;
    
    if (_Size_1 <= arg5)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(rcx + arg2, arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - arg5;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_140018250(int64_t* arg1, int64_t arg2, uint64_t arg3, int64_t* arg4)
{
    void* rcx = *arg1;
    int64_t rbx = *(rcx - 0x18);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    void* _Buf2 = *arg4;
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size_2 = *(_Buf2 - 0x18);
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(rcx + arg2, _Buf2, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_1400182e0(int64_t* arg1, int64_t arg2, uint64_t arg3, int64_t* arg4, int64_t arg5, uint64_t arg6)
{
    void* rcx = *arg1;
    int64_t rbx = *(rcx - 0x18);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    void* rdx = *arg4;
    int64_t rsi = *(rdx - 0x18);
    
    if (rsi < arg5)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size_2 = rsi - arg5;
    
    if (_Size_2 > arg6)
        _Size_2 = arg6;
    
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(rcx + arg2, rdx + arg5, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int64_t* sub_1400183b0(int64_t* arg1, int64_t* arg2)
{
    int64_t rdx_1 = *arg2;
    *arg1 = rdx_1 + *(rdx_1 - 0x18);
    return arg1;
}

int64_t sub_1400183c0(int64_t* arg1, int64_t arg2, uint64_t arg3)
{
    if (*(*arg1 - 0x18) >= arg2)
        return arg2;
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", arg3);
    /* no return */
}

int64_t sub_1400183f0(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t rax_1 = *(*arg1 - 0x18) - arg2;
    
    if (rax_1 > arg3)
        return arg3;
    
    return rax_1;
}

int64_t sub_140018410(int64_t* arg1)
{
    return *(*arg1 - 0x10);
}

int64_t sub_140018420() __pure
{
    return 0x3ffffffffffffff9;
}

int64_t sub_140018430(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018440(int64_t* arg1, int64_t arg2)
{
    return *arg1 + arg2;
}

int64_t sub_140018450() __pure
{
    return "std::bad_typeid";
}

int64_t sub_140018460(int64_t arg1, int32_t* arg2)
{
    int64_t* rax = *(arg2 + 8);
    int64_t r9 = *rax;
    (*(r9 + 0x28))(arg1, rax, *arg2, r9);
    return arg1;
}

int64_t sub_140018490(void* arg1)
{
    return *(arg1 + 8);
}

int64_t sub_1400184a0() __pure
{
    return "std::bad_exception";
}

int512_t sub_1400184b0(void* arg1)
{
    int64_t rax = *(arg1 + 8);
    int512_t result;
    
    if (rax != sub_14001c0c0
        && (rax == sub_14001c060 | rax == sub_14001c0f0 || rax == sub_14001c010))
    {
        result = 0x4040000000000000;
        return result;
    }
    
    result = {0};
    return result;
}

int64_t sub_140018500() __pure
{
    return "std::bad_array_new_length";
}

void** sub_140018510(void** arg1, int64_t* arg2)
{
    char* var_38;
    (*(*arg2 + 0x20))(&var_38);
    uint64_t var_30;
    sub_14001c190(arg1, var_38, var_30);
    char* rcx_2 = var_38;
    void var_28;
    
    if (rcx_2 != &var_28)
        sub_140021540(rcx_2);
    
    return arg1;
}

void sub_140018557(void* arg1 @ rax, int64_t* arg2 @ rsi) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

int64_t* sub_140018570(int64_t* arg1, int64_t* arg2)
{
    char* var_10;
    (*(*arg2 + 0x18))(&var_10);
    char* rdx = var_10;
    sub_14001c4b0(arg1, rdx, *(rdx - 0x18));
    char* rcx_2 = var_10;
    
    if (data_140023080)
    {
        int32_t rax_4 = *(rcx_2 - 8);
        *(rcx_2 - 8) -= 1;
        
        if (rax_4 <= 0)
            sub_1400199c0(rcx_2 - 0x18);
    }
    else
    {
        int32_t rax_2 = *(rcx_2 - 8);
        *(rcx_2 - 8) = rax_2 - 1;
        
        if (rax_2 <= 0)
            sub_1400199c0(rcx_2 - 0x18);
    }
    
    return arg1;
}

void sub_1400185e5(void* arg1 @ rax, void* arg2) __noreturn
{
    sub_1400199d0(arg2 - 0x18);
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_140018610(int64_t arg1, int32_t* arg2, int32_t arg3)
{
    if (*(arg2 + 8) != arg1)
        return 0;
    
    int64_t result;
    result = *arg2 == arg3;
    return result;
}

int64_t sub_140018630(int64_t* arg1, int32_t arg2, int32_t* arg3)
{
    int64_t var_18;
    (*(*arg1 + 0x28))(&var_18, arg1, arg2, &var_18);
    int64_t var_10;
    
    if (*(arg3 + 8) != var_10)
        return 0;
    
    int64_t result;
    result = *arg3 == var_18;
    return result;
}

int32_t* sub_140018680(int32_t* arg1, int64_t arg2, int32_t arg3)
{
    *arg1 = arg3;
    *(arg1 + 8) = arg2;
    return arg1;
}

uint64_t sub_140018690(int64_t* arg1, int64_t arg2)
{
    int32_t r8 = 1;
    int64_t rax = *arg1;
    
    if (arg2 >= rax)
        r8 = rax + arg1[1] < arg2;
    
    return r8;
}

void* sub_1400186b0(int64_t* arg1)
{
    void* result;
    result = &arg1[2] == *arg1;
    return result;
}

int64_t sub_1400186c0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400186f0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_1400186f0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t rbx = arg1[1];
    
    if (!rbx || !arg4)
        return -1;
    
    int64_t result = rbx - 1;
    void* rbp = *arg1;
    
    if (result > arg3)
        result = arg3;
    
    int64_t i;
    
    do
    {
        if (memchr(arg2, *(rbp + result), arg4))
            break;
        
        i = result;
        result -= 1;
    } while (i >= 1);
    return result;
}

int64_t sub_140018770(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400186f0(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018780(int64_t* arg1, char arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018e40(arg1, arg2, arg3);
}

int64_t sub_140018790(int64_t arg1) __pure
{
    return arg1 + 0x10;
}

int64_t sub_1400187a0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400187d0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_1400187d0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t result = -1;
    
    if (arg4)
    {
        int64_t rbp_1 = arg1[1];
        
        if (arg3 < rbp_1)
        {
            void* r12_1 = *arg1;
            result = arg3;
            
            while (!memchr(arg2, *(r12_1 + result), arg4))
            {
                result += 1;
                
                if (result == rbp_1)
                    return -1;
            }
        }
    }
    
    return result;
}

int64_t sub_140018850(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400187d0(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018860(int64_t* arg1, char arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018ca0(arg1, arg2, arg3);
}

int64_t sub_140018870(int64_t arg1) __pure
{
    return arg1;
}

int64_t sub_140018880(void* arg1, int64_t arg2, int64_t arg3, char* arg4)
{
    if (arg2 + 0x3fffffffffffffff - *(arg1 + 8) >= arg3)
        return 0x3fffffffffffffff;
    
    sub_140021ff0(arg4);
    /* no return */
}

int64_t sub_1400188b0(int64_t arg1) __pure
{
    return arg1;
}

int64_t sub_1400188c0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400188f0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_1400188f0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t result = -1;
    int64_t rax = arg1[1];
    
    if (rax)
    {
        result = arg3;
        
        if (rax - 1 <= arg3)
            result = rax - 1;
        
        if (arg4)
        {
            void* rbp_1 = *arg1;
            int64_t i;
            
            do
            {
                if (!memchr(arg2, *(rbp_1 + result), arg4))
                    break;
                
                i = result;
                result -= 1;
            } while (i >= 1);
        }
    }
    
    return result;
}

int64_t sub_140018960(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400188f0(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018970(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t result = -1;
    int64_t r9 = arg1[1];
    
    if (r9)
    {
        result = arg3;
        
        if (r9 - 1 <= arg3)
            result = r9 - 1;
        
        while ((*arg1)[result] == arg2)
        {
            int64_t result_1 = result;
            result -= 1;
            
            if (result_1 < 1)
                break;
        }
    }
    
    return result;
}

int64_t sub_1400189b0(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400189e0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_1400189e0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t rbp = arg1[1];
    int64_t result = arg3;
    
    if (arg3 >= rbp)
        return -1;
    
    if (!arg4)
        return result;
    
    void* r12_1 = *arg1;
    
    while (true)
    {
        if (!memchr(arg2, *(r12_1 + result), arg4))
            return result;
        
        result += 1;
        
        if (result == rbp)
            return -1;
    }
}

int64_t sub_140018a60(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_1400189e0(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018a70(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t result = arg3;
    int64_t r8 = arg1[1];
    
    if (result < r8)
    {
        do
        {
            if ((*arg1)[result] != arg2)
                return result;
            
            result += 1;
        } while (result != r8);
    }
    
    return -1;
}

int64_t sub_140018ab0(int64_t* arg1, uint64_t arg2)
{
    if (arg2 < arg1[1])
        return *arg1 + arg2;
    
    sub_140022090("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", arg2);
    /* no return */
}

int64_t sub_140018ae0(int64_t* arg1)
{
    return *arg1 + arg1[1];
}

int64_t sub_140018af0(int64_t* arg1)
{
    return *arg1 + arg1[1] - 1;
}

int64_t sub_140018b00(int64_t* arg1)
{
    return *arg1 + arg1[1];
}

uint64_t sub_140018b10(void* arg1, char* arg2, uint64_t arg3, int64_t arg4)
{
    int64_t rbx = *(arg1 + 8);
    
    if (rbx < arg4)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::copy");
        /* no return */
    }
    
    uint64_t _Size = rbx - arg4;
    
    if (_Size > arg3)
        _Size = arg3;
    
    if (_Size)
    {
        char* rdx_1 = arg4 + *arg1;
        
        if (_Size == 1)
        {
            *arg2 = *rdx_1;
            return _Size;
        }
        
        memcpy(arg2, rdx_1, _Size);
    }
    
    return _Size;
}

int64_t sub_140018b80(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018b90(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018bc0(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140018bc0(int64_t* arg1, char* arg2, int64_t arg3, uint64_t arg4)
{
    int64_t rax = arg1[1];
    
    if (!arg4)
    {
        if (rax >= arg3)
            return arg3;
        
        return -1;
    }
    
    if (arg3 < rax)
    {
        int64_t r14_1 = *arg1;
        int32_t _Val = *arg2;
        int64_t rax_1 = rax - arg3;
        int64_t _Buf = r14_1 + arg3;
        
        if (rax_1 >= arg4)
        {
            int64_t _Buf1;
            
            while (true)
            {
                if (rax_1 != -((1 - arg4)))
                {
                    _Buf1 = memchr(_Buf, _Val, rax_1 + 1 - arg4);
                    
                    if (_Buf1)
                    {
                        if (!memcmp(_Buf1, arg2, arg4))
                            break;
                        
                        _Buf = _Buf1 + 1;
                        rax_1 = r14_1 + rax - _Buf;
                        
                        if (rax_1 >= arg4)
                            continue;
                    }
                }
                
                return -1;
            }
            
            return _Buf1 - r14_1;
        }
    }
    
    return -1;
}

int64_t sub_140018c90(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018bc0(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018ca0(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t r8 = arg1[1];
    
    if (arg3 < r8)
    {
        int64_t rsi_1 = *arg1;
        int64_t rax_1 = memchr(rsi_1 + arg3, arg2, r8 - arg3);
        
        if (rax_1)
            return rax_1 - rsi_1;
    }
    
    return -1;
}

int64_t* sub_140018cf0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    return arg1;
}

int64_t sub_140018d00(void* arg1)
{
    return *(arg1 + 8);
}

int64_t sub_140018d10(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018d20(int64_t* arg1)
{
    return *arg1;
}

int64_t* sub_140018d30(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    return arg1;
}

int64_t Concurrency::details::List<class Concurrency::details::SchedulerProxy,class Concurrency::details::CollectionTypes::Count>::Empty(void* arg1)
{
    int64_t result;
    result = !*(arg1 + 8);
    return result;
}

int64_t sub_140018d50(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018d60(int64_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018d90(arg1, arg2, arg3, strlen(arg2));
}

int64_t sub_140018d90(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4)
{
    int64_t rax = -1;
    int64_t rdx = arg1[1];
    
    if (rdx >= arg4)
    {
        int64_t rdx_1 = rdx - arg4;
        rax = arg3;
        
        if (rdx_1 <= arg3)
            rax = rdx_1;
        
        if (arg4)
        {
            int64_t rbp_1 = *arg1;
            int64_t rbx_1 = rax;
            
            while (true)
            {
                if (!memcmp(rbp_1 + rbx_1, arg2, arg4))
                    return rbx_1;
                
                if (!rbx_1)
                    break;
                
                rbx_1 -= 1;
            }
            
            return -1;
        }
    }
    
    return rax;
}

int64_t sub_140018e20(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    /* tailcall */
    return sub_140018d90(arg1, *arg2, arg3, arg2[1]);
}

int64_t sub_140018e40(int64_t* arg1, char arg2, int64_t arg3)
{
    int64_t i = -1;
    int64_t r9 = arg1[1];
    
    if (r9)
    {
        i = arg3;
        
        if (r9 - 1 <= arg3)
            i = r9 - 1;
        
        do
        {
            char rcx = (*arg1)[i];
            int64_t i_1 = i;
            i -= 1;
            
            if (rcx == arg2)
                return i_1;
        } while (i != -1);
    }
    
    return i;
}

int64_t sub_140018ec0(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_140018ed0(void* arg1)
{
    return *(arg1 + 8);
}

int64_t* sub_140018ee0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2 + arg2[1];
    return arg1;
}

int64_t* sub_140018ef0(int64_t* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    int64_t r10 = arg2[1];
    
    if (r10 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::substr");
        /* no return */
    }
    
    int64_t r10_1 = r10 - arg3;
    *arg1 = &arg1[2];
    char* rax_2 = *arg2 + arg3;
    
    if (r10_1 > arg4)
        r10_1 = arg4;
    
    sub_14001e240(arg1, rax_2, &rax_2[r10_1]);
    return arg1;
}

int64_t sub_140018f50(int64_t* arg1)
{
    return *arg1;
}

int32_t sub_140018f60(int64_t* arg1, char* arg2)
{
    uint64_t _Size_2 = arg1[1];
    uint64_t _Size_1 = strlen(arg2);
    uint64_t _Size = _Size_2;
    
    if (_Size_1 <= _Size_2)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(*arg1, arg2, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx = _Size_2 - _Size_1;
        result = 0x7fffffff;
        
        if (rbx <= 0x7fffffff)
        {
            if (rbx < -0x80000000)
                return -0x80000000;
            
            return rbx;
        }
    }
    
    return result;
}

int32_t sub_140018fd0(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size_1 = arg1[1];
    uint64_t _Size_2 = arg2[1];
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(*arg1, *arg2, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx <= 0x7fffffff)
        {
            if (rbx < -0x80000000)
                return -0x80000000;
            
            return rbx;
        }
    }
    
    return result;
}

int32_t sub_140019030(void* arg1, int64_t arg2, uint64_t arg3, char* arg4)
{
    int64_t rbx = *(arg1 + 8);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_2 = rbx - arg2;
    
    if (_Size_2 > arg3)
        _Size_2 = arg3;
    
    uint64_t _Size_1 = strlen(arg4);
    uint64_t _Size = _Size_2;
    
    if (_Size_1 <= _Size_2)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(arg2 + *arg1, arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_2 - _Size_1;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_1400190e0(void* arg1, int64_t arg2, uint64_t arg3, int64_t arg4, uint64_t arg5)
{
    int64_t rbx = *(arg1 + 8);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size = arg5;
    
    if (_Size_1 <= arg5)
        _Size = _Size_1;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(arg2 + *arg1, arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - arg5;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_140019170(int64_t* arg1, int64_t arg2, uint64_t arg3, int64_t* arg4)
{
    int64_t rbx = arg1[1];
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    uint64_t _Size_2 = arg4[1];
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(*arg1 + arg2, *arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int32_t sub_140019200(void* arg1, int64_t arg2, uint64_t arg3, void* arg4, int64_t arg5, uint64_t arg6)
{
    int64_t rbx = *(arg1 + 8);
    
    if (rbx < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    int64_t rsi = *(arg4 + 8);
    
    if (rsi < arg5)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::compare");
        /* no return */
    }
    
    uint64_t _Size_1 = rbx - arg2;
    
    if (_Size_1 > arg3)
        _Size_1 = arg3;
    
    uint64_t _Size_2 = rsi - arg5;
    
    if (_Size_2 > arg6)
        _Size_2 = arg6;
    
    uint64_t _Size = _Size_1;
    
    if (_Size_2 <= _Size_1)
        _Size = _Size_2;
    
    int32_t result;
    
    if (_Size)
        result = memcmp(arg2 + *arg1, arg5 + *arg4, _Size);
    
    if (!_Size || !result)
    {
        uint64_t rbx_1 = _Size_1 - _Size_2;
        result = 0x7fffffff;
        
        if (rbx_1 <= 0x7fffffff)
        {
            if (rbx_1 < -0x80000000)
                return -0x80000000;
            
            return rbx_1;
        }
    }
    
    return result;
}

int64_t* sub_1400192d0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2 + arg2[1];
    return arg1;
}

int64_t sub_1400192e0(void* arg1, int64_t arg2, uint64_t arg3)
{
    if (*(arg1 + 8) >= arg2)
        return arg2;
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", arg3);
    /* no return */
}

int64_t sub_140019310(void* arg1, int64_t arg2, int64_t arg3)
{
    int64_t rax = *(arg1 + 8) - arg2;
    
    if (rax > arg3)
        return arg3;
    
    return rax;
}

int64_t sub_140019320(int64_t* arg1)
{
    if (*arg1 == &arg1[2])
        return 0xf;
    
    return arg1[2];
}

int64_t sub_140019340() __pure
{
    return 0x3fffffffffffffff;
}

int64_t sub_140019350(int64_t* arg1, int64_t arg2)
{
    return *arg1 + arg2;
}

int64_t sub_140019360() __pure
{
    return "std::bad_cast";
}

int64_t sub_140019370() __pure
{
    return "std::bad_alloc";
}

int64_t sub_140019380() __pure
{
    return "std::exception";
}

int32_t sub_140019390(void* arg1, void* arg2)
{
    int32_t result = 1;
    
    if (arg1 != arg2)
    {
        char* _Str1 = *(arg1 + 8);
        result = 0;
        
        if (*_Str1 != 0x2a)
        {
            char* rdx = *(arg2 + 8);
            int64_t rax;
            rax = *rdx == 0x2a;
            result = !strcmp(_Str1, &rdx[rax]);
        }
    }
    
    return result;
}

int64_t sub_1400193d0() __pure
{
    return 0;
}

int64_t sub_1400193e0() __pure
{
    return 0;
}

int32_t sub_1400193f0(void* arg1, void* arg2)
{
    int32_t result = 1;
    
    if (arg2 != arg1)
    {
        char* _Str1 = *(arg1 + 8);
        result = 0;
        
        if (*_Str1 != 0x2a)
        {
            char* rdx = *(arg2 + 8);
            int64_t rax;
            rax = *rdx == 0x2a;
            result = !strcmp(_Str1, &rdx[rax]);
        }
    }
    
    return result;
}

uint64_t sub_140019430(int64_t arg1, int64_t arg2) __pure
{
    int64_t rcx = arg1 - arg2;
    
    if (rcx > 0x7fffffff)
        return 0x7fffffff;
    
    if (rcx < -0x80000000)
        return 0x80000000;
    
    return rcx;
}

int64_t sub_140019460(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

int64_t sub_140019470(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

void* sub_140019480(int64_t* arg1)
{
    void* result = *arg1;
    
    if (!*(result - 0x18))
        return result;
    
    if (!data_140023080)
    {
        if (*(result - 8) > 0)
            goto label_1400194cd;
        
        *(result - 8) = 0xffffffff;
    }
    else if (*(result - 8) > 0)
    {
    label_1400194cd:
        sub_14001ae60(arg1, 0, 0, 0);
        result = *arg1;
        *(result - 8) = 0xffffffff;
    }
    else
    {
        result = *arg1;
        *(result - 8) = 0xffffffff;
    }
    
    return result;
}

void* sub_140019500(uint64_t arg1, char arg2)
{
    uint64_t* rax = sub_140019b40(arg1, 0);
    void* result = &rax[3];
    
    if (arg1)
    {
        if (arg1 == 1)
            rax[3] = arg2;
        else
            result = memset(result, arg2, arg1);
    }
    
    rax[2] = 0;
    *rax = arg1;
    *(rax + arg1 + 0x18) = 0;
    return result;
}

void* sub_140019560(char* arg1, int64_t arg2)
{
    uint64_t _Size = arg2 - arg1;
    uint64_t* rax = sub_140019b40(_Size, 0);
    void* result = &rax[3];
    
    if (_Size == 1)
        rax[3] = *arg1;
    else if (_Size)
        result = memcpy(result, arg1, _Size);
    
    rax[2] = 0;
    *rax = _Size;
    *(rax + _Size + 0x18) = 0;
    return result;
}

void* sub_1400195d0(char* arg1, int64_t arg2)
{
    void* result;
    void* _Size;
    void* result_1;
    int64_t* rsi;
    
    if (!arg1)
    {
        if (arg2)
        {
            sub_140021f00("basic_string::_S_construct null not valid");
            /* no return */
        }
        
        _Size = nullptr;
        int64_t* rax_3 = sub_140019b40(0, 0);
        result = &rax_3[3];
        rsi = rax_3;
        result_1 = result;
    }
    else
    {
        _Size = arg2 - arg1;
        int64_t* rax = sub_140019b40(_Size, 0);
        rsi = rax;
        result = &rax[3];
        
        if (_Size != 1)
        {
            result_1 = rax + _Size + 0x18;
            
            if (_Size)
                result = memcpy(result, arg1, _Size);
        }
        else
        {
            result_1 = rsi + 0x19;
            rsi[3] = *arg1;
        }
    }
    
    rsi[2] = 0;
    *rsi = _Size;
    *result_1 = 0;
    return result;
}

void* sub_140019670(char* arg1, int64_t arg2)
{
    void* result;
    void* _Size;
    void* result_1;
    int64_t* rsi;
    
    if (!arg1)
    {
        if (arg2)
        {
            sub_140021f00("basic_string::_S_construct null not valid");
            /* no return */
        }
        
        _Size = nullptr;
        int64_t* rax_3 = sub_140019b40(0, 0);
        result = &rax_3[3];
        rsi = rax_3;
        result_1 = result;
    }
    else
    {
        _Size = arg2 - arg1;
        int64_t* rax = sub_140019b40(_Size, 0);
        rsi = rax;
        result = &rax[3];
        
        if (_Size != 1)
        {
            result_1 = rax + _Size + 0x18;
            
            if (_Size)
                result = memcpy(result, arg1, _Size);
        }
        else
        {
            result_1 = rsi + 0x19;
            rsi[3] = *arg1;
        }
    }
    
    rsi[2] = 0;
    *rsi = _Size;
    *result_1 = 0;
    return result;
}

void* sub_140019710(char* arg1, int64_t arg2)
{
    void* result;
    void* _Size;
    void* result_1;
    int64_t* rsi;
    
    if (!arg1)
    {
        if (arg2)
        {
            sub_140021f00("basic_string::_S_construct null not valid");
            /* no return */
        }
        
        _Size = nullptr;
        int64_t* rax_3 = sub_140019b40(0, 0);
        result = &rax_3[3];
        rsi = rax_3;
        result_1 = result;
    }
    else
    {
        _Size = arg2 - arg1;
        int64_t* rax = sub_140019b40(_Size, 0);
        rsi = rax;
        result = &rax[3];
        
        if (_Size != 1)
        {
            result_1 = rax + _Size + 0x18;
            
            if (_Size)
                result = memcpy(result, arg1, _Size);
        }
        else
        {
            result_1 = rsi + 0x19;
            rsi[3] = *arg1;
        }
    }
    
    rsi[2] = 0;
    *rsi = _Size;
    *result_1 = 0;
    return result;
}

int64_t sub_1400197b0() __pure
{
    return &data_140023200;
}

void sub_1400197c0(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_1400197e0(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_140019800(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_140019820(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

int64_t x7b7936fb::_Delete_this::operator[]::_ExceptionPtr_normal::_Delete_this(int64_t* arg1)
{
    return sub_14001ac60(arg1);
}

int64_t* sub_140019850(int64_t* arg1, uint64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    if (0x3ffffffffffffff9 + arg3 - *(*arg1 - 0x18) < arg4)
    {
        sub_140021ff0("basic_string::_M_replace_aux");
        /* no return */
    }
    
    sub_14001ae60(arg1, arg2, arg3, arg4);
    
    if (arg4)
    {
        char* rdi_1 = arg2 + *arg1;
        
        if (arg4 == 1)
        {
            *rdi_1 = arg5;
            return arg1;
        }
        
        memset(rdi_1, arg5, arg4);
    }
    
    return arg1;
}

int64_t* sub_1400198d0(int64_t* arg1, uint64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    sub_14001ae60(arg1, arg2, arg3, arg5);
    
    if (arg5)
    {
        char* rsi_1 = arg2 + *arg1;
        
        if (arg5 == 1)
        {
            *rsi_1 = *arg4;
            return arg1;
        }
        
        memcpy(rsi_1, arg4, arg5);
    }
    
    return arg1;
}

int64_t sub_140019940(uint64_t arg1, char arg2)
{
    /* tailcall */
    return sub_140019500(arg1, arg2);
}

void* sub_140019950(int64_t* arg1, uint64_t arg2)
{
    void* rax = *arg1;
    
    if (arg2 >= *(rax - 0x18))
    {
        sub_140022090("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", arg2);
        /* no return */
    }
    
    if (*(rax - 8) >= 0)
    {
        sub_140019480(arg1);
        rax = *arg1;
    }
    
    return rax + arg2;
}

void* sub_140019990(int64_t* arg1)
{
    void* rax = *arg1;
    
    if (*(rax - 8) >= 0)
    {
        sub_140019480(arg1);
        rax = *arg1;
    }
    
    return rax + *(rax - 0x18);
}

void sub_1400199c0(void* _Block)
{
    /* tailcall */
    return sub_140021540(_Block);
}

int64_t sub_1400199d0(void* arg1)
{
    int32_t result;
    
    if (data_140023080)
    {
        result = *(arg1 + 0x10);
        *(arg1 + 0x10) -= 1;
        
        if (result <= 0)
            /* tailcall */
            return sub_1400199c0(arg1);
    }
    else
    {
        result = *(arg1 + 0x10);
        *(arg1 + 0x10) = result - 1;
        
        if (result <= 0)
            /* tailcall */
            return sub_1400199c0(arg1);
    }
    
    return result;
}

void* sub_140019a10(void* arg1)
{
    if (data_140023080)
    {
        *(arg1 + 0x10) += 1;
        return arg1 + 0x18;
    }
    
    *(arg1 + 0x10) += 1;
    return arg1 + 0x18;
}

int64_t sub_140019a40(int64_t arg1) __pure
{
    return arg1 + 0x18;
}

int64_t sub_140019a50() __pure
{
    return &data_140023200;
}

int64_t pdb_internal::EnumMap<int32_t,int32_t,class pdb_internal::HashClass<unsigned long,0>,void,class CriticalSectionNop>::reset(void* arg1)
{
    *(arg1 + 0x10) = 0xffffffff;
}

int64_t Dbg1::Reset(void* arg1)
{
    *(arg1 + 0x10) = 0;
}

int64_t sub_140019a80(int64_t* arg1, int64_t arg2)
{
    arg1[2] = 0;
    *arg1 = arg2;
    *(arg1 + arg2 + 0x18) = 0;
}

void* sub_140019a90(int64_t* arg1, int64_t arg2)
{
    if (arg1[2] < 0)
        /* tailcall */
        return sub_140019ad0(arg1, arg2, 0);
    
    if (data_140023080)
    {
        arg1[2] += 1;
        return &arg1[3];
    }
    
    arg1[2] += 1;
    return &arg1[3];
}

void* sub_140019ad0(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t* rax = sub_140019b40(*arg1 + arg3, arg1[1]);
    uint64_t _Size = *arg1;
    void* result = &rax[3];
    
    if (_Size)
    {
        if (_Size == 1)
        {
            rax[3] = arg1[3];
            _Size = *arg1;
        }
        else
        {
            void* result_1 = memcpy(result, &arg1[3], _Size);
            _Size = *arg1;
            result = result_1;
        }
    }
    
    rax[2] = 0;
    *rax = _Size;
    *(rax + _Size + 0x18) = 0;
    return result;
}

void* sub_140019b40(int64_t arg1, int64_t arg2)
{
    int64_t rbx = arg1;
    
    if (0x3ffffffffffffff9 < arg1)
    {
        sub_140021ff0("basic_string::_S_create");
        /* no return */
    }
    
    if (arg2 < arg1)
    {
        int64_t rax_1 = arg2 * 2;
        
        if (arg1 < rax_1)
            rbx = rax_1;
        
        if (rbx + 0x39 > 0x1000 && arg2 < rbx)
        {
            rbx = rbx + 0x1000 - ((rbx + 0x39) & 0xfff);
            
            if (rbx > 0x3ffffffffffffff9)
                rbx = 0x3ffffffffffffff9;
        }
    }
    
    void* result = sub_140021560(rbx + 0x19);
    *(result + 8) = rbx;
    *(result + 0x10) = 0;
    return result;
}

void* sub_140019bc0(int64_t* arg1)
{
    void* rax = *arg1;
    int64_t rsi = *(rax - 0x18) - 1;
    
    if (*(rax - 8) >= 0)
    {
        sub_140019480(arg1);
        rax = *arg1;
    }
    
    return rax + rsi;
}

void** sub_140019bf0(void** arg1, int64_t* arg2)
{
    void* rax = *arg2;
    
    if (*(rax - 8) >= 0)
    {
        sub_140019480(arg2);
        rax = *arg2;
    }
    
    *arg1 = rax;
    return arg1;
}

void* sub_140019c20(int64_t* arg1, void** arg2)
{
    void* result = *arg1;
    
    if (*(result - 8) < 0)
        *(result - 8) = 0;
    
    void* r8_1 = *arg2;
    
    if (*(r8_1 - 8) < 0)
        *(r8_1 - 8) = 0;
    
    *arg1 = r8_1;
    *arg2 = result;
    return result;
}

void* sub_140019c50(int64_t* arg1)
{
    void* result = *arg1;
    
    if (*(result - 8) < 0)
        return result;
    
    sub_140019480(arg1);
    return *arg1;
}

int64_t sub_140019c70(int64_t* arg1)
{
    /* tailcall */
    return sub_14001ae60(arg1, 0, *(*arg1 - 0x18), 0);
}

void* sub_140019c90(int64_t* arg1, int64_t arg2)
{
    uint64_t rsi_1 = arg2 - *arg1;
    sub_14001ae60(arg1, rsi_1, 1, 0);
    void* rax = *arg1;
    *(rax - 8) = 0xffffffff;
    return rax + rsi_1;
}

void* sub_140019cd0(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    if (arg3 == arg2)
        return arg2;
    
    uint64_t rax_1 = arg2 - *arg1;
    sub_14001ae60(arg1, rax_1, arg3 - arg2, 0);
    void* rax_2 = *arg1;
    *(rax_2 - 8) = 0xffffffff;
    return rax_2 + rax_1;
}

int64_t* sub_140019d20(int64_t* arg1, uint64_t arg2, int64_t arg3)
{
    int64_t r9 = *(*arg1 - 0x18);
    int64_t rax_2 = r9 - arg2;
    
    if (rax_2 <= arg3)
        arg3 = rax_2;
    
    if (r9 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::erase");
        /* no return */
    }
    
    sub_14001ae60(arg1, arg2, arg3, 0);
    return arg1;
}

void* sub_140019d70(int64_t* arg1)
{
    void* result = *arg1;
    
    if (*(result - 8) < 0)
        return result;
    
    sub_140019480(arg1);
    return *arg1;
}

int64_t sub_140019d90(int64_t* arg1, void* arg2)
{
    /* tailcall */
    return sub_140019dc0(arg1, arg2, strlen(arg2));
}

void** sub_140019dc0(int64_t* arg1, void* arg2, uint64_t arg3)
{
    void** result = arg1;
    void* rdi = arg2;
    
    if (arg3)
    {
        void* rcx = *arg1;
        int64_t rax_1 = *(rcx - 0x18);
        
        if (0x3ffffffffffffff9 - rax_1 < arg3)
        {
            sub_140021ff0("basic_string::append");
            /* no return */
        }
        
        int64_t rbp_1 = arg3 + rax_1;
        
        if (*(rcx - 0x10) >= rbp_1)
        {
            if (data_140023080)
            {
                int32_t rax_8 = *(rcx - 8);
                rcx = *result;
                
                if (rax_8 <= 0)
                    goto label_140019e88;
            }
            else if (*(rcx - 8) <= 0)
                goto label_140019e20;
        }
        
        void* rcx_2;
        
        if (rdi < rcx || *(rcx - 0x18) + rcx < rdi)
        {
            sub_14001ad40(result, rbp_1);
            rcx = *result;
            rax_1 = *(rcx - 0x18);
        label_140019e20:
            rcx_2 = rcx + rax_1;
            
            if (arg3 == 1)
                *rcx_2 = *rdi;
            else
                memcpy(rcx_2, rdi, arg3);
        }
        else
        {
            void* rdi_1 = rdi - rcx;
            sub_14001ad40(result, rbp_1);
            rcx = *result;
            rdi = rdi_1 + rcx;
        label_140019e88:
            rcx_2 = rcx + *(rcx - 0x18);
            
            if (arg3 != 1)
                memcpy(rcx_2, rdi, arg3);
            else
                *rcx_2 = *rdi;
        }
        char* rax_4 = *result;
        *(rax_4 - 8) = 0;
        *(rax_4 - 0x18) = rbp_1;
        rax_4[rbp_1] = 0;
    }
    
    return result;
}

void** sub_140019ec0(int64_t* arg1, int64_t* arg2)
{
    char* rdx = *arg2;
    void** result = arg1;
    uint64_t _Size = *(rdx - 0x18);
    
    if (_Size)
    {
        void* rcx = *arg1;
        int64_t rax_1 = *(rcx - 0x18);
        int64_t rbp_1 = rax_1 + _Size;
        
        if (*(rcx - 0x10) < rbp_1)
        {
        label_140019ef1:
            sub_14001ad40(result, rbp_1);
            rcx = *result;
            rdx = *arg2;
            rax_1 = *(rcx - 0x18);
        }
        else if (data_140023080)
        {
            if (*(rcx - 8) > 0)
                goto label_140019ef1;
            
            rcx = *result;
            rdx = *arg2;
            rax_1 = *(rcx - 0x18);
        }
        else if (*(rcx - 8) > 0)
            goto label_140019ef1;
        
        void* rcx_2 = rcx + rax_1;
        
        if (_Size == 1)
            *rcx_2 = *rdx;
        else
            memcpy(rcx_2, rdx, _Size);
        
        char* rax_2 = *result;
        *(rax_2 - 8) = 0;
        *(rax_2 - 0x18) = rbp_1;
        rax_2[rbp_1] = 0;
    }
    
    return result;
}

void** sub_140019f70(int64_t* arg1, int64_t* arg2, int64_t arg3, uint64_t arg4)
{
    void* rdx = *arg2;
    void** result = arg1;
    int64_t rbx = *(rdx - 0x18);
    
    if (rbx < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::append");
        /* no return */
    }
    
    uint64_t _Size = rbx - arg3;
    
    if (_Size > arg4)
        _Size = arg4;
    
    if (_Size)
    {
        void* rcx = *arg1;
        int64_t rax_1 = *(rcx - 0x18);
        int64_t r12_1 = rax_1 + _Size;
        
        if (*(rcx - 0x10) < r12_1)
        {
        label_140019fb9:
            sub_14001ad40(result, r12_1);
            rcx = *result;
            rdx = *arg2;
            rax_1 = *(rcx - 0x18);
        }
        else if (data_140023080)
        {
            if (*(rcx - 8) > 0)
                goto label_140019fb9;
            
            rcx = *result;
            rdx = *arg2;
            rax_1 = *(rcx - 0x18);
        }
        else if (*(rcx - 8) > 0)
            goto label_140019fb9;
        
        void* rdx_2 = rdx + arg3;
        void* rcx_2 = rcx + rax_1;
        
        if (_Size == 1)
            *rcx_2 = *rdx_2;
        else
            memcpy(rcx_2, rdx_2, _Size);
        
        char* rax_2 = *result;
        *(rax_2 - 8) = 0;
        *(rax_2 - 0x18) = r12_1;
        rax_2[r12_1] = 0;
    }
    
    return result;
}

int64_t sub_14001a060(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_140019dc0(arg1, *arg2, arg2[1]);
}

void** sub_14001a070(int64_t* arg1, uint64_t arg2, char arg3)
{
    void** result = arg1;
    
    if (arg2)
    {
        void* rcx = *arg1;
        int64_t rax_1 = *(rcx - 0x18);
        
        if (0x3ffffffffffffff9 - rax_1 < arg2)
        {
            sub_140021ff0("basic_string::append");
            /* no return */
        }
        
        int64_t rbp_1 = arg2 + rax_1;
        
        if (*(rcx - 0x10) < rbp_1)
        {
        label_14001a0b3:
            sub_14001ad40(result, rbp_1);
            rcx = *result;
            rax_1 = *(rcx - 0x18);
        }
        else if (data_140023080)
        {
            if (*(rcx - 8) > 0)
                goto label_14001a0b3;
            
            rcx = *result;
            rax_1 = *(rcx - 0x18);
        }
        else if (*(rcx - 8) > 0)
            goto label_14001a0b3;
        
        void* rcx_2 = rcx + rax_1;
        
        if (arg2 == 1)
            *rcx_2 = arg3;
        else
            memset(rcx_2, arg3, arg2);
        
        char* rax_2 = *result;
        *(rax_2 - 8) = 0;
        *(rax_2 - 0x18) = rbp_1;
        rax_2[rbp_1] = 0;
    }
    
    return result;
}

int64_t* sub_14001a140(int64_t* arg1, void** arg2)
{
    sub_140019c20(arg1, arg2);
    return arg1;
}

int64_t sub_14001a160(int64_t* arg1, char* arg2)
{
    /* tailcall */
    return sub_14001a190(arg1, arg2, strlen(arg2));
}

int64_t* sub_14001a190(int64_t* arg1, char* arg2, uint64_t arg3)
{
    char* rcx = *arg1;
    int64_t r8 = *(rcx - 0x18);
    
    if (0x3ffffffffffffff9 < arg3)
    {
        sub_140021ff0("basic_string::assign");
        /* no return */
    }
    
    if (arg2 >= rcx && &rcx[r8] >= arg2)
    {
        if (data_140023080)
        {
            int32_t rax_4 = *(rcx - 8);
            rcx = *arg1;
            
            if (rax_4 <= 0)
            {
            label_14001a20d:
                int64_t rax_6 = arg2 - rcx;
                
                if (rax_6 >= arg3)
                {
                    if (arg3 == 1)
                    {
                        *rcx = *arg2;
                        rcx = *arg1;
                    }
                    else if (arg3)
                    {
                        memcpy(rcx, arg2, arg3);
                        rcx = *arg1;
                    }
                }
                else if (rax_6)
                {
                    if (arg3 == 1)
                    {
                        *rcx = *arg2;
                        rcx = *arg1;
                    }
                    else
                    {
                        memmove(rcx, arg2, arg3);
                        rcx = *arg1;
                    }
                }
                
                *(rcx - 8) = 0;
                *(rcx - 0x18) = arg3;
                rcx[arg3] = 0;
                return arg1;
            }
            
            r8 = *(rcx - 0x18);
        }
        else if (*(rcx - 8) <= 0)
            goto label_14001a20d;
    }
    
    return sub_1400198d0(arg1, 0, r8, arg2, arg3);
}

void** sub_14001a290(int64_t* arg1, int64_t* arg2)
{
    void* rsi = *arg2;
    void** result = arg1;
    
    if (*arg1 != rsi)
    {
        void* rcx_2;
        
        if (*(rsi - 8) >= 0)
        {
            if (data_140023080)
                *(rsi - 8) += 1;
            else
                *(rsi - 8) += 1;
            
            rcx_2 = *result;
            
            if (data_140023080)
                goto label_14001a30d;
            
            goto label_14001a2ca;
        }
        
        void var_19;
        void* rax_5 = sub_140019ad0(rsi - 0x18, &var_19, 0);
        rcx_2 = *result;
        rsi = rax_5;
        
        if (!data_140023080)
        {
        label_14001a2ca:
            int32_t rax_3 = *(rcx_2 - 8);
            *(rcx_2 - 8) = rax_3 - 1;
            
            if (rax_3 <= 0)
                sub_1400199c0(rcx_2 - 0x18);
        }
        else
        {
        label_14001a30d:
            int32_t rax_7 = *(rcx_2 - 8);
            *(rcx_2 - 8) -= 1;
            
            if (rax_7 <= 0)
                sub_1400199c0(rcx_2 - 0x18);
        }
        
        *result = rsi;
    }
    
    return result;
}

int64_t sub_14001a340(int64_t* arg1, int64_t* arg2, int64_t arg3, uint64_t arg4)
{
    void* rdx = *arg2;
    int64_t r10 = *(rdx - 0x18);
    uint64_t r8_1 = r10 - arg3;
    
    if (r8_1 > arg4)
        r8_1 = arg4;
    
    if (r10 >= arg3)
        /* tailcall */
        return sub_14001a190(arg1, rdx + arg3, r8_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::assign");
    /* no return */
}

int64_t sub_14001a390(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_14001a190(arg1, *arg2, arg2[1]);
}

int64_t* sub_14001a3a0(int64_t* arg1, uint64_t arg2, char arg3)
{
    return sub_140019850(arg1, 0, *(*arg1 - 0x18), arg2, arg3);
}

int64_t sub_14001a3d0(int64_t* arg1, int64_t arg2, int64_t* arg3)
{
    /* tailcall */
    return sub_14001a480(arg1, arg2 - *arg1, *arg3, arg3[1]);
}

void* sub_14001a3e0(int64_t* arg1, int64_t arg2, char arg3)
{
    uint64_t rsi_1 = arg2 - *arg1;
    sub_140019850(arg1, rsi_1, 0, 1, arg3);
    void* rax = *arg1;
    *(rax - 8) = 0xffffffff;
    return rax + rsi_1;
}

int64_t* sub_14001a420(int64_t* arg1, int64_t arg2, uint64_t arg3, char arg4)
{
    return sub_140019850(arg1, arg2 - *arg1, 0, arg3, arg4);
}

int64_t sub_14001a450(int64_t* arg1, uint64_t arg2, char* arg3)
{
    /* tailcall */
    return sub_14001a480(arg1, arg2, arg3, strlen(arg3));
}

int64_t* sub_14001a480(int64_t* arg1, uint64_t arg2, char* arg3, uint64_t arg4)
{
    void* rdx = *arg1;
    void* r9 = *(rdx - 0x18);
    
    if (r9 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::insert");
        /* no return */
    }
    
    if (0x3ffffffffffffff9 - r9 < arg4)
    {
        sub_140021ff0("basic_string::insert");
        /* no return */
    }
    
    if (arg3 >= rdx && r9 + rdx >= arg3)
    {
        if (data_140023080)
        {
            if (*(rdx - 8) <= 0)
            {
            label_14001a526:
                void* rsi_2 = arg3 - *arg1;
                sub_14001ae60(arg1, arg2, 0, arg4);
                void* rcx_3 = *arg1;
                void* rdx_3 = rcx_3 + rsi_2;
                void* rcx_4 = rcx_3 + arg2;
                char* rax_4 = rdx_3 + arg4;
                
                if (rcx_4 >= rax_4)
                {
                    if (arg4 == 1)
                        *rcx_4 = *rdx_3;
                    else if (arg4)
                        memcpy(rcx_4, rdx_3, arg4);
                }
                else if (rdx_3 < rcx_4)
                {
                    void* _Size_1 = arg2 - rsi_2;
                    
                    if (_Size_1 == 1)
                        *rcx_4 = *rdx_3;
                    else
                        rcx_4 = memcpy(rcx_4, rdx_3, _Size_1);
                    
                    rdx_3 = rcx_4 + arg4;
                    rcx_4 += _Size_1;
                    uint64_t _Size = arg4 - arg2 + rsi_2;
                    
                    if (_Size == 1)
                        *rcx_4 = *rdx_3;
                    else if (_Size)
                        memcpy(rcx_4, rdx_3, _Size);
                }
                else if (arg4 == 1)
                    *rcx_4 = *rax_4;
                else if (arg4)
                    memcpy(rcx_4, rax_4, arg4);
                
                return arg1;
            }
        }
        else if (*(rdx - 8) <= 0)
            goto label_14001a526;
    }
    
    return sub_1400198d0(arg1, arg2, 0, arg3, arg4);
}

int64_t sub_14001a600(int64_t* arg1, uint64_t arg2, int64_t* arg3)
{
    char* r8_1 = *arg3;
    /* tailcall */
    return sub_14001a480(arg1, arg2, r8_1, *(r8_1 - 0x18));
}

int64_t sub_14001a610(int64_t* arg1, uint64_t arg2, int64_t* arg3, int64_t arg4, uint64_t arg5)
{
    void* r10 = *arg3;
    int64_t r8 = *(r10 - 0x18);
    uint64_t r9_1 = r8 - arg4;
    
    if (r9_1 > arg5)
        r9_1 = arg5;
    
    if (r8 >= arg4)
        /* tailcall */
        return sub_14001a480(arg1, arg2, r10 + arg4, r9_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::insert");
    /* no return */
}

int64_t* sub_14001a660(int64_t* arg1, uint64_t arg2, uint64_t arg3, char arg4)
{
    if (*(*arg1 - 0x18) >= arg2)
        return sub_140019850(arg1, arg2, 0, arg3, arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::insert");
    /* no return */
}

void** sub_14001a6b0(void** arg1, int64_t* arg2)
{
    void* r8 = *arg2;
    
    if (*(r8 - 8) >= 0)
    {
        sub_140019480(arg2);
        r8 = *arg2;
    }
    
    *arg1 = r8 + *(r8 - 0x18);
    return arg1;
}

int64_t sub_14001a6f0(int64_t* arg1, uint64_t arg2)
{
    /* tailcall */
    return sub_14001a700(arg1, arg2, 0);
}

int64_t sub_14001a700(int64_t* arg1, uint64_t arg2, char arg3)
{
    int64_t result = *(*arg1 - 0x18);
    
    if (0x3ffffffffffffff9 < arg2)
    {
        sub_140021ff0("basic_string::resize");
        /* no return */
    }
    
    if (result < arg2)
        /* tailcall */
        return sub_14001a070(arg1, arg2 - result, arg3);
    
    if (arg2 < result)
        /* tailcall */
        return sub_14001ae60(arg1, arg2, result - arg2, 0);
    
    return result;
}

void sub_14001a770(char* arg1, char* arg2, uint64_t arg3)
{
    if (arg3 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (arg3)
        /* tailcall */
        return memcpy(arg1, arg2, arg3);
}

int64_t sub_14001a790(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
    return arg2;
}

int64_t sub_14001a7a0(int64_t* arg1)
{
    int32_t result = *(*arg1 - 8);
    
    if (result >= 0)
        /* tailcall */
        return sub_140019480(arg1);
    
    return result;
}

void sub_14001a7c0(char* arg1, char* arg2, uint64_t arg3)
{
    if (arg3 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (arg3)
        /* tailcall */
        return memmove(arg1, arg2, arg3);
}

int64_t sub_14001a7e0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    /* tailcall */
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5 - arg4);
}

int64_t* sub_14001a800(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4)
{
    uint64_t rax = strlen(arg4);
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4, rax);
}

int64_t sub_14001a850(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    /* tailcall */
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5 - arg4);
}

int64_t sub_14001a870(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4)
{
    /* tailcall */
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4);
}

int64_t* sub_14001a890(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    char* r9 = *arg4;
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, r9, *(r9 - 0x18));
}

int64_t sub_14001a8c0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    /* tailcall */
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5 - arg4);
}

int64_t sub_14001a8e0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    /* tailcall */
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5 - arg4);
}

int64_t* sub_14001a900(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    return sub_14001a990(arg1, arg2 - *arg1, arg3 - arg2, *arg4, arg4[1]);
}

int64_t sub_14001a930(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    arg5 = arg5;
    /* tailcall */
    return sub_140019850(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5);
}

int64_t* sub_14001a950(int64_t* arg1, uint64_t arg2, void* arg3, char* arg4)
{
    return sub_14001a990(arg1, arg2, arg3, arg4, strlen(arg4));
}

int64_t* sub_14001a990(int64_t* arg1, uint64_t arg2, void* arg3, char* arg4, uint64_t arg5)
{
    void* rax = *arg1;
    void* r9 = *(rax - 0x18);
    
    if (r9 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::replace");
        /* no return */
    }
    
    void* rsi_1 = r9 - arg2;
    
    if (rsi_1 > arg3)
        rsi_1 = arg3;
    
    if (0x3ffffffffffffff9 - r9 + rsi_1 < arg5)
    {
        sub_140021ff0("basic_string::replace");
        /* no return */
    }
    
    if (arg4 >= rax && r9 + rax >= arg4)
    {
        if (data_140023080)
        {
            if (*(rax - 8) <= 0)
            {
                rax = *arg1;
            label_14001aa4a:
                void* r10_1 = &arg4[arg5];
                void* r12_1;
                
                if (rax + arg2 >= r10_1)
                    r12_1 = arg4 - rax;
                else
                {
                    if (arg4 < arg2 + rsi_1 + rax)
                    {
                        char* rax_4 = sub_1400195d0(arg4, r10_1);
                        int64_t* rax_3 = sub_1400198d0(arg1, arg2, rsi_1, rax_4, arg5);
                        int32_t rdx_13;
                        
                        if (data_140023080)
                        {
                            rdx_13 = *(rax_4 - 8);
                            *(rax_4 - 8) -= 1;
                        }
                        else
                        {
                            rdx_13 = *(rax_4 - 8);
                            *(rax_4 - 8) = rdx_13 - 1;
                        }
                        
                        if (rdx_13 > 0)
                            return rax_3;
                        
                        sub_1400199c0(&rax_4[-0x18]);
                        return rax_3;
                    }
                    
                    r12_1 = arg5 - rsi_1 + arg4 - rax;
                }
                
                sub_14001ae60(arg1, arg2, rsi_1, arg5);
                void* rcx_7 = *arg1;
                void* rdx_9 = rcx_7 + r12_1;
                void* rcx_8 = rcx_7 + arg2;
                
                if (arg5 == 1)
                    *rcx_8 = *rdx_9;
                else if (arg5)
                    memcpy(rcx_8, rdx_9, arg5);
                
                return arg1;
            }
        }
        else if (*(rax - 8) <= 0)
            goto label_14001aa4a;
    }
    
    /* tailcall */
    return sub_1400198d0(arg1, arg2, rsi_1, arg4, arg5);
}

void sub_14001ab4d(void* arg1 @ rax, void* arg2 @ r14) __noreturn
{
    sub_1400199d0(arg2 - 0x18);
    sub_14000f620(arg1);
    /* no return */
}

int64_t* sub_14001ab90(int64_t* arg1, uint64_t arg2, void* arg3, int64_t* arg4)
{
    char* r9 = *arg4;
    return sub_14001a990(arg1, arg2, arg3, r9, *(r9 - 0x18));
}

int64_t sub_14001abb0(int64_t* arg1, uint64_t arg2, void* arg3, int64_t* arg4, uint64_t arg5, uint64_t arg6)
{
    void* r11 = *arg4;
    int64_t r9 = *(r11 - 0x18);
    uint64_t rax_1 = r9 - arg5;
    
    if (rax_1 > arg6)
        rax_1 = arg6;
    
    if (r9 >= arg5)
        /* tailcall */
        return sub_14001a990(arg1, arg2, arg3, r11 + arg5, rax_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001ac10(int64_t* arg1, uint64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    int64_t r10 = *(*arg1 - 0x18);
    int64_t rax_2 = r10 - arg2;
    
    if (rax_2 <= arg3)
        arg3 = rax_2;
    
    if (r10 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::replace");
        /* no return */
    }
    
    arg5 = arg5;
    /* tailcall */
    return sub_140019850(arg1, arg2, arg3, arg4, arg5);
}

int64_t sub_14001ac60(int64_t* arg1)
{
    void** rbx = arg1;
    void* rcx = *arg1;
    
    if (*(rcx - 0x18) < *(rcx - 0x10))
        goto label_14001ac9c;
    
    int32_t result = 0x40023080;
    
    if (data_140023080)
    {
        result = *(rcx - 8);
        
        if (result > 0)
        {
            rcx = *rbx;
        label_14001ac9c:
            void var_19;
            void* rax_1 = sub_140019ad0(rcx - 0x18, &var_19, 0);
            void* rcx_2 = *rbx;
            
            if (data_140023080)
            {
                result = *(rcx_2 - 8);
                *(rcx_2 - 8) -= 1;
                
                if (result <= 0)
                    result = sub_1400199c0(rcx_2 - 0x18);
            }
            else
            {
                result = *(rcx_2 - 8);
                *(rcx_2 - 8) = result - 1;
                
                if (result <= 0)
                    result = sub_1400199c0(rcx_2 - 0x18);
            }
            
            *rbx = rax_1;
        }
    }
    else if (*(rcx - 8) > 0)
        goto label_14001ac9c;
    
    return result;
}

int64_t sub_14001acfc(int64_t arg1, int64_t arg2, void* arg3 @ rax, int64_t arg4, int64_t arg5, int64_t arg6)
{
    if (arg2 != 1)
    {
        sub_1400216b0(arg3);
        /* tailcall */
        return sub_140021850();
    }
    
    sub_1400216b0(arg3);
    sub_1400219e0();
    /* no return */
}

void sub_14001ad21(void* arg1 @ rax) __noreturn
{
    sub_140021850();
    sub_14000f620(arg1);
    /* no return */
}

uint64_t sub_14001ad40(int64_t* arg1, int64_t arg2)
{
    uint64_t result = *arg1;
    int64_t r8 = arg2;
    int64_t rdx = *(result - 0x10);
    
    if (rdx < r8)
        goto label_14001ad90;
    
    if (data_140023080)
    {
        result = *(result - 8);
        
        if (result > 0)
        {
            result = *arg1;
            r8 = rdx;
        label_14001ad90:
            void var_29;
            void* rax = sub_140019ad0(result - 0x18, &var_29, r8 - *(result - 0x18));
            void* rcx_2 = *arg1;
            
            if (data_140023080)
            {
                result = *(rcx_2 - 8);
                *(rcx_2 - 8) -= 1;
                
                if (result <= 0)
                    result = sub_1400199c0(rcx_2 - 0x18);
            }
            else
            {
                result = *(rcx_2 - 8);
                *(rcx_2 - 8) = result - 1;
                
                if (result <= 0)
                    result = sub_1400199c0(rcx_2 - 0x18);
            }
            
            *arg1 = rax;
        }
    }
    else if (*(result - 8) > 0)
    {
        r8 = rdx;
        goto label_14001ad90;
    }
    
    return result;
}

int64_t sub_14001adf0(int64_t* arg1)
{
    int64_t rax_1 = *(*arg1 - 0x18);
    
    if (rax_1 >= rax_1 - 1)
        /* tailcall */
        return sub_14001ae60(arg1, rax_1 - 1, 1, 0);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::erase");
    /* no return */
}

void sub_14001ae30(char* arg1, uint64_t arg2, char arg3)
{
    if (arg2 == 1)
    {
        *arg1 = arg3;
        return;
    }
    
    if (arg2)
        /* tailcall */
        return memset(arg1, arg3, arg2);
}

void sub_14001ae60(int64_t* arg1, uint64_t arg2, int64_t arg3, int64_t arg4)
{
    void* rbx = *arg1;
    int64_t r12 = *(rbx - 0x18);
    int64_t r15 = arg3 + arg2;
    int64_t rdx = *(rbx - 0x10);
    int64_t rsi_2 = arg4 - arg3 + r12;
    uint64_t _Size = r12 - r15;
    
    if (rdx < rsi_2)
        goto label_14001aec2;
    
    if (!data_140023080)
    {
        if (*(rbx - 8) <= 0)
            goto label_14001af9a;
        
        goto label_14001aec2;
    }
    
    uint32_t rax = *(rbx - 8);
    rbx = *arg1;
    
    if (rax > 0)
    {
        rdx = *(rbx - 0x10);
    label_14001aec2:
        void var_49;
        void* var_68_1 = &var_49;
        void* rax_1 = sub_140019b40(rsi_2, rdx);
        void* r9_1 = rax_1;
        rbx = rax_1 + 0x18;
        
        if (arg2)
        {
            char* rdx_1 = *arg1;
            
            if (arg2 == 1)
            {
                *(r9_1 + 0x18) = *rdx_1;
                
                if (!_Size)
                    goto label_14001af02;
                
                goto label_14001af45;
            }
            
            memcpy(rbx, rdx_1, arg2);
            r9_1 = rax_1;
        }
        
        if (!_Size)
            goto label_14001af02;
        
    label_14001af45:
        char* r15_1 = r15 + *arg1;
        void* rcx_4 = r9_1 + arg2 + arg4 + 0x18;
        void* rcx_3;
        
        if (_Size != 1)
        {
            memcpy(rcx_4, r15_1, _Size);
            rcx_3 = *arg1;
            
            if (!data_140023080)
                goto label_14001af09;
            
            goto label_14001af70;
        }
        
        *rcx_4 = *r15_1;
    label_14001af02:
        rcx_3 = *arg1;
        
        if (data_140023080)
        {
        label_14001af70:
            rax = *(rcx_3 - 8);
            *(rcx_3 - 8) -= 1;
            
            if (rax <= 0)
                sub_1400199c0(rcx_3 - 0x18);
        }
        else
        {
        label_14001af09:
            rax = *(rcx_3 - 8);
            *(rcx_3 - 8) = rax - 1;
            
            if (rax <= 0)
                sub_1400199c0(rcx_3 - 0x18);
        }
        
        *arg1 = rbx;
    }
    else
    {
    label_14001af9a:
        
        if (_Size && arg4 != arg3)
        {
            void* rdx_5 = rbx + r15;
            void* rcx_6 = rbx + arg4 + arg2;
            
            if (_Size == 1)
            {
                *rcx_6 = *rdx_5;
                rbx = *arg1;
            }
            else
            {
                memmove(rcx_6, rdx_5, _Size);
                rbx = *arg1;
            }
        }
    }
    
    *(rbx - 8) = 0;
    *(rbx - 0x18) = rsi_2;
    *(rbx + rsi_2) = 0;
}

char* sub_14001b010(int64_t* arg1, char arg2)
{
    char* rax = *arg1;
    int64_t rdx = *(rax - 0x18);
    int64_t rsi = rdx + 1;
    
    if (*(rax - 0x10) < rsi)
    {
    label_14001b049:
        sub_14001ad40(arg1, rsi);
        rax = *arg1;
        rdx = *(rax - 0x18);
    }
    else if (data_140023080)
    {
        if (*(rax - 8) > 0)
            goto label_14001b049;
        
        rax = *arg1;
        rdx = *(rax - 0x18);
    }
    else if (*(rax - 8) > 0)
        goto label_14001b049;
    
    rax[rdx] = arg2;
    char* result = *arg1;
    *(result - 8) = 0;
    *(result - 0x18) = rsi;
    result[rsi] = 0;
    return result;
}

void* sub_14001b090(int64_t* arg1, int64_t* arg2)
{
    void* result = *arg2;
    int32_t r8 = data_140023080;
    *arg1 = result;
    
    if (r8)
    {
        int32_t r8_1 = *(result - 8);
        result = *arg1;
        
        if (r8_1 > 0)
        {
            if (data_140023080)
            {
                *(result - 8) += 1;
                return result;
            }
            
            *(result - 8) += 1;
            return result;
        }
    }
    else
    {
        int32_t rdx = *(result - 8);
        
        if (rdx > 0)
        {
            *(result - 8) = rdx + 1;
            return result;
        }
    }
    
    *(result - 8) = 1;
    return result;
}

void* sub_14001b0e0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    void* result = sub_140019500(0, 0);
    *arg2 = result;
    return result;
}

void* sub_14001b100(void** arg1, char* arg2)
{
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    void* result = sub_1400195d0(arg2, rdx);
    *arg1 = result;
    return result;
}

void* sub_14001b150(void** arg1, char* arg2, void* arg3)
{
    void* result = sub_1400195d0(arg2, arg3 + arg2);
    *arg1 = result;
    return result;
}

void* sub_14001b180(void** arg1)
{
    void* result = sub_140019500(0, 0);
    *arg1 = result;
    return result;
}

void* sub_14001b1a0(void** arg1, int64_t* arg2)
{
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        *arg1 = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        *arg1 = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    *arg1 = rax;
    return rax;
}

void* sub_14001b200(void** arg1, int64_t* arg2, int64_t arg3)
{
    void* rax_1 = *arg2;
    
    if (*(rax_1 - 8) < 0)
    {
        void* rax_2 = sub_140019ad0(rax_1 - 0x18, arg3, 0);
        *arg1 = rax_2;
        return rax_2;
    }
    
    if (data_140023080)
    {
        *(rax_1 - 8) += 1;
        *arg1 = rax_1;
        return rax_1;
    }
    
    *(rax_1 - 8) += 1;
    *arg1 = rax_1;
    return rax_1;
}

void* sub_14001b270(void** arg1, int64_t* arg2, int64_t arg3)
{
    void* rcx = *arg2;
    int64_t r9_1 = *(rcx - 0x18);
    
    if (r9_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rcx + r9_1);
    *arg1 = result;
    return result;
}

void* sub_14001b2c0(void** arg1, int64_t* arg2, int64_t arg3, void* arg4)
{
    void* rcx = *arg2;
    int64_t rax = *(rcx - 0x18);
    void* rdx_1 = rax - arg3;
    
    if (rdx_1 > arg4)
        rdx_1 = arg4;
    
    if (rax < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rdx_1 + arg3 + rcx);
    *arg1 = result;
    return result;
}

void* sub_14001b320(void** arg1, int64_t* arg2, int64_t arg3, void* arg4, int64_t arg5)
{
    void* rcx = *arg2;
    int64_t rax = *(rcx - 0x18);
    void* rdx_1 = rax - arg3;
    
    if (rdx_1 > arg4)
        rdx_1 = arg4;
    
    if (rax < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rdx_1 + arg3 + rcx);
    *arg1 = result;
    return result;
}

void* sub_14001b380(void** arg1, int64_t* arg2)
{
    char* rcx = *arg2;
    void* result = sub_1400195d0(rcx, &rcx[arg2[1]]);
    *arg1 = result;
    return result;
}

void* sub_14001b3b0(void** arg1)
{
    void* result = sub_140019500(0, 0);
    *arg1 = result;
    return result;
}

void* sub_14001b3d0(void** arg1, uint64_t arg2, char arg3)
{
    void* result = sub_140019500(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b400(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_140019560(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b430(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_1400195d0(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b460(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_140019710(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b490(int64_t* arg1, int64_t* arg2)
{
    void* result = *arg2;
    int32_t r8 = data_140023080;
    *arg1 = result;
    
    if (r8)
    {
        int32_t r8_1 = *(result - 8);
        result = *arg1;
        
        if (r8_1 > 0)
        {
            if (data_140023080)
            {
                *(result - 8) += 1;
                return result;
            }
            
            *(result - 8) += 1;
            return result;
        }
    }
    else
    {
        int32_t rdx = *(result - 8);
        
        if (rdx > 0)
        {
            *(result - 8) = rdx + 1;
            return result;
        }
    }
    
    *(result - 8) = 1;
    return result;
}

void* sub_14001b4e0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    void* result = sub_140019500(0, 0);
    *arg2 = result;
    return result;
}

void* sub_14001b500(void** arg1, char* arg2)
{
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    void* result = sub_1400195d0(arg2, rdx);
    *arg1 = result;
    return result;
}

void* sub_14001b550(void** arg1, char* arg2, void* arg3)
{
    void* result = sub_1400195d0(arg2, arg3 + arg2);
    *arg1 = result;
    return result;
}

void* sub_14001b580(void** arg1)
{
    void* result = sub_140019500(0, 0);
    *arg1 = result;
    return result;
}

void* sub_14001b5a0(void** arg1, int64_t* arg2)
{
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        *arg1 = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        *arg1 = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    *arg1 = rax;
    return rax;
}

void* sub_14001b600(void** arg1, int64_t* arg2, int64_t arg3)
{
    void* rax_1 = *arg2;
    
    if (*(rax_1 - 8) < 0)
    {
        void* rax_2 = sub_140019ad0(rax_1 - 0x18, arg3, 0);
        *arg1 = rax_2;
        return rax_2;
    }
    
    if (data_140023080)
    {
        *(rax_1 - 8) += 1;
        *arg1 = rax_1;
        return rax_1;
    }
    
    *(rax_1 - 8) += 1;
    *arg1 = rax_1;
    return rax_1;
}

void* sub_14001b670(void** arg1, int64_t* arg2, int64_t arg3)
{
    void* rcx = *arg2;
    int64_t r9_1 = *(rcx - 0x18);
    
    if (r9_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rcx + r9_1);
    *arg1 = result;
    return result;
}

void* sub_14001b6c0(void** arg1, int64_t* arg2, int64_t arg3, void* arg4)
{
    void* rcx = *arg2;
    int64_t rax = *(rcx - 0x18);
    void* rdx_1 = rax - arg3;
    
    if (rdx_1 > arg4)
        rdx_1 = arg4;
    
    if (rax < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rdx_1 + arg3 + rcx);
    *arg1 = result;
    return result;
}

void* sub_14001b720(void** arg1, int64_t* arg2, int64_t arg3, void* arg4, int64_t arg5)
{
    void* rcx = *arg2;
    int64_t rax = *(rcx - 0x18);
    void* rdx_1 = rax - arg3;
    
    if (rdx_1 > arg4)
        rdx_1 = arg4;
    
    if (rax < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    void* result = sub_140019710(rcx + arg3, rdx_1 + arg3 + rcx);
    *arg1 = result;
    return result;
}

void* sub_14001b780(void** arg1, int64_t* arg2)
{
    char* rcx = *arg2;
    void* result = sub_1400195d0(rcx, &rcx[arg2[1]]);
    *arg1 = result;
    return result;
}

void* sub_14001b7b0(void** arg1)
{
    void* result = sub_140019500(0, 0);
    *arg1 = result;
    return result;
}

void* sub_14001b7d0(void** arg1, uint64_t arg2, char arg3)
{
    void* result = sub_140019500(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b800(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_140019560(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b830(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_1400195d0(arg2, arg3);
    *arg1 = result;
    return result;
}

void* sub_14001b860(void** arg1, char* arg2, int64_t arg3)
{
    void* result = sub_140019710(arg2, arg3);
    *arg1 = result;
    return result;
}

int64_t sub_14001b890(int64_t* arg1)
{
    void* rcx = *arg1;
    int32_t result;
    
    if (data_140023080)
    {
        result = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    else
    {
        result = *(rcx - 8);
        *(rcx - 8) = result - 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    
    return result;
}

int64_t sub_14001b8f0(int64_t* arg1)
{
    void* rcx = *arg1;
    int32_t result;
    
    if (data_140023080)
    {
        result = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    else
    {
        result = *(rcx - 8);
        *(rcx - 8) = result - 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    
    return result;
}

int64_t* sub_14001b950(int64_t* arg1, void** arg2)
{
    sub_140019c20(arg1, arg2);
    return arg1;
}

int64_t sub_14001b970(int64_t* arg1, char* arg2)
{
    /* tailcall */
    return sub_14001a190(arg1, arg2, strlen(arg2));
}

void** j_sub_14001a290(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_14001a290(arg1, arg2);
}

int64_t* sub_14001b9b0(int64_t* arg1, int64_t* arg2)
{
    sub_14001a190(arg1, *arg2, arg2[1]);
    return arg1;
}

int64_t* sub_14001b9d0(int64_t* arg1, char arg2)
{
    sub_140019850(arg1, 0, *(*arg1 - 0x18), 1, arg2);
    return arg1;
}

void* sub_14001ba00(int64_t* arg1, int64_t arg2)
{
    void* rax = *arg1;
    
    if (*(rax - 8) >= 0)
    {
        sub_140019480(arg1);
        rax = *arg1;
    }
    
    return rax + arg2;
}

int64_t sub_14001ba30(int64_t* arg1, void* arg2)
{
    /* tailcall */
    return sub_140019dc0(arg1, arg2, strlen(arg2));
}

void** j_sub_140019ec0(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_140019ec0(arg1, arg2);
}

int64_t sub_14001ba70(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_140019dc0(arg1, *arg2, arg2[1]);
}

int64_t* sub_14001ba80(int64_t* arg1, char arg2)
{
    char* rax = *arg1;
    int64_t rdx = *(rax - 0x18);
    int64_t rsi = rdx + 1;
    
    if (*(rax - 0x10) < rsi)
    {
    label_14001bab9:
        sub_14001ad40(arg1, rsi);
        rax = *arg1;
        rdx = *(rax - 0x18);
    }
    else if (data_140023080)
    {
        if (*(rax - 8) > 0)
            goto label_14001bab9;
        
        rax = *arg1;
        rdx = *(rax - 0x18);
    }
    else if (*(rax - 8) > 0)
        goto label_14001bab9;
    
    rax[rdx] = arg2;
    char* rax_1 = *arg1;
    *(rax_1 - 8) = 0;
    *(rax_1 - 0x18) = rsi;
    rax_1[rsi] = 0;
    return arg1;
}

int64_t sub_14001bb00(struct std::exception::std::bad_typeid::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_typeid{for `std::exception'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_14001bb30(struct std::exception::std::bad_typeid::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_typeid{for `std::exception'};
    /* tailcall */
    return sub_140021080();
}

void* sub_14001bb40(struct std::exception::std::logic_error::VTable** arg1, void* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* result = *(arg2 + 8);
    arg1[1] = result;
    
    if (data_140023080)
    {
        int32_t r8_1 = *(result - 8);
        result = arg1[1];
        
        if (r8_1 > 0)
        {
            if (data_140023080)
            {
                *(result - 8) += 1;
                return result;
            }
            
            *(result - 8) += 1;
            return result;
        }
    }
    else
    {
        int32_t rdx = *(result - 8);
        
        if (rdx > 0)
        {
            *(result - 8) = rdx + 1;
            return result;
        }
    }
    
    *(result - 8) = 1;
    return result;
}

void* sub_14001bba0(struct std::exception::std::logic_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    void* result = sub_140019670(arg2, rdx);
    arg1[1] = result;
    return result;
}

void sub_14001bbea(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

uint64_t* sub_14001bc00(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    return sub_14001c190(&arg1[1], *arg2, r8);
}

void sub_14001bc32(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

void* sub_14001bc50(struct std::exception::std::logic_error::VTable** arg1, void* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *(arg2 + 8);
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        arg1[1] = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        arg1[1] = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    arg1[1] = rax;
    return rax;
}

void* sub_14001bcc0(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_19;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_19, 0);
        arg1[1] = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        arg1[1] = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    arg1[1] = rax;
    return rax;
}

void sub_14001bd30(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001bd50(struct std::exception::std::logic_error::VTable** arg1)
{
    sub_14001bd70(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001bd70(struct std::exception::std::logic_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

void* sub_14001bde0(void* arg1, void* arg2)
{
    sub_140019c20(arg1 + 8, arg2 + 8);
    return arg1;
}

void* sub_14001be00(void* arg1, void* arg2)
{
    sub_14001a290(arg1 + 8, arg2 + 8);
    return arg1;
}

int64_t sub_14001be20(struct std::exception::std::runtime_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::range_error{for `std::runtime_error'};
    return &_vtable_for_std::range_error{for `std::runtime_error'};
}

void sub_14001be78(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001be90(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::range_error{for `std::runtime_error'};
    return &_vtable_for_std::range_error{for `std::runtime_error'};
}

void sub_14001becf(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001bef0(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::range_error{for `std::runtime_error'};
    return &_vtable_for_std::range_error{for `std::runtime_error'};
}

void sub_14001bf57(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001bf70(struct std::runtime_error::std::range_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::range_error{for `std::runtime_error'};
    sub_14001d760(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001bfa0(struct std::exception::std::runtime_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

uint64_t sub_14001c010()
{
    bool cond:0 = &__return_addr < 0x38;
    int32_t i_1 = 0x64;
    int32_t i;
    
    do
    {
        uint64_t rflags_1;
        int32_t temp0_1;
        temp0_1 = _rdrand16_step();
        int32_t rax_1 = temp0_1;
        int32_t var_c_1 = rax_1;
        
        if (cond:0)
            rax_1 = 1;
        
        if (rax_1)
            return var_c_1;
        
        i = i_1;
        i_1 -= 1;
        cond:0 = i < 1;
    } while (i != 1);
    sub_140022130("random_device: rdrand failed");
    /* no return */
}

uint64_t sub_14001c060(int64_t arg1)
{
    bool cond:1 = &__return_addr < 0x38;
    uint64_t rflags;
    int32_t temp0;
    temp0 = _rdseed16_step();
    int32_t var_c = temp0;
    
    if (&__return_addr >= 0x38)
    {
        int32_t r8_1 = 0x63;
        
        while (true)
        {
            uint64_t rflags_1;
            int32_t temp0_1;
            temp0_1 = _rdseed16_step();
            var_c = temp0_1;
            
            if (cond:1)
                break;
            
            int32_t temp1_1 = r8_1;
            r8_1 -= 1;
            cond:1 = temp1_1 < 1;
            
            if (temp1_1 == 1)
            {
                if (arg1)
                    return arg1(0);
                
                sub_140022130("random_device: rdseed failed");
                /* no return */
            }
        }
    }
    
    return var_c;
}

uint64_t sub_14001c0c0()
{
    int32_t var_c;
    
    if (!data_140023110(&var_c))
        return var_c;
    
    sub_140022130("random_device: rand_s failed");
    /* no return */
}

uint64_t sub_14001c0f0()
{
    bool cond:1 = &__return_addr < 0x38;
    uint64_t rflags;
    int32_t temp0;
    temp0 = _rdseed16_step();
    int32_t var_c = temp0;
    
    if (&__return_addr >= 0x38)
    {
        int32_t rcx_1 = 0x63;
        
        while (true)
        {
            uint64_t rflags_1;
            int32_t temp0_1;
            temp0_1 = _rdseed16_step();
            var_c = temp0_1;
            
            if (cond:1)
                break;
            
            int32_t temp1_1 = rcx_1;
            rcx_1 -= 1;
            cond:1 = temp1_1 < 1;
            
            if (temp1_1 == 1)
                return sub_14001c010();
        }
    }
    
    return var_c;
}

void* sub_14001c140(int64_t* arg1, int64_t* arg2)
{
    void* result = *arg2;
    int32_t r8 = data_140023080;
    *arg1 = result;
    
    if (r8)
    {
        int32_t r8_1 = *(result - 8);
        result = *arg1;
        
        if (r8_1 > 0)
        {
            if (data_140023080)
            {
                *(result - 8) += 1;
                return result;
            }
            
            *(result - 8) += 1;
            return result;
        }
    }
    else
    {
        int32_t rdx = *(result - 8);
        
        if (rdx > 0)
        {
            *(result - 8) = rdx + 1;
            return result;
        }
    }
    
    *(result - 8) = 1;
    return result;
}

uint64_t* sub_14001c190(void** arg1, char* arg2, uint64_t arg3)
{
    if (arg2 != -(arg3) && !arg2)
    {
        sub_140021f00("basic_string::_S_construct null not valid");
        /* no return */
    }
    
    uint64_t* result = sub_140019b40(arg3, 0);
    uint64_t* result_2 = result;
    void* result_1 = &result[3];
    
    if (arg3 == 1)
    {
        result = *arg2;
        result_2[3] = result;
    }
    else if (arg3)
    {
        result = memcpy(result_1, arg2, arg3);
        result_1 = result;
    }
    
    result_2[2] = 0;
    *result_2 = arg3;
    *(result_2 + arg3 + 0x18) = 0;
    *arg1 = result_1;
    return result;
}

int64_t sub_14001c220(void** arg1, int64_t* arg2)
{
    /* tailcall */
    return sub_14001c190(arg1, *arg2, arg2[1]);
}

void* sub_14001c230(void** arg1, int64_t* arg2)
{
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        *arg1 = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        *arg1 = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    *arg1 = rax;
    return rax;
}

void* sub_14001c290(void** arg1, int64_t* arg2)
{
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        *arg1 = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        *arg1 = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    *arg1 = rax;
    return rax;
}

void* sub_14001c2f0(void** arg1)
{
    void* result = sub_140019500(0, 0);
    *arg1 = result;
    return result;
}

int64_t sub_14001c310(int64_t* arg1)
{
    void* rcx = *arg1;
    int32_t result;
    
    if (data_140023080)
    {
        result = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    else
    {
        result = *(rcx - 8);
        *(rcx - 8) = result - 1;
        
        if (result <= 0)
            return sub_1400199c0(rcx - 0x18);
    }
    
    return result;
}

int64_t* sub_14001c370(int64_t* arg1, void** arg2)
{
    sub_140019c20(arg1, arg2);
    return arg1;
}

int64_t* sub_14001c390(int64_t* arg1, int64_t* arg2)
{
    sub_14001a290(arg1, arg2);
    return arg1;
}

int64_t* sub_14001c3b0(int64_t* arg1, int64_t* arg2)
{
    *arg1 = &arg1[2];
    int64_t rdx = *arg2;
    int64_t rdx_2;
    
    if (rdx == &arg2[2])
    {
        rdx_2 = arg2[1];
        
        if (rdx_2 + 1 >= 8)
        {
            arg1[2] = arg2[2];
            uint64_t rdx_6 = rdx_2 + 1;
            *(&arg1[2] + rdx_6 - 8) = *(&arg2[2] + rdx_6 - 8);
            void* rdx_8 = &arg1[3] & 0xfffffffffffffff8;
            void* rcx_1 = &arg1[2] - rdx_8;
            int32_t r10_4 = (rdx_2 + 1 + rcx_1) & 0xfffffff8;
            
            if (r10_4 >= 8)
            {
                int32_t i = 0;
                
                do
                {
                    uint64_t i_1 = i;
                    i += 8;
                    *(rdx_8 + i_1) = *(&arg2[2] - rcx_1 + i_1);
                } while (i < (r10_4 & 0xfffffff8));
            }
            
            rdx_2 = arg2[1];
        }
        else if ((rdx_2 + 1) & 4)
        {
            uint64_t r10_6 = rdx_2 + 1;
            arg1[2] = arg2[2];
            *(&arg1[2] + r10_6 - 4) = *(&arg2[2] + r10_6 - 4);
            rdx_2 = arg2[1];
        }
        else if (rdx_2 != 0xffffffff)
        {
            arg1[2] = arg2[2];
            
            if (!((rdx_2 + 1) & 2))
                rdx_2 = arg2[1];
            else
            {
                uint64_t r10_2 = rdx_2 + 1;
                *(&arg1[2] + r10_2 - 2) = *(&arg2[2] + r10_2 - 2);
                rdx_2 = arg2[1];
            }
        }
    }
    else
    {
        *arg1 = rdx;
        arg1[2] = arg2[2];
        rdx_2 = arg2[1];
    }
    
    arg1[1] = rdx_2;
    *arg2 = &arg2[2];
    arg2[1] = 0;
    arg2[2] = 0;
    return arg2;
}

void sub_14001c4b0(int64_t* arg1, char* arg2, uint64_t arg3)
{
    char* rcx = &arg1[2];
    *arg1 = rcx;
    
    if (!arg2 && arg3)
    {
        sub_140021f00("basic_string: construction from null is not valid");
        /* no return */
    }
    
    uint64_t var_20 = arg3;
    
    if (arg3 > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &var_20, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = var_20;
    }
    else
    {
        if (arg3 == 1)
        {
            char rax_1 = *arg2;
            arg1[1] = arg3;
            arg1[2] = rax_1;
            rcx[arg3] = 0;
            return;
        }
        
        if (!arg3)
        {
            arg1[1] = arg3;
            rcx[arg3] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, arg3);
    uint64_t rbx_1 = var_20;
    char* rcx_2 = *arg1;
    arg1[1] = rbx_1;
    rcx_2[rbx_1] = 0;
}

void sub_14001c570(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size = arg2[1];
    char* rcx = &arg1[2];
    uint64_t _Size_1 = _Size;
    *arg1 = rcx;
    char* rdi = *arg2;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        if (_Size == 1)
        {
            char rax_1 = *rdi;
            arg1[1] = _Size;
            arg1[2] = rax_1;
            rcx[_Size] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, rdi, _Size);
    uint64_t _Size_2 = _Size_1;
    char* rcx_2 = *arg1;
    arg1[1] = _Size_2;
    rcx_2[_Size_2] = 0;
}

void sub_14001c610(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size = arg2[1];
    char* rcx = &arg1[2];
    uint64_t _Size_1 = _Size;
    *arg1 = rcx;
    char* rdi = *arg2;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        if (_Size == 1)
        {
            char rax_1 = *rdi;
            arg1[1] = _Size;
            arg1[2] = rax_1;
            rcx[_Size] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, rdi, _Size);
    uint64_t _Size_2 = _Size_1;
    char* rcx_2 = *arg1;
    arg1[1] = _Size_2;
    rcx_2[_Size_2] = 0;
}

int64_t sub_14001c6b0(int64_t* arg1, int64_t* arg2)
{
    char* rdx_1 = *arg2;
    /* tailcall */
    return sub_14001c4b0(arg1, rdx_1, *(rdx_1 - 0x18));
}

void* sub_14001c6c0(int64_t* arg1)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    return &arg1[2];
}

int64_t sub_14001c6e0(int64_t* arg1)
{
    int64_t result = *arg1;
    
    if (result == &arg1[2])
        return result;
    
    /* tailcall */
    return sub_140021540(result);
}

int64_t* sub_14001c700(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size = arg2[1];
    void* rcx = *arg1;
    void* rdx = *arg2;
    
    if (rcx != &arg1[2])
    {
        if (&arg2[2] == rdx)
            goto label_14001c780;
        
        *arg1 = rdx;
        int64_t r9_1 = arg1[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        
        if (!rcx)
        {
            rcx = &arg2[2];
            *arg2 = rcx;
        }
        else
        {
            *arg2 = rcx;
            arg2[2] = r9_1;
        }
    }
    else if (&arg2[2] == rdx)
    {
    label_14001c780:
        
        if (arg2 == arg1)
            rcx = rdx;
        else
        {
            if (_Size)
            {
                if (_Size == 1)
                {
                    *rcx = *rdx;
                    _Size = arg2[1];
                    rcx = *arg1;
                }
                else
                {
                    memcpy(rcx, rdx, _Size);
                    _Size = arg2[1];
                    rcx = *arg1;
                }
            }
            
            arg1[1] = _Size;
            *(rcx + _Size) = 0;
            rcx = *arg2;
        }
    }
    else
    {
        *arg1 = rdx;
        rcx = &arg2[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        *arg2 = rcx;
    }
    
    arg2[1] = 0;
    *rcx = 0;
    return arg1;
}

int64_t* sub_14001c7e0(int64_t* arg1, int64_t* arg2)
{
    sub_140020030(arg1, arg2);
    return arg1;
}

int64_t sub_14001c800(struct std::exception::std::logic_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::domain_error{for `std::logic_error'};
    return &_vtable_for_std::domain_error{for `std::logic_error'};
}

void sub_14001c858(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001c870(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::domain_error{for `std::logic_error'};
    return &_vtable_for_std::domain_error{for `std::logic_error'};
}

void sub_14001c8af(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001c8d0(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::domain_error{for `std::logic_error'};
    return &_vtable_for_std::domain_error{for `std::logic_error'};
}

void sub_14001c937(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001c950(struct std::logic_error::std::domain_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::domain_error{for `std::logic_error'};
    sub_14001bd70(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001c980(struct std::exception::std::logic_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001c9f0(struct std::exception::std::logic_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::length_error{for `std::logic_error'};
    return &_vtable_for_std::length_error{for `std::logic_error'};
}

void sub_14001ca48(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001ca60(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::length_error{for `std::logic_error'};
    return &_vtable_for_std::length_error{for `std::logic_error'};
}

void sub_14001ca9f(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001cac0(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::length_error{for `std::logic_error'};
    return &_vtable_for_std::length_error{for `std::logic_error'};
}

void sub_14001cb27(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001cb40(struct std::logic_error::std::length_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::length_error{for `std::logic_error'};
    sub_14001bd70(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001cb70(struct std::exception::std::logic_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001cbe0(struct std::exception::std::logic_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::out_of_range{for `std::logic_error'};
    return &_vtable_for_std::out_of_range{for `std::logic_error'};
}

void sub_14001cc38(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001cc50(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::out_of_range{for `std::logic_error'};
    return &_vtable_for_std::out_of_range{for `std::logic_error'};
}

void sub_14001cc8f(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001ccb0(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::out_of_range{for `std::logic_error'};
    return &_vtable_for_std::out_of_range{for `std::logic_error'};
}

void sub_14001cd17(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001cd30(struct std::logic_error::std::out_of_range::VTable** arg1)
{
    *arg1 = &_vtable_for_std::out_of_range{for `std::logic_error'};
    sub_14001bd70(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001cd60(struct std::exception::std::logic_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001cdd0(struct std::runtime_error::std::system_error::VTable** arg1, int64_t* arg2, char* arg3)
{
    int64_t* rdi = arg2[1];
    int64_t rbp = *arg2;
    int64_t var_68;
    (*(*rdi + 0x20))(&var_68, rdi, rbp);
    int64_t* rax_1 = sub_14001de90(&var_68, 0, 0, ": ", 2);
    int64_t var_78;
    int64_t* var_88 = &var_78;
    int64_t* rdx_1 = *rax_1;
    
    if (rdx_1 == &rax_1[2])
    {
        char* r10_1 = &var_78;
        void* r8_1 = &rax_1[2];
        int32_t rdx_9 = rax_1[1] + 1;
        
        if (rdx_9 >= 8)
        {
            uint64_t r8_4 = 0;
            
            do
            {
                uint64_t r9_7 = r8_4;
                r8_4 = r8_4 + 8;
                *(&var_78 + r9_7) = *(&rax_1[2] + r9_7);
            } while (r8_4 < (rdx_9 & 0xfffffff8));
            
            r10_1 = &var_78 + r8_4;
            r8_1 = r8_4 + &rax_1[2];
        }
        
        int64_t r9_3 = 0;
        
        if (rdx_9 & 4)
        {
            *r10_1 = *r8_1;
            r9_3 = 4;
        }
        
        if (rdx_9 & 2)
        {
            *(r10_1 + r9_3) = *(r8_1 + r9_3);
            r9_3 += 2;
        }
        
        if (rdx_9 & 1)
            r10_1[r9_3] = *(r8_1 + r9_3);
    }
    else
    {
        var_88 = rdx_1;
        var_78 = rax_1[2];
    }
    
    int64_t rdx_3 = rax_1[1];
    *rax_1 = &rax_1[2];
    rax_1[1] = 0;
    rax_1[2] = 0;
    int64_t var_80 = rdx_3;
    int64_t* rax_3 = sub_14001de90(&var_88, 0, 0, arg3, strlen(arg3));
    int64_t var_98;
    int64_t* var_a8 = &var_98;
    int64_t* rdx_4 = *rax_3;
    
    if (rdx_4 == &rax_3[2])
    {
        char* r10_2 = &var_98;
        void* r8_2 = &rax_3[2];
        int32_t rdx_12 = rax_3[1] + 1;
        
        if (rdx_12 >= 8)
        {
            uint64_t r8_3 = 0;
            
            do
            {
                uint64_t r9_6 = r8_3;
                r8_3 = r8_3 + 8;
                *(&var_98 + r9_6) = *(&rax_3[2] + r9_6);
            } while (r8_3 < (rdx_12 & 0xfffffff8));
            
            r10_2 = &var_98 + r8_3;
            r8_2 = r8_3 + &rax_3[2];
        }
        
        int64_t r9_5 = 0;
        
        if (rdx_12 & 4)
        {
            *r10_2 = *r8_2;
            r9_5 = 4;
        }
        
        if (rdx_12 & 2)
        {
            *(r10_2 + r9_5) = *(r8_2 + r9_5);
            r9_5 += 2;
        }
        
        if (rdx_12 & 1)
            r10_2[r9_5] = *(r8_2 + r9_5);
    }
    else
    {
        var_a8 = rdx_4;
        var_98 = rax_3[2];
    }
    
    int64_t rdx_6 = rax_3[1];
    *rax_3 = &rax_3[2];
    rax_3[1] = 0;
    rax_3[2] = 0;
    int64_t var_a0 = rdx_6;
    sub_14001d5f0(arg1, &var_a8);
    int64_t* rcx_7 = var_a8;
    
    if (rcx_7 != &var_98)
        sub_140021540(rcx_7);
    
    int64_t* rcx_8 = var_88;
    
    if (rcx_8 != &var_78)
        sub_140021540(rcx_8);
    
    int64_t rcx_9 = var_68;
    void var_58;
    
    if (rcx_9 != &var_58)
        sub_140021540(rcx_9);
    
    arg1[2] = rbp;
    arg1[3] = rdi;
    *arg1 = &_vtable_for_std::system_error{for `std::runtime_error'};
    return &_vtable_for_std::system_error{for `std::runtime_error'};
}

void sub_14001d03a(void* arg1 @ rax, int64_t* arg2 @ r13) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

void sub_14001d03f(void* arg1 @ rax, int64_t* arg2 @ rsi, int64_t* arg3 @ r13, int64_t* arg4 @ r14) __noreturn
{
    sub_14001de70(arg2);
    sub_14001de70(arg4);
    sub_14001de70(arg3);
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d070(struct std::runtime_error::std::system_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::system_error{for `std::runtime_error'};
    sub_14001d760(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001d0a0(struct std::runtime_error::std::system_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::system_error{for `std::runtime_error'};
    /* tailcall */
    return sub_14001d760(arg1);
}

int64_t sub_14001d0b0(int64_t arg1)
{
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_14001d0c0() __pure
{
    return;
}

uint64_t (*)() sub_14001d0d0(int64_t* arg1, int64_t* arg2)
{
    char* rax = *arg2;
    
    if ((arg2[1] != 7 || *rax != 0x3931746d || *(rax + 3) != 0x37333939) && *rax - 0x30 > 9)
        /* tailcall */
        return sub_14001d230(arg1, arg2);
    
    void var_28;
    void* var_38 = &var_28;
    sub_14001e2e0(&var_38, "default", &data_14002634a[7]);
    uint64_t (* result)() = sub_14001d230(arg1, &var_38);
    void* rcx_2 = var_38;
    
    if (rcx_2 == &var_28)
        return result;
    
    return sub_140021540(rcx_2);
}

void sub_14001d163(void* arg1 @ rax, int64_t* arg2 @ rsi) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d180(int64_t* arg1, int64_t* arg2)
{
    char* rdx_1 = *arg2;
    /* tailcall */
    return sub_14001d1b0(arg1, rdx_1, *(rdx_1 - 0x18));
}

uint64_t j_sub_14001d480(int64_t* arg1)
{
    /* tailcall */
    return sub_14001d480(arg1);
}

int64_t sub_14001d1a0() __pure
{
    return;
}

uint64_t (*)() sub_14001d1b0(int64_t* arg1, char* arg2, void* arg3)
{
    void var_28;
    void* var_38 = &var_28;
    
    if (!arg2 && arg3)
    {
        sub_140021f00("basic_string: construction from null is not valid");
        /* no return */
    }
    
    sub_14001e2e0(&var_38, arg2, arg3 + arg2);
    uint64_t (* result)() = sub_14001d230(arg1, &var_38);
    void* rcx_2 = var_38;
    
    if (rcx_2 == &var_28)
        return result;
    
    return sub_140021540(rcx_2);
}

uint64_t (*)() sub_14001d230(int64_t* arg1, int64_t* arg2)
{
    *arg1 = 0;
    int64_t* r8 = arg1;
    arg1[1] = 0;
    arg1[2] = 0xffffffff;
    int64_t rax = arg2[1];
    uint64_t (* rax_11)();
    
    if (rax == 7)
    {
        int32_t* rax_4 = *arg2;
        
        if (*rax_4 != 0x61666564 || *(rax_4 + 3) != 0x746c7561)
        {
            sub_1400222f0(0x16, 
                "random_device::random_device(const std::string&): unsupported token");
            /* no return */
        }
        
    label_14001d2a0:
        rax_11 = sub_14001c0c0;
        r8[1] = rax_11;
        return rax_11;
    }
    
    if (rax == 6)
    {
        int32_t* rax_1 = *arg2;
        
        if (*rax_1 == 0x65736472 && rax_1[1] == 0x6465)
        {
            int32_t temp0_3;
            int32_t temp1_3;
            int32_t temp2_3;
            int32_t temp3_3;
            temp0_3 = __cpuid(0, arg1);
            
            if (!temp0_3 || (temp1_3 != 0x68747541 && temp1_3 != 0x756e6547))
            {
                sub_1400222f0(0x28, 
                    "random_device::random_device(const std::string&): device not available");
                /* no return */
            }
            
            int32_t temp0_4;
            int32_t temp1_4;
            int32_t temp2_4;
            int32_t temp3_4;
            temp0_4 = __cpuid(7, 0);
            arg1 = temp2_4;
            
            if (!(temp1_4 & 0x40000))
            {
                sub_1400222f0(0x28, 
                    "random_device::random_device(const std::string&): device not available");
                /* no return */
            }
            
        label_14001d386:
            int32_t temp0_5;
            int32_t temp1_5;
            int32_t temp2_5;
            int32_t temp3_5;
            temp0_5 = __cpuid(1, arg1);
            uint64_t (* rax_7)() = sub_14001c0f0;
            
            if (!(temp2_5 & 0x40000000))
                rax_7 = sub_14001c060;
            
            r8[1] = rax_7;
            return rax_7;
        }
        
        if (*rax_1 != 0x61726472 || rax_1[1] != 0x646e)
        {
            if (*rax_1 == 0x646e6172 && rax_1[1] == 0x735f)
                goto label_14001d2a0;
            
            sub_1400222f0(0x16, 
                "random_device::random_device(const std::string&): unsupported token");
            /* no return */
        }
    }
    else if (rax == 5)
    {
        int32_t* rax_8 = *arg2;
        
        if (*rax_8 != 0x6e726472 || rax_8[1] != 0x64)
        {
            sub_1400222f0(0x16, 
                "random_device::random_device(const std::string&): unsupported token");
            /* no return */
        }
    }
    else
    {
        if (rax == 2)
        {
            if (**arg2 != 0x7768)
            {
                sub_1400222f0(0x16, 
                    "random_device::random_device(const std::string&): unsupported token");
                /* no return */
            }
        }
        else if (rax != 8 || **arg2 != 0x6572617764726168)
        {
            sub_1400222f0(0x16, 
                "random_device::random_device(const std::string&): unsupported token");
            /* no return */
        }
        
        int32_t temp0_1;
        int32_t temp1_1;
        int32_t temp2_1;
        int32_t temp3_1;
        temp0_1 = __cpuid(0, arg1);
        arg1 = temp2_1;
        
        if (temp0_1 && (temp1_1 == 0x68747541 || temp1_1 == 0x756e6547))
        {
            int32_t temp0_2;
            int32_t temp1_2;
            int32_t temp2_2;
            int32_t temp3_2;
            temp0_2 = __cpuid(7, 0);
            arg1 = temp2_2;
            
            if (temp1_2 & 0x40000)
                goto label_14001d386;
        }
    }
    
    int32_t temp0_6;
    int32_t temp1_6;
    int32_t temp2_6;
    int32_t temp3_6;
    temp0_6 = __cpuid(0, arg1);
    
    if (!temp0_6 || (temp1_6 != 0x756e6547 && temp1_6 != 0x68747541))
    {
        sub_1400222f0(0x28, 
            "random_device::random_device(const std::string&): device not available");
        /* no return */
    }
    
    int32_t temp0_7;
    int32_t temp1_7;
    int32_t temp2_7;
    int32_t temp3_7;
    temp0_7 = __cpuid(1, temp2_6);
    
    if (!(temp2_7 & 0x40000000))
    {
        sub_1400222f0(0x28, 
            "random_device::random_device(const std::string&): device not available");
        /* no return */
    }
    
    rax_11 = sub_14001c010;
    r8[1] = rax_11;
    return rax_11;
}

int64_t sub_14001d470(int64_t* arg1, int64_t* arg2)
{
    char* rdx_1 = *arg2;
    /* tailcall */
    return sub_14001d1b0(arg1, rdx_1, *(rdx_1 - 0x18));
}

uint64_t sub_14001d480(int64_t* arg1)
{
    int64_t rax = arg1[1];
    
    if (rax)
    {
        *arg1;
        /* jump -> rax */
    }
    
    int64_t rbx = 4;
    int32_t var_2c;
    int32_t* _DstBuf = &var_2c;
    
    while (true)
    {
        int32_t rax_1 = _read(arg1[2], _DstBuf, rbx);
        
        if (rax_1 <= 0)
        {
            if (rax_1 != 0xffffffff)
                break;
            
            if (*_errno() != 4)
                break;
        }
        else
        {
            int64_t rax_2 = rax_1;
            _DstBuf += rax_2;
            int64_t temp0_1 = rbx;
            rbx -= rax_2;
            
            if (temp0_1 == rax_2)
                return var_2c;
        }
    }
    
    sub_1400222f0(*_errno(), "random_device could not be read");
    /* no return */
}

void* sub_14001d530(struct std::exception::std::runtime_error::VTable** arg1, void* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* result = *(arg2 + 8);
    arg1[1] = result;
    
    if (data_140023080)
    {
        int32_t r8_1 = *(result - 8);
        result = arg1[1];
        
        if (r8_1 > 0)
        {
            if (data_140023080)
            {
                *(result - 8) += 1;
                return result;
            }
            
            *(result - 8) += 1;
            return result;
        }
    }
    else
    {
        int32_t rdx = *(result - 8);
        
        if (rdx > 0)
        {
            *(result - 8) = rdx + 1;
            return result;
        }
    }
    
    *(result - 8) = 1;
    return result;
}

void* sub_14001d590(struct std::exception::std::runtime_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    void* result = sub_140019670(arg2, rdx);
    arg1[1] = result;
    return result;
}

void sub_14001d5da(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

uint64_t* sub_14001d5f0(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    return sub_14001c190(&arg1[1], *arg2, r8);
}

void sub_14001d622(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

void* sub_14001d640(struct std::exception::std::runtime_error::VTable** arg1, void* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rax = *(arg2 + 8);
    
    if (*(rax - 8) < 0)
    {
        void var_9;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_9, 0);
        arg1[1] = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        arg1[1] = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    arg1[1] = rax;
    return rax;
}

void* sub_14001d6b0(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rax = *arg2;
    
    if (*(rax - 8) < 0)
    {
        void var_19;
        void* rax_1 = sub_140019ad0(rax - 0x18, &var_19, 0);
        arg1[1] = rax_1;
        return rax_1;
    }
    
    if (data_140023080)
    {
        *(rax - 8) += 1;
        arg1[1] = rax;
        return rax;
    }
    
    *(rax - 8) += 1;
    arg1[1] = rax;
    return rax;
}

void sub_14001d720(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d740(struct std::exception::std::runtime_error::VTable** arg1)
{
    sub_14001d760(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001d760(struct std::exception::std::runtime_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

void* sub_14001d7d0(void* arg1, void* arg2)
{
    sub_140019c20(arg1 + 8, arg2 + 8);
    return arg1;
}

void* sub_14001d7f0(void* arg1, void* arg2)
{
    sub_14001a290(arg1 + 8, arg2 + 8);
    return arg1;
}

int64_t sub_14001d810(struct std::exception::std::runtime_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::overflow_error{for `std::runtime_error'};
    return &_vtable_for_std::overflow_error{for `std::runtime_error'};
}

void sub_14001d868(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d880(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::overflow_error{for `std::runtime_error'};
    return &_vtable_for_std::overflow_error{for `std::runtime_error'};
}

void sub_14001d8bf(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d8e0(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::overflow_error{for `std::runtime_error'};
    return &_vtable_for_std::overflow_error{for `std::runtime_error'};
}

void sub_14001d947(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001d960(struct std::runtime_error::std::overflow_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::overflow_error{for `std::runtime_error'};
    sub_14001d760(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001d990(struct std::exception::std::runtime_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001da00(struct std::exception::std::runtime_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::underflow_error{for `std::runtime_error'};
    return &_vtable_for_std::underflow_error{for `std::runtime_error'};
}

void sub_14001da58(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001da70(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::underflow_error{for `std::runtime_error'};
    return &_vtable_for_std::underflow_error{for `std::runtime_error'};
}

void sub_14001daaf(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001dad0(struct std::exception::std::runtime_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::underflow_error{for `std::runtime_error'};
    return &_vtable_for_std::underflow_error{for `std::runtime_error'};
}

void sub_14001db37(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001db50(struct std::runtime_error::std::underflow_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::underflow_error{for `std::runtime_error'};
    sub_14001d760(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001db80(struct std::exception::std::runtime_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::runtime_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001dbf0(struct std::exception::std::logic_error::VTable** arg1, char* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rdx = -ffffffffffffffff;
    
    if (arg2)
        rdx = &arg2[strlen(arg2)];
    
    arg1[1] = sub_140019670(arg2, rdx);
    *arg1 = &_vtable_for_std::invalid_argument{for `std::logic_error'};
    return &_vtable_for_std::invalid_argument{for `std::logic_error'};
}

void sub_14001dc48(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001dc60(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    sub_14001c190(&arg1[1], *arg2, r8);
    *arg1 = &_vtable_for_std::invalid_argument{for `std::logic_error'};
    return &_vtable_for_std::invalid_argument{for `std::logic_error'};
}

void sub_14001dc9f(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001dcc0(struct std::exception::std::logic_error::VTable** arg1, int64_t* arg2)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rax = *arg2;
    void var_19;
    
    if (*(rax - 8) < 0)
        rax = sub_140019ad0(rax - 0x18, &var_19, 0);
    else if (data_140023080)
        *(rax - 8) += 1;
    else
        *(rax - 8) += 1;
    arg1[1] = rax;
    *arg1 = &_vtable_for_std::invalid_argument{for `std::logic_error'};
    return &_vtable_for_std::invalid_argument{for `std::logic_error'};
}

void sub_14001dd27(void* arg1 @ rax) __noreturn
{
    sub_14000f620(arg1);
    /* no return */
}

int64_t sub_14001dd40(struct std::logic_error::std::invalid_argument::VTable** arg1)
{
    *arg1 = &_vtable_for_std::invalid_argument{for `std::logic_error'};
    sub_14001bd70(arg1);
    /* tailcall */
    return sub_140021540(arg1);
}

int64_t sub_14001dd70(struct std::exception::std::logic_error::VTable** arg1)
{
    *arg1 = &_vtable_for_std::logic_error{for `std::exception'};
    void* rcx = arg1[1];
    
    if (data_140023080)
    {
        int32_t rax_2 = *(rcx - 8);
        *(rcx - 8) -= 1;
        
        if (rax_2 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    else
    {
        int32_t rax_1 = *(rcx - 8);
        *(rcx - 8) = rax_1 - 1;
        
        if (rax_1 <= 0)
        {
            sub_1400199c0(rcx - 0x18);
            /* tailcall */
            return sub_140021080();
        }
    }
    
    /* tailcall */
    return sub_140021080();
}

int64_t sub_14001dde0(struct std::exception::std::bad_array_new_length::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_array_new_length{for `std::exception'};
    sub_140021060(arg1);
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_14001de10(struct std::exception::std::bad_array_new_length::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_array_new_length{for `std::exception'};
    /* tailcall */
    return sub_140021060(arg1);
}

void sub_14001de20(void* _Block)
{
    /* tailcall */
    return sub_140021540(_Block);
}

int64_t sub_14001de30() __pure
{
    return;
}

int64_t sub_14001de40() __pure
{
    return &data_1400231e0;
}

int64_t sub_14001de50() __pure
{
    return &data_1400231f0;
}

int64_t sub_14001de60(int64_t* arg1)
{
    /* tailcall */
    return sub_140021540(*arg1);
}

int64_t sub_14001de70(int64_t* arg1)
{
    int64_t result = *arg1;
    
    if (result == &arg1[2])
        return result;
    
    /* tailcall */
    return sub_140021540(result);
}

int64_t* sub_14001de90(int64_t* arg1, uint64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t rcx = arg1[1];
    
    if (0x3fffffffffffffff + arg3 - rcx < arg5)
    {
        sub_140021ff0("basic_string::_M_replace");
        /* no return */
    }
    
    int64_t rax_2 = *arg1;
    int64_t rsi_2 = arg5 - arg3 + rcx;
    int64_t r10_1;
    
    if (rax_2 == &arg1[2])
        r10_1 = 0xf;
    else
        r10_1 = arg1[2];
    
    if (r10_1 < rsi_2)
        sub_140020170(arg1, arg2, arg3, arg4, arg5);
    else
    {
        char* rbp_1 = rax_2 + arg2;
        uint64_t _Size = rcx - (arg2 + arg3);
        
        if (arg4 >= rax_2 && rax_2 + rcx >= arg4)
            sub_14001e690(arg1, rbp_1, arg3, arg4, arg5, _Size);
        else
        {
            if (!_Size || arg3 == arg5)
                goto label_14001df28;
            
            char* rdx_1 = &rbp_1[arg3];
            void* rcx_1 = &rbp_1[arg5];
            
            if (_Size == 1)
            {
                *rcx_1 = *rdx_1;
                
                if (arg5)
                    goto label_14001df2d;
            }
            else
            {
                memmove(rcx_1, rdx_1, _Size);
            label_14001df28:
                
                if (arg5)
                {
                label_14001df2d:
                    
                    if (arg5 == 1)
                        *rbp_1 = *arg4;
                    else
                        memcpy(rbp_1, arg4, arg5);
                }
            }
        }
    }
    
    char* rax_3 = *arg1;
    arg1[1] = rsi_2;
    rax_3[rsi_2] = 0;
    return arg1;
}

uint64_t sub_14001dfd0(int64_t arg1, int64_t arg2) __pure
{
    int64_t rcx = arg1 - arg2;
    
    if (rcx > 0x7fffffff)
        return 0x7fffffff;
    
    if (rcx < -0x80000000)
        return 0x80000000;
    
    return rcx;
}

int64_t sub_14001e000(void* arg1, int64_t arg2)
{
    *(arg1 + 0x10) = arg2;
}

int64_t sub_14001e010(int64_t arg1, uint64_t arg2)
{
    if (arg2 >= 0)
        /* tailcall */
        return sub_140021560(arg2);
    
    sub_140021e00();
    /* no return */
}

int64_t sub_14001e030(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

int64_t sub_14001e040(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

int64_t sub_14001e050(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

int64_t sub_14001e060(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

uint64_t sub_14001e070(int64_t* arg1, uint64_t arg2, char arg3)
{
    uint64_t _Size_1 = arg2;
    uint64_t _Size = arg2;
    char* rcx;
    
    if (arg2 > 0xf)
    {
        char* rax = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax;
        rcx = rax;
        _Size = _Size_1;
        arg1[2] = _Size;
    }
    else
        rcx = *arg1;
    
    if (_Size)
    {
        if (_Size == 1)
        {
            *rcx = arg3;
            uint64_t _Size_2 = _Size_1;
            int64_t rcx_1 = *arg1;
            arg1[1] = _Size_2;
            *(rcx_1 + _Size_2) = 0;
            return _Size_2;
        }
        
        memset(rcx, arg3, _Size);
        _Size = _Size_1;
        rcx = *arg1;
    }
    
    arg1[1] = _Size;
    rcx[_Size] = 0;
    return _Size;
}

void sub_14001e100(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

void sub_14001e1a0(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

void sub_14001e240(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

void sub_14001e2e0(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

void sub_14001e380(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

void sub_14001e420(int64_t* arg1, char* arg2, int64_t arg3)
{
    uint64_t _Size = arg3 - arg2;
    uint64_t _Size_1 = _Size;
    char* rcx;
    
    if (_Size > 0xf)
    {
        char* rax_2 = sub_1400200f0(arg1, &_Size_1, 0);
        *arg1 = rax_2;
        rcx = rax_2;
        arg1[2] = _Size_1;
    }
    else
    {
        rcx = *arg1;
        
        if (_Size == 1)
        {
            *rcx = *arg2;
            uint64_t _Size_2 = _Size_1;
            char* rcx_1 = *arg1;
            arg1[1] = _Size_2;
            rcx_1[_Size_2] = 0;
            return;
        }
        
        if (!_Size)
        {
            arg1[1] = _Size;
            rcx[_Size] = 0;
            return;
        }
    }
    
    memcpy(rcx, arg2, _Size);
    uint64_t _Size_3 = _Size_1;
    int64_t rcx_2 = *arg1;
    arg1[1] = _Size_3;
    *(rcx_2 + _Size_3) = 0;
}

int64_t sub_14001e4c0(int64_t arg1) __pure
{
    return arg1 + 0x10;
}

char* sub_14001e4d0(int64_t* arg1, int64_t arg2)
{
    char* result = *arg1;
    arg1[1] = arg2;
    result[arg2] = 0;
    return result;
}

void sub_14001e4e0(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_14001e500(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_14001e520(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

void sub_14001e540(char* arg1, char* arg2, int64_t arg3)
{
    uint64_t r8_1 = arg3 - arg2;
    
    if (r8_1 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (r8_1)
        /* tailcall */
        return memcpy(arg1, arg2, r8_1);
}

int64_t sub_14001e560(int64_t* arg1)
{
    return sub_14001fcd0(arg1);
}

int64_t* sub_14001e570(int64_t* arg1, uint64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    int64_t rdx = arg1[1];
    
    if (0x3fffffffffffffff + arg3 - rdx < arg4)
    {
        sub_140021ff0("basic_string::_M_replace_aux");
        /* no return */
    }
    
    char* rcx = *arg1;
    int64_t rdi_2 = arg4 - arg3 + rdx;
    int64_t rax_3;
    
    if (rcx == &arg1[2])
        rax_3 = 0xf;
    else
        rax_3 = arg1[2];
    
    if (rax_3 < rdi_2)
    {
        sub_140020170(arg1, arg2, arg3, nullptr, arg4);
        rcx = *arg1;
    }
    else
    {
        int64_t rax_4 = arg3 + arg2;
        uint64_t _Size = rdx - rax_4;
        
        if (rdx != rax_4 && arg3 != arg4)
        {
            void* rcx_1 = &rcx[arg2];
            void* rax_5 = rcx_1 + arg3;
            void* rcx_2 = rcx_1 + arg4;
            
            if (_Size == 1)
            {
                *rcx_2 = *rax_5;
                rcx = *arg1;
            }
            else
            {
                memmove(rcx_2, rax_5, _Size);
                rcx = *arg1;
            }
        }
    }
    
    if (arg4)
    {
        char* rcx_3 = &rcx[arg2];
        
        if (arg4 == 1)
        {
            *rcx_3 = arg5;
            rcx = *arg1;
        }
        else
        {
            memset(rcx_3, arg5, arg4);
            rcx = *arg1;
        }
    }
    
    arg1[1] = rdi_2;
    rcx[rdi_2] = 0;
    return arg1;
}

void* sub_14001e690(int64_t arg1, char* arg2, int64_t arg3, char* arg4, uint64_t arg5, uint64_t arg6)
{
    void* result = arg5 - 1;
    
    if (result < arg3)
    {
        if (arg5 != 1)
            result = memmove(arg2, arg4, arg5);
        else
        {
            result = *arg4;
            *arg2 = result;
        }
    }
    
    if (arg6 && arg5 != arg3)
    {
        void* rdx_1 = &arg2[arg3];
        void* rcx_1 = &arg2[arg5];
        
        if (arg6 != 1)
            result = memmove(rcx_1, rdx_1, arg6);
        else
        {
            result = *rdx_1;
            *rcx_1 = result;
        }
    }
    
    if (arg3 < arg5)
    {
        void* r12_1 = &arg2[arg3];
        result = &arg4[arg5];
        
        if (r12_1 >= result)
        {
            if (arg5 != 1)
                /* tailcall */
                return memmove(arg2, arg4, arg5);
            
            result = *arg4;
            *arg2 = result;
        }
        else
        {
            void* rsi_3;
            
            if (arg4 < r12_1)
            {
                void* _Size = r12_1 - arg4;
                
                if (_Size != 1)
                    result = memmove(arg2, arg4, _Size);
                else
                {
                    result = *arg4;
                    *arg2 = result;
                }
                
                rsi_3 = &arg2[arg5];
                char* rbp = arg2 + _Size;
                void* count = arg5 - _Size;
                
                if (count == 1)
                {
                    result = *rsi_3;
                    *rbp = result;
                }
                else if (count)
                    __builtin_memcpy(rbp, rsi_3, count);
            }
            else
            {
                rsi_3 = arg5 - arg3 + arg4;
                
                if (arg5 == 1)
                {
                    result = *rsi_3;
                    *arg2 = result;
                }
                else
                    __builtin_memcpy(arg2, rsi_3, arg5);
            }
        }
    }
    
    return result;
}

int64_t sub_14001e7b0(int64_t arg1) __pure
{
    return arg1;
}

int64_t sub_14001e7c0() __pure
{
    return;
}

int64_t sub_14001e7d0(int64_t arg1) __pure
{
    return arg1 + 0x10;
}

int64_t sub_14001e7e0(int64_t* arg1, uint64_t arg2, char arg3)
{
    /* tailcall */
    return sub_14001e070(arg1, arg2, arg3);
}

int64_t sub_14001e7f0(int64_t* arg1, uint64_t arg2)
{
    if (arg2 < arg1[1])
        return *arg1 + arg2;
    
    sub_140022090("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", arg2);
    /* no return */
}

int64_t sub_14001e820(int64_t* arg1)
{
    return *arg1 + arg1[1];
}

int64_t sub_14001e830(int64_t* arg1)
{
    return *arg1 + arg1[1] - 1;
}

int64_t* sub_14001e840(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2;
    return arg1;
}

int64_t* sub_14001e850(int64_t* arg1, int64_t* arg2)
{
    if (arg1 != arg2)
    {
        char* r8_1 = *arg1;
        char* rcx = *arg2;
        int64_t rcx_2;
        
        if (&arg1[2] == r8_1)
        {
            int64_t r10_2 = arg1[1];
            
            if (&arg2[2] == rcx)
            {
                int64_t r11_2 = arg2[1];
                int64_t rbx_8 = r11_2;
                
                if (!r10_2)
                {
                    if (r11_2)
                    {
                        if (r11_2 + 1 >= 8)
                        {
                            arg1[2] = arg2[2];
                            uint64_t rcx_9 = r11_2 + 1;
                            *(&arg1[2] + rcx_9 - 8) = *(&arg2[2] + rcx_9 - 8);
                            void* rcx_11 = &arg1[3] & 0xfffffffffffffff8;
                            int64_t r9_8 = &arg1[2] - rcx_11;
                            int32_t r8_10 = (r11_2 + 1 + r9_8) & 0xfffffff8;
                            
                            if (r8_10 >= 8)
                            {
                                int32_t i = 0;
                                
                                do
                                {
                                    uint64_t i_9 = i;
                                    i += 8;
                                    *(rcx_11 + i_9) = *(&arg2[2] - r9_8 + i_9);
                                } while (i < (r8_10 & 0xfffffff8));
                            }
                            
                            rcx = *arg2;
                            rbx_8 = arg2[1];
                        }
                        else if ((r11_2 + 1) & 4)
                        {
                            uint64_t r8_16 = r11_2 + 1;
                            arg1[2] = arg2[2];
                            *(&arg1[2] + r8_16 - 4) = *(rcx + r8_16 - 4);
                            rcx = *arg2;
                            rbx_8 = arg2[1];
                        }
                        else if (r11_2 != 0xffffffff)
                        {
                            arg1[2] = arg2[2];
                            
                            if ((r11_2 + 1) & 2)
                            {
                                uint64_t r8_17 = r11_2 + 1;
                                *(&arg1[2] + r8_17 - 2) = *(rcx + r8_17 - 2);
                                rcx = *arg2;
                                rbx_8 = arg2[1];
                            }
                            else
                            {
                                rcx = *arg2;
                                rbx_8 = arg2[1];
                            }
                        }
                        
                        arg1[1] = rbx_8;
                        arg2[1] = 0;
                        *rcx = 0;
                    }
                    else
                    {
                        arg1[1] = r11_2;
                        arg2[1] = 0;
                    }
                }
                else if (rbx_8)
                {
                    int64_t var_38;
                    char* rdi_1 = &var_38;
                    void* r9_4 = rcx;
                    
                    if (rbx_8 + 1 >= 8)
                    {
                        uint64_t r9_9 = 0;
                        
                        do
                        {
                            uint64_t rsi_8 = r9_9;
                            r9_9 = r9_9 + 8;
                            *(&var_38 + rsi_8) = *(rcx + rsi_8);
                        } while (r9_9 < ((rbx_8 + 1) & 0xfffffff8));
                        
                        rdi_1 = &var_38 + r9_9;
                        r9_4 = &rcx[r9_9];
                    }
                    
                    int64_t rsi_6 = 0;
                    
                    if ((rbx_8 + 1) & 4)
                    {
                        *rdi_1 = *r9_4;
                        rsi_6 = 4;
                    }
                    
                    if ((rbx_8 + 1) & 2)
                    {
                        *(rdi_1 + rsi_6) = *(r9_4 + rsi_6);
                        rsi_6 += 2;
                    }
                    
                    if ((rbx_8 + 1) & 1)
                        rdi_1[rsi_6] = *(r9_4 + rsi_6);
                    
                    if (r10_2 + 1 >= 8)
                    {
                        *rcx = *r8_1;
                        uint64_t r9_12 = r10_2 + 1;
                        *(rcx + r9_12 - 8) = *(r8_1 + r9_12 - 8);
                        void* rsi_12 = &rcx[8] & 0xfffffffffffffff8;
                        void* rcx_14 = rcx - rsi_12;
                        int32_t rcx_16 = (rcx_14 + r10_2 + 1) & 0xfffffff8;
                        
                        if (rcx_16 >= 8)
                        {
                            int32_t i_1 = 0;
                            
                            do
                            {
                                uint64_t i_11 = i_1;
                                i_1 += 8;
                                *(rsi_12 + i_11) = *(r8_1 - rcx_14 + i_11);
                            } while (i_1 < (rcx_16 & 0xfffffff8));
                        }
                    }
                    else if ((r10_2 + 1) & 4)
                    {
                        uint64_t r11_18 = r10_2 + 1;
                        *rcx = *r8_1;
                        *(rcx + r11_18 - 4) = *(r8_1 + r11_18 - 4);
                    }
                    else if (r10_2 != 0xffffffff)
                    {
                        *rcx = *r8_1;
                        
                        if ((r10_2 + 1) & 2)
                        {
                            uint64_t r11_21 = r10_2 + 1;
                            *(rcx + r11_21 - 2) = *(r8_1 + r11_21 - 2);
                        }
                    }
                    
                    if (rbx_8 + 1 >= 8)
                    {
                        *r8_1 = var_38;
                        uint64_t rcx_19 = rbx_8 + 1;
                        void var_40;
                        *(r8_1 + rcx_19 - 8) = *(&var_40 + rcx_19);
                        void* r9_15 = &r8_1[8] & 0xfffffffffffffff8;
                        void* r8_15 = r8_1 - r9_15;
                        int32_t rbx_13 = (rbx_8 + 1 + r8_15) & 0xfffffff8;
                        
                        if (rbx_13 >= 8)
                        {
                            int32_t i_2 = 0;
                            
                            do
                            {
                                uint64_t i_8 = i_2;
                                i_2 += 8;
                                *(r9_15 + i_8) = *(&var_38 - r8_15 + i_8);
                            } while (i_2 < (rbx_13 & 0xfffffff8));
                        }
                    }
                    else if ((rbx_8 + 1) & 4)
                    {
                        uint64_t rbx_15 = rbx_8 + 1;
                        *r8_1 = var_38;
                        void var_3c;
                        *(r8_1 + rbx_15 - 4) = *(&var_3c + rbx_15);
                    }
                    else if (rbx_8 != 0xffffffff)
                    {
                        *r8_1 = var_38;
                        
                        if ((rbx_8 + 1) & 2)
                        {
                            uint64_t rbx_16 = rbx_8 + 1;
                            void var_3a;
                            *(r8_1 + rbx_16 - 2) = *(&var_3a + rbx_16);
                        }
                    }
                    
                    rcx_2 = arg1[1];
                    arg1[1] = arg2[1];
                    arg2[1] = rcx_2;
                }
                else
                {
                    if (r10_2 + 1 >= 8)
                    {
                        arg2[2] = arg1[2];
                        uint64_t rcx_13 = r10_2 + 1;
                        *(&arg2[2] + rcx_13 - 8) = *(&arg1[2] + rcx_13 - 8);
                        void* r8_14 = &arg2[3] & 0xfffffffffffffff8;
                        void* rsi_9 = &arg2[2] - r8_14;
                        int32_t r11_15 = (r10_2 + 1 + rsi_9) & 0xfffffff8;
                        
                        if (r11_15 >= 8)
                        {
                            int32_t i_3 = 0;
                            
                            do
                            {
                                uint64_t i_10 = i_3;
                                i_3 += 8;
                                *(r8_14 + i_10) = *(&arg1[2] - rsi_9 + i_10);
                            } while (i_3 < (r11_15 & 0xfffffff8));
                        }
                        
                        r8_1 = *arg1;
                        r10_2 = arg1[1];
                    }
                    else if ((r10_2 + 1) & 4)
                    {
                        uint64_t r11_19 = r10_2 + 1;
                        arg2[2] = arg1[2];
                        *(&arg2[2] + r11_19 - 4) = *(r8_1 + r11_19 - 4);
                        r8_1 = *arg1;
                        r10_2 = arg1[1];
                    }
                    else if (r10_2 != 0xffffffff)
                    {
                        arg2[2] = arg1[2];
                        
                        if ((r10_2 + 1) & 2)
                        {
                            uint64_t r11_20 = r10_2 + 1;
                            *(&arg2[2] + r11_20 - 2) = *(r8_1 + r11_20 - 2);
                            r8_1 = *arg1;
                            r10_2 = arg1[1];
                        }
                        else
                        {
                            r8_1 = *arg1;
                            r10_2 = arg1[1];
                        }
                    }
                    
                    arg2[1] = r10_2;
                    arg1[1] = 0;
                    *r8_1 = 0;
                }
            }
            else
            {
                int64_t rbx_2 = arg2[2];
                
                if (r10_2 + 1 >= 8)
                {
                    arg2[2] = arg1[2];
                    uint64_t r10_5 = r10_2 + 1;
                    *(&arg2[2] + r10_5 - 8) = *(&arg1[2] + r10_5 - 8);
                    void* r10_7 = &arg2[3] & 0xfffffffffffffff8;
                    void* r11_9 = &arg2[2] - r10_7;
                    int32_t r8_4 = (r10_2 + 1 + r11_9) & 0xfffffff8;
                    
                    if (r8_4 >= 8)
                    {
                        int32_t i_4 = 0;
                        
                        do
                        {
                            uint64_t i_7 = i_4;
                            i_4 += 8;
                            *(r10_7 + i_7) = *(&arg1[2] - r11_9 + i_7);
                        } while (i_4 < (r8_4 & 0xfffffff8));
                    }
                    
                    r10_2 = arg1[1];
                }
                else if ((r10_2 + 1) & 4)
                {
                    uint64_t r8_6 = r10_2 + 1;
                    arg2[2] = arg1[2];
                    *(&arg2[2] + r8_6 - 4) = *(&arg1[2] + r8_6 - 4);
                    r10_2 = arg1[1];
                }
                else if (r10_2 != 0xffffffff)
                {
                    arg2[2] = arg1[2];
                    
                    if ((r10_2 + 1) & 2)
                    {
                        uint64_t r8_8 = r10_2 + 1;
                        *(&arg2[2] + r8_8 - 2) = *(&arg1[2] + r8_8 - 2);
                        r10_2 = arg1[1];
                    }
                    else
                        r10_2 = arg1[1];
                }
                
                *arg1 = rcx;
                *arg2 = &arg2[2];
                arg1[2] = rbx_2;
                arg1[1] = arg2[1];
                arg2[1] = r10_2;
            }
        }
        else
        {
            int64_t r10_1 = arg1[2];
            int64_t rbx_1;
            
            if (rcx == &arg2[2])
            {
                rbx_1 = arg2[1];
                
                if (rbx_1 + 1 >= 8)
                {
                    arg1[2] = *rcx;
                    uint64_t rbx_5 = rbx_1 + 1;
                    *(&arg1[2] + rbx_5 - 8) = *(rcx + rbx_5 - 8);
                    void* rbx_7 = &arg1[3] & 0xfffffffffffffff8;
                    void* rsi_4 = &arg1[2] - rbx_7;
                    int32_t r11_5 = (rbx_1 + 1 + rsi_4) & 0xfffffff8;
                    
                    if (r11_5 >= 8)
                    {
                        int32_t i_5 = 0;
                        
                        do
                        {
                            uint64_t i_6 = i_5;
                            i_5 += 8;
                            *(rbx_7 + i_6) = *(rcx - rsi_4 + i_6);
                        } while (i_5 < (r11_5 & 0xfffffff8));
                    }
                    
                    rbx_1 = arg2[1];
                }
                else if ((rbx_1 + 1) & 4)
                {
                    uint64_t r11_11 = rbx_1 + 1;
                    arg1[2] = *rcx;
                    *(&arg1[2] + r11_11 - 4) = *(rcx + r11_11 - 4);
                    rbx_1 = arg2[1];
                }
                else if (rbx_1 != 0xffffffff)
                {
                    arg1[2] = *rcx;
                    
                    if ((rbx_1 + 1) & 2)
                    {
                        uint64_t r11_12 = rbx_1 + 1;
                        *(&arg1[2] + r11_12 - 2) = *(rcx + r11_12 - 2);
                        rbx_1 = arg2[1];
                    }
                    else
                        rbx_1 = arg2[1];
                }
                
                *arg2 = r8_1;
                *arg1 = &arg1[2];
            }
            else
            {
                *arg1 = rcx;
                int64_t rcx_1 = arg2[2];
                *arg2 = r8_1;
                arg1[2] = rcx_1;
                rbx_1 = arg2[1];
            }
            
            arg2[2] = r10_1;
            rcx_2 = arg1[1];
            arg1[1] = rbx_1;
            arg2[1] = rcx_2;
        }
    }
    
    return arg1;
}

int64_t sub_14001ee00(int64_t* arg1)
{
    return *arg1;
}

char* sub_14001ee10(int64_t* arg1)
{
    char* result = *arg1;
    arg1[1] = 0;
    *result = 0;
    return result;
}

void* sub_14001ee20(int64_t* arg1, int64_t arg2)
{
    void* rbx_1 = arg2 - *arg1;
    sub_14001ff10(arg1, rbx_1, 1);
    return *arg1 + rbx_1;
}

void* sub_14001ee50(int64_t* arg1, char* arg2, int64_t arg3)
{
    int64_t rcx = *arg1;
    void* rsi_1 = arg2 - rcx;
    
    if (arg3 != rcx + arg1[1])
    {
        sub_14001ff10(arg1, rsi_1, arg3 - arg2);
        return *arg1 + rsi_1;
    }
    
    arg1[1] = rsi_1;
    *arg2 = 0;
    return *arg1 + rsi_1;
}

int64_t* sub_14001eeb0(int64_t* arg1, void* arg2, void* arg3)
{
    int64_t r9 = arg1[1];
    
    if (r9 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::erase");
        /* no return */
    }
    
    if (arg3 == -1)
    {
        arg1[1] = arg2;
        *(*arg1 + arg2) = 0;
        return arg1;
    }
    
    if (!arg3)
        return arg1;
    
    void* r9_1 = r9 - arg2;
    
    if (r9_1 <= arg3)
        arg3 = r9_1;
    
    sub_14001ff10(arg1, arg2, arg3);
    return arg1;
}

int64_t sub_14001ef20(int64_t* arg1)
{
    return *arg1;
}

int64_t sub_14001ef30(int64_t* arg1, char* arg2)
{
    uint64_t rax = strlen(arg2);
    
    if (0x3fffffffffffffff - arg1[1] >= rax)
        /* tailcall */
        return sub_14001ffa0(arg1, arg2, rax);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_14001ef80(int64_t* arg1, char* arg2, uint64_t arg3)
{
    if (0x3fffffffffffffff - arg1[1] >= arg3)
        /* tailcall */
        return sub_14001ffa0(arg1, arg2, arg3);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_14001efb0(int64_t* arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    
    if (0x3fffffffffffffff - arg1[1] >= r8)
        /* tailcall */
        return sub_14001ffa0(arg1, *arg2, r8);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_14001eff0(int64_t* arg1, int64_t* arg2, int64_t arg3, uint64_t arg4)
{
    int64_t r10 = arg2[1];
    uint64_t r8_1 = r10 - arg3;
    
    if (r8_1 > arg4)
        r8_1 = arg4;
    
    if (r10 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::append");
        /* no return */
    }
    
    if (0x3fffffffffffffff - arg1[1] >= r8_1)
        /* tailcall */
        return sub_14001ffa0(arg1, *arg2 + arg3, r8_1);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_14001f060(int64_t* arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    
    if (0x3fffffffffffffff - arg1[1] >= r8)
        /* tailcall */
        return sub_14001ffa0(arg1, *arg2, r8);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t* sub_14001f0a0(int64_t* arg1, uint64_t arg2, char arg3)
{
    return sub_14001e570(arg1, arg1[1], 0, arg2, arg3);
}

int64_t* sub_14001f0d0(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size = arg2[1];
    void* rcx = *arg1;
    void* rdx = *arg2;
    
    if (rcx != &arg1[2])
    {
        if (&arg2[2] == rdx)
            goto label_14001f150;
        
        *arg1 = rdx;
        int64_t r9_1 = arg1[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        
        if (!rcx)
        {
            rcx = &arg2[2];
            *arg2 = rcx;
        }
        else
        {
            *arg2 = rcx;
            arg2[2] = r9_1;
        }
    }
    else if (&arg2[2] == rdx)
    {
    label_14001f150:
        
        if (arg1 == arg2)
            rcx = rdx;
        else
        {
            if (_Size)
            {
                if (_Size == 1)
                {
                    *rcx = *rdx;
                    _Size = arg2[1];
                    rcx = *arg1;
                }
                else
                {
                    memcpy(rcx, rdx, _Size);
                    _Size = arg2[1];
                    rcx = *arg1;
                }
            }
            
            arg1[1] = _Size;
            *(rcx + _Size) = 0;
            rcx = *arg2;
        }
    }
    else
    {
        *arg1 = rdx;
        rcx = &arg2[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        *arg2 = rcx;
    }
    
    arg2[1] = 0;
    *rcx = 0;
    return arg1;
}

int64_t* sub_14001f1b0(int64_t* arg1, char* arg2)
{
    uint64_t rax = strlen(arg2);
    return sub_14001de90(arg1, 0, arg1[1], arg2, rax);
}

int64_t* sub_14001f1f0(int64_t* arg1, char* arg2, uint64_t arg3)
{
    return sub_14001de90(arg1, 0, arg1[1], arg2, arg3);
}

int64_t* sub_14001f210(int64_t* arg1, int64_t* arg2)
{
    sub_140020030(arg1, arg2);
    return arg1;
}

int64_t* sub_14001f230(int64_t* arg1, int64_t* arg2, int64_t arg3, uint64_t arg4)
{
    int64_t r10 = arg2[1];
    uint64_t rax_1 = r10 - arg3;
    
    if (rax_1 > arg4)
        rax_1 = arg4;
    
    if (r10 >= arg3)
        return sub_14001de90(arg1, 0, arg1[1], *arg2 + arg3, rax_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::assign");
    /* no return */
}

int64_t* sub_14001f280(int64_t* arg1, int64_t* arg2)
{
    char* r10 = *arg2;
    uint64_t _Size = arg2[1];
    char* rcx = *arg1;
    int64_t rax;
    
    if (&arg1[2] == rcx)
        rax = 0xf;
    else
        rax = arg1[2];
    
    if (rax < _Size)
    {
        uint64_t _Size_2 = 0;
        int64_t var_38;
        int64_t* var_48 = &var_38;
        sub_14001e240(&var_48, r10, &r10[_Size]);
        int64_t* rcx_2 = *arg1;
        uint64_t _Size_1 = _Size_2;
        int64_t* rax_2 = var_48;
        
        if (&arg1[2] != rcx_2)
        {
            if (rax_2 == &var_38)
                goto label_14001f3c3;
            
            int64_t rdx_2 = arg1[2];
            *arg1 = rax_2;
            *(arg1 + 8) = _Size_1 | var_38 << 0x40;
            
            if (!rcx_2)
            {
                var_48 = &var_38;
                rcx_2 = &var_38;
            }
            else
            {
                var_48 = rcx_2;
                var_38 = rdx_2;
            }
        }
        else if (rax_2 == &var_38)
        {
        label_14001f3c3:
            
            if (_Size_1)
            {
                if (_Size_1 == 1)
                {
                    *rcx_2 = var_38;
                    _Size_1 = _Size_2;
                    rcx_2 = *arg1;
                }
                else
                {
                    memcpy(rcx_2, &var_38, _Size_1);
                    _Size_1 = _Size_2;
                    rcx_2 = *arg1;
                }
            }
            
            arg1[1] = _Size_1;
            *(rcx_2 + _Size_1) = 0;
            rcx_2 = var_48;
        }
        else
        {
            *arg1 = rax_2;
            *(arg1 + 8) = _Size_1 | var_38 << 0x40;
            var_48 = &var_38;
            rcx_2 = &var_38;
        }
        
        int64_t var_40_1 = 0;
        *rcx_2 = 0;
        int64_t* rcx_3 = var_48;
        
        if (rcx_3 != &var_38)
            sub_140021540(rcx_3);
    }
    else
    {
        if (_Size)
        {
            if (_Size == 1)
            {
                *rcx = *r10;
                rcx = *arg1;
            }
            else
            {
                memcpy(rcx, r10, _Size);
                rcx = *arg1;
            }
        }
        
        arg1[1] = _Size;
        rcx[_Size] = 0;
    }
    
    return arg1;
}

int64_t* sub_14001f410(int64_t* arg1, uint64_t arg2, char arg3)
{
    return sub_14001e570(arg1, 0, arg1[1], arg2, arg3);
}

int64_t sub_14001f430(int64_t* arg1, int64_t arg2, int64_t* arg3)
{
    uint64_t rbx_1 = arg2 - *arg1;
    
    if (arg1[1] < rbx_1)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::replace");
        /* no return */
    }
    
    sub_14001de90(arg1, rbx_1, 0, *arg3, arg3[1]);
    return *arg1 + rbx_1;
}

int64_t sub_14001f490(int64_t* arg1, int64_t arg2, char arg3)
{
    uint64_t rbx_1 = arg2 - *arg1;
    sub_14001e570(arg1, rbx_1, 0, 1, arg3);
    return *arg1 + rbx_1;
}

int64_t sub_14001f4d0(int64_t* arg1, int64_t arg2, uint64_t arg3, char arg4)
{
    uint64_t rbx_1 = arg2 - *arg1;
    sub_14001e570(arg1, rbx_1, 0, arg3, arg4);
    return *arg1 + rbx_1;
}

int64_t* sub_14001f510(int64_t* arg1, int64_t arg2, char** arg3)
{
    uint64_t rdx = arg2 - *arg1;
    
    if (arg1[1] >= rdx)
        return sub_14001de90(arg1, rdx, 0, *arg3, arg3[1]);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f560(int64_t* arg1, uint64_t arg2, char* arg3)
{
    uint64_t rax = strlen(arg3);
    
    if (arg1[1] >= arg2)
        return sub_14001de90(arg1, arg2, 0, arg3, rax);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f5c0(int64_t* arg1, uint64_t arg2, char* arg3, uint64_t arg4)
{
    if (arg1[1] >= arg2)
        return sub_14001de90(arg1, arg2, 0, arg3, arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f600(int64_t* arg1, uint64_t arg2, char** arg3)
{
    if (arg1[1] >= arg2)
        return sub_14001de90(arg1, arg2, 0, *arg3, arg3[1]);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001f640(int64_t* arg1, uint64_t arg2, int64_t* arg3, int64_t arg4, uint64_t arg5)
{
    int64_t r11 = arg3[1];
    uint64_t r10_1 = r11 - arg4;
    
    if (r10_1 > arg5)
        r10_1 = arg5;
    
    if (r11 < arg4)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::insert");
        /* no return */
    }
    
    if (arg1[1] >= arg2)
        /* tailcall */
        return sub_14001de90(arg1, arg2, 0, *arg3 + arg4, r10_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f6c0(int64_t* arg1, uint64_t arg2, uint64_t arg3, char arg4)
{
    if (arg1[1] >= arg2)
        return sub_14001e570(arg1, arg2, 0, arg3, arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "basic_string::insert");
    /* no return */
}

int64_t* sub_14001f700(int64_t* arg1, int64_t* arg2)
{
    *arg1 = *arg2 + arg2[1];
    return arg1;
}

int64_t sub_14001f710(int64_t* arg1, int64_t arg2)
{
    /* tailcall */
    return sub_14001f720(arg1, arg2, 0);
}

void sub_14001f720(int64_t* arg1, int64_t arg2, char arg3)
{
    uint64_t rdx = arg1[1];
    
    if (rdx < arg2)
    {
        sub_14001e570(arg1, rdx, 0, arg2 - rdx, arg3);
        return;
    }
    
    if (arg2 >= rdx)
        return;
    
    char* rax = *arg1;
    arg1[1] = arg2;
    rax[arg2] = 0;
}

int64_t sub_14001f770(int64_t* arg1, int64_t arg2)
{
    *arg1 = arg2;
}

void sub_14001f780(char* arg1, char* arg2, uint64_t arg3)
{
    if (arg3 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (arg3)
        /* tailcall */
        return memcpy(arg1, arg2, arg3);
}

void sub_14001f7a0(char* arg1, char* arg2, uint64_t arg3)
{
    if (arg3 == 1)
    {
        *arg1 = *arg2;
        return;
    }
    
    if (arg3)
        /* tailcall */
        return memmove(arg1, arg2, arg3);
}

int64_t sub_14001f7c0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r11 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r11 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r11 >= rdx)
        /* tailcall */
        return sub_14001de90(arg1, rdx, r8, arg4, arg5 - arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001f820(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r11 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r11 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r11 >= rdx)
        /* tailcall */
        return sub_14001de90(arg1, rdx, r8, arg4, arg5 - arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f880(int64_t* arg1, int64_t arg2, int64_t arg3, char** arg4)
{
    int64_t r10 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r10 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r10 >= rdx)
        return sub_14001de90(arg1, rdx, r8, *arg4, arg4[1]);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001f8e0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4)
{
    int64_t rbx_1 = arg3 - arg2;
    uint64_t rax = strlen(arg4);
    int64_t r9 = arg1[1];
    uint64_t rdx_1 = arg2 - *arg1;
    int64_t r8 = rbx_1;
    int64_t rcx_2 = r9 - rdx_1;
    
    if (rbx_1 > rcx_2)
        r8 = rcx_2;
    
    if (r9 >= rdx_1)
        return sub_14001de90(arg1, rdx_1, r8, arg4, rax);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001f950(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r11 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r11 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r11 >= rdx)
        /* tailcall */
        return sub_14001de90(arg1, rdx, r8, arg4, arg5 - arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001f9b0(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r10 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r10 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r10 >= rdx)
        /* tailcall */
        return sub_14001de90(arg1, rdx, r8, arg4, arg5);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001fa00(int64_t* arg1, int64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r11 = arg1[1];
    uint64_t rdx = arg2 - *arg1;
    int64_t r8 = arg3 - arg2;
    int64_t rax_2 = r11 - rdx;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r11 >= rdx)
        /* tailcall */
        return sub_14001de90(arg1, rdx, r8, arg4, arg5 - arg4);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001fa60(int64_t* arg1, int64_t arg2, int64_t arg3, char** arg4)
{
    int64_t r10 = arg1[1];
    int64_t r8 = arg3 - arg2;
    uint64_t rdx_2 = arg2 - *arg1;
    int64_t rax_2 = r10 - rdx_2;
    
    if (r8 > rax_2)
        r8 = rax_2;
    
    if (r10 >= rdx_2)
        return sub_14001de90(arg1, rdx_2, r8, *arg4, arg4[1]);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001fac0(int64_t* arg1, int64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    arg5 = arg5;
    /* tailcall */
    return sub_14001e570(arg1, arg2 - *arg1, arg3 - arg2, arg4, arg5);
}

int64_t* sub_14001fae0(int64_t* arg1, uint64_t arg2, int64_t arg3, char* arg4)
{
    uint64_t rax = strlen(arg4);
    int64_t r9 = arg1[1];
    int64_t r8 = arg3;
    int64_t rdx_1 = r9 - arg2;
    
    if (rdx_1 <= arg3)
        r8 = rdx_1;
    
    if (r9 >= arg2)
        return sub_14001de90(arg1, arg2, r8, arg4, rax);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001fb50(int64_t* arg1, uint64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t r10 = arg1[1];
    int64_t rax_1 = r10 - arg2;
    
    if (rax_1 <= arg3)
        arg3 = rax_1;
    
    if (r10 >= arg2)
        /* tailcall */
        return sub_14001de90(arg1, arg2, arg3, arg4, arg5);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t* sub_14001fba0(int64_t* arg1, uint64_t arg2, int64_t arg3, char** arg4)
{
    int64_t r10 = arg1[1];
    int64_t rax_1 = r10 - arg2;
    
    if (rax_1 <= arg3)
        arg3 = rax_1;
    
    if (r10 >= arg2)
        return sub_14001de90(arg1, arg2, arg3, *arg4, arg4[1]);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001fbf0(int64_t* arg1, uint64_t arg2, int64_t arg3, int64_t* arg4, uint64_t arg5, uint64_t arg6)
{
    int64_t rbx = arg4[1];
    uint64_t r10 = arg6;
    uint64_t rax_1 = rbx - arg5;
    
    if (rax_1 <= r10)
        r10 = rax_1;
    
    if (rbx < arg5)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::replace");
        /* no return */
    }
    
    int64_t r11_1 = arg1[1];
    int64_t rax_3 = r11_1 - arg2;
    
    if (rax_3 <= arg3)
        arg3 = rax_3;
    
    if (r11_1 >= arg2)
        /* tailcall */
        return sub_14001de90(arg1, arg2, arg3, *arg4 + arg5, r10);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::replace");
    /* no return */
}

int64_t sub_14001fc80(int64_t* arg1, uint64_t arg2, int64_t arg3, uint64_t arg4, char arg5)
{
    int64_t r10 = arg1[1];
    int64_t rax_1 = r10 - arg2;
    
    if (rax_1 <= arg3)
        arg3 = rax_1;
    
    if (r10 < arg2)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::replace");
        /* no return */
    }
    
    arg5 = arg5;
    /* tailcall */
    return sub_14001e570(arg1, arg2, arg3, arg4, arg5);
}

void sub_14001fcd0(int64_t* arg1)
{
    char* rcx = *arg1;
    
    if (&arg1[2] == rcx)
        return;
    
    int64_t rsi_1 = arg1[1];
    
    if (rsi_1 <= 0xf)
    {
        if (!rsi_1)
            arg1[2] = *rcx;
        else if (rsi_1 + 1 >= 8)
        {
            arg1[2] = *rcx;
            uint64_t rdx_4 = rsi_1 + 1;
            *(&arg1[2] + rdx_4 - 8) = *(rcx + rdx_4 - 8);
            void* rdx_6 = &arg1[3] & 0xfffffffffffffff8;
            void* r8_4 = &arg1[2] - rdx_6;
            int32_t rax_5 = (rsi_1 + 1 + r8_4) & 0xfffffff8;
            
            if (rax_5 >= 8)
            {
                int32_t i = 0;
                
                do
                {
                    uint64_t i_1 = i;
                    i += 8;
                    *(rdx_6 + i_1) = *(rcx - r8_4 + i_1);
                } while (i < (rax_5 & 0xfffffff8));
            }
        }
        else if ((rsi_1 + 1) & 4)
        {
            uint64_t rax_8 = rsi_1 + 1;
            arg1[2] = *rcx;
            *(&arg1[2] + rax_8 - 4) = *(rcx + rax_8 - 4);
        }
        else if (rsi_1 != 0xffffffff)
        {
            arg1[2] = *rcx;
            
            if ((rsi_1 + 1) & 2)
            {
                uint64_t rax_9 = rsi_1 + 1;
                *(&arg1[2] + rax_9 - 2) = *(rcx + rax_9 - 2);
            }
        }
        
        sub_140021540(rcx);
        *arg1 = &arg1[2];
    }
    else if (rsi_1 < arg1[2])
    {
        if (rsi_1 + 1 < 0)
        {
            sub_140021e00();
            /* no return */
        }
        
        int64_t rax_2 = sub_140021560(rsi_1 + 1);
        int64_t r12 = *arg1;
        memcpy(rax_2, r12, rsi_1 + 1);
        
        if (&arg1[2] != r12)
            sub_140021540(r12);
        
        *arg1 = rax_2;
        arg1[2] = rsi_1;
    }
}

int64_t sub_14001fe35(int64_t arg1, int64_t arg2, void* arg3 @ rax, int64_t arg4, int64_t arg5, int64_t arg6, int64_t arg7, int64_t arg8, int64_t arg9)
{
    if (arg2 != 1)
    {
        sub_1400216b0(arg3);
        /* tailcall */
        return sub_140021850();
    }
    
    sub_1400216b0(arg3);
    sub_1400219e0();
    /* no return */
}

void sub_14001fe5f(void* arg1 @ rax) __noreturn
{
    sub_140021850();
    sub_14000f620(arg1);
    /* no return */
}

void sub_14001fe70(int64_t* arg1, int64_t arg2)
{
    int64_t arg_10 = arg2;
    int64_t r8;
    
    if (&arg1[2] == *arg1)
        r8 = 0xf;
    else
        r8 = arg1[2];
    
    if (r8 >= arg_10)
        return;
    
    char* rax = sub_1400200f0(arg1, &arg_10, r8);
    char* rcx_1 = *arg1;
    int64_t rax_1 = arg1[1];
    
    if (!rax_1)
    {
        *rax = *rcx_1;
    label_14001feeb:
        rcx_1 = *arg1;
        
        if (&arg1[2] != rcx_1)
            sub_140021540(rcx_1);
    }
    else
    {
        if (rax_1 != -1)
        {
            memcpy(rax, rcx_1, rax_1 + 1);
            goto label_14001feeb;
        }
        
        sub_140021540(rcx_1);
    }
    
    int64_t rax_2 = arg_10;
    *arg1 = rax;
    arg1[2] = rax_2;
}

int64_t sub_14001ff10(int64_t* arg1, void* arg2, int64_t arg3)
{
    int64_t rax = arg1[1];
    void* r9 = arg2 + arg3;
    uint64_t _Size = rax - r9;
    
    if (rax != r9 && arg3)
    {
        void* rcx = *arg1;
        char* r9_1 = r9 + rcx;
        char* rcx_1 = rcx + arg2;
        
        if (_Size == 1)
        {
            *rcx_1 = *r9_1;
            rax = arg1[1];
        }
        else
        {
            memmove(rcx_1, r9_1, _Size);
            rax = arg1[1];
        }
    }
    
    char* rdx_1 = *arg1;
    int64_t result = rax - arg3;
    arg1[1] = result;
    rdx_1[result] = 0;
    return result;
}

int64_t sub_14001ff80(int64_t* arg1)
{
    return sub_14001ff10(arg1, arg1[1] - 1, 1);
}

int64_t* sub_14001ffa0(int64_t* arg1, char* arg2, uint64_t arg3)
{
    uint64_t rax = arg1[1];
    char* rcx = *arg1;
    uint64_t rsi = arg3 + rax;
    int64_t r9_1;
    
    if (rcx == &arg1[2])
        r9_1 = 0xf;
    else
        r9_1 = arg1[2];
    
    if (r9_1 < rsi)
    {
        sub_140020170(arg1, rax, 0, arg2, arg3);
        rcx = *arg1;
    }
    else if (arg3)
    {
        void* rcx_1 = &rcx[rax];
        
        if (arg3 == 1)
        {
            *rcx_1 = *arg2;
            rcx = *arg1;
        }
        else
        {
            memcpy(rcx_1, arg2, arg3);
            rcx = *arg1;
        }
    }
    
    arg1[1] = rsi;
    rcx[rsi] = 0;
    return arg1;
}

void sub_140020030(int64_t* arg1, int64_t* arg2)
{
    if (arg1 == arg2)
        return;
    
    char* rbp_1 = *arg1;
    uint64_t _Size = arg2[1];
    int64_t r8_1;
    
    if (&arg1[2] == rbp_1)
        r8_1 = 0xf;
    else
        r8_1 = arg1[2];
    
    if (r8_1 < _Size)
    {
        uint64_t _Size_1 = _Size;
        char* rax_1 = sub_1400200f0(arg1, &_Size_1, r8_1);
        int64_t rcx_1 = *arg1;
        rbp_1 = rax_1;
        
        if (&arg1[2] != rcx_1)
            sub_140021540(rcx_1);
        
        uint64_t _Size_2 = _Size_1;
        *arg1 = rbp_1;
        arg1[2] = _Size_2;
        goto label_1400200ae;
    }
    
    if (_Size)
    {
    label_1400200ae:
        char* rdx_1 = *arg2;
        
        if (_Size == 1)
        {
            *rbp_1 = *rdx_1;
            rbp_1 = *arg1;
        }
        else
        {
            memcpy(rbp_1, rdx_1, _Size);
            rbp_1 = *arg1;
        }
    }
    
    arg1[1] = _Size;
    rbp_1[_Size] = 0;
}

int64_t sub_1400200f0(int64_t arg1, int64_t* arg2, int64_t arg3)
{
    int64_t rax = *arg2;
    
    if (0x3fffffffffffffff < rax)
    {
        sub_140021ff0("basic_string::_M_create");
        /* no return */
    }
    
    uint64_t r9 = rax + 1;
    
    if (arg3 < rax)
    {
        int64_t r8 = arg3 * 2;
        
        if (rax < r8)
        {
            if (0x3fffffffffffffff >= r8)
            {
                *arg2 = r8;
                /* tailcall */
                return sub_140021560(r8 + 1);
            }
            
            r9 = 0x4000000000000000;
            *arg2 = 0x3fffffffffffffff;
        }
    }
    
    /* tailcall */
    return sub_140021560(r9);
}

int64_t sub_140020160(void* arg1, int64_t arg2)
{
    *(arg1 + 8) = arg2;
}

int64_t sub_140020170(int64_t* arg1, uint64_t arg2, int64_t arg3, char* arg4, uint64_t arg5)
{
    int64_t rdx = arg1[1];
    int64_t r15 = arg2 + arg3;
    int64_t result_1 = arg5 - arg3 + rdx;
    uint64_t _Size = rdx - r15;
    int64_t r8;
    
    if (&arg1[2] == *arg1)
        r8 = 0xf;
    else
        r8 = arg1[2];
    
    char* rax_3 = sub_1400200f0(arg1, &result_1, r8);
    
    if (arg2)
    {
        char* rdx_2 = *arg1;
        
        if (arg2 == 1)
            *rax_3 = *rdx_2;
        else
            memcpy(rax_3, rdx_2, arg2);
    }
    
    if (arg4 && arg5)
    {
        void* rcx_2 = &rax_3[arg2];
        
        if (arg5 == 1)
            *rcx_2 = *arg4;
        else
            memcpy(rcx_2, arg4, arg5);
    }
    
    if (_Size)
    {
        char* r15_1 = r15 + *arg1;
        void* rcx_4 = &rax_3[arg2 + arg5];
        
        if (_Size == 1)
            *rcx_4 = *r15_1;
        else
            memcpy(rcx_4, r15_1, _Size);
    }
    
    int64_t rcx_5 = *arg1;
    
    if (&arg1[2] != rcx_5)
        sub_140021540(rcx_5);
    
    int64_t result = result_1;
    *arg1 = rax_3;
    arg1[2] = result;
    return result;
}

void sub_1400202a0(char* arg1, uint64_t arg2, char arg3)
{
    if (arg2 == 1)
    {
        *arg1 = arg3;
        return;
    }
    
    if (arg2)
        /* tailcall */
        return memset(arg1, arg3, arg2);
}

int64_t sub_1400202d0(int64_t* arg1, char arg2)
{
    uint64_t rsi = arg1[1];
    int64_t rax = *arg1;
    int64_t rdx_1;
    
    if (rax == &arg1[2])
        rdx_1 = 0xf;
    else
        rdx_1 = arg1[2];
    
    if (rdx_1 < rsi + 1)
    {
        sub_140020170(arg1, rsi, 0, nullptr, 1);
        rax = *arg1;
    }
    
    *(rax + rsi) = arg2;
    int64_t result = *arg1;
    arg1[1] = rsi + 1;
    *(result + rsi + 1) = 0;
    return result;
}

int64_t* sub_140020350(int64_t* arg1, int64_t* arg2)
{
    *arg1 = &arg1[2];
    int64_t rdx = *arg2;
    int64_t rdx_2;
    
    if (&arg2[2] == rdx)
    {
        rdx_2 = arg2[1];
        
        if (rdx_2 + 1 >= 8)
        {
            arg1[2] = arg2[2];
            uint64_t rdx_6 = rdx_2 + 1;
            *(&arg1[2] + rdx_6 - 8) = *(&arg2[2] + rdx_6 - 8);
            void* rdx_8 = &arg1[3] & 0xfffffffffffffff8;
            void* rcx_1 = &arg1[2] - rdx_8;
            int32_t r10_4 = (rdx_2 + 1 + rcx_1) & 0xfffffff8;
            
            if (r10_4 >= 8)
            {
                int32_t i = 0;
                
                do
                {
                    uint64_t i_1 = i;
                    i += 8;
                    *(rdx_8 + i_1) = *(&arg2[2] - rcx_1 + i_1);
                } while (i < (r10_4 & 0xfffffff8));
            }
            
            rdx_2 = arg2[1];
        }
        else if ((rdx_2 + 1) & 4)
        {
            uint64_t r10_6 = rdx_2 + 1;
            arg1[2] = arg2[2];
            *(&arg1[2] + r10_6 - 4) = *(&arg2[2] + r10_6 - 4);
            rdx_2 = arg2[1];
        }
        else if (rdx_2 != 0xffffffff)
        {
            arg1[2] = arg2[2];
            
            if (!((rdx_2 + 1) & 2))
                rdx_2 = arg2[1];
            else
            {
                uint64_t r10_2 = rdx_2 + 1;
                *(&arg1[2] + r10_2 - 2) = *(&arg2[2] + r10_2 - 2);
                rdx_2 = arg2[1];
            }
        }
    }
    else
    {
        *arg1 = rdx;
        arg1[2] = arg2[2];
        rdx_2 = arg2[1];
    }
    
    arg1[1] = rdx_2;
    *arg2 = &arg2[2];
    arg2[1] = 0;
    arg2[2] = 0;
    return arg2;
}

int64_t* sub_140020450(int64_t* arg1, int64_t* arg2)
{
    *arg1 = &arg1[2];
    char* rcx = *arg2;
    uint128_t zmm0 = arg2[1];
    
    if (&arg2[2] != rcx)
    {
        zmm0 = zmm0 | arg2[2] << 0x40;
        *arg1 = rcx;
        *arg2 = &arg2[2];
        arg2[1] = 0;
        arg2[2] = 0;
        *(arg1 + 8) = zmm0;
        return arg2;
    }
    
    if (zmm0 + 1 >= 8)
    {
        arg1[2] = arg2[2];
        uint64_t rcx_2 = zmm0 + 1;
        *(&arg1[2] + rcx_2 - 8) = *(&arg2[2] + rcx_2 - 8);
        void* rcx_4 = &arg1[3] & 0xfffffffffffffff8;
        void* r8_1 = &arg1[2] - rcx_4;
        int32_t r10_3 = (zmm0 + 1 + r8_1) & 0xfffffff8;
        
        if (r10_3 >= 8)
        {
            int32_t i = 0;
            
            do
            {
                uint64_t i_1 = i;
                i += 8;
                *(rcx_4 + i_1) = *(&arg2[2] - r8_1 + i_1);
            } while (i < (r10_3 & 0xfffffff8));
        }
        
        rcx = *arg2;
        zmm0 = arg2[1];
    }
    else if ((zmm0 + 1) & 4)
    {
        uint64_t r10_5 = zmm0 + 1;
        arg1[2] = arg2[2];
        *(&arg1[2] + r10_5 - 4) = *(rcx + r10_5 - 4);
        rcx = *arg2;
        zmm0 = arg2[1];
    }
    else if (zmm0 != 0xffffffff)
    {
        arg1[2] = arg2[2];
        
        if (!((zmm0 + 1) & 2))
        {
            rcx = *arg2;
            zmm0 = arg2[1];
        }
        else
        {
            uint64_t r10_1 = zmm0 + 1;
            *(&arg1[2] + r10_1 - 2) = *(rcx + r10_1 - 2);
            rcx = *arg2;
            zmm0 = arg2[1];
        }
    }
    
    arg2[1] = 0;
    arg1[1] = zmm0;
    *rcx = 0;
    return arg2;
}

int64_t sub_140020570(int64_t* arg1, char* arg2)
{
    char* rbx = arg2;
    *arg1 = &arg1[2];
    
    if (arg2)
        /* tailcall */
        return sub_14001e240(arg1, rbx, &rbx[strlen(arg2)]);
    
    sub_140021f00("basic_string: construction from null is not valid");
    /* no return */
}

int64_t sub_1400205c0(int64_t* arg1, char* arg2, void* arg3)
{
    *arg1 = &arg1[2];
    
    if (arg2 || !arg3)
        /* tailcall */
        return sub_14001e240(arg1, arg2, arg3 + arg2);
    
    sub_140021f00("basic_string: construction from null is not valid");
    /* no return */
}

void* sub_140020600(int64_t* arg1)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    return &arg1[2];
}

int64_t sub_140020620(int64_t* arg1, int64_t* arg2)
{
    void* r8 = arg2[1];
    *arg1 = &arg1[2];
    char* rax_1 = *arg2;
    /* tailcall */
    return sub_14001e420(arg1, rax_1, r8 + rax_1);
}

int64_t sub_140020640(int64_t* arg1, int64_t* arg2)
{
    void* r8 = arg2[1];
    *arg1 = &arg1[2];
    char* rax_1 = *arg2;
    /* tailcall */
    return sub_14001e100(arg1, rax_1, r8 + rax_1);
}

int64_t sub_140020660(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    void* r10 = *arg2;
    
    if (rax_1 >= arg3)
        /* tailcall */
        return sub_14001e240(arg1, r10 + arg3, r10 + rax_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::basic_string");
    /* no return */
}

int64_t sub_1400206b0(int64_t* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    
    if (rax_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    int64_t rax_2 = rax_1 - arg3;
    char* rdx = *arg2 + arg3;
    
    if (rax_2 > arg4)
        rax_2 = arg4;
    
    /* tailcall */
    return sub_14001e240(arg1, rdx, &rdx[rax_2]);
}

int64_t sub_140020700(int64_t* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    
    if (rax_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "string::string");
        /* no return */
    }
    
    int64_t rax_2 = rax_1 - arg3;
    char* rdx = *arg2 + arg3;
    
    if (rax_2 > arg4)
        rax_2 = arg4;
    
    /* tailcall */
    return sub_14001e240(arg1, rdx, &rdx[rax_2]);
}

int64_t sub_140020750(int64_t* arg1, int64_t* arg2)
{
    char* rax = *arg2;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e240(arg1, rax, &rax[arg2[1]]);
}

void* sub_140020770(int64_t* arg1)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    return &arg1[2];
}

int64_t sub_140020790(int64_t* arg1, uint64_t arg2, char arg3)
{
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e070(arg1, arg2, arg3);
}

int64_t sub_1400207a0(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e1a0(arg1, arg2, arg3);
}

int64_t sub_1400207c0(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e240(arg1, arg2, arg3);
}

int64_t sub_1400207e0(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e420(arg1, arg2, arg3);
}

int64_t* sub_140020800(int64_t* arg1, int64_t* arg2)
{
    *arg1 = &arg1[2];
    int64_t rdx = *arg2;
    int64_t rdx_2;
    
    if (&arg2[2] == rdx)
    {
        rdx_2 = arg2[1];
        
        if (rdx_2 + 1 >= 8)
        {
            arg1[2] = arg2[2];
            uint64_t rdx_6 = rdx_2 + 1;
            *(&arg1[2] + rdx_6 - 8) = *(&arg2[2] + rdx_6 - 8);
            void* rdx_8 = &arg1[3] & 0xfffffffffffffff8;
            void* rcx_1 = &arg1[2] - rdx_8;
            int32_t r10_4 = (rdx_2 + 1 + rcx_1) & 0xfffffff8;
            
            if (r10_4 >= 8)
            {
                int32_t i = 0;
                
                do
                {
                    uint64_t i_1 = i;
                    i += 8;
                    *(rdx_8 + i_1) = *(&arg2[2] - rcx_1 + i_1);
                } while (i < (r10_4 & 0xfffffff8));
            }
            
            rdx_2 = arg2[1];
        }
        else if ((rdx_2 + 1) & 4)
        {
            uint64_t r10_6 = rdx_2 + 1;
            arg1[2] = arg2[2];
            *(&arg1[2] + r10_6 - 4) = *(&arg2[2] + r10_6 - 4);
            rdx_2 = arg2[1];
        }
        else if (rdx_2 != 0xffffffff)
        {
            arg1[2] = arg2[2];
            
            if (!((rdx_2 + 1) & 2))
                rdx_2 = arg2[1];
            else
            {
                uint64_t r10_2 = rdx_2 + 1;
                *(&arg1[2] + r10_2 - 2) = *(&arg2[2] + r10_2 - 2);
                rdx_2 = arg2[1];
            }
        }
    }
    else
    {
        *arg1 = rdx;
        arg1[2] = arg2[2];
        rdx_2 = arg2[1];
    }
    
    arg1[1] = rdx_2;
    *arg2 = &arg2[2];
    arg2[1] = 0;
    arg2[2] = 0;
    return arg2;
}

int64_t* sub_140020900(int64_t* arg1, int64_t* arg2)
{
    *arg1 = &arg1[2];
    char* rcx = *arg2;
    uint128_t zmm0 = arg2[1];
    
    if (&arg2[2] != rcx)
    {
        zmm0 = zmm0 | arg2[2] << 0x40;
        *arg1 = rcx;
        *arg2 = &arg2[2];
        arg2[1] = 0;
        arg2[2] = 0;
        *(arg1 + 8) = zmm0;
        return arg2;
    }
    
    if (zmm0 + 1 >= 8)
    {
        arg1[2] = arg2[2];
        uint64_t rcx_2 = zmm0 + 1;
        *(&arg1[2] + rcx_2 - 8) = *(&arg2[2] + rcx_2 - 8);
        void* rcx_4 = &arg1[3] & 0xfffffffffffffff8;
        void* r8_1 = &arg1[2] - rcx_4;
        int32_t r10_3 = (zmm0 + 1 + r8_1) & 0xfffffff8;
        
        if (r10_3 >= 8)
        {
            int32_t i = 0;
            
            do
            {
                uint64_t i_1 = i;
                i += 8;
                *(rcx_4 + i_1) = *(&arg2[2] - r8_1 + i_1);
            } while (i < (r10_3 & 0xfffffff8));
        }
        
        rcx = *arg2;
        zmm0 = arg2[1];
    }
    else if ((zmm0 + 1) & 4)
    {
        uint64_t r10_5 = zmm0 + 1;
        arg1[2] = arg2[2];
        *(&arg1[2] + r10_5 - 4) = *(rcx + r10_5 - 4);
        rcx = *arg2;
        zmm0 = arg2[1];
    }
    else if (zmm0 != 0xffffffff)
    {
        arg1[2] = arg2[2];
        
        if (!((zmm0 + 1) & 2))
        {
            rcx = *arg2;
            zmm0 = arg2[1];
        }
        else
        {
            uint64_t r10_1 = zmm0 + 1;
            *(&arg1[2] + r10_1 - 2) = *(rcx + r10_1 - 2);
            rcx = *arg2;
            zmm0 = arg2[1];
        }
    }
    
    arg2[1] = 0;
    arg1[1] = zmm0;
    *rcx = 0;
    return arg2;
}

int64_t sub_140020a20(int64_t* arg1, char* arg2)
{
    char* rbx = arg2;
    *arg1 = &arg1[2];
    
    if (arg2)
        /* tailcall */
        return sub_14001e240(arg1, rbx, &rbx[strlen(arg2)]);
    
    sub_140021f00("basic_string: construction from null is not valid");
    /* no return */
}

int64_t sub_140020a70(int64_t* arg1, char* arg2, void* arg3)
{
    *arg1 = &arg1[2];
    
    if (arg2 || !arg3)
        /* tailcall */
        return sub_14001e240(arg1, arg2, arg3 + arg2);
    
    sub_140021f00("basic_string: construction from null is not valid");
    /* no return */
}

void* sub_140020ab0(int64_t* arg1)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    return &arg1[2];
}

int64_t sub_140020ad0(int64_t* arg1, int64_t* arg2)
{
    void* r8 = arg2[1];
    *arg1 = &arg1[2];
    char* rax_1 = *arg2;
    /* tailcall */
    return sub_14001e420(arg1, rax_1, r8 + rax_1);
}

int64_t sub_140020af0(int64_t* arg1, int64_t* arg2)
{
    void* r8 = arg2[1];
    *arg1 = &arg1[2];
    char* rax_1 = *arg2;
    /* tailcall */
    return sub_14001e100(arg1, rax_1, r8 + rax_1);
}

int64_t sub_140020b10(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    void* r10 = *arg2;
    
    if (rax_1 >= arg3)
        /* tailcall */
        return sub_14001e240(arg1, r10 + arg3, r10 + rax_1);
    
    sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
        "basic_string::basic_string");
    /* no return */
}

int64_t sub_140020b60(int64_t* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    
    if (rax_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", 
            "basic_string::basic_string");
        /* no return */
    }
    
    int64_t rax_2 = rax_1 - arg3;
    char* rdx = *arg2 + arg3;
    
    if (rax_2 > arg4)
        rax_2 = arg4;
    
    /* tailcall */
    return sub_14001e240(arg1, rdx, &rdx[rax_2]);
}

int64_t sub_140020bb0(int64_t* arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    *arg1 = &arg1[2];
    int64_t rax_1 = arg2[1];
    
    if (rax_1 < arg3)
    {
        sub_140022090("%s: __pos (which is %zu) > this->size() (which is %zu)", "string::string");
        /* no return */
    }
    
    int64_t rax_2 = rax_1 - arg3;
    char* rdx = *arg2 + arg3;
    
    if (rax_2 > arg4)
        rax_2 = arg4;
    
    /* tailcall */
    return sub_14001e240(arg1, rdx, &rdx[rax_2]);
}

int64_t sub_140020c00(int64_t* arg1, int64_t* arg2)
{
    char* rax = *arg2;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e240(arg1, rax, &rax[arg2[1]]);
}

void* sub_140020c20(int64_t* arg1)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    return &arg1[2];
}

int64_t sub_140020c40(int64_t* arg1, uint64_t arg2, char arg3)
{
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e070(arg1, arg2, arg3);
}

int64_t sub_140020c50(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e1a0(arg1, arg2, arg3);
}

int64_t sub_140020c70(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e240(arg1, arg2, arg3);
}

int64_t sub_140020c90(int64_t* arg1, char* arg2, int64_t arg3)
{
    arg1[1] = 0;
    *arg1 = &arg1[2];
    /* tailcall */
    return sub_14001e420(arg1, arg2, arg3);
}

int64_t sub_140020cb0(int64_t* arg1)
{
    int64_t result = *arg1;
    
    if (result == &arg1[2])
        return result;
    
    /* tailcall */
    return sub_140021540(result);
}

int64_t sub_140020cd0(int64_t* arg1)
{
    int64_t result = *arg1;
    
    if (result == &arg1[2])
        return result;
    
    /* tailcall */
    return sub_140021540(result);
}

int64_t* sub_140020cf0(int64_t* arg1, int64_t* arg2)
{
    uint64_t _Size = arg2[1];
    void* rcx = *arg1;
    void* rdx = *arg2;
    
    if (rcx != &arg1[2])
    {
        if (&arg2[2] == rdx)
            goto label_140020d70;
        
        *arg1 = rdx;
        int64_t r9_1 = arg1[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        
        if (!rcx)
        {
            rcx = &arg2[2];
            *arg2 = rcx;
        }
        else
        {
            *arg2 = rcx;
            arg2[2] = r9_1;
        }
    }
    else if (&arg2[2] == rdx)
    {
    label_140020d70:
        
        if (arg1 == arg2)
            rcx = rdx;
        else
        {
            if (_Size)
            {
                if (_Size == 1)
                {
                    *rcx = *rdx;
                    rcx = *arg1;
                    _Size = arg2[1];
                }
                else
                {
                    memcpy(rcx, rdx, _Size);
                    rcx = *arg1;
                    _Size = arg2[1];
                }
            }
            
            arg1[1] = _Size;
            *(rcx + _Size) = 0;
            rcx = *arg2;
        }
    }
    else
    {
        *arg1 = rdx;
        rcx = &arg2[2];
        arg1[1] = _Size;
        arg1[2] = arg2[2];
        *arg2 = rcx;
    }
    
    arg2[1] = 0;
    *rcx = 0;
    return arg1;
}

int64_t* sub_140020dd0(int64_t* arg1, char* arg2)
{
    uint64_t rax = strlen(arg2);
    return sub_14001de90(arg1, 0, arg1[1], arg2, rax);
}

int64_t* sub_140020e10(int64_t* arg1, int64_t* arg2)
{
    sub_140020030(arg1, arg2);
    return arg1;
}

int64_t* sub_140020e30(int64_t* arg1, int64_t* arg2)
{
    sub_14001de90(arg1, 0, arg1[1], *arg2, arg2[1]);
    return arg1;
}

int64_t* sub_140020e60(int64_t* arg1, char arg2)
{
    sub_14001e570(arg1, 0, arg1[1], 1, arg2);
    return arg1;
}

int64_t sub_140020e90(int64_t* arg1, int64_t arg2)
{
    return *arg1 + arg2;
}

int64_t sub_140020ea0(int64_t* arg1, char* arg2)
{
    uint64_t rax = strlen(arg2);
    
    if (0x3fffffffffffffff - arg1[1] >= rax)
        /* tailcall */
        return sub_14001ffa0(arg1, arg2, rax);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_140020ef0(int64_t* arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    
    if (0x3fffffffffffffff - arg1[1] >= r8)
        /* tailcall */
        return sub_14001ffa0(arg1, *arg2, r8);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t sub_140020f30(int64_t* arg1, int64_t* arg2)
{
    uint64_t r8 = arg2[1];
    
    if (0x3fffffffffffffff - arg1[1] >= r8)
        /* tailcall */
        return sub_14001ffa0(arg1, *arg2, r8);
    
    sub_140021ff0("basic_string::append");
    /* no return */
}

int64_t* sub_140020f70(int64_t* arg1, char arg2)
{
    uint64_t rsi = arg1[1];
    int64_t rax = *arg1;
    int64_t rdx_1;
    
    if (rax == &arg1[2])
        rdx_1 = 0xf;
    else
        rdx_1 = arg1[2];
    
    if (rdx_1 < rsi + 1)
    {
        sub_140020170(arg1, rsi, 0, nullptr, 1);
        rax = *arg1;
    }
    
    *(rax + rsi) = arg2;
    int64_t rax_1 = *arg1;
    arg1[1] = rsi + 1;
    *(rax_1 + rsi + 1) = 0;
    return arg1;
}

int64_t sub_140020ff0(struct std::exception::std::bad_cast::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_cast{for `std::exception'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140021020(struct std::exception::std::bad_cast::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_cast{for `std::exception'};
    /* tailcall */
    return sub_140021080();
}

int64_t sub_140021030(struct std::exception::std::bad_alloc::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_alloc{for `std::exception'};
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140021060(struct std::exception::std::bad_alloc::VTable** arg1)
{
    *arg1 = &_vtable_for_std::bad_alloc{for `std::exception'};
    /* tailcall */
    return sub_140021080();
}

int64_t sub_140021070(int64_t arg1)
{
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_140021080() __pure
{
    return;
}

int64_t sub_140021090(int64_t arg1)
{
    /* tailcall */
    return sub_140021550(arg1);
}

int64_t sub_1400210a0() __pure
{
    return;
}

void* sub_1400210b0()
{
    return data_140023170;
}

void* sub_1400210c0(void* arg1)
{
    void* rax = arg1;
    
    if (!arg1)
        rax = sub_140016720;
    
    void* result = data_140023170;
    data_140023170 = rax;
    return result;
}

void* sub_1400210e0()
{
    return data_140023180;
}

void* sub_1400210f0(void* arg1)
{
    void* rax = arg1;
    
    if (!arg1)
        rax = sub_140021b00;
    
    void* result = data_140023180;
    data_140023180 = rax;
    return result;
}

int64_t sub_140021110()
{
    return data_140023190;
}

int64_t sub_140021120(int64_t arg1)
{
    int64_t result = data_140023190;
    data_140023190 = arg1;
    return result;
}

int64_t _get_terminate()
{
    int32_t result;
    result = *(sub_140021960() + 8);
    return result;
}

uint64_t _statfp()
{
    return *(sub_140021960() + 8);
}

void** sub_140021170(void** arg1, char* arg2, int64_t* arg3)
{
    uint64_t rbp = arg3[1];
    char* r12 = *arg3;
    uint64_t rax = strlen(arg2);
    arg1[1] = 0;
    arg1[2] = 0;
    *arg1 = &arg1[2];
    sub_14001fe70(arg1, rbp + rax);
    
    if (0x3fffffffffffffff - arg1[1] < rax)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, arg2, rax);
    
    if (0x3fffffffffffffff - arg1[1] < rbp)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, r12, rbp);
    return arg1;
}

void sub_140021202(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

int64_t* sub_140021230(int64_t* arg1, int64_t* arg2, int64_t* arg3)
{
    uint64_t rsi = arg3[1];
    uint64_t rdi = arg2[1];
    char* r12 = *arg2;
    char* rbp = *arg3;
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    sub_14001fe70(arg1, rsi + rdi);
    
    if (0x3fffffffffffffff - arg1[1] < rdi)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, r12, rdi);
    
    if (0x3fffffffffffffff - arg1[1] < rsi)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, rbp, rsi);
    return arg1;
}

void sub_1400212b7(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

int64_t* sub_1400212f0(int64_t* arg1, char arg2, int64_t* arg3)
{
    uint64_t rsi = arg3[1];
    char* rdi = *arg3;
    arg1[1] = 0;
    *arg1 = &arg1[2];
    arg1[2] = 0;
    char arg_10 = arg2;
    sub_14001fe70(arg1, rsi + 1);
    
    if (arg1[1] == 0x3fffffffffffffff)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, &arg_10, 1);
    
    if (0x3fffffffffffffff - arg1[1] < rsi)
    {
        sub_140021ff0("basic_string::append");
        /* no return */
    }
    
    sub_14001ffa0(arg1, rdi, rsi);
    return arg1;
}

void sub_140021370(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_14001de70(arg2);
    sub_14000f620(arg1);
    /* no return */
}

void** sub_1400213a0(void** arg1, void* arg2, int64_t* arg3)
{
    void* rbp = *arg3;
    uint64_t r12 = *(rbp - 0x18);
    uint64_t rax = strlen(arg2);
    *arg1 = sub_140019500(0, 0);
    sub_14001ad40(arg1, r12 + rax);
    sub_140019dc0(arg1, arg2, rax);
    sub_140019dc0(arg1, rbp, r12);
    return arg1;
}

void sub_140021410(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_1400199d0(*arg2 - 0x18);
    sub_14000f620(arg1);
    /* no return */
}

void** sub_140021430(void** arg1, int64_t* arg2, int64_t* arg3)
{
    void* rsi = *arg3;
    void* rbp = *arg2;
    uint64_t rdi = *(rsi - 0x18);
    uint64_t r12 = *(rbp - 0x18);
    *arg1 = sub_140019500(0, 0);
    sub_14001ad40(arg1, rdi + r12);
    sub_140019dc0(arg1, rbp, r12);
    sub_140019dc0(arg1, rsi, rdi);
    return arg1;
}

void sub_140021499(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_1400199d0(*arg2 - 0x18);
    sub_14000f620(arg1);
    /* no return */
}

void** sub_1400214c0(void** arg1, char arg2, int64_t* arg3)
{
    void* rsi = *arg3;
    uint64_t rdi = *(rsi - 0x18);
    char arg_10 = arg2;
    *arg1 = sub_140019500(0, 0);
    sub_14001ad40(arg1, rdi + 1);
    sub_140019dc0(arg1, &arg_10, 1);
    sub_140019dc0(arg1, rsi, rdi);
    return arg1;
}

void sub_140021523(void* arg1 @ rax, int64_t* arg2 @ rbx) __noreturn
{
    sub_1400199d0(*arg2 - 0x18);
    sub_14000f620(arg1);
    /* no return */
}

void sub_140021540(void* _Block)
{
    /* tailcall */
    return free(_Block);
}

void sub_140021550(void* _Block)
{
    /* tailcall */
    return sub_140021540(_Block);
}

int64_t sub_140021560(uint64_t arg1)
{
    uint64_t _Size = 1;
    
    if (arg1)
        _Size = arg1;
    
    while (true)
    {
        int64_t result = malloc(_Size);
        
        if (result)
            return result;
        
        int64_t rax = sub_140021110();
        
        if (!rax)
            break;
        
        rax();
    }
    
    void* rax_1 = sub_140021640(8);
    *rax_1 = &_vtable_for_std::bad_alloc{for `std::exception'};
    sub_140021a30(rax_1, &_typeinfo_for_std::bad_alloc, sub_140021060);
    /* no return */
}

int64_t* sub_1400215d0()
{
    int64_t* result_1 = malloc(0x90);
    int64_t* result = result_1;
    
    if (!result_1)
    {
        int64_t* result_2 = sub_140016360(0x90);
        result = result_2;
        
        if (!result_2)
        {
            sub_140021b00();
            /* no return */
        }
    }
    
    *result = 0;
    result[0x11] = 0;
    void* rdi_1 = &result[1] & 0xfffffffffffffff8;
    __builtin_memset(rdi_1, 0, (result - rdi_1 + 0x90) >> 3 << 3);
    return result;
}

void* sub_140021640(int64_t arg1)
{
    int64_t* rax = malloc(arg1 + 0xa0);
    
    if (!rax)
    {
        rax = sub_140016360(arg1 + 0xa0);
        
        if (!rax)
        {
            sub_140021b00();
            /* no return */
        }
    }
    
    *rax = 0;
    rax[0x13] = 0;
    void* rdi_2 = &rax[1] & 0xfffffffffffffff8;
    __builtin_memset(rdi_2, 0, (rax - rdi_2 + 0xa0) >> 3 << 3);
    return &rax[0x14];
}

int64_t sub_1400216b0(void* arg1)
{
    int64_t* rax = sub_140021960();
    int64_t result = *rax;
    
    if (-0x474e5543432b2b00 + *arg1 > 1)
    {
        if (result)
        {
            sub_140021b00();
            /* no return */
        }
        
        *rax = arg1 - 0x50;
        return result;
    }
    
    int32_t r9 = *(arg1 - 0x28);
    int32_t rcx_1 = r9 + 1;
    
    if (r9 < 0)
        rcx_1 = 1 - r9;
    
    *(arg1 - 0x28) = rcx_1;
    rax[1] -= 1;
    
    if (result != arg1 - 0x50)
    {
        *(arg1 - 0x30) = result;
        *rax = arg1 - 0x50;
    }
    
    return *(arg1 - 8);
}

void sub_140021730(void* arg1) __noreturn
{
    sub_1400216b0(arg1);
    *(arg1 - 0x18);
    *(arg1 - 0x24);
    int64_t var_48 = *(arg1 - 0x10);
    *(arg1 - 0x38);
    sub_140015960(*(arg1 - 0x40));
    /* no return */
}

void** sub_140021820()
{
    void** result = *sub_140021960();
    
    if (!result)
        return result;
    
    if (result[0xa] & 1)
        result = *result - 0x90;
    
    return *result;
}

int64_t* sub_140021850()
{
    int64_t* result = sub_140021970();
    void* rcx = *result;
    
    if (rcx)
    {
        int64_t rdx_1 = -0x474e5543432b2b00 + *(rcx + 0x50);
        
        if (rdx_1 > 1)
        {
            *result = 0;
            /* tailcall */
            return sub_14000f780(rcx + 0x50, rdx_1);
        }
        
        int32_t rdx_2 = *(rcx + 0x28);
        int32_t rdx_3;
        
        if (rdx_2 < 0)
        {
            rdx_3 = rdx_2 + 1;
            
            if (rdx_2 == 0xffffffff)
                *result = *(rcx + 0x20);
        }
        else
        {
            rdx_3 = rdx_2 - 1;
            
            if (rdx_2 == 1)
            {
                int64_t rdx_5 = *(rcx + 0x20);
                *result = rdx_5;
                /* tailcall */
                return sub_14000f780(rcx + 0x50, rdx_5);
            }
            
            if (rdx_3 == 0xffffffff)
            {
                sub_140021b00();
                /* no return */
            }
        }
        
        *(rcx + 0x28) = rdx_3;
    }
    
    return result;
}

int64_t sub_1400218e0(void* arg1)
{
    int64_t rax_2 = data_1400231d0;
    
    if (arg1 < data_1400231d8 + rax_2 && rax_2 < arg1)
        /* tailcall */
        return sub_1400161c0(arg1);
    
    /* tailcall */
    return free(arg1);
}

int64_t sub_140021910(int64_t arg1)
{
    int64_t rax_2 = data_1400231d0;
    
    if (arg1 - 0xa0 < data_1400231d8 + rax_2 && rax_2 < arg1 - 0xa0)
        /* tailcall */
        return sub_1400161c0(arg1 - 0xa0);
    
    /* tailcall */
    return free(arg1 - 0xa0);
}

int64_t sub_140021950(void* arg1)
{
    return *(arg1 - 8);
}

int64_t sub_140021960()
{
    /* tailcall */
    return sub_14000fa30(&data_140023240);
}

int64_t sub_140021970()
{
    /* tailcall */
    return sub_14000fa30(&data_140023240);
}

void* sub_140021980(void* arg1, int64_t arg2, int64_t arg3)
{
    *(arg1 - 0xa0) = 0;
    *(arg1 - 0x90) = arg2;
    *(arg1 - 0x88) = arg3;
    *(arg1 - 0x80) = sub_1400210e0();
    *(arg1 - 0x78) = sub_1400210b0();
    *(arg1 - 0x40) = 0x474e5543432b2b00;
    *(arg1 - 0x38) = sub_140015770;
    return arg1 - 0xa0;
}

void sub_1400219e0() __noreturn
{
    int64_t* rax = sub_140021960();
    void* rcx = *rax;
    rax[1] += 1;
    
    if (!rcx)
    {
        sub_140021b00();
        /* no return */
    }
    
    if (-0x474e5543432b2b00 + *(rcx + 0x50) <= 1)
        *(rcx + 0x28) = -(*(rcx + 0x28));
    else
        *rax = 0;
    
    sub_14000f700(rcx + 0x50);
    /* no return */
}

void sub_140021a30(void* arg1, int64_t arg2, int64_t arg3) __noreturn
{
    void* rax = sub_140021960();
    *(rax + 8) += 1;
    void* rax_1 = sub_140021980(arg1, arg2, arg3);
    *rax_1 = 1;
    sub_14000f5e0(rax_1 + 0x60);
    /* no return */
}

int64_t sub_140021a80(int32_t* arg1, int64_t arg2, CONTEXT* arg3, void* arg4)
{
    sub_14000f3b0(arg1, arg2, arg3, arg4, sub_140015a40);
    return 1;
}

int64_t sub_140021aa0()
{
    int32_t result = data_140023080;
    
    if (result)
        return DeleteCriticalSection(&data_1400231a0);
    
    return result;
}

int64_t sub_140021ae0() __pure
{
    return;
}

int64_t sub_140021af0() __pure
{
    return;
}

void sub_140021b00() __noreturn
{
    sub_140015940(data_140023170);
    /* no return */
}

void sub_140021b20() __noreturn
{
    sub_140015960(data_140023180);
    /* no return */
}

void sub_140021b40(int64_t arg1, int64_t arg2, int64_t arg3, void* arg4 @ rbx) __noreturn
{
    *(arg4 + 0x18) = arg2;
    void arg_20;
    sub_140002f60(&arg_20, &data_140024478, arg3);
    *0x10;
    trap(6);
}

void sub_140021b60()
{
    int64_t rcx = data_1400231d0;
    
    if (rcx)
    {
        free(rcx);
        data_1400231d0 = 0;
    }
}

int64_t sub_140021b90()
{
    if (data_140023080)
        InitializeCriticalSection(&data_1400231a0);
    
    __builtin_memset(&data_1400231c8, 0, 0x18);
    int32_t var_58 = 0;
    char* i_1 = getenv("GLIBCXX_TUNABLES");
    int64_t var_68 = 8;
    char const* const var_60 = "obj_size";
    int64_t var_50 = 9;
    char const* const var_48 = "obj_count";
    int32_t var_40 = 0x100;
    uint64_t _Size;
    
    if (i_1)
    {
        char* i;
        
        do
        {
            int64_t rax_1;
            rax_1 = *i_1 == 0x3a;
            void* _EndPtr_1 = &i_1[rax_1];
            
            if (*_EndPtr_1 == 0x2e78786362696c67 && *(_EndPtr_1 + 7) == 0x6c6f6f705f68652e
                && *(_EndPtr_1 + 0xf) == 0x2e)
            {
                _EndPtr_1 += 0x10;
                void* j = &var_68;
                void var_38;
                
                do
                {
                    uint64_t _Size_1 = *j;
                    int32_t rax_2;
                    
                    if (_Size_1)
                        rax_2 = memcmp(*(j + 8), _EndPtr_1, _Size_1);
                    
                    if ((!_Size_1 || !rax_2) && *(_EndPtr_1 + _Size_1) == 0x3d)
                    {
                        char* _EndPtr;
                        uint32_t rax_8 = strtoul(_EndPtr_1 + _Size_1 + 1, &_EndPtr, 0);
                        _EndPtr_1 = _EndPtr;
                        char rdx_5 = *_EndPtr_1;
                        
                        if ((rdx_5 == 0x3a || !rdx_5) && rax_8 >= 0)
                            *(j + 0x10) = rax_8;
                        
                        break;
                    }
                    
                    j += 0x18;
                } while (&var_38 != j);
            }
            
            i = strchr(_EndPtr_1, 0x3a);
            i_1 = i;
        } while (i);
        int32_t rdx_2 = 0x1000;
        
        if (var_40 <= 0x1000)
            rdx_2 = var_40;
        
        int32_t rax_4 = var_58;
        
        if (!rax_4)
            rax_4 = 6;
        
        _Size = ((rax_4 + 0x26) * rdx_2) << 3;
        data_1400231d8 = _Size;
        
        if (_Size)
            goto label_140021d02;
    }
    else
    {
        data_1400231d8 = 0x16000;
        _Size = 0x16000;
    label_140021d02:
        uint64_t* rax_7 = malloc(_Size);
        data_1400231d0 = rax_7;
        
        if (!rax_7)
            data_1400231d8 = 0;
        else
        {
            data_1400231c8 = rax_7;
            *rax_7 = _Size;
            rax_7[1] = 0;
        }
    }
    /* tailcall */
    return sub_140001410(sub_140021aa0);
}

void sub_140021d80(void* arg1) __noreturn
{
    if (arg1)
    {
        sub_1400216b0(arg1);
        
        if (-0x474e5543432b2b00 + *arg1 <= 1)
        {
            sub_140015940(*(arg1 - 0x38));
            /* no return */
        }
    }
    
    sub_140021b00();
    /* no return */
}

void sub_140021dc0() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for_std::bad_exception{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for_std::bad_exception, sub_14001d0c0);
    /* no return */
}

void sub_140021e00() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for_std::bad_alloc{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for_std::bad_alloc, sub_140021060);
    /* no return */
}

void sub_140021e40() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for_std::bad_array_new_length{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for_std::bad_array_new_length, sub_14001de10);
    /* no return */
}

void sub_140021e80() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for_std::bad_cast{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for_std::bad_cast, sub_140021020);
    /* no return */
}

void sub_140021ec0() __noreturn
{
    void* rax = sub_140021640(8);
    *rax = &_vtable_for_std::bad_typeid{for `std::exception'};
    sub_140021a30(rax, &_typeinfo_for_std::bad_typeid, sub_14001bb30);
    /* no return */
}

void sub_140021f00(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001bba0(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::logic_error, sub_14001bd70);
    /* no return */
}

void sub_140021f50(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001c800(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::domain_error, sub_14001c980);
    /* no return */
}

void sub_140021fa0(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001dbf0(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::invalid_argument, sub_14001dd70);
    /* no return */
}

void sub_140021ff0(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001c9f0(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::length_error, sub_14001cb70);
    /* no return */
}

void sub_140022040(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001cbe0(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::out_of_range, sub_14001cd60);
    /* no return */
}

void sub_140022090(char* arg1, uint64_t arg2) __noreturn
{
    uint64_t arg_10 = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    uint64_t rax = strlen(arg1);
    int64_t rax_2 = (rax + 0x20f) & 0xfffffffffffffff0;
    sub_14000efc0(rax_2);
    uint64_t* var_20 = &arg_10;
    void var_48;
    sub_140016580(&var_48 - rax_2 + 0x20, rax + 0x200, arg1, &arg_10);
    void* rax_3 = sub_140021640(0x10);
    sub_14001cbe0(rax_3, &var_48 - rax_2 + 0x20);
    sub_140021a30(rax_3, &_typeinfo_for_std::out_of_range, sub_14001cd60);
    /* no return */
}

void sub_140022130(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001d590(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::runtime_error, sub_14001d760);
    /* no return */
}

void sub_140022180(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001be20(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::range_error, sub_14001bfa0);
    /* no return */
}

void sub_1400221d0(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001d810(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::overflow_error, sub_14001d990);
    /* no return */
}

void sub_140022220(char* arg1) __noreturn
{
    void* rax = sub_140021640(0x10);
    sub_14001da00(rax, arg1);
    sub_140021a30(rax, &_typeinfo_for_std::underflow_error, sub_14001db80);
    /* no return */
}

void sub_140022270(int64_t arg1, int64_t arg2) __noreturn
{
    void var_81;
    __builtin_strncpy(&var_81, 
        "not enough space for format expansion (Please submit full bug report at https://gcc.gnu."
    "org/bugs/):\n    ", 
        0x69);
    int64_t count = arg2 - arg1;
    int64_t rax_1 = (count + 0x78) & 0xfffffffffffffff0;
    sub_14000efc0(rax_1);
    void var_a8;
    void* rsp = &var_a8 - rax_1;
    __builtin_memcpy(rsp + 0x20, &var_81, 0x68);
    __builtin_memcpy(rsp + 0x88, arg1, count);
    *(rsp + count + 0x88) = 0;
    sub_140021f00(rsp + 0x20);
    /* no return */
}

void sub_1400222f0(int32_t arg1, char* arg2) __noreturn
{
    void* rax = sub_140021640(0x20);
    uint64_t var_28 = arg1;
    void** var_20 = &data_1400231f0;
    sub_14001cdd0(rax, &var_28, arg2);
    sub_140021a30(rax, &_typeinfo_for_std::system_error, sub_14001d0a0);
    /* no return */
}

void sub_140022360(int32_t arg1) __noreturn
{
    void* rax = sub_140021640(0x20);
    int64_t var_48;
    (*(data_1400231f0 + 0x20))(&var_48, &data_1400231f0, arg1);
    sub_14001d5f0(rax, &var_48);
    int64_t rcx_2 = var_48;
    void var_38;
    
    if (rcx_2 != &var_38)
        sub_140021540(rcx_2);
    
    *(rax + 0x10) = arg1;
    *rax = &_vtable_for_std::system_error{for `std::runtime_error'};
    *(rax + 0x18) = &data_1400231f0;
    sub_140021a30(rax, &_typeinfo_for_std::system_error, sub_14001d0a0);
    /* no return */
}

int64_t Concurrency::details::xb23c4834::_Task_cv::operator[]::_Task_cv::()
{
    sub_140001410(sub_140021ae0);
    /* tailcall */
    return sub_140001410(sub_140021af0);
}

int64_t main()
{
    int32_t rsi = 0;
    sub_14000dff0();
    void* const rbx = *sub_140014bc0();
    
    if (rbx)
    {
        while (true)
        {
            int32_t _C = *rbx;
            
            if (_C <= 0x20)
            {
                if (!_C)
                    break;
                
                if (!(rsi & 1))
                {
                    if (_C)
                    {
                        char i;
                        
                        do
                        {
                            i = *(rbx + 1);
                            rbx += 1;
                            
                            if (!i)
                                break;
                        } while (i <= 0x20);
                    }
                    
                    break;
                }
                
                rsi = 1;
            }
            else if (_C == 0x22)
                rsi ^= 1;
            
            if (_ismbblead(_C))
                rbx = rbx + 1;
            
            rbx += 1;
        }
    }
    else
        rbx = &data_1400270b0;
    
    STARTUPINFOA startupInfo;
    __builtin_memset(&startupInfo, 0, 0x68);
    GetStartupInfoA(&startupInfo);
    enum SHOW_WINDOW_CMD wShowWindow = SW_SHOWDEFAULT;
    
    if (startupInfo.dwFlags & 1)
        wShowWindow = startupInfo.wShowWindow;
    
    /* tailcall */
    return sub_140002620(&__dos_header, 0, rbx, wShowWindow);
}

int64_t j_sub_140001430()
{
    /* tailcall */
    return sub_140001430();
}

