#%%
s = input()
n = len(s)

if n < 2:
    print(0)

else:
    ans, i = 0, 0
    rem = []

    while i < n:

        if not rem:

            if i+1 < n:
                if s[i] == s[i+1]:
                    rem.append(s[i])
                    i += 1

                else:
                    i += 2
                    ans += 2

            else:
                i += 1

        else:
            if rem[-1] != s[i]:
                rem.pop()
                i += 1
                ans += 2
            
            else:
                if i + 1 < n:
                    if s[i] == s[i+1]:
                        rem.append(s[i])
                        i += 1

                    else:
                        i += 2
                        ans += 2

                else:
                    i += 1
    print(ans)
