# 学习Git
## 基础操作
1. 提交：git commit
2. 创建分支：git branch <new branch name>
3. 切换分支：git checkout <new branch name>
4. 合并代码：git merge < other branch>
5. rebase:git rebase < new branch name> < other branch>
当执行rebase操作时，git会从两个分支的共同祖先开始提取待变基分支上的修改，然后将待变基分支指向基分支的最新提交，最后将刚才提取的修改应用到基分支的最新提交的后面。

## 高级操作
1. 分离HEAD:git checkout < 提交记录的HASH值>
2. 相对引用：git checkout < branch name>^
3. 相对引用2：git branch -f < branch name> HEAD~[移动次数]
4. 撤销变更：
   1. git reset < branch name>~1 撤销本地最后一次变更
   2. git revert < branch name> 撤销远程仓库最后的变更，相当于又提交了一次

## 移动提交记录
1. 将某一些提交记录移到当前分支下：git cherry-pick < 提交记录A B C……>
2. 交互式rebase: git rebase < branch name>~[最近的几次提交]
> 交互式 rebase 指的是使用带参数 --interactive 的 rebase 命令, 简写为 -i
如果你在命令后增加了这个选项, Git 会打开一个 UI 界面并列出将要被复制到目标分支的备选提交记录，它还会显示每个提交记录的哈希值和提交说明，提交说明有助于你理解这个提交进行了哪些更改。

## 杂项
1. 只需要把某一次的提交合并到主干上：git cherry-pick <提交记录>， git rebase -i < branch name>~
2. 我们可以通过下面的方法来克服困难：

先用 git rebase -i 将提交重新排序，然后把我们想要修改的提交记录挪到最前
然后用 git commit --amend 来进行一些小修改
接着再用 git rebase -i 来将他们调回原来的顺序
最后我们把 main 移到修改的最前端（用你自己喜欢的方法），就大功告成啦！
当然完成这个任务的方法不止上面提到的一种（我知道你在看 cherry-pick 啦），之后我们会多点关注这些技巧啦，但现在暂时只专注上面这种方法。 最后有必要说明一下目标状态中的那几个' —— 我们把这个提交移动了两次，每移动一次会产生一个 '；而 C2 上多出来的那个是我们在使用了 amend 参数提交时产生的，所以最终结果就是这样了。

也就是说，我在对比结果的时候只会对比提交树的结构，对于 ' 的数量上的不同，并不纳入对比范围内。只要你的 main 分支结构与目标结构相同，我就算你通过。

3. git tag 
4. git describe 的​​语法是：
```
git describe <ref>

<ref> 可以是任何能被 Git 识别成提交记录的引用，如果你没有指定的话，Git 会使用你目前所在的位置（HEAD）。

它输出的结果是这样的：

<tag>_<numCommits>_g<hash>

tag 表示的是离 ref 最近的标签， numCommits 是表示这个 ref 与 tag 相差有多少个提交记录， hash 表示的是你所给定的 ref 所表示的提交记录哈希值的前几位。

当 ref 提交记录上有某个标签时，则只输出标签名称
```

## 远程
1. git clone
2. git commit
3. git fetch:获取远程数据
4. git pull: fetch和merge两个命令的合并
5. git push
6. git checkout -b totallyNotMain o/main 创建一个名为 totallyNotMain 的分支，它跟踪远程分支 o/main
7. 