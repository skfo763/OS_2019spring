import subprocess

print("Pages\tTrials\tMicroSeconds")
	
for i in range(1, 21, 2):
	subprocess.call(["./tlb.test", str(i), "10000000"]);




