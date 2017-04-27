<?php

//此处根据请求的文件 路径，来实现路由功能。返回结果给浏览器


// file_put_contents('./1.txt', 'hello1');
echo "HTTP/1.0 200 OK\r\n";
echo "Content-Type: text/html\r\n";
echo "\r\n";
var_dump(['123'=>123]);