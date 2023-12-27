class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch == "(":
                stack+=["("]
            elif ch == "{":
                stack+=["{"]
            elif ch == "[":
                stack+=["["]
            elif ch == ")":
                if len(stack)==0 or stack[-1]!="(":
                    return False
                stack.pop()
            elif ch == "}":
                if len(stack)==0 or stack[-1]!="{":
                    return False
                stack.pop()
            elif ch == "]":
                if len(stack)==0 or stack[-1]!="[":
                    return False
                stack.pop()

        return len(stack)==0
             
                
