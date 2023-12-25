@REM batch file to push to github with a message easily

git add .

git commit -m %1

git push origin main