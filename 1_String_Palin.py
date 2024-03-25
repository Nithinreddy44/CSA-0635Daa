def is_palindrome(s):
    if len(s)<=1:
        return True
    if s[0]==s[-1]:
        return is_palindrome(s[1:-1])
    else:
        return False
if __name__=="__main__":
    test_string=input("\nEnter a string = ").lower()
    if is_palindrome(test_string):
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")