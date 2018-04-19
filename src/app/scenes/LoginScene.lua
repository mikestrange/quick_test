local LoginScene = class("LoginScene", function()
    return display.newScene("LoginScene")
end)

function LoginScene:ctor()
    
end

function LoginScene:onEnter()
    display.newTTFLabel({text = "你好啊", size = 24, color = cc.c3b(180,180,255)}):addTo(self)
			:align(display.CENTER_BOTTOM, display.cx, display.cy)
end


return LoginScene
