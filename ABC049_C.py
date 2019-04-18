
#%%

s = input()
l_o = ['dream','dreamer', 'ereaser', 'erase']
l_r = [x[::-1] for x in l_o]

mi = min([len(word) for word in l_o])

def helper(s):
    if s == '':
        return True
    elif len(s) < mi:
        return False

    else:
        for word in l_r:
            if s.startswith(word):
                return helper(s[len(word):])
        return False


flag = helper(s[::-1])

if flag:
    print('YES')
else:
    print('NO')
