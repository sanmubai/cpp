local newProductor

function productor()
     local i = 0
     while true do
          i=i+1
          coroutine.yield(i)     -- 将生产的物品发送给消费者
     end
end

function consumer()
     while true do
          local status, value = coroutine.resume(newProductor)
          print(value)
          if(value >10) then
               break
          end
     end
end

-- 启动程序
newProductor = coroutine.create(productor)
consumer()