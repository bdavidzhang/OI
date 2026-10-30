t = int(input())

for _ in range(t):
    n,q = map(int,input().split(' '))

    s = input().strip()
    ba = 0 
    ca = 0
    cb = 0
    baex = 0
    caex = 0
    bcc = 0
    cbb = 0
    
    for i in range(q):
        u,v = input().split(' ') 
        z = u+v
        if z == 'ba':
            ba += 1
            if cbb > 0:
                cbb -= 1
                caex += 1
        if z == 'ca':
            ca += 1
            if bcc > 0:
                bcc -= 1
                baex += 1
        if z == 'cb':
            cb += 1
            cbb += 1
        if z == 'bc':
            bcc += 1
    
    wba = 0
    wcb = 0
    wca = 0    
            

    def test(wba,wcb,wca):
        ba2 = ba
        cb2 = cb
        ca2 = ca 

        t_ca = min(wca,ca2)
        wca -= t_ca
        ca2 -= t_ca

        t_cb = min(wcb,cb2)
        wcb -= t_cb 
        cb2 -= t_cb 
        
        t_ba = min(wba,ba2)
        wba -= t_ba
        ba2 -= t_ba 

        t_ba_chain = min(wba,baex,ca2)
        wba -= t_ba_chain

        t_ca_chain = min(wca,caex,cb2,ba2)
        wca -= t_ca_chain

        return wba == 0 and wcb == 0 and wca == 0

    out = []
    for c in s:
        if c == 'a':
            out.append('a')
        elif c == 'b':
            if test(wba+1,wcb,wca):
                out.append('a')
                wba+=1
            else:
                out.append('b')
        else:
            if test(wba,wcb,wca+1):
                out.append('a')
                wca += 1
            elif test(wba,wcb+1,wca):
                out.append('b')
                wcb += 1
            else:
                out.append(c)
        
    print(''.join(out))


