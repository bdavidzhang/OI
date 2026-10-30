import sys

def run():
    size = int(input())
    i = 0
    cSplit = 1
    while(1):
        print("? " + str(cSplit) + " "+ str(min(cSplit + (2**i) - 1,size)))
        sys.stdout.flush()
        resp = int(input())
        if(resp == -1):
            return
        if(resp == 1):
            sIdx = cSplit
            eIdx = cSplit + 2 ** i - 1
            while(1):
                if(sIdx == eIdx):
                    print("! " + str(sIdx))
                    sys.stdout.flush()
                    return
                mid = (sIdx + eIdx )//2
                print("? " + str(mid - 2**i + 1) + " "+ str(mid))
                sys.stdout.flush()
                resp = int(input())
                if(resp == -1):
                    return
                if(resp == 0):
                    sIdx = mid + 1
                else:
                    eIdx = mid
        else:
            cSplit += 2** i
            i += 1

run()