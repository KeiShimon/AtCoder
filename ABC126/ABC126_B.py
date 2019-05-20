S = input()

eligible_months = set(range(1,13))

first = int(S[:2])
second = int(S[-2:])

if first in eligible_months:

    if second in eligible_months:

        print('AMBIGUOUS')

    else:

        print('MMYY')

else:

    if second in eligible_months:

        print('YYMM')

    else:

        print('NA')