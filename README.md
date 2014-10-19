install git:

A)set up git hub account(online)- "I've alread your email"
B)sudo apt-get install git


Clone files:
git Clone https://github.com/dsmi516/Project2.git

when programming work from clone folder

if you neeed to create a origin: git remote add origin https://github.com/dsmi516/Project2.git(dnt think you need to do this for clone)

Adding edited files to git
A)git status
B) git add filename.cpp(this is best practice)(if adding new files) or git add . (add untracked files)
C)git commit -m "message"
C)(if not adding new files) git commit -a -m ("message")

E)git pull origin master(only if master online is different to your copy)
D)git push origin master
