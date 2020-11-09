#pragma once

#include "Cesium3DTiles/IAssetRequest.h"
#include "Cesium3DTiles/Library.h"
#include "Cesium3DTiles/RasterOverlay.h"
#include "CesiumGeospatial/Ellipsoid.h"
#include "CesiumGeospatial/GlobeRectangle.h"
#include "CesiumGeometry/QuadtreeTilingScheme.h"
#include <functional>

namespace Cesium3DTiles {

    struct TileMapServiceRasterOverlayOptions {
        std::optional<std::string> fileExtension;
        std::optional<std::string> credit;
        std::optional<uint32_t> minimumLevel;
        std::optional<uint32_t> maximumLevel;
        std::optional<CesiumGeometry::Rectangle> coverageRectangle;
        std::optional<CesiumGeospatial::Projection> projection;
        std::optional<CesiumGeometry::QuadtreeTilingScheme> tilingScheme;
        std::optional<CesiumGeospatial::Ellipsoid> ellipsoid;
        std::optional<uint32_t> tileWidth;
        std::optional<uint32_t> tileHeight;
        std::optional<bool> flipXY;
    };

    class CESIUM3DTILES_API TileMapServiceRasterOverlay : public RasterOverlay {
    public:
        TileMapServiceRasterOverlay(
            const std::string& url,
            const std::vector<IAssetAccessor::THeader>& headers = std::vector<IAssetAccessor::THeader>(),
            const TileMapServiceRasterOverlayOptions& options = TileMapServiceRasterOverlayOptions()
        );
        virtual ~TileMapServiceRasterOverlay() override;

        virtual void createTileProvider(TilesetExternals& tilesetExternals, std::function<CreateTileProviderCallback>&& callback) override;

    private:
        std::string _url;
        std::vector<IAssetAccessor::THeader> _headers;
        TileMapServiceRasterOverlayOptions _options;

        std::unique_ptr<IAssetRequest> _pMetadataRequest;
        std::function<CreateTileProviderCallback> _callback;
    };

}