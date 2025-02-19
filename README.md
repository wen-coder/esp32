2025年2月18日，创建了在线的github仓库用来代码更新迭代。希望在这个过程中学习到git的基本使用方法。

1. 作用是添加一个名为 “origin” 的远程仓库，其地址为 “https://github.com/wen-coder/esp32.git”。使用这条命令后，可以通过 “origin” 这个名称来指代这个远程仓库，方便后续进行诸如推送（push）、拉取（pull）等操作。

    git remote add origin https://github.com/wen-coder/esp32.git

2.将本地仓库的 “main” 分支推送到名为 “origin” 的远程仓库，并且设置上游分支，以便后续可以使用更简洁的命令进行推送和拉取操作。

    git push -u origin main