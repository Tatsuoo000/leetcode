"""
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it. 
Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. 
Furthermore, a double period .. moves the directory up a level. 
For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, 
and there must be only a single slash / between two directory names. 
The last directory name (if it exists) must not end with a trailing /. 
Also, the canonical path must be the shortest string representing the absolute path.

"""

class Solution:
    def simplifyPath(self, path: str) -> str:
        paths = path.split("/")
        ans = []
        for path in paths:
            if path != "." and path != ".." and path:
                ans.append(path)
            elif path == ".." and ans != []:
                ans.pop()
        if ans == []:
            return "/"
        shortest_path = ""
        for path in ans:
            shortest_path += "/" + path
        return shortest_path
