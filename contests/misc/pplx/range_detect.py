from dataclasses import dataclass

#detects whether a given ip falls in a range 

@dataclass
class IPRange:
    prefix:int
    length:int 
    
    def __post_init__(self) -> None:
        #is the range ok? 
        if not 0 <= self.prefix <= 0xFFFFFFFF:
            raise ValueError()
        if not 0 <= self.length <= 32:
            raise ValueError()



    

def is_addy_in_range(ip_addy:int,ip_range:IPRange):
    if not 0 <= ip_addy <= 0xFFFFFFFF:
        raise ValueError()
    #use binary masking here 
    mask = 0xFFFFFFFF << (32-ip_range.length) & 0xFFFFFFFF
    if ip_addy & mask == ip_range.prefix & mask:
        return True
    return False


def build_ip(name:str):
    nums = list(map(int,name.split('.')))
    res = 0
    for k in range(4):
        res += nums[k] << 8*(3-k)
    return res 


if __name__ == "__main__":
    #1.1.1.0/30: 1.1.1.0 - 1.1.1.3
    ip_range = IPRange(build_ip("1.1.1.0"),30)
    print(is_addy_in_range(build_ip("1.1.1.2"),ip_range))


    