class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        for sandwich in sandwiches:
            ok = False
            for i in range(len(students)):
                currStudent = students.pop(0)
                if currStudent == sandwich:
                    ok = True
                    break
                students.append(currStudent)
            if not ok:
                return len(students)
            
        return 0





class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        counts = [0, 0]
        for student in students:
            counts[student] += 1

        remaining = len(sandwiches)
        for sandwich in sandwiches:
            if counts[sandwich] == 0:
                break
            if remaining == 0:
                break
            counts[sandwich] -= 1
            remaining -= 1
        
        return remaining