# Need tmk_core remote to update:
#   git remote add -f tmk)core https://github.com/tmk/tmk_core
#
# Initial subtree added using
#   git subtree add -P tmk_core tmk_core master --squash

git subtree pull -P firmware/tmk_core tmk_core master --squash
