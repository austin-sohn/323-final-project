def token(st):
    token = ['=', '*', ';', ':','(',')', ',', '+', '"']
    for t in token:
        st = st.replace(t, ' ' + t + ' ')
    return st

def comment(s):
    st = s
    if s.find('**') == 0 and s.count('**') == 2: # removes comment beginning of string
        st = s.replace(s, '')
    elif s.find('**') > 1 and s.count('**') == 2: # removes comment in middle of string
        st = s[0:s.find('**')] + '\n'
    elif s.find('**') >= 0 and s.count('**') == 1: # removes half comment
        if s.find('**') == len(s) - 3:
            st = s.replace(s[0:s.find('**') + 2], '')
        else:
            st = s.replace(s[s.find('**'):len(s)], '') + '\n'
    return st

def main():
    newtext = []
    with open('finalp1.txt', 'r') as r, open('finalp2.txt', 'w') as w:
        line = r.readlines()
        for s in line:
            s = s.replace(' ', '')
            #s = s[s.find('.')+1:len(s)]  # only use if numbers are required
            if s.count('**') >= 0:
                s = comment(s)
            s = token(s)
            if(s != '\n'):
                newtext.append(s)
            
        print(newtext)
        w.writelines(newtext) 

if __name__ == '__main__':
    main()