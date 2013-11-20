astyle \
--options=none --suffix=none --formatted \
--break-blocks \
--pad-oper --unpad-paren --pad-header \
$(find src/ -name '*.*pp')
