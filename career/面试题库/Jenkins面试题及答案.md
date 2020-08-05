Jenkins面试题及答案

SZX@ 2020-03-07 20:29:22  1117  收藏 11
版权
Jenkins是一个开源自动化服务器，它是用Java开发的持续集成工具。 Jenkins通过持续集成并促进持续交付的技术方面，帮助实现软件开发过程中非人为部分的自动化。

Jenkins是什么？
Jenkins是一个开源自动化服务器。 Jenkins是用Java开发的持续集成工具。 Jenkins通过持续集成并促进持续交付的技术方面，帮助实现软件开发过程中非人为部分的自动化。 Jenkins是一个开源软件；Jenkins是一个自动化服务器；Jenkins可以帮助自动化软件开发过程；Jenkins可以通过持续集成实现流程自动化，并促进持续交付的技术方面；Jenkins开发的Jenkins是名为Hudson的项目的分支；Jenkins许可证：MIT；；Jenkins用Java编写；详细答案>>

为什么使用Jenkins？
Jenkins是一种使用Java编程语言编写的开源持续集成软件工具，用于实时测试和报告较大代码库中的孤立更改。 Jenkins软件使开发人员能够快速找到并解决代码库中的缺陷，并自动进行构建测试。详细答案>>

Maven是什么？Jenkins是什么？
Maven是一个构建工具，简而言之是ant的继承者。它有助于构建和版本控制。 但是，Jenkins是持续集成系统，其中maven用于构建。 Jenkins可用于自动化部署过程。

Hudson 和 Jenkins 有什么区别？
Jenkins是新的Hudson。 因为整个开发社区都移至Jenkins，所以它实际上更像是重命名，而不是分叉。 （甲骨文正坐在角落里抱着他们的“Hudson”，但现在这只是个无灵魂的项目。） 简而言之，Jenkins CI是领先的开源持续集成服务器。

在Jenkins中持续集成是什么？
持续集成是一个将所有开发工作尽早集成的过程。 生成的工件会自动创建和测试。 此过程允许尽早发现错误。 Jenkins是一种流行的开源工具，可以执行持续集成和构建自动化。

为什么将Jenkins与Selenium一起使用？
在Jenkins中运行Selenium测试允许您在每次软件更改时运行测试，并在测试通过时将软件部署到新环境中。 Jenkins可以安排您的测试在特定时间运行。

CI工具是什么？
以下是前8种持续集成工具的列表：

JenkinsTeamCityTravis CIGo CDBambooGitLab CICircleCICodeship详细答案>>
8. CI CD管道是什么？
持续集成和部署管道（CD / CI）是软件项目中如此重要的方面。 它节省了大量的手动，易于出错的部署工作。 它产生了用于持续集成，自动化测试和代码指标的高质量软件。

在Jenkins中构建管道是什么？
Jenkins中的作业链接是执行作业后自动启动其他作业的过程。 这种方法使您可以构建多步骤的构建管道，或者如果更新了其中一个依赖项，则可以触发项目的重建。

Jenkins Pipeline是什么？
Jenkins Pipeline插件是Jenkins用户的游戏规则改变者。 Pipeline插件基于Groovy中的领域特定语言（DSL），使管道可编写脚本，并且是开发复杂的多步DevOps管道的强大方法。

DSL Jenkins是什么？
Jenkins的“作业DSL/插件”由两部分组成：领域特定语言（DSL）本身，它允许用户使用基于Groovy的语言来描述工作，以及Jenkins插件，用于管理脚本和更新。 因此创建并维护的Jenkins工作。

持续集成和部署是什么？
持续集成（CI）是一种开发实践，要求开发人员每天多次将代码集成到共享存储库中。 然后，每个签入均由自动构建进行验证，从而使团队可以及早发现问题。

用于配置和配置的工具是什么？
Ansible是一种无代理的配置管理以及编排工具。 在Ansible中，配置模块称为“Playbooks”。 像其他工具一样，Ansible可用于云配置。

