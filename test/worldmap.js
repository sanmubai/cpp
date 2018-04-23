!system.worldmap ? system.worldmap = {} : null;

system.worldmap.test = system.commonLayer.template_layer.extend({

    ctor: function (srcLayerStr) {
        this._super(resWorldmap.ui.mainLayer1);

        this.mapSizeX=1024;
        this.mapSizeY=512;

        this.lastScrollX=0;
        this.lastScrollY=0;

        this.modelSizeX=8;
        this.modelSizeY=10;

        this.centerPos=cc.p(0,0);

        this.baseModelPos=cc.p(0,0); //model cell 左下角grid pos

        this.narrowAxis="y"; //grid要错位的轴

        var ui_config = {};

        ui_config.btn_arr=[
            ["btnBack",this.onBtnBack.bind(this)]
        ];

        this._init_ui_config = ui_config;

    },

    close: function () {
        this.closeWithEffectSmall();
    },

    onBtnBack: function(){
        var loadLayer = system.res.getLoadingLayer("group_worldmap", "group_city");
        ccsp.layerMgr.switchLayer(this, loadLayer);
    },

    initUI: function(){

        var self=this;

        this.scrollView=ccsp.ui.util.getWidgetByName(this,"scrollView");
        var grid=ccsp.ui.util.getWidgetByName(this,"grid");

        this.grid=grid;
        this.grid.setTouchEnabled(false);
        this.grid.setSwallowTouches(false);
        this.grid.retain();

        this.gridPixWidth=grid.width;
        this.gridPixHeight=grid.height;

        var scroll=this.scrollView;

        scroll.removeAllChildren();

        var modelSizeX=this.modelSizeX;
        var modelSizeY=this.modelSizeY;

        var gridPixWidth=this.gridPixWidth;
        var gridPixHeight=this.gridPixHeight;

        var mapWidth=this.mapSizeX*gridPixWidth;
        var mapHeight=this.mapSizeY*gridPixHeight;

        scroll.setInnerContainerSize(cc.size(mapWidth,mapHeight));


        for(var j=modelSizeY-1;j>=0;j--){

            for(var i=0;i<modelSizeX;i++){

                var gridCell = grid.clone();
                // batchNode.addChild(sprite);

                if(j%2==0){
                    var w=(i+1)*gridPixWidth;
                }else{
                    var w=(i+0.5)*gridPixWidth;
                }

                // gridCell.setTouchEnabled(true);
                // gridCell.addClickEventListener(function () {
                //     console.log(this.coordinate);
                // });

                var h=(j+1)*gridPixHeight/2;

                gridCell.x=w;
                gridCell.y=h;
                gridCell.coordinate=cc.p(i,j);

                var tag=parseInt(j*this.mapSizeX+i+1);

                ccsp.ui.util.getWidgetByName(gridCell,"textName").setString(i+","+j+","+tag);

                scroll.addChild(gridCell,0,tag);

            }
        }

        this.centerPos=cc.p(-400,-200);

        // this.lastScrollX=0;
        // this.lastScrollY=0;

        scroll.getInnerContainer().setPosition(this.centerPos);

        this.scrollView.addEventListener(function (target, event) {
            if (event == ccui.ScrollView.EVENT_CONTAINER_MOVED || event == ccui.ScrollView.EVENT_AUTOSCROLL_ENDED)
                self.parseScrollEvent();
        });

        this.scrollView.setTouchEnabled(true);
        this.scrollView.addClickEventListener(function(target){
            var startClickPos=target.getTouchBeganPosition();
            var clickPos=target.getTouchEndPosition();

            if(startClickPos.x != clickPos.x || startClickPos.y != clickPos.y) return;

            var innerClickPos=target.getInnerContainer().convertToNodeSpace(clickPos);

            var tilePos=self.pixPosToTilePos(innerClickPos);

            // console.log(clickPos,innerClickPos);



        });

    },

    pixPosToTilePos:function (pixPos) {

        if(this.narrowAxis=="x"){

        }else{

            var x=Math.floor(pixPos.x/this.gridPixWidth*2);
            var y=Math.floor(pixPos.y/this.gridPixHeight*2);

            if(y%2==0){
                var x1=Math.floor((pixPos.x-this.gridPixWidth/2)/this.gridPixWidth);
            }else{
                var x1=Math.floor(pixPos.x/this.gridPixWidth);
            }




            var tilePos=cc.p(x,y);
        }

        // console.log(tilePos,cc.p(x1,y));
        console.log(cc.p(x1,y));

        return tilePos;
    },

    parseScrollEvent: function () {

        var self = this;

        self.scrollTouchBegin = true;
        var innerContainer = self.scrollView.getInnerContainer();
        var pos = innerContainer.getPosition();

        //1 up 2 right 4 down 3 left

        var scrollX=Math.ceil(pos.x/this.gridPixWidth);
        var scrollY=Math.ceil(pos.y/this.gridPixHeight*2);

        var lastScrollX=this.lastScrollX;
        var lastScrollY=this.lastScrollY;

        if(scrollX!=lastScrollX){
            var direct=scrollX-lastScrollX;

            if( !(direct ==1 || direct ==-1)){
                cc.log("direct: %d,scrollX: %d, lastScrollX: %d",direct,scrollX,lastScrollX);
                var newPos=cc.p(pos.x- direct * this.gridPixWidth,pos.y);
                innerContainer.setPosition(newPos);
                return;
            }

            var tempDirect=direct/Math.abs(direct);

            this.generateYNewCells(scrollX,tempDirect);
            this.baseModelPos.x=this.baseModelPos.x-tempDirect;

            this.lastScrollX=scrollX;
        }

        if(scrollY!=lastScrollY){
            var direct=scrollY-lastScrollY;

            if( !(direct ==1 || direct ==-1)){
                cc.log("direct: %d,scrollY: %d, lastScrollY: %d",direct,scrollY,lastScrollY);
                var newPos=cc.p(pos.x,pos.y - direct * this.gridPixHeight /2 );
                innerContainer.setPosition(newPos);
                return;
            }
            var tempDirect=direct/Math.abs(direct);

            this.generateXNewCells(scrollY,tempDirect);
            this.baseModelPos.y=this.baseModelPos.y-tempDirect;
            this.lastScrollY=scrollY;
        }

    },

    //生成新的一行cell（用老的一行）
    //index: int (x/y 的格子坐标)
    //direct: enum{-1,1} -1 down, 1 up
    generateXNewCells:function(index,direct){
        var modelSizeX=this.modelSizeX;
        var modelSizeY=this.modelSizeY;

        var displacement=direct*(-1)*modelSizeY* (this.gridPixHeight/2);

        var baseModelPos=this.baseModelPos;

        // console.log("Y direct:",direct,"basePos:",baseModelPos);

        for(var i=0;i<modelSizeX;i++){

            if(direct==1){
                var oldY=baseModelPos.y+ this.modelSizeY-1;
            }else if(direct==-1){
                var oldY=baseModelPos.y;
            }

            var newY=oldY+direct*(-1)*modelSizeY;

            var oldCoordinate=cc.p(baseModelPos.x+i,oldY);
            var newCoordinate=cc.p(oldCoordinate.x,newY);

            // var oldTag=parseInt(oldY*this.mapSizeX+i+1);
            // var newTag=oldTag+direct*(-1)*this.mapSizeX*this.modelSizeY;

            var oldTag=this.getCellTag(oldCoordinate);
            var newTag=this.getCellTag(newCoordinate);

            // console.log("oldTag:",oldTag,"newTag:",newTag);

            var cell=this.scrollView.getChildByTag(oldTag);
            cell.setTag(newTag);

            var newPos=cc.p(cell.x,cell.y+displacement);
            cell.setPosition(newPos);

            this.updateCell(oldCoordinate,newCoordinate,cell);

        }


    },
    // 生成新的一列cell（用老的一列）
    //index: int (x/y 的格子坐标)
    //direct: enum{-1,1} -1/left 1 right
    generateYNewCells:function (index,direct) {
        var modelSizeX=this.modelSizeX;
        var modelSizeY=this.modelSizeY;

        var displacement=direct*(-1)*modelSizeX*this.gridPixWidth;

        var baseModelPos=this.baseModelPos;

        // console.log("X direct:",direct,"basePos:",baseModelPos);

        for(var i=0;i<modelSizeY;i++){

            if(direct==1){
                var oldX=baseModelPos.x+ this.modelSizeX-1;
            }else if(direct==-1){
                var oldX=baseModelPos.x;
            }

            var newX=oldX+direct*(-1)*modelSizeX;

            var oldCoordinate=cc.p(oldX,baseModelPos.y+i);
            var newCoordinate=cc.p(newX,oldCoordinate.y);

            // var oldTag=parseInt((baseModelPos.y+i)*this.mapSizeX+oldX+1);
            // var newTag=oldTag+direct*(-1)*modelSizeX;

            var oldTag=this.getCellTag(oldCoordinate);
            var newTag=this.getCellTag(newCoordinate);

            // console.log("oldTag:",oldTag,"newTag:",newTag);

            var cell=this.scrollView.getChildByTag(oldTag);
            cell.setTag(newTag);

            var newPos=cc.p(cell.x+displacement,cell.y);
            cell.setPosition(newPos);

            this.updateCell(oldCoordinate,newCoordinate,cell);

        }
    },

    updateCell:function (oldCoordinate,newCoordinate,cellObj) {

        var i=newCoordinate.x;
        var j=newCoordinate.y;
        var tag=cellObj.getTag();

        ccsp.ui.util.getWidgetByName(cellObj,"textName").setString(i+","+j+","+tag);

    },

    getCellTag:function (pos) {
        return pos.x+pos.y*this.mapSizeX+1;
    },

    onEnter: function () {
        this._super();
        this.initUI();

    },

    onExit: function () {
        this._super();

        this.grid.release();

    }

});