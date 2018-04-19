
require("config")
require("cocos.init")
require("framework.init")

cc.utils                = require("framework.cc.utils.init")
cc.net                  = require("framework.cc.net.init")
scheduler 				= require("framework.scheduler")



local MyApp = class("MyApp", cc.mvc.AppBase)

app = nil

is_update = false

function MyApp:ctor()
	app = self
    MyApp.super.ctor(self)
end

function MyApp:init_scene()
	
end

function MyApp:run()
	self:init_scene()
	cc.FileUtils:getInstance():addSearchPath("res/")
	cc.FileUtils:getInstance():addSearchPath(cc.FileUtils:getInstance():getWritablePath().."download/")  
	cc.FileUtils:getInstance():setPopupNotify(false)
    --
    self:enterScene("LoginScene")

    --self:enterScene("GameScene")
end

function MyApp:enterScene(name, data)
	display.replaceScene(require("app.scenes."..name).new(data)) 
end

return MyApp
