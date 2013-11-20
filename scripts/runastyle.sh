astyle \
--options=none --suffix=none --formatted \
--break-blocks --delete-empty-lines \
--pad-oper --unpad-paren --pad-header \
$(find src/ -name '*.*pp')
