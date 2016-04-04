# git 实战练习文件
1. initial file , create first; -> master
2. modified file second; -> other
3. modified file third; -> other
  - git rebase other -> add history 2 and 3 ; -> master
4. modified file fourth -> other
5. modified file fifth -> other
<<<<<<< 3753c8fd75ac84b7ce83751b9e0e28c0b69ac741
<<<<<<< 43444c4bdd8c4701811adebe55d8108d9ceaf684
7. modified file seventh -> other

9. modified file ninth -> other
=======
6. modified file sixth -> master
>>>>>>> sixth commit master
=======
6. modified file sixth -> master
7. modified file seventh -> other
  - git merge other -> merge 6 and 7; -> master
8. modified file eighth -> master
>>>>>>> eighth commit master
