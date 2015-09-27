
## 强制删除提交到远程版本库的数据与版本记录

参考:[Git操作：强制删除提交到远程版本库的数据与版本记录](http://youngsterxyf.github.io/2013/01/08/git-cancel-commits/)

```
git reset --hard HEAD~2                   # 取消当前版本之前的两次提交
git push origin HEAD --force              # 强制提交到远程版本库，从而删除之前的两次提交数据
```

## 强制删除之后的恢复

参考：[从Git仓库中恢复已删除的分支或丢失的commit](http://sumsung753.blog.163.com/blog/static/146364501201301711943864/)


```
git reflog # git log -g 找到想要恢复的hash值，然后执行：
git reset --hard [hash值]
```
居然恢复了。
