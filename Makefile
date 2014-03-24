all:    openiapp OpeniSend_rec GetUdid done

openiapp:	
	@gcc openiapp.c -o openiapp -limobiledevice -lplist

OpeniSend_rec:	
	@gcc OpeniSend_rec.c -o OpeniSend_rec -lusb-1.0

GetUdid:	
	@gcc -o GetUdid -framework CoreFoundation -framework MobileDevice -F/System/Library/PrivateFrameworks GetUdid.c
     
done:	
	@echo 'Successfully built GetUdid'
	@echo 'Successfully built openiapp'
	@echo 'Successfully built OpeniSend_rec'

clean:
	@rm -rf OpeniSend_rec openiapp GetUdid
	@echo Cleaned.
