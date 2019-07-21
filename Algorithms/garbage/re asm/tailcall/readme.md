# **test**

## **1. [vcvarsall.bat] Environment initialized for: 'x86'; optimization level by default**
*$ cl /EHsc /c main.cpp*  
*$ dumpbin /DISASM main.obj*

    Dump of file main.obj

    File Type: COFF OBJECT

    ?fibonacci@@YAHHHH@Z (int __cdecl fibonacci(int,int,int)):  
        00000000: 55                 push        ebp  
        00000001: 8B EC              mov         ebp,esp  
        00000003: 83 7D 08 00        cmp         dword ptr [ebp+8],0  
        00000007: 75 05              jne         0000000E  
        00000009: 8B 45 0C           mov         eax,dword ptr [ebp+0Ch]  
        0000000C: EB 1A              jmp         00000028  
        0000000E: 8B 45 0C           mov         eax,dword ptr [ebp+0Ch]  
        00000011: 03 45 10           add         eax,dword ptr [ebp+10h]  
        00000014: 50                 push        eax  
        00000015: 8B 4D 10           mov         ecx,dword ptr [ebp+10h]  
        00000018: 51                 push        ecx  
        00000019: 8B 55 08           mov         edx,dword ptr [ebp+8]  
        0000001C: 83 EA 01           sub         edx,1  
        0000001F: 52                 push        edx  
```diff
+   00000020: E8 00 00 00 00     call        ?fibonacci@@YAHHHH@Z  
``` 
        00000025: 83 C4 0C           add         esp,0Ch  
        00000028: 5D                 pop         ebp  
        00000029: C3                 ret  
```diff
- multiple int 3
```
        0000002A: CC                 int         3   
    _main:  
        00000030: 55                 push        ebp  
        00000031: 8B EC              mov         ebp,esp  
        00000033: 6A 01              push        1  
        00000035: 6A 00              push        0  
        00000037: 6A 0A              push        0Ah  
```diff
+   00000039: E8 00 00 00 00     call        ?fibonacci@@YAHHHH@Z  
``` 
        0000003E: 83 C4 0C           add         esp,0Ch  
        00000041: 33 C0              xor         eax,eax  
        00000043: 5D                 pop         ebp  
        00000044: C3                 ret  

## **2. [vcvarsall.bat] Environment initialized for: 'x86'; optimization level /O2**
*$ cl /EHsc /c /O2 main.cpp*  
*$ dumpbin /DISASM main.obj*  

    Dump of file main.obj

    File Type: COFF OBJECT

    ?fibonacci@@YAHHHH@Z (int __cdecl fibonacci(int,int,int)):  
        00000000: 8B 54 24 04        mov         edx,dword ptr [esp+4]  
        00000004: 85 D2              test        edx,edx  
        00000006: 74 19              je          00000021  
        00000008: 8B 44 24 0C        mov         eax,dword ptr [esp+0Ch]  
        0000000C: 56                 push        esi  
        0000000D: 8B 74 24 0C        mov         esi,dword ptr [esp+0Ch]  
        00000011: 8D 0C 06           lea         ecx,[esi+eax]  
        00000014: 8B F0              mov         esi,eax  
        00000016: 8B C1              mov         eax,ecx  
        00000018: 83 EA 01           sub         edx,1 
```diff
+   0000001B: 75 F4              jne         00000011    
``` 
        0000001D: 8B C6              mov         eax,esi  
        0000001F: 5E                 pop         esi  
        00000020: C3                 ret  
        00000021: 8B 44 24 08        mov         eax,dword ptr [esp+8]  
        00000025: C3                 ret  
    _main:  
        00000000: 33 C0              xor         eax,eax  
        00000002: C3                 ret  

## **3. [vcvarsall.bat] Environment initialized for: 'x64'; optimization level by default**
*$ cl /EHsc /c main.cpp*  
*$ dumpbin /DISASM main.obj*  

    Dump of file main.obj

    File Type: COFF OBJECT

    ?fibonacci@@YAHHHH@Z (int __cdecl fibonacci(int,int,int)):
        0000000000000000: 44 89 44 24 18     mov         dword ptr [rsp+18h],r8d
        0000000000000005: 89 54 24 10        mov         dword ptr [rsp+10h],edx
        0000000000000009: 89 4C 24 08        mov         dword ptr [rsp+8],ecx
        000000000000000D: 48 83 EC 28        sub         rsp,28h
        0000000000000011: 83 7C 24 30 00     cmp         dword ptr [rsp+30h],0
        0000000000000016: 75 06              jne         000000000000001E
        0000000000000018: 8B 44 24 38        mov         eax,dword ptr [rsp+38h]
        000000000000001C: EB 1E              jmp         000000000000003C
        000000000000001E: 8B 44 24 40        mov         eax,dword ptr [rsp+40h]
        0000000000000022: 8B 4C 24 38        mov         ecx,dword ptr [rsp+38h]
        0000000000000026: 03 C8              add         ecx,eax
        0000000000000028: 8B C1              mov         eax,ecx
        000000000000002A: 8B 4C 24 30        mov         ecx,dword ptr [rsp+30h]
        000000000000002E: FF C9              dec         ecx
        0000000000000030: 44 8B C0           mov         r8d,eax
        0000000000000033: 8B 54 24 40        mov         edx,dword ptr [rsp+40h]
```diff
+   0000000000000037: E8 00 00 00 00     call        ?fibonacci@@YAHHHH@Z
```
        000000000000003C: 48 83 C4 28        add         rsp,28h
        0000000000000040: C3                 ret
```diff
- multiple int 3
```
        0000000000000041: CC                 int         3
    main:
        0000000000000050: 48 83 EC 28        sub         rsp,28h
        0000000000000054: 41 B8 01 00 00 00  mov         r8d,1
        000000000000005A: 33 D2              xor         edx,edx
        000000000000005C: B9 0A 00 00 00     mov         ecx,0Ah
```diff
+   0000000000000061: E8 00 00 00 00     call        ?fibonacci@@YAHHHH@Z
```
        0000000000000066: 33 C0              xor         eax,eax
        0000000000000068: 48 83 C4 28        add         rsp,28h
        000000000000006C: C3                 ret  

## **4. [vcvarsall.bat] Environment initialized for: 'x64'; optimization level /O2**
*$ cl /EHsc /c main.cpp*  
*$ dumpbin /DISASM main.obj*  

    Dump of file main.obj

    File Type: COFF OBJECT

    ?fibonacci@@YAHHHH@Z (int __cdecl fibonacci(int,int,int)):
        0000000000000000: 85 C9              test        ecx,ecx
        0000000000000002: 74 1B              je          000000000000001F
        0000000000000004: 0F 1F 40 00        nop         dword ptr [rax]
        0000000000000008: 0F 1F 84 00 00 00  nop         dword ptr [rax+rax+0000000000000000h]
                          00 00
        0000000000000010: 42 8D 04 02        lea         eax,[rdx+r8]
        0000000000000014: 41 8B D0           mov         edx,r8d
        0000000000000017: 44 8B C0           mov         r8d,eax
        000000000000001A: 83 E9 01           sub         ecx,1
```diff
+   000000000000001D: 75 F1              jne         0000000000000010
```
        000000000000001F: 8B C2              mov         eax,edx
        0000000000000021: C3                 ret
    main:
        0000000000000000: 33 C0              xor         eax,eax
        0000000000000002: C3                 ret