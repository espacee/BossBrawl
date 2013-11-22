astyle \
--options=none --suffix=none --formatted \
--break-blocks --delete-empty-lines \
--pad-oper --unpad-paren --pad-header \
--align-pointer=name --align-reference=name \
$(find src/ -name '*.*pp')
