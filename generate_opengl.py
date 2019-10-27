import subprocess

subprocess.call(["glad", "--generator=c", "--out-path=GL", "--profile=core", "--api=gl=4.6"])
