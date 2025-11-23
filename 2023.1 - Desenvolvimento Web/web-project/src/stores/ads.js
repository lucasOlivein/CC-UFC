import { defineStore } from 'pinia';
import { ref, computed } from 'vue';
import { api } from '../apiConfig.js'



export const Ads = defineStore('Ads', {
    state: () => {
        return {
            anuncios: [],
            filterResult: [],
            userAnuncios: ref([]),
            adminAnuncios: ref([]),
            categoryAds: null,
            categoryEmpty: true,
            categoryId: null,
            loaded: false,
            categorias: ref([]),
            catLoaded: false,
            categoryAdsButton: false,
            updateState: '',
            categoryAdss: []
        }
    },

    actions: {

        search(event){
            this.filterResult = event
        },
        getCategories() {
            api.get("categorias").then(
                response => { this.categorias.value = response.data.data; })
        },

        handleGetResponse(response){
            if(response.data)
                response = response.data.data.attributes.anuncios.data
            
            var ads = []
            for (var i = 0; i < response.length; i++) {
                var photos = response[i].attributes.photos.data
                ads.push(response[i].attributes)
                ads.id = response[i].id
                ads[i].photos = []
                if(photos)
                for (let j = 0; j < photos.length; j++) {
                    ads[i].photos.push(photos[j].attributes)
                    ads[i].photos[j].id = photos[j].id
                }

            }

            for (let i = 0; i < ads.length; i++)
                Object.assign(ads[i], { configOpt: { optDiv: true, editDiv: false, deleteDiv: false, disabled: true }, show: true })

            return ads
        },

        async getCategoryAds(id) {
            if (this.categoryAdsButton && this.categoryId == id) {
                this.categoryAdsButton = false
            } else {
                this.anuncios = null,
                this.categoryAdsButton = true
                this.categoryId = id

                this.filterResult = this.anuncios = this.handleGetResponse(await api.get(`categorias/${id}?populate=anuncios&populate=anuncios.photos`))
            }
            if(!this.anuncios.length)
                this.categoryEmpty = true
            else
                this.categoryEmpty = false

        },

        getAllUsersAds() {
            api.get(`users/?populate=anuncios.photos&populate=anuncios.categoria`
            ).then(response => {
                let anuncios = []
                if (response.status == '200') {
                    this.userAnuncios.value = response.data
                    for (let i = 0; i < this.userAnuncios.value.length; i++) {
                        for (let j = 0; j < this.userAnuncios.value[i].anuncios.length; j++) {
                            anuncios.push(this.userAnuncios.value[i].anuncios[j])
                        }
                    }

                    for (let i = 0; i < anuncios.length; i++)
                        Object.assign(anuncios[i], { configOpt: { optDiv: true, editDiv: false, deleteDiv: false, disabled: true }, show: true })
                    this.filterResult = this.anuncios = anuncios

                } else {
                }
            })

        },

        getUserAds(id) {
            api.get(`users/${id}?populate=anuncios.photos&populate=anuncios.categoria`,
            ).then(response => {
                if (response.status == '200') {
                    this.userAnuncios.value = response.data.anuncios

                    for (let i = 0; i < this.userAnuncios.value.length; i++)
                        Object.assign(this.userAnuncios.value[i], { configOpt: { optDiv: true, editDiv: false, deleteDiv: false, disabled: true }, show: true })

                    console.log(this.userAnuncios.value)
                    console.log("sucesso na requisicao dos anuncios do usuario");
                } else {
                    console.log("falha na requisicao dos anuncios do usuario");
                }
            })


        },
        async uploadImages(images, imageNames, token) {
            var imageId = null
            const arrayFotos = []

            for (let i = 0; i < images.length; i++) {
                arrayFotos.push(await fetch(images[i].src).then(response => response.blob()))
            }
            const formData = new FormData();
            for (let i = 0; i < arrayFotos.length; i++) {
                formData.append('files', arrayFotos[i], imageNames[i])
            }


            return api.post('/upload/', formData, {
                headers: {
                    Authorization: `Bearer ${token}`,
                },

            }).then(response => {
                imageId = response.data.map(item => item.id)
                console.log(response)
                return imageId
            }).catch(erro => { return erro })



        },
        deleteImages(id, token) {
            return api.delete(`upload/files/${id}`, {
                headers: {
                    Authorization: `Bearer ${token}`
                }
            }).then(response => {
                console.log(response)
                if (response.status == '200') {
                    return 200
                } else {
                    return response
                }
            })
        },


        // CRUD dos Anuncios
        createAd(fields, authorization) {
            return api.post('anuncios/', fields, authorization).then(response => { return response })
        },
        async getAds() {
            const ads = await api.get("anuncios?populate=*&pagination[pageSize]=5")
            this.filterResult = this.anuncios = this.handleGetResponse(ads.data.data)

        },
        updateAd(id, token, fields) {
            return api.put(`anuncios/${id}`, { data: fields }, {
                headers: {
                    Authorization: `Bearer ${token}`
                }
            }).then(response => {
                console.log(response)
                return response
            }
            ).catch(erro => { return erro })

        },
        deleteAd(id, token) {
            return api.delete(`anuncios/${id}?populate=photos`, {
                headers: {
                    Authorization: `Bearer ${token}`
                }
            }).then(
                response => {
                    const fotos = response.data.data.attributes.photos.data
                    if (fotos) {
                        for (let i = 0; i < fotos.length; i++) {
                            console.log(this.deleteImages(fotos[i].id, token))
                        }
                    }
                    return response
                }
            ).catch(erro => { return erro })

        },

    },


})