Maven，Ant和Jenkins有什么区别？
Maven和ANT是构建工具，但主要区别在于Maven还提供了依赖项管理，标准项目布局和项目管理。 关于Maven，ANT和Jenkins之间的区别，后来的是一个持续集成工具，其作用远不止构建工具。

Jenkins支持哪些SCM工具？
Jenkins支持版本控制工具，包括AccuRev，CVS，Subversion，Git，Mercurial，Perforce，ClearCase和RTC，并且可以执行基于Apache Ant，Apache Maven和sbt的项目以及任意的shell脚本和Windows批处理命令。

如何在Jenkins中计划构建？
在Jenkins中，在工作配置下，我们可以定义各种构建触发器。只需找到“构建触发器”部分，然后选中“定期构建”复选框即可。 使用定期构建，您可以按星期几或星期几以及执行构建的时间安排构建定义。 “时间表”文本框的格式如下： MINUTE（0-59），HOUR （0-23），DAY（1-31），MONTH（1-12），WEEK （0-7）

为什么在Jenkins中使用管道？
Pipeline在Jenkins上添加了一套强大的自动化工具，支持从简单的持续集成到全面的持续交付管道的用例。 通过对一系列相关任务进行建模，用户可以利用Pipeline的许多功能： 代码：流水线是用代码实现的，通常会检查到源代码管理中，从而使团队能够编辑，查看和迭代其交付流水线。耐用：管道可以在Jenkins主服务器的计划内和计划外重启中生存。可暂停：管道可以选择停止并等待人工输入或批准，然后再继续管道运行。多功能：管道支持复杂的现实世界中的连续交付需求，包括分叉/加入，循环和并行执行工作的能力。

Jenkinsfile是什么？
Jenkinsfile是一个文本文件，其中包含Jenkins Pipeline的定义，并已签入源代码管理。 创建Jenkinsfile（已检入源代码管理）可带来许多直接好处： 管道上的代码审查/迭代；管道的审计跟踪；管道的唯一事实来源，可以由项目的多个成员查看和编辑。

如何在Jenkins中创建多分支管道？
Multibranch Pipeline项目类型使您可以为同一项目的不同分支实现不同的Jenkinsfile。 在Multibranch Pipeline项目中，Jenkins自动发现，管理和执行针对在源代码管理中包含Jenkinsfile的分支的管道。

Jenkins的Blue Ocean是什么？
Blue Ocean是一个重新思考Jenkins的用户体验的项目，它通过尽可能少的点击显示对开发团队重要的信息，同时仍然忠于Jenkins核心的可扩展性，从而对软件开发过程进行建模和展示。

Jenkins中重要的插件是什么？
以下是Jenkins中一些重要插件的列表：

Maven 2 projectGitAmazon EC2HTML publisherCopy artifactJoinGreen Balls

Jenkins的作业（Job）是什么？
Jenkins可用于执行典型的构建服务器工作，例如进行连续/正式/每晚构建，运行测试或执行一些重复的批处理任务。 这在詹金斯（Jenkins）中被称为“自由式软件项目”。

如何在Jenkins创建作业？
转到Jenkins主页，选择“新建作业”，然后选择“构建自由样式的软件项目”。 此作业类型包含以下元素： 可选的SCM，例如源代码所在的CVS或Subversion。可选触发器，用于控制Jenkins何时执行构建。 某种执行构建的构建脚本（ant，maven，shell脚本，批处理文件等），其中实际工作发生在可选步骤中，以从构建中收集信息，例如存档工件和/或记录javadoc和测试 结果。 可选步骤，以将构建结果通知其他人/系统，例如发送电子邮件，IM，更新问题跟踪器等。

如何在Jenkins中配置自动构建？
在Jenkins中的构建可以定期触发（按计划，在配置中指定），或者在检测到项目中的源更改时触发，或者可以通过请求URL自动触发： http://YOURHOST/jenkins/job/PROJECTNAME/build

如何在Jenkins中创建备份和复制文件？
创建备份，需要做的就是定期备份JENKINS_HOME目录。 这包含所有构建作业配置，从属节点配置以及构建历史记录。 要创建Jenkins设置的备份，只需复制此目录。
