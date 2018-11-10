select * from depositor, account where depositor.a_no=account.account_no;

select * from depositor, account, customer where depositor.a_no=account.account_no and depositor.c_no=customer.customer_no;