<script>
import { ref } from 'vue';
import { Auth } from '../../stores/user.js';






export default {
    data() {
        return {
            auth: Auth(),
            formRegist: ref({
                username: '',
                email: '',
                contato: '',
                password: '',
            }),
            regisSucess: ref(null),
            regisError: ref(null),
        }
    },
    methods: {
        async register() {
            if(!this.formRegist.username || !this.formRegist.email || !this.formRegist.password ){
                this.$emit('erro', 'Campo Obrigatório Não Preenchido')
                this.$refs.regisError.click()
                return 
            }
            const res = await this.auth.register(this.formRegist.username, this.formRegist.email, this.formRegist.contato, this.formRegist.password)
            if (res == '200') {
                this.$refs.regisSucess.click()
            } else {
                console.log(res)
                this.$emit('erro', res.message)
                this.$refs.regisError.click()
            }
        }
    },
    inheritAttrs: false
}
</script>





<template>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#registerSucess" ref="regisSucess"
        style="display: none;"> </button>

    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#regisError" ref="regisError"
        style="display: none;">error</button>
    <div>
        <form class="float-start" @submit.prevent="register()">
            <!-- username -->
            <div class="form-group">
                <input id="textBox1" autocomplete="off" v-model="formRegist.username" type="text"
                    class="form-control mx-3 my-3" placeholder="Nome de Usuário">
            </div>

            <!-- email -->
            <div class="form-group">
                <input id="textBox2" autocomplete="off" v-model="formRegist.email" type="email"
                    class="form-control mx-3 my-3" aria-describedby="emailHelp" placeholder="Seu email">
            </div>

            <!-- password -->

            <div class="form-group mb-3">
                <input id="textBox3" autocomplete="off" v-model="formRegist.contato" type="tel"
                    class="form-control mx-3 my-1" placeholder="Contato">
            </div>
            <div class="form-group">
                <input id="textBox4" autocomplete="off" v-model="formRegist.password" type="password"
                    class="form-control mx-3 mb-2" placeholder="Senha">
            </div>


            <button type="submit" class="btn btn-outline-success float-start ms-4">Register</button>

        </form>
    </div>
</template